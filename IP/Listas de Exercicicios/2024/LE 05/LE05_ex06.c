/**
 * @file   LE05_ex06.c
 * @brief  Arquivo com a implementa��o de sugest�o de 
 *         solu��o do exerc�cio 06 da LE 05 de 2024.
 * @author Leandro Maia Silva
 * @date   2024-05-24
 */

/* Inclus�es */
#include <stdio.h>   // printf e scanf

/* Constantes */

// Constante que associa o c�digo de erro 0 ao significado de sucesso
#define SUCESSO  0

// ----------------------------------------------------------------------

/**
 * Macro para utiliza��o do canal de sa�da de erro como
 * sa�da de texto para testes autom�ticos.
 */
#ifdef TESTADOR
  #define PRINTF(format, args...) fprintf(stderr, format, args)
#else
  #define PRINTF(format, args...) printf(format, args)
#endif

// ----------------------------------------------------------------------

/**
 *  Fa�a uma fun��o que calcule um elemento do tri�ngulo de Pascal.
 *  Utilize essa fun��o para imprimir o tri�ngulo com alturas variando de 0
 *  a 10.
 */
int main(int argc, char ** argv) {
  
  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}