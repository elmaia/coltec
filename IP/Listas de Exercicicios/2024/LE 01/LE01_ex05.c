/**
 * @file   LE01_ex05.c
 * @brief  Arquivo com a implementação de sugestão de 
 *         solução do exercício 05 da LE 01 de 2024.
 * @author Leandro Maia Silva
 * @date   2024-03-28
 */

/* Inclusões */
#include <stdio.h>

/* Constantes */

// Constante que associa o código de erro 0 ao significado de sucesso
#define SUCESSO  0

/**
 * Faça o fluxograma e um programa que calcule o novo
 * salário de um funcionário. Você deverá obter o salário atual e o
 * percentual de aumento que será dado ao funcionário.
 */
int main(int argc, char ** argv){

  float salario, percAumento, valAumento, novoSalario;

  // Obtem os dados
  printf("Digite seu salario atual: ");
  scanf("%f", &salario);
  printf("Digite a porcentagem de aumento: ");
  scanf("%f", &percAumento);

  // Calcula o aumento, novo salario e imprime o valores
  valAumento = salario * (percAumento / 100);
  novoSalario = salario + valAumento;
  printf("Valor do aumento: %.2f\nValor do salario: %.2f\n", valAumento, novoSalario);

  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}