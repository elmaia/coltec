/**
 * @file   LE02_ex01.c
 * @brief  Arquivo com a implementa��o de sugest�o de 
 *         solu��o do exerc�cio 01 da LE 02 de 2024.
 * @author Leandro Maia Silva
 * @date   2024-03-28
 */

/* Inclus�es */
#include <stdio.h>   // printf e scanf

/* Constantes */

// Constante que associa o c�digo de erro 0 ao significado de sucesso
#define SUCESSO  0

/**
 * Fa�a o fluxograma e um programa que leia dois n�meros
 * inteiros e determine qual deles � o maior (n�o o maior valor) ou se s�o
 * iguais
 */
int main(int argc, char ** argv){

  int numero1, numero2;

  // Obtenho os n�meros
  printf("Digite dois numeros separados par espaco para compara-los (Ex: 8 15) : ");
  scanf("%d %d", &numero1, &numero2);

  // Realizo as compara��es e imprimo a informa��o conforme resultado
  if (numero1 == numero2) {
    printf("Os numeros %d e %d sao IGUAIS.\n", numero1, numero2);
  } else {
    if (numero1 < numero2) {
      printf("Entre os numeros %d e %d, o segundo eh maior com valor %d.\n", numero1, numero2, numero2);
    } else {
      printf("Entre os numeros %d e %d, o primeiro eh maior com valor %d.\n", numero1, numero2, numero1);
    }
  }

  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}