/**
 * @file   LE05_ex08.c
 * @brief  Arquivo com a implementação de sugestão de 
 *         solução do exercício 03 da LE 08 de 2024.
 * @author Leandro Maia Silva
 * @date   2024-05-24
 */

/* Inclusões */
#include <stdio.h>   // printf e scanf

/* Constantes */

// Constante que associa o código de erro 0 ao significado de sucesso
#define SUCESSO  0

// ----------------------------------------------------------------------

/**
 * Macro para utilização do canal de saída de erro como
 * saída de texto para testes automáticos.
 */
#ifdef TESTADOR
  #define PRINTF(format, args...) fprintf(stderr, format, args)
#else
  #define PRINTF(format, args...) printf(format, args)
#endif

// ----------------------------------------------------------------------

/**
 *  Fazer uma função para calcular o número de Fibonacci.
 *  Em seguida faça um programa para calcular e mostrar os N primeiros termos
 *  da série de Fibonacci. O número N é fornecido pelo usuário. A série de
 *  Fibonacci é : 1 1 2 3 5 8 13 ... Isto é f1 = f2 = 1, f3 = f1 + f2, f4 =
 *  f2 + f3
 */
int main(int argc, char ** argv) {
  
  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}