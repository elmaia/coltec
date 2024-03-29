/**
 * @file   LE01_ex03.c
 * @brief  Arquivo com a implementação de sugestão de 
 *         solução do exercício 03 da LE 01 de 2024.
 * @author Leandro Maia Silva
 * @date   2024-03-28
 */

/* Inclusões */
#include <stdio.h>

/* Constantes */

// Constante que associa o código de erro 0 ao significado de sucesso
#define SUCESSO  0

/**
 * Faça o fluxograma e um programa para ler seis valores
 * reais, calcular e imprimir a média aritmética deles.
 */
int main(int argc, char ** argv){
  
  float val1, val2, val3, val4, val5, val6, media;

  // Leitura dos valores digitados pelo usuário
  printf("Vamos calcular a media de seis valores. Digite cada valor e aperte <enter>.\n");
  scanf("%f", &val1);
  scanf("%f", &val2);
  scanf("%f", &val3);
  scanf("%f", &val4);
  scanf("%f", &val5);
  scanf("%f", &val6);

  // Calcula a média e mostra o resultado
  media = (val1 + val2 + val3 + val4 + val5 + val6) / 6;
  printf("A media dos seis valores e: %f\n", media);

  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}