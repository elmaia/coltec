/**
 * @file   LE01_ex04.c
 * @brief  Arquivo com a implementa��o de sugest�o de 
 *         solu��o do exerc�cio 04 da LE 01 de 2024.
 * @author Leandro Maia Silva
 * @date   2024-03-28
 */

/* Inclus�es */
#include <stdio.h>

/* Constantes */

// Constante que associa o c�digo de erro 0 ao significado de sucesso
#define SUCESSO  0

/**
 * Fa�a o fluxograma e um programa para calcular e imprimir
 * o valor de H, sendo H = 1/1 + 1/2 + 1/3 + 1/4 + 1/5
 */
int main(int argc, char ** argv){

  float H;

  // Calcula o valor de H
  H = 1 + (1.0f / 2) + (1.0f / 3) + (1.0f / 4) + (1.0f / 5);

  printf("O valor de H e: %f", H);

  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}