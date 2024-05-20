/* Inclus�es */
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

// Tempo m�ximo que o programa tem para rodar
#define TIMEOUT_SECS 1

/* Macros */

#define popen _popen
#define pclose _pclose

/* Vari�veis Globais */

// Vari�vel para sinalizar que o tempo acabou
volatile sig_atomic_t timed_out = 0;

/* Erros */

// C�digo de erro indicando que deu tudo certo
#define SUCESSO                       0
// C�digo de erro indicando que o n�mero de argumentos foi inv�lido
#define ERRO_ARGUMENTOS_INSUFICIENTES 1
// C�digo de erro indicando que deu falha ao abrir o programa
#define ERRO_ABERTURA_PROGRAMA        2
// C�digo de erro indicando falha ao abrir arquivo de sa�da
#define ERRO_ABERTURA_ARQUIVO_SAIDA   3

/**
 * Fun��o para sinalizar que o tempo acabou.
 */
void handle_timeout(int sig) {
  timed_out = 1;
}

/**
 * Programa para testar automaticamente seus exerc�cios.
 * @param argc N�mero de argumentos.
 * @param argv Valores do argumentos.
 * @return C�digo de erro indicando o que aconteceu com o programa.
 */ 
int main(int argc, char ** argv) {
  
  char comando[MAX_BUFFER];
  char* programa = argv[1];
  char* entrada = argv[2];
  char* saida_esperada = argv[3];
  char buffer_saida[MAX_BUFFER];
  char buffer_esperado[MAX_BUFFER];
  bool iguais = true;

  // Verifica��o do n�mero de argumentos
  if (argc != 4) {
    fprintf(stderr, "Uso: %s <programa> <entrada> <saida_esperada>\n", argv[0]);
    return ERRO_ARGUMENTOS_INSUFICIENTES;
  }

  // Monta o comando
  sprintf(comando, "%s 2>&1 >nul <%s", programa, entrada);
  printf("Comando: %s\n",comando);

  // Abre o programa obtendo a sa�da
  FILE* pipe = popen(comando, "r");
  if (!pipe) {
    perror("Erro ao executar o programa");
    return ERRO_ABERTURA_PROGRAMA;
  }

  // Aguardar o t�rmino do processo usando WaitForSingleObject
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

  // Abre o arquivo de sa�da esperada
  FILE* arq_saida_esperada = fopen(saida_esperada, "r");
  if (!arq_saida_esperada) {
    perror("Erro ao abrir o arquivo de sa�da esperada");
    pclose(pipe);
    return ERRO_ABERTURA_ARQUIVO_SAIDA;
  }
  
  // Inicialmente s�o iguais
  iguais = true;

  // Compara linha a linha
  while (fgets(buffer_saida, MAX_BUFFER, pipe) && fgets(buffer_esperado, MAX_BUFFER, arq_saida_esperada)) {
    if (strcmp(buffer_saida, buffer_esperado) != 0) {
      // Se algo j� � diferente, ent�o encerra
      iguais = false;
      break;
    }
  }
  if (iguais && (fgets(buffer_saida, MAX_BUFFER, pipe) || fgets(buffer_esperado, MAX_BUFFER, arq_saida_esperada))) {
    iguais = false;
  }

  // Fecha as sa�das
  pclose(pipe);
  fclose(arq_saida_esperada);

  // Mostra o resultado
  if (iguais) {
    printf("As saidas sao iguais.\n");
  } else {
    printf("As saidas sao diferentes.\n");
  }

  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}
