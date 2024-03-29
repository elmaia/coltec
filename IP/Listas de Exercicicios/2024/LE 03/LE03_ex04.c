/**
 * @file   LE03_ex04.c
 * @brief  Arquivo com a implementa��o de sugest�o de 
 *         solu��o do exerc�cio 04 da LE 03 de 2024.
 * @author Leandro Maia Silva
 * @date   2024-03-28
 */

/* Inclus�es */
#include <stdio.h>   // printf e scanf

/* Constantes */

// Constante que associa o c�digo de erro 0 ao significado de sucesso
#define SUCESSO  0

/**
 * Fa�a um programa que calcule N! (fatorial de N), sendo
 * que o valor de N � fornecido pelo usu�rio.
 */
int main(int argc, char ** argv) {
  
  int n;
  int i;
  int fatorial = 1;

  // Intera��o o usu�rio para obter o n�mero de termos
  printf("Digite o N para calcular F!: ");
  scanf("%d", &n);

  // Calcula o N!
  for (i = 1; i <= n; i++) {
    fatorial *= i;
  }

  // Mostra o N!
  printf("%d! = %d\n", n, fatorial);

  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}