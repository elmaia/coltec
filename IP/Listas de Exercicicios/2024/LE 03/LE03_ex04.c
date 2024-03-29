/**
 * @file   LE03_ex04.c
 * @brief  Arquivo com a implementação de sugestão de 
 *         solução do exercício 04 da LE 03 de 2024.
 * @author Leandro Maia Silva
 * @date   2024-03-28
 */

/* Inclusões */
#include <stdio.h>   // printf e scanf

/* Constantes */

// Constante que associa o código de erro 0 ao significado de sucesso
#define SUCESSO  0

/**
 * Faça um programa que calcule N! (fatorial de N), sendo
 * que o valor de N é fornecido pelo usuário.
 */
int main(int argc, char ** argv) {
  
  int n;
  int i;
  int fatorial = 1;

  // Interação o usuário para obter o número de termos
  printf("Digite o N para calcular F!: ");
  scanf("%d", &n);

  // Calcula o N!
  for (i = 1; i <= n; i++) {
    fatorial *= i;
  }

  // Mostra o N!
  printf("%d! = %d\n", n, fatorial);

  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}