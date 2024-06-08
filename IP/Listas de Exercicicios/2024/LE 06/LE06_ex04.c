/**
 * @file   LE06_ex01.c
 * @brief  Arquivo com a implementação de sugestão de 
 *         solução do exercício 04 da LE 06 de 2024.
 * @author Leandro Maia Silva
 * @date   2024-06-08
 */

/* Inclusões */
#include <stdio.h>   // printf e scanf

/* Constantes */

// Constante que associa o código de erro 0 ao significado de sucesso
#define SUCESSO  0

// ----------------------------------------------------------------------

/**
 * Macro para utilização do canal de saída de erro como
 * saída de texto para testes automáticos.
 */
#ifdef TESTADOR
  #define PRINTF(format, ...) fprintf(stderr, format, __VA_ARGS__)
#else
  #define PRINTF(format, ...) printf(format, __VA_ARGS__)
#endif

// ----------------------------------------------------------------------

#define VETOR_TAMANHO_MAXIMO    10

/**
 * Faça um programa que leia um vetor de um tamanho escolhido
 * pelo usuário e calcule a média aritmética de seus valores, com duas casas decimais.
 * Atenção! Você deve determinar o máximo para que o exercício seja factível 
 * com o assunto estudado até o momento.
 * 
 * Exemplo:
 * Entrada: 4\n5.5 8.2 6.0 7.3
 * Saída: 6.75
 * Explicação: Foi lido um vetor de tamanho 4 com os valores [5.5 8.2 6.0 7.3], cuja 
 * média aritmética destes valores é 6.75.
 */
int main(int argc, char ** argv) {
  
  int tamanho, i;
  float vetor[VETOR_TAMANHO_MAXIMO], soma = 0.0, media;

  // Leitura do tamanho do vetor
  printf("Digite o tamanho do vetor [1:%d]: ", VETOR_TAMANHO_MAXIMO);
  scanf("%d", &tamanho);

  // Leitura dos elementos do vetor
  printf("Digite os elementos do vetor:\n");
  for (i = 0; i < tamanho; i++) {
      printf("Vetor[%d]: ", i );
      scanf("%f", &vetor[i]);
      
      // Soma o valor lido 
      soma += vetor[i];
  }

  // Cálculo da média
  media = soma / tamanho;

  // Impressão da média com duas casas decimais
  printf("A media aritmetica dos valores eh: ");
  PRINTF("%.2f", media);
  printf("\n");

  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}