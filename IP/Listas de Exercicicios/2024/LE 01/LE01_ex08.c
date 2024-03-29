/**
 * @file   LE01_ex08.c
 * @brief  Arquivo com a implementa��o de sugest�o de 
 *         solu��o do exerc�cio 08 da LE 01 de 2024.
 * @author Leandro Maia Silva
 * @date   2024-03-28
 */

/* Inclus�es */
#include <stdio.h>

/* Constantes */

// Constante que associa o c�digo de erro 0 ao significado de sucesso
#define SUCESSO  0

/**
 * Fa�a um programa que leia, nesta ordem, a idade (valor
 * inteiro) de uma pessoa e a inicial do nome (caractere) e em seguida imprima os
 * valores lidos.
 */
int main(int argc, char ** argv){
  
  int idade;
  char inicial;
  
  // Obtem os dados do usu�rio
  printf("Digite a idade: ");
  scanf("%d", &idade);
  printf("Digite a inicial: ");
  scanf(" %c", &inicial);  // <--- O espa�o no inicio remove a quebra de linha que ficou
                           // Essa � uma de v�rias solu��es poss�veis. Para entender
                           // � necess�rio consultar a refer�ncia e ver que o espa�o (' ')
                           // remove quaisquer caracteres "whitespaces", incluindo o '\n'
  
  // Imprime os valores lidos
  printf("Idade: %d\t Inicial: %c\n", idade, inicial);
  
  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}