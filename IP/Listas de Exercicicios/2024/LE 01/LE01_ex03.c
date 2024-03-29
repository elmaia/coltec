/**
 * @file   LE01_ex03.c
 * @brief  Arquivo com a implementa��o de sugest�o de 
 *         solu��o do exerc�cio 03 da LE 01 de 2024.
 * @author Leandro Maia Silva
 * @date   2024-03-28
 */

/* Inclus�es */
#include <stdio.h>

/* Constantes */

// Constante que associa o c�digo de erro 0 ao significado de sucesso
#define SUCESSO  0

/**
 * Fa�a o fluxograma e um programa para ler seis valores
 * reais, calcular e imprimir a m�dia aritm�tica deles.
 */
int main(int argc, char ** argv){
  
  float val1, val2, val3, val4, val5, val6, media;

  // Leitura dos valores digitados pelo usu�rio
  printf("Vamos calcular a media de seis valores. Digite cada valor e aperte <enter>.\n");
  scanf("%f", &val1);
  scanf("%f", &val2);
  scanf("%f", &val3);
  scanf("%f", &val4);
  scanf("%f", &val5);
  scanf("%f", &val6);

  // Calcula a m�dia e mostra o resultado
  media = (val1 + val2 + val3 + val4 + val5 + val6) / 6;
  printf("A media dos seis valores e: %f\n", media);

  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}