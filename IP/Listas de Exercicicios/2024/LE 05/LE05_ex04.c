/**
 * @file   LE05_ex04.c
 * @brief  Arquivo com a implementa��o de sugest�o de 
 *         solu��o do exerc�cio 04 da LE 05 de 2024.
 * @author Leandro Maia Silva
 * @date   2024-05-24
 */

/* Inclus�es */
#include <stdio.h>   // printf e scanf
#include <stdbool.h> // bool, true e false

/* Constantes */

// Constante que associa o c�digo de erro 0 ao significado de sucesso
#define SUCESSO  0

// ----------------------------------------------------------------------

/**
 * Macro para utiliza��o do canal de sa�da de erro como
 * sa�da de texto para testes autom�ticos.
 */
#ifdef TESTADOR
  #define PRINTF(format, ...) fprintf(stderr, format, __VA_ARGS__)
#else
  #define PRINTF(format, ...) printf(format, __VA_ARGS__)
#endif

// ----------------------------------------------------------------------

bool ehPrimo(unsigned int numero) {
  
  unsigned int i;
  
  // Verifica se � 1, pois 1 n�o � primo.
  if (numero == 1) return false;
  
  for(i = 2; i < numero; i++) {
    // Verifica se � divisor
    if ((numero % i) == 0) return false;
  }
  
  // Se chegou at� aqui � porque � divis�vel apenas por 1 e ele mesmo
  return true;
}

/**
 *  Implemente uma fun��o que receba um n�mero inteiro como
 *  entrada e verifique se esse n�mero � primo ou n�o.
 */
int main(int argc, char ** argv) {
    
  unsigned int numero;
  bool numEhPrimo;
  
  printf("Teste de numero Primo.\n");
  printf("Digite o numero pra saber se eh primo.\n");
  printf(":> ");
  scanf("%u", &numero);
  
  // Verifica se � primo e mostra
  numEhPrimo = ehPrimo(numero);
  printf("O numero %u eh primo? ", numero);
  PRINTF("%s", (numEhPrimo ? "Sim" : "Nao"));
  printf("\n");
  
  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}