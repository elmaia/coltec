/**
 * @file   LE08_ex01.c
 * @brief  Arquivo com a implementação de sugestão de 
 *         solução do exercício 01 da LE 08 de 2024.
 * @author Leandro Maia Silva
 * @date   2024-06-19
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

#define NUMERO_DE_LINHAS  (5)
#define NUMERO_DE_COLUNAS (5)

/**
 * Função que lê os dados de uma matriz 5 x 5.
 * @param matriz Matriz onde os dados lidos serão armazenados.
 */
void leMatriz(int matriz[NUMERO_DE_LINHAS][NUMERO_DE_COLUNAS]) {
  
  int i, j;
  
  printf("Entre com os valores inteiros da matriz:\n");
  for (i = 0; i < NUMERO_DE_LINHAS; i++) {
    for (j = 0; j < NUMERO_DE_COLUNAS; j++) {
      printf("matriz[%d][%d]: ", i, j);
      scanf("%d%*c", &matriz[i][j]);
    }
  }  
}

/**
 * Função que imprime os dados de uma matriz 5 x 5.
 * @param matriz Matriz a partir do qual os dados serão impressos.
 */
void imprimeMatriz(int matriz[NUMERO_DE_LINHAS][NUMERO_DE_COLUNAS]) {
  
  int i, j;
  
  printf("Dados da matriz:\n");
  for (i = 0; i < NUMERO_DE_LINHAS; i++) {
    for (j = 0; j < NUMERO_DE_COLUNAS; j++) {
      printf("matriz[%d][%d]: ", i, j);
      PRINTF("%d\n", matriz[i][j]);
    }
  }
}

/**
 * Faça um procedimento que leia os dados de uma matriz 5x5 e um procedimento que a imprima.
 *
 * Exemplo:
 * Entrada: 1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24\n25\n
 * Saída: 1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24\n25\n
 */
int main(int argc, char ** argv) {
  
  int matriz[NUMERO_DE_LINHAS][NUMERO_DE_COLUNAS];
  

  // Interação com o usuário
  printf("Le e imprime matriz 5 x 5.\n");
  
  // Faz a leitura dos dados
  leMatriz(matriz);
  
  // Faz a impressão
  imprimeMatriz(matriz);

  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}