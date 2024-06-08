/**
 * @file   LE06_ex01.c
 * @brief  Arquivo com a implementação de sugestão de 
 *         solução do exercício 06 da LE 06 de 2024.
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
 * Multiplica um vetor de tamanho especificado por um escalar e coloca
 * em um vetor de resultado.
 * @param vetor Vetor de número a ser multiplicado.
 * @param tamanho Quantidade de números no vetor.
 * @param escalar Valor escalar que multiplicará o vetor.
 * @param resultado Vetor que receberá o resultado da multiplicação.
 */
void multiplicaVetorEscalar(float vetor[], int tamanho, float escalar, float resultado[]) {
  
  int i;
  
  // Multiplicação do vetor pelo escalar
  for (i = 0; i < tamanho; i++) {
    resultado[i] = vetor[i] * escalar;
  }  
}

/**
 * Questão 02:
 * Desenvolva um programa que leia um vetor de números reais, um escalar e 
 * imprima o resultado da multiplicação do vetor pelo escalar, com duas casas decimais.
 * Atenção! Você deve determinar o máximo para que o exercício seja factível 
 * com o assunto estudado até o momento.
 * 
 * Exemplo: 
 * Entrada: 5\n2 3.5 0 1.8 4\n3
 * Saída: 6.00 -10.50 0.00 5.40 12.00
 * Explicação: Foi lido um vetor de tamanho 5 com os valores [2 3.5 0 1.8  4], além do escalar 3. 
 * Cada um dos números foi multiplicado por 3 (escalar) e a saída é o vetor [6.00 -10.50 0.00 5.40 12.00]
 *
 * Questão 06:
 * Faça uma cópia da questão 02 e crie uma função que, dado um vetor, seu tamanho e um escalar, 
 * calcule o resultado da multiplicação do vetor pelo escalar.
 * Modifique a questão para encontrar a solução usando a função criada.
 */
int main(int argc, char ** argv) {
  
  float vetor[VETOR_TAMANHO_MAXIMO];
  float escalar;
  float resultado[VETOR_TAMANHO_MAXIMO];
  int tamanho;
  int i;
  
  // Leitura do tamanho do vetor
  printf("Digite o tamanho do vetor [1:%d]: ", VETOR_TAMANHO_MAXIMO);
  scanf("%d", &tamanho);

  // Leitura dos elementos do vetor
  printf("Digite os elementos do vetor:\n");
  for (i = 0; i < tamanho; i++) {
      printf("Vetor[%d]: ", i);
      scanf("%f", &vetor[i]);
  }

  // Leitura do escalar
  printf("Digite o valor do escalar: ");
  scanf("%f", &escalar);
  
  // Calcula o produto do vetor pelo escalar
  multiplicaVetorEscalar(vetor, tamanho, escalar, resultado);

  // Imprime o resultado
  printf("Resultado da multiplicacao:\n");
  printf("[");
  for (i = 0; i < tamanho; i++) {
    PRINTF("%.2f ", resultado[i]);
  }
  printf("]\n");

  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}