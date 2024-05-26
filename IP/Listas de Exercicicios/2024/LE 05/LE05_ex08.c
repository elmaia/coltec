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
  #define PRINTF(format, ...) fprintf(stderr, format, __VA_ARGS__)
#else
  #define PRINTF(format, ...) printf(format, __VA_ARGS__)
#endif

// ----------------------------------------------------------------------

int numeroFibonacci(int termo) {
  
  int i;
  int Fn, Fn1 = 0, Fn2 = 1;

  for (i = 0; i < termo; i++) {

    // Calcula o termo atual
    Fn = Fn1 + Fn2;

    // Atualiza os termos
    Fn2 = Fn1;
    Fn1 = Fn;
  }
  
  // Retorna o número
  return Fn;
}

/**
 *  Fazer uma função para calcular o número de Fibonacci.
 *  Em seguida faça um programa para calcular e mostrar os N primeiros termos
 *  da série de Fibonacci. O número N é fornecido pelo usuário. A série de
 *  Fibonacci é : 1 1 2 3 5 8 13 ... Isto é f1 = f2 = 1, f3 = f1 + f2, f4 =
 *  f2 + f3
 */
int main(int argc, char ** argv) {
    
  int tamanho;
  int i;

  // Interação com o usuário
  printf("Serie de Fibonacci.\n");
  printf("Digite o numero de termos da serie: ");
  (void)scanf("%d", &tamanho);

  for (i = 1; i <= tamanho; i++) {
    // Mostra o número da serie
    PRINTF("%d ", numeroFibonacci(i));
  }
  printf("\n");  
  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}