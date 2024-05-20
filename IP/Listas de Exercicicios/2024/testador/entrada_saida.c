#include <string.h>
#include <stdio.h>

#define BUFFER_MAX 1024
#define SUCESSO 0

/**
 * Macro para utilização do canal de saída de erro como
 * saída de texto para testes automáticos.
 */
#ifdef TESTADOR
  #define PRINTF(format, args...) fprintf(stderr, format, args)
#else
  #define PRINTF(format, args...) printf(format, args)
#endif

/**
 * Programa que recebe uma entrada e imprime na saída
 * exatamente a entrada.
 * Feito para testar o testador.
 * @param argc Número de argumentos.
 * @param argv Valores dos argumentos.
 * @return Código de erro indicando o que ocorreu.
 */
int main(int argc, char ** argv) {
  
  char entrada[BUFFER_MAX];
  
  // Lê a entrada e remove o \n final
  fgets(entrada, BUFFER_MAX, stdin);
  if ((strlen(entrada) > 0) && (entrada[strlen(entrada) -1] = '\n')) {
    entrada[strlen(entrada) -1] = '\0';
  }
  
  printf("Saida Normal\n");
  PRINTF("%s\n", entrada);
  
  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;  
}