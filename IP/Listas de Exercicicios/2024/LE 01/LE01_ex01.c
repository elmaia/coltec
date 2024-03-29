/**
 * @file   LE01_ex01.c
 * @brief  Arquivo com a implementa��o de sugest�o de 
 *         solu��o do exerc�cio 01 da LE 01 de 2024.
 * @author Leandro Maia Silva
 * @date   2024-03-28
 */

/* Inclus�es */
#include <stdio.h>

/* Constantes */

// Constante que associa o c�digo de erro 0 ao significado de sucesso
#define SUCESSO  0

/**
 * Fa�a o fluxograma e um programa que leia o numerador e
 * o denominador de uma fra��o e imprima ambos seguido do resultado.
 * Considere que todos os n�meros s�o de ponto flutuante.
 */
int main(int argc, char ** argv) {
  
  float numerador, denominador, resultado;
  
  // Obtem os valores do usu�rio
  printf("Entre com os valores para calcular o resultado.\n");
  printf("Numerador: ");
  scanf("%f", &numerador);
  printf("Denominador: ");
  scanf("%f", &denominador);
  
  // Calcula e imprime o resultado
  resultado = numerador / denominador;
  printf("%f / %f = %f\n", numerador, denominador, resultado);
  
  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}