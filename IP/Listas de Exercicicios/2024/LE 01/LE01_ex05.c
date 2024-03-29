/**
 * @file   LE01_ex05.c
 * @brief  Arquivo com a implementa��o de sugest�o de 
 *         solu��o do exerc�cio 05 da LE 01 de 2024.
 * @author Leandro Maia Silva
 * @date   2024-03-28
 */

/* Inclus�es */
#include <stdio.h>

/* Constantes */

// Constante que associa o c�digo de erro 0 ao significado de sucesso
#define SUCESSO  0

/**
 * Fa�a o fluxograma e um programa que calcule o novo
 * sal�rio de um funcion�rio. Voc� dever� obter o sal�rio atual e o
 * percentual de aumento que ser� dado ao funcion�rio.
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

  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}