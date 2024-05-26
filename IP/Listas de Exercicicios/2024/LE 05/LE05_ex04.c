/**
 * @file   LE05_ex04.c
 * @brief  Arquivo com a implementação de sugestão de 
 *         solução do exercício 04 da LE 05 de 2024.
 * @author Leandro Maia Silva
 * @date   2024-05-24
 */

/* Inclusões */
#include <stdio.h>   // printf e scanf
#include <stdbool.h> // bool, true e false

/* Constantes */

// Constante que associa o código de erro 0 ao significado de sucesso
#define SUCESSO  0

// ----------------------------------------------------------------------

/**
 * Macro para utilização do canal de saída de erro como
 * saída de texto para testes automáticos.
 */
#ifdef TESTADOR
  #define PRINTF(format, ...) fprintf(stderr, format, __VA_ARGS__)
#else
  #define PRINTF(format, ...) printf(format, __VA_ARGS__)
#endif

// ----------------------------------------------------------------------

bool ehPrimo(unsigned int numero) {
  
  unsigned int i;
  
  // Verifica se é 1, pois 1 não é primo.
  if (numero == 1) return false;
  
  for(i = 2; i < numero; i++) {
    // Verifica se é divisor
    if ((numero % i) == 0) return false;
  }
  
  // Se chegou até aqui é porque é divisível apenas por 1 e ele mesmo
  return true;
}

/**
 *  Implemente uma função que receba um número inteiro como
 *  entrada e verifique se esse número é primo ou não.
 */
int main(int argc, char ** argv) {
    
  unsigned int numero;
  bool numEhPrimo;
  
  printf("Teste de numero Primo.\n");
  printf("Digite o numero pra saber se eh primo.\n");
  printf(":> ");
  scanf("%u", &numero);
  
  // Verifica se é primo e mostra
  numEhPrimo = ehPrimo(numero);
  printf("O numero %u eh primo? ", numero);
  PRINTF("%s", (numEhPrimo ? "Sim" : "Nao"));
  printf("\n");
  
  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}