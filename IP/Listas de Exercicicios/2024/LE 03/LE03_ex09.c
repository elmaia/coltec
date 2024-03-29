/**
 * @file   LE03_ex09.c
 * @brief  Arquivo com a implementa��o de sugest�o de 
 *         solu��o do exerc�cio 09 da LE 03 de 2024.
 * @author Leandro Maia Silva
 * @date   2024-03-28
 */

/* Inclus�es */
#include <stdio.h>   // printf e scanf

/* Constantes */

// Constante que associa o c�digo de erro 0 ao significado de sucesso
#define SUCESSO  0

/**
 * Fazer um programa para calcular e mostrar os N primeiros
 * termos da s�rie de Fibonacci. O n�mero N � fornecido pelo usu�rio. A
 * s�rie de Fibonacci � : 1 1 2 3 5 8 13 ... Isto � f1 = f2 = 1, f3 = f1 +
 * f2, f4 = f2 + f3
 */
int main(int argc, char ** argv) {
  
  int tamanho;
  int i, retorno;
  int Fn, Fn1 = 0, Fn2 = 1;

  // Intera��o com o usu�rio
  printf("Digite o numero de termos da serie de Fibonacci: ");
  retorno = scanf("%d", &tamanho);

  for (i = 0; i < tamanho; i++) {

    // Calcula o termo atual
    Fn = Fn1 + Fn2;

    // Mostra o n�mero da sequencia
    printf("%d ", Fn);

    // Atualiza os termos
    Fn2 = Fn1;
    Fn1 = Fn;
  }
  printf("\n");
  
  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}