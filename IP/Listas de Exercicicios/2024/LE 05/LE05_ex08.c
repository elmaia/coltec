/**
 * @file   LE05_ex08.c
 * @brief  Arquivo com a implementa��o de sugest�o de 
 *         solu��o do exerc�cio 03 da LE 08 de 2024.
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
 *  Fazer uma fun��o para calcular o n�mero de Fibonacci.
 *  Em seguida fa�a um programa para calcular e mostrar os N primeiros termos
 *  da s�rie de Fibonacci. O n�mero N � fornecido pelo usu�rio. A s�rie de
 *  Fibonacci � : 1 1 2 3 5 8 13 ... Isto � f1 = f2 = 1, f3 = f1 + f2, f4 =
 *  f2 + f3
 */
int main(int argc, char ** argv) {
  
  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}