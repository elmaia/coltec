/**
 * @file   LE02_ex04.c
 * @brief  Arquivo com a implementa��o de sugest�o de 
 *         solu��o do exerc�cio 04 da LE 02 de 2024.
 * @author Leandro Maia Silva
 * @date   2024-03-28
 */

/* Inclus�es */
#include <stdio.h>   // printf e scanf
#include <math.h>    // pow

/* Constantes */

// Constante que associa o c�digo de erro 0 ao significado de sucesso
#define SUCESSO  0

/**
 * Fa�a o fluxograma e um programa que leia dois n�meros
 * inteiros e uma das opera��es (soma, subtra��o, multiplica��o, divis�o,
 * pot�ncia e radicia��o) e imprima a opera��o com o resultado.
 */
int main(int argc, char ** argv){

  int numero1, numero2;
  char operador;

  // Obtem a expressao
  printf("Digite a expressao simples a ser calculada (Ex: 2 * 2): ");
  printf("+ : adicao\n");
  printf("* : substracao\n");
  printf("* : multiplicacao\n");
  printf("/ : divisao\n");
  printf("^ : potenciacao\n");
  printf("# : radiciacao\n");
  scanf("%d %c %d", &numero1, &operador, &numero2);

  switch (operador) {
  case '+':
    printf("%d %c %d = %d", numero1, operador, numero2, numero1 + numero2);
    break;
  case '-':
    printf("%d %c %d = %d", numero1, operador, numero2, numero1 - numero2);
    break;
  case '*':
    printf("%d %c %d = %d", numero1, operador, numero2, numero1 * numero2);
    break;
  case '/':
    printf("%d %c %d = %f", numero1, operador, numero2, 1.0 * numero1 / numero2);
    break;
  case '^':
    printf("%d %c %d = %lf", numero1, operador, numero2,  pow(numero1, numero2));
    break;
  case '#':
    printf("%d %c %d = %lf", numero1, operador, numero2,  pow(numero1, 1.0 / numero2));
    break;
  default:
    printf("Operacao invalida.\n");
    break;
  }

  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}