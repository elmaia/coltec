/**
 * @file   LE02_ex01.c
 * @brief  Arquivo com a implementação de sugestão de 
 *         solução do exercício 01 da LE 02 de 2024.
 * @author Leandro Maia Silva
 * @date   2024-03-28
 */

/* Inclusões */
#include <stdio.h>   // printf e scanf

/* Constantes */

// Constante que associa o código de erro 0 ao significado de sucesso
#define SUCESSO  0

/**
 * Faça o fluxograma e um programa que leia dois números
 * inteiros e determine qual deles é o maior (não o maior valor) ou se são
 * iguais
 */
int main(int argc, char ** argv){

  int numero1, numero2;

  // Obtenho os números
  printf("Digite dois numeros separados par espaco para compara-los (Ex: 8 15) : ");
  scanf("%d %d", &numero1, &numero2);

  // Realizo as comparações e imprimo a informação conforme resultado
  if (numero1 == numero2) {
    printf("Os numeros %d e %d sao IGUAIS.\n", numero1, numero2);
  } else {
    if (numero1 < numero2) {
      printf("Entre os numeros %d e %d, o segundo eh maior com valor %d.\n", numero1, numero2, numero2);
    } else {
      printf("Entre os numeros %d e %d, o primeiro eh maior com valor %d.\n", numero1, numero2, numero1);
    }
  }

  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}