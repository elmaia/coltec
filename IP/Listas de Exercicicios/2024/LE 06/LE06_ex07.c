/**
 * @file   LE06_ex03.c
 * @brief  Arquivo com a implementação de sugestão de 
 *         solução do exercício 03 da LE 06 de 2024.
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

float produtoEscalarVetores(float vetor1[], float vetor2[], int tamanho) {
  
  int i;
  float produtoEscalar = 0.0f;
  
  // Calcula o produto escalar
  for (i = 0; i < tamanho; i++) {
      produtoEscalar += vetor1[i] * vetor2[i];
  }
  
  // retorna o produto escalar calculado
  return produtoEscalar;
}

/**
 * Questão 03:
 * Faça um programa que leia 2 vetores de mesmo tamanho e calcule o produto escalar deles, com duas casas decimais.
 * Atenção! Você deve determinar o máximo para que o exercício seja factível com o assunto estudado até o momento.
 * 
 * Exemplo:
 * Entrada: 3\n1 2 3\n4 5 6\n
 * Saída: 32.00
 * Explicação: Foram lidos dois vetores de tamanho 3, [1 2 3] e [4 5 6] e o produto escalar dele é (1*4 + 2*5 + 3*6) = 32 
 *
 * Questão 07:
 * Faça uma cópia da questão 03 e crie uma função que, dado dois vetores e seus tamanhos 
 * (mesmo tamanho para ambos), calcule o resultado do produto escalar deles.
 * Modifique a questão para encontrar a solução usando a função criada.
 */
int main(int argc, char ** argv) {

  int tamanho, i;
  float vetor1[VETOR_TAMANHO_MAXIMO], vetor2[VETOR_TAMANHO_MAXIMO], produtoEscalar = 0.0f;

  // Leitura do tamanho dos vetores
  printf("Digite o tamanho dos vetores [1:%d]: ", VETOR_TAMANHO_MAXIMO);
  scanf("%d", &tamanho);

  // Leitura dos elementos do primeiro vetor
  printf("Digite os elementos do primeiro vetor:\n");
  for (i = 0; i < tamanho; i++) {
      printf("Vetor1[%d]: ", i);
      scanf("%f", &vetor1[i]);
  }

  // Leitura dos elementos do segundo vetor
  printf("Digite os elementos do segundo vetor:\n");
  for (i = 0; i < tamanho; i++) {
      printf("Vetor2[%d]: ", i);
      scanf("%f", &vetor2[i]);
  }

  // Cálculo do produto escalar
  produtoEscalar = produtoEscalarVetores(vetor1, vetor2, tamanho);

  // Impressão do resultado
  printf("O produto escalar dos vetores eh: ");
  PRINTF("%.2f", produtoEscalar);
  printf("\n");

  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}