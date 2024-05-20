#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>    // Para fork, execvp, pipe, dup2
#include <sys/wait.h>  // Para waitpid
#include <sys/time.h>  // Para gettimeofday
#include <fcntl.h>     // Para open

/* Constantes */

// Tamanho do buffer
#define MAX_BUFFER 1024

// Tempo máximo que o programa tem para rodar
#define TIMEOUT_SECS 1

/* Variáveis Globais */

// Variável para sinalizar que o tempo acabou
volatile sig_atomic_t timed_out = 0;
// Variável global para armazenar o PID do processo filho
pid_t child_pid;


/* Erros */

// Código de erro indicando que deu tudo certo
#define SUCESSO                       0
// Código de erro indicando que o número de argumentos foi inválido
#define ERRO_ARGUMENTOS_INSUFICIENTES 1
// Código de erro indicando que deu falha ao abrir o programa
#define ERRO_ABERTURA_PROGRAMA        2
// Código de erro indicando falha ao abrir arquivo de saída
#define ERRO_ABERTURA_ARQUIVO_SAIDA   3

/**
 * Função para sinalizar que o tempo acabou.
 */
void handle_timeout(int sig) {
    printf("Tempo limite excedido!\n");
    if (child_pid > 0) {
        kill(child_pid, SIGKILL); // Encerra o processo filho imediatamente
    }
}

/**
 * Programa para testar automaticamente seus exercícios.
 * @param argc Número de argumentos.
 * @param argv Valores do argumentos.
 * @return Código de erro indicando o que aconteceu com o programa.
 */ 
int main(int argc, char **argv) {

    char comando[MAX_BUFFER];
    char* programa = argv[1];
    char* entrada = argv[2];
    char* saida_esperada = argv[3];
    char buffer_saida[MAX_BUFFER];
    char buffer_esperado[MAX_BUFFER];
    bool iguais = true;

    // Verificação do número de argumentos
    if (argc != 4) {
    fprintf(stderr, "Uso: %s <programa> <entrada> <saida_esperada>\n", argv[0]);
    return ERRO_ARGUMENTOS_INSUFICIENTES;
    }

    // Monta o comando
    sprintf(comando, "%s < %s", programa, entrada);
    printf("Comando: %s\n",comando);

    int pipefd[2];  // Descritor de arquivo para o pipe
    pid_t pid;

    if (pipe(pipefd) == -1) {
        perror("Erro ao criar o pipe");
        return ERRO_ABERTURA_PROGRAMA;
    }

    child_pid = fork();
    if (child_pid == -1) {
        perror("Erro ao criar o processo filho");
        return ERRO_ABERTURA_PROGRAMA;
    } else if (child_pid == 0) { // Processo filho
        dup2(pipefd[1], STDERR_FILENO);  // Redireciona stderr para o pipe
        close(pipefd[0]);  // Fecha a extremidade de leitura do pipe
        close(pipefd[1]);  // Fecha a extremidade de escrita do pipe

        // Abre o arquivo de entrada e redireciona stdin
        int fd_entrada = open(entrada, O_RDONLY);
        if (fd_entrada < 0) {
            perror("Erro ao abrir o arquivo de entrada");
            return ERRO_ABERTURA_PROGRAMA;
        }
        dup2(fd_entrada, STDIN_FILENO);
        close(fd_entrada);
        
        // Redireciona stdout para /dev/null
        int devNull = open("/dev/null", O_WRONLY);
        if (devNull == -1) {
            perror("Erro ao abrir /dev/null");
            return ERRO_ABERTURA_PROGRAMA;
        }
        dup2(devNull, STDOUT_FILENO);
        close(devNull);        

        char *args[] = {programa, NULL};
        execvp(programa, args);
        perror("Erro ao executar o programa");
        return ERRO_ABERTURA_PROGRAMA;
        
    } else { // Processo pai
        close(pipefd[1]);  // Fecha a extremidade de escrita do pipe
        FILE *pipe = fdopen(pipefd[0], "r"); // Abre o pipe para leitura
        
        // Configuração do alarme para o timeout
        struct sigaction sa;
        memset(&sa, 0, sizeof(sa));
        sa.sa_handler = handle_timeout;
        sigaction(SIGALRM, &sa, NULL);
        alarm(TIMEOUT_SECS);

        FILE *arq_saida_esperada = fopen(saida_esperada, "r");
        if (!arq_saida_esperada) {
            perror("Erro ao abrir o arquivo de saída esperada");
            pclose(pipe);
            return ERRO_ABERTURA_ARQUIVO_SAIDA;
        }

        iguais = true;

        while (fgets(buffer_saida, MAX_BUFFER, pipe) && fgets(buffer_esperado, MAX_BUFFER, arq_saida_esperada)) {
            if (strcmp(buffer_saida, buffer_esperado) != 0) {
              // Se algo já é diferente, então encerra
              iguais = false;
              break;
            }
        }
        if (iguais && (fgets(buffer_saida, MAX_BUFFER, pipe) || fgets(buffer_esperado, MAX_BUFFER, arq_saida_esperada))) {
            iguais = false;
        }

        fclose(arq_saida_esperada);
        fclose(pipe); // Fecha o pipe antes de esperar pelo filho

        // Aguarda o término do processo filho (ou timeout)
        int status;
        waitpid(child_pid, &status, 0);

        if (iguais) {
            printf("As saidas sao iguais.\n");
        } else {
            printf("As saidas sao diferentes.\n");
        }
    }
    
    // Se chegou até aqui é porque correu tudo bem
    return SUCESSO;
}