/**
 * @file   LE02_ex02.c
 * @brief  Arquivo com a implementa��o de sugest�o de 
 *         solu��o do exerc�cio 02 da LE 02 de 2024.
 * @author Leandro Maia Silva
 * @date   2024-03-28
 */

/* Inclus�es */
#include <stdio.h>   // printf e scanf
#include <stdbool.h> // bool

/* Constantes */

// Constante que associa o c�digo de erro 0 ao significado de sucesso
#define SUCESSO  0

/**
 * Fa�a o fluxograma e um programa que leia tr�s
 * comprimentos (x, y e z) e responda se eles formam um tri�ngulo, ou seja,
 * se x < y + z e y < x + z e z < x + y.
 */
int main(int argc, char ** argv){

  float x, y, z;
  bool ehTriangulo;

  // Obtem os lados
  printf("Digite os comprimentos dos segmentos para verificar se forma um triangulo (Ex: 1.0 1.0. 2.0): ");
  scanf("%f %f %f", &x, &y, &z);

  // Verifica se � um triangulo
  ehTriangulo = (x < y + z) && (y < x + z) && (z < x + y);

  // Mostra o resultado
  if (ehTriangulo) {
    printf("Os comprimentos %f, %f e %f FORMAM um triangulo.\n", x, y, z);
  } else {
    printf("Os comprimentos %f, %f e %f NAO FORMAM um triangulo.\n", x, y, z);
  }

  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}
