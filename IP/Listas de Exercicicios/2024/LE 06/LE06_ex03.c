/**
 * @file   LE06_ex03.c
 * @brief  Arquivo com a implementa��o de sugest�o de 
 *         solu��o do exerc�cio 03 da LE 06 de 2024.
 * @author Leandro Maia Silva
 * @date   2024-06-08
 */

/* Inclus�es */
#include <stdio.h>   // printf e scanf

/* Constantes */

// Constante que associa o c�digo de erro 0 ao significado de sucesso
#define SUCESSO  0

// ----------------------------------------------------------------------

/**
 * Macro para utiliza��o do canal de sa�da de erro como
 * sa�da de texto para testes autom�ticos.
 */
#ifdef TESTADOR
  #define PRINTF(format, ...) fprintf(stderr, format, __VA_ARGS__)
#else
  #define PRINTF(format, ...) printf(format, __VA_ARGS__)
#endif

// ----------------------------------------------------------------------

#define VETOR_TAMANHO_MAXIMO    10

/**
 *  
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

  // C�lculo do produto escalar
  for (i = 0; i < tamanho; i++) {
      produtoEscalar += vetor1[i] * vetor2[i];
  }

  // Impress�o do resultado
  printf("O produto escalar dos vetores eh: ");
  PRINTF("%.2f", produtoEscalar);
  printf("\n");

  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}