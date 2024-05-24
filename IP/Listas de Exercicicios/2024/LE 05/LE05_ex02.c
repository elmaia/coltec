/**
 * @file   LE05_ex02.c
 * @brief  Arquivo com a implementação de sugestão de 
 *         solução do exercício 02 da LE 05 de 2024.
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
 *  Faça uma função que receba a idade de uma pessoa em
 *  anos, meses e dias e retorna essa idade expressa em dias.
 *  Considere cada ano como 365 dias e cada mês como 30 dias.
 */
int main(int argc, char ** argv) {
  
  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}