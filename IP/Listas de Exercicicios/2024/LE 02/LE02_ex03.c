/**
 * @file   LE02_ex03.c
 * @brief  Arquivo com a implementação de sugestão de 
 *         solução do exercício 03 da LE 02 de 2024.
 * @author Leandro Maia Silva
 * @date   2024-03-28
 */

/* Inclusões */
#include <stdio.h>   // printf e scanf

/* Constantes */

// Constante que associa o código de erro 0 ao significado de sucesso
#define SUCESSO  0

/**
 * Faça um programa para ler o número do dia da semana e
 * imprimir seu respectivo nome por extenso. Considere o número 1 como
 * domingo, 2 como segunda e etc. Caso o dia da semana seja inválido, exibir
 * a mensagem “Dia da Semana invalido”.
 */
int main(int argc, char ** argv){

  int diaSemana;

  // Obtem o dia da semana
  printf("Digite o numero referente ao dia da semana para obter seu nome [1:7]: ");
  scanf("%d", &diaSemana);

  // Imprime o dia da semana conforme o numero
  switch (diaSemana) {
    case 1:
      printf("Domingo\n");
      break;
    case 2:
      printf("Segunda-feira\n");
      break;
    case 3:
      printf("Terca-feira\n");
      break;
    case 4:
      printf("Quarta-feira\n");
      break;
    case 5:
      printf("Quinta-feira\n");
      break;
    case 6:
      printf("Sexta-feira\n");
      break;
    case 7:
      printf("Sabado\n");
      break;

    default:
      printf("Dia da semana invalido\n");
      break;
  }

  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}