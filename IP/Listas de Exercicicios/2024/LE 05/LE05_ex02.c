/**
 * @file   LE05_ex02.c
 * @brief  Arquivo com a implementa��o de sugest�o de 
 *         solu��o do exerc�cio 02 da LE 05 de 2024.
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
 *  Fa�a uma fun��o que receba a idade de uma pessoa em
 *  anos, meses e dias e retorna essa idade expressa em dias.
 *  Considere cada ano como 365 dias e cada m�s como 30 dias.
 */
int main(int argc, char ** argv) {
  
  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}