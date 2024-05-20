/* Inclusões */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <signal.h>
#include <io.h> // Para _get_osfhandle no Windows
#include <windows.h>

/* Constantes */

// Tamanho do buffer
#define MAX_BUFFER 1024

// Tempo máximo que o programa tem para rodar
#define TIMEOUT_SECS 1

/* Macros */

#define popen _popen
#define pclose _pclose

/* Variáveis Globais */

// Variável para sinalizar que o tempo acabou
volatile sig_atomic_t timed_out = 0;

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
  timed_out = 1;
}

/**
 * Programa para testar automaticamente seus exercícios.
 * @param argc Número de argumentos.
 * @param argv Valores do argumentos.
 * @return Código de erro indicando o que aconteceu com o programa.
 */ 
int main(int argc, char ** argv) {
  
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
  sprintf(comando, "%s 2>&1 >nul <%s", programa, entrada);
  printf("Comando: %s\n",comando);

  // Abre o programa obtendo a saída
  FILE* pipe = popen(comando, "r");
  if (!pipe) {
    perror("Erro ao executar o programa");
    return ERRO_ABERTURA_PROGRAMA;
  }

  // Aguardar o término do processo usando WaitForSingleObject
  HANDLE processHandle = (HANDLE)_get_osfhandle(_fileno(pipe));
  DWORD exitCode;
  DWORD start_time = GetTickCount();
  while (GetTickCount() - start_time < TIMEOUT_SECS * 1000 && !timed_out) {
    if (GetExitCodeProcess(processHandle, &exitCode) && exitCode != STILL_ACTIVE) {
      break; // O processo filho terminou
    }
    Sleep(100);
  }
  if (timed_out) {
    printf("Tempo limite excedido!\n");
    TerminateProcess(processHandle, 1);
  }

  // Abre o arquivo de saída esperada
  FILE* arq_saida_esperada = fopen(saida_esperada, "r");
  if (!arq_saida_esperada) {
    perror("Erro ao abrir o arquivo de saída esperada");
    pclose(pipe);
    return ERRO_ABERTURA_ARQUIVO_SAIDA;
  }
  
  // Inicialmente são iguais
  iguais = true;

  // Compara linha a linha
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

  // Fecha as saídas
  pclose(pipe);
  fclose(arq_saida_esperada);

  // Mostra o resultado
  if (iguais) {
    printf("As saidas sao iguais.\n");
  } else {
    printf("As saidas sao diferentes.\n");
  }

  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}
