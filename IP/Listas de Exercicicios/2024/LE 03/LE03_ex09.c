/**
 * @file   LE03_ex09.c
 * @brief  Arquivo com a implementação de sugestão de 
 *         solução do exercício 09 da LE 03 de 2024.
 * @author Leandro Maia Silva
 * @date   2024-03-28
 */

/* Inclusões */
#include <stdio.h>   // printf e scanf

/* Constantes */

// Constante que associa o código de erro 0 ao significado de sucesso
#define SUCESSO  0

/**
 * Fazer um programa para calcular e mostrar os N primeiros
 * termos da série de Fibonacci. O número N é fornecido pelo usuário. A
 * série de Fibonacci é : 1 1 2 3 5 8 13 ... Isto é f1 = f2 = 1, f3 = f1 +
 * f2, f4 = f2 + f3
 */
int main(int argc, char ** argv) {
  
  int tamanho;
  int i, retorno;
  int Fn, Fn1 = 0, Fn2 = 1;

  // Interação com o usuário
  printf("Digite o numero de termos da serie de Fibonacci: ");
  retorno = scanf("%d", &tamanho);

  for (i = 0; i < tamanho; i++) {

    // Calcula o termo atual
    Fn = Fn1 + Fn2;

    // Mostra o número da sequencia
    printf("%d ", Fn);

    // Atualiza os termos
    Fn2 = Fn1;
    Fn1 = Fn;
  }
  printf("\n");
  
  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}