/**
 * @file   LE01_ex02.c
 * @brief  Arquivo com a implementa��o de sugest�o de 
 *         solu��o do exerc�cio 02 da LE 01 de 2024.
 * @author Leandro Maia Silva
 * @date   2024-03-28
 */

/* Inclus�es */
#include <stdio.h>

/* Constantes */

// Constante que associa o c�digo de erro 0 ao significado de sucesso
#define SUCESSO  0

/**
 * Fa�a o fluxograma e um programa que leia cinco valores
 * inteiros, calcule e imprima a soma deles.
 */
int main(int argc, char ** argv){
  
  int val1, val2, val3, val4, val5, soma;

  // Leitura dos valores digitados pelo usu�rio
  printf("Vamos somar cinco valores. Digite cada valor e aperte <enter>.\n");
  scanf("%d", &val1);
  scanf("%d", &val2);
  scanf("%d", &val3);
  scanf("%d", &val4);
  scanf("%d", &val5);

  // Calcula a soma e mostra o resultado
  soma = val1 + val2 + val3 + val4 + val5;
  printf("A soma dos cinco valores e: %d\n", soma);
  
  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}