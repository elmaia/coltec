/**
 * @file   LE03_ex08.c
 * @brief  Arquivo com a implementação de sugestão de 
 *         solução do exercício 08 da LE 03 de 2024.
 * @author Leandro Maia Silva
 * @date   2024-03-28
 */

/* Inclusões */
#include <stdio.h>   // printf e scanf

/* Constantes */

// Constante que associa o código de erro 0 ao significado de sucesso
#define SUCESSO  0

/**
 * Escrever um programa que lê um valor N inteiro e positivo
 * e que calcula e escreve o valor de E: E = 1 + 1/2! + 1/3! + ... + 1/N!
 * Atenção: Se fizer exatamente como está escrito acima, o resultado será 1.
 */
int main(int argc, char ** argv) {
  
  float E = 0;
  int i, j, retorno;
  int tamanho;
  float termoAtual, i_fatorial = 1;

  // Interação com o usuário
  printf("Digite o numero de termos de E: ");
  retorno = scanf("%d", &tamanho);

  // Calcula o valor de E com N termos
  for (i = 1; i <= tamanho; i++) {

    i_fatorial = 1;

    // Calcula o i!
    for (j = 1; j <= i; j++) {
      i_fatorial *= j;
    }

    // Calculo do termo atual
    termoAtual = 1 / i_fatorial;

    // Somo o termo atual no E
    E+= termoAtual;
  }

  // Mostra o valor do E
  printf("E : %f\n", E);
  
  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}