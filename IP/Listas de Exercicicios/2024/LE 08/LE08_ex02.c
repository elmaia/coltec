/**
 * @file   LE08_ex02.c
 * @brief  Arquivo com a implementa��o de sugest�o de 
 *         solu��o do exerc�cio 02 da LE 08 de 2024.
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

#define NUMERO_DE_LINHAS_MAXIMA  (10)
#define NUMERO_DE_COLUNAS_MAXIMA (10)

/**
 * Fun��o que l� os dados de uma matriz.
 * @param matriz Matriz onde os dados lidos ser�o armazenados.
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
 * Fun��o que somas os dados da matriz.
 * @param matriz Matriz a partir do qual os dados ser�o somados.
 * @param nLinhas N�mero de linhas da matriz.
 * @param nColunas N�mero de colunas da matriz.
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
 * Crie uma fun��o que receba uma matriz de n�meros reais e retorne a soma dos elementos dessa matriz. 
 * As dimens�es m�ximas dessa matriz devem ser definidas atrav�s de duas constantes, mas o usu�rio pode 
 * escolher as dimens�es desejadas, dentro dos m�ximos.
 *
 * Exemplo:
 * Entrada: 2\n3\n1.0\n1.1\n1.2\n2.0\n2.1\n2.2\n
 * Sa�da: 9.600000
 * Explica��o: O usu�rio determinou que a matriz � 2x3 e colocou na primeira 
 * linha os valores 1.0 1.1 1.2 e na segunda linha 2.0 2.1 2.2
 */
int main(int argc, char ** argv) {
  
  float matriz[NUMERO_DE_LINHAS_MAXIMA][NUMERO_DE_COLUNAS_MAXIMA];
  int nLinhas, nColunas;
  float soma;
  
  // Intera��o com o usu�rio
  printf("Le e soma os elementos de uma matriz.\n");
  printf("Digite o numero de linhas  [1:%d]: ", NUMERO_DE_LINHAS_MAXIMA);
  scanf("%d%*c", &nLinhas);
  printf("Digite o numero de colunas [1:%d]: ", NUMERO_DE_COLUNAS_MAXIMA);
  scanf("%d%*c", &nColunas);
  
  // L� os dados da matriz
  leMatriz(matriz, nLinhas, nColunas);
  
  // Obtem a soma dos elementos
  soma = somaElementosMatriz(matriz, nLinhas, nColunas);
  
  // Imprime o resultado
  printf("A soma de todos os elementos da matriz[%d][%d] eh: ", nLinhas, nColunas);
  PRINTF("%f", soma);

  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}