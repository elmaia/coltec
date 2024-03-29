/**
 * @file   LE02_ex06.c
 * @brief  Arquivo com a implementa��o de sugest�o de 
 *         solu��o do exerc�cio 06 da LE 02 de 2024.
 * @author Leandro Maia Silva
 * @date   2024-03-28
 */

/* Inclus�es */
#include <stdio.h>   // printf e scanf

/* Constantes */

// Constante que associa o c�digo de erro 0 ao significado de sucesso
#define SUCESSO  0

/**
 * Fa�a um programa que leia, nesta ordem, a altura (em
 * metros) e o sexo (caractere) e em seguida imprima o peso ideal dela.
 * Homens: (72,7 x altura) - 58
 * Mulheres: (62,1 x altura) � 44,7
 */
int main(int argc, char ** argv){

  float altura, pesoIdeal;
  char sexo;

  // Obtem os dados
  printf("Digite sua altura em metros: ");
  scanf("%f", &altura);
  printf("Digite seu sexo (M/m ou F/f): ");
  scanf(" %c", &sexo);

  // Calcula o peso ideal
  if ((sexo == 'M') || (sexo == 'm')) {
    pesoIdeal = (72.7f * altura) - 58;
  } else {
    pesoIdeal = (62.1f * altura) - 44.7f;
  }

  // Informa o peso ideal
  printf("Seu peso ideal eh %.2f. ", pesoIdeal);

  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}