/**
 * @file   LE08_ex02.c
 * @brief  Arquivo com a implementação de sugestão de 
 *         solução do exercício 02 da LE 08 de 2024.
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

#define NUMERO_DE_LINHAS_MAXIMA  (10)
#define NUMERO_DE_COLUNAS_MAXIMA (10)

/**
 * Função que lê os dados de uma matriz.
 * @param matriz Matriz onde os dados lidos serão armazenados.
 */
void leMatriz(float matriz[NUMERO_DE_LINHAS_MAXIMA][NUMERO_DE_COLUNAS_MAXIMA], int nLinhas, int nColunas) {
  
  int i, j;
  
  printf("Entre com os valores reais da matriz:\n");
  for (i = 0; i < nLinhas; i++) {
    for (j = 0; j < nColunas; j++) {
      printf("matriz[%d][%d]: ", i, j);
      scanf("%f%*c", &matriz[i][j]);
    }
  }  
}

/**
 * Função que somas os dados da matriz.
 * @param matriz Matriz a partir do qual os dados serão somados.
 * @param nLinhas Número de linhas da matriz.
 * @param nColunas Número de colunas da matriz.
 * @return Soma de todos os elementos da matriz.
 */
float somaElementosMatriz(float matriz[NUMERO_DE_LINHAS_MAXIMA][NUMERO_DE_COLUNAS_MAXIMA], int nLinhas, int nColunas) {
  
  int i, j;
  float soma = 0.0f;
  
  for (i = 0; i < nLinhas; i++) {
    for (j = 0; j < nColunas; j++) {
      soma += matriz[i][j];
    }
  }
  
  // Retorna a soma
  return soma;
}

/**
 * Crie uma função que receba uma matriz de números reais e retorne a soma dos elementos dessa matriz. 
 * As dimensões máximas dessa matriz devem ser definidas através de duas constantes, mas o usuário pode 
 * escolher as dimensões desejadas, dentro dos máximos.
 *
 * Exemplo:
 * Entrada: 2\n3\n1.0\n1.1\n1.2\n2.0\n2.1\n2.2\n
 * Saída: 9.600000
 * Explicação: O usuário determinou que a matriz é 2x3 e colocou na primeira 
 * linha os valores 1.0 1.1 1.2 e na segunda linha 2.0 2.1 2.2
 */
int main(int argc, char ** argv) {
  
  float matriz[NUMERO_DE_LINHAS_MAXIMA][NUMERO_DE_COLUNAS_MAXIMA];
  int nLinhas, nColunas;
  float soma;
  
  // Interação com o usuário
  printf("Le e soma os elementos de uma matriz.\n");
  printf("Digite o numero de linhas  [1:%d]: ", NUMERO_DE_LINHAS_MAXIMA);
  scanf("%d%*c", &nLinhas);
  printf("Digite o numero de colunas [1:%d]: ", NUMERO_DE_COLUNAS_MAXIMA);
  scanf("%d%*c", &nColunas);
  
  // Lê os dados da matriz
  leMatriz(matriz, nLinhas, nColunas);
  
  // Obtem a soma dos elementos
  soma = somaElementosMatriz(matriz, nLinhas, nColunas);
  
  // Imprime o resultado
  printf("A soma de todos os elementos da matriz[%d][%d] eh: ", nLinhas, nColunas);
  PRINTF("%f", soma);

  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}