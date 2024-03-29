/**
 * @file   LE01_ex06.c
 * @brief  Arquivo com a implementação de sugestão de 
 *         solução do exercício 06 da LE 01 de 2024.
 * @author Leandro Maia Silva
 * @date   2024-03-28
 */

/* Inclusões */
#include <stdio.h>

/* Constantes */

// Constante que associa o código de erro 0 ao significado de sucesso
#define SUCESSO  0

/**
 * Faça um programa que leia o numerador e o denominador
 * de uma fração e imprima ambos seguido do resultado, sendo todos com três
 * casas decimais. Considere que todos os números são de ponto flutuante.
 */
int main(int argc, char ** argv){
  
  float numerador, denominador, resultado;
  
  // Obtem os valores do usuário
  printf("Entre com os valores para calcular o resultado.\n");
  printf("Numerador: ");
  scanf("%f", &numerador);
  printf("Denominador: ");
  scanf("%f", &denominador);
  
  // Calcula e imprime o resultado
  resultado = numerador / denominador;
  printf("%.3f / %.3f = %.3f\n", numerador, denominador, resultado);

  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}