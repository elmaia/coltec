/**
 * @file   LE01_ex08.c
 * @brief  Arquivo com a implementação de sugestão de 
 *         solução do exercício 08 da LE 01 de 2024.
 * @author Leandro Maia Silva
 * @date   2024-03-28
 */

/* Inclusões */
#include <stdio.h>

/* Constantes */

// Constante que associa o código de erro 0 ao significado de sucesso
#define SUCESSO  0

/**
 * Faça um programa que leia, nesta ordem, a idade (valor
 * inteiro) de uma pessoa e a inicial do nome (caractere) e em seguida imprima os
 * valores lidos.
 */
int main(int argc, char ** argv){
  
  int idade;
  char inicial;
  
  // Obtem os dados do usuário
  printf("Digite a idade: ");
  scanf("%d", &idade);
  printf("Digite a inicial: ");
  scanf(" %c", &inicial);  // <--- O espaço no inicio remove a quebra de linha que ficou
                           // Essa é uma de várias soluções possíveis. Para entender
                           // é necessário consultar a referência e ver que o espaço (' ')
                           // remove quaisquer caracteres "whitespaces", incluindo o '\n'
  
  // Imprime os valores lidos
  printf("Idade: %d\t Inicial: %c\n", idade, inicial);
  
  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}