/**
 * @file   LE08_ex01.c
 * @brief  Arquivo com a implementa��o de sugest�o de 
 *         solu��o do exerc�cio 01 da LE 08 de 2024.
 * @author Leandro Maia Silva
 * @date   2024-06-19
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

#define NUMERO_DE_LINHAS  (5)
#define NUMERO_DE_COLUNAS (5)

/**
 * Fun��o que l� os dados de uma matriz 5 x 5.
 * @param matriz Matriz onde os dados lidos ser�o armazenados.
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
 * Fun��o que imprime os dados de uma matriz 5 x 5.
 * @param matriz Matriz a partir do qual os dados ser�o impressos.
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
 * Fa�a um procedimento que leia os dados de uma matriz 5x5 e um procedimento que a imprima.
 *
 * Exemplo:
 * Entrada: 1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24\n25\n
 * Sa�da: 1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24\n25\n
 */
int main(int argc, char ** argv) {
  
  int matriz[NUMERO_DE_LINHAS][NUMERO_DE_COLUNAS];
  

  // Intera��o com o usu�rio
  printf("Le e imprime matriz 5 x 5.\n");
  
  // Faz a leitura dos dados
  leMatriz(matriz);
  
  // Faz a impress�o
  imprimeMatriz(matriz);

  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}