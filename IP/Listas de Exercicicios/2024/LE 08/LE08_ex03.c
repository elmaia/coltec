/**
 * @file   LE08_ex03.c
 * @brief  Arquivo com a implementa��o de sugest�o de 
 *         solu��o do exerc�cio 03 da LE 08 de 2024.
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

#define DIMENSAO_MAXIMA  (10)

/**
 * Fun��o que l� os dados de uma matriz.
 * @param matriz Matriz onde os dados lidos ser�o armazenados.
 */
void leMatriz(float matriz[][DIMENSAO_MAXIMA], int nLinhas, int nColunas) {
  
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
 * Fun�ao que l� os dados de um vetor.
 * @param tamanho Tamanho do vetor.
 */
void leVetor(float vetor[], int tamanho) {
  
  int i, j;
  
  printf("Entre com os valores reais do vetor:\n");
  for (i = 0; i < tamanho; i++) {
    printf("vetor[%d]: ", i);
    scanf("%f%*c", &vetor[i]);
  }
}

/**
 * Fun��o que imprime um vetor.
 * @param tamanho Tamanho do vetor.
 */
void imprimeVetor(float vetor[], int tamanho) {
  
  int i;
  
  printf("Conteudo do Vetor:\n");
  for (i = 0; i < tamanho; i++) {
    printf("vetor[%d]: ", i);
    PRINTF("%f\n", vetor[i]);
  }  
}

/**
 * Fun��o que multiplica um vetor por uma matriz
 * @param vetor Vetor que ser� multiplicado.
 * @param matriz Matriz que ser� multiplicada.
 * @param dimensao Dimens�o do vetor e da matriz quadrada.
 * @param resultado Vetor onde o resultado ser� armazenado.
 */
float multiplicaVetorMatriz(float vetor[], float matriz[][DIMENSAO_MAXIMA], int dimensao, float resultado[]) {
  
  int i, j;
  
  for (i = 0; i < dimensao; i++) {
    
    // Inicia a linha do resultado com 0
    resultado[i] = 0.0f;
    
    // Faz a multiplica��o e soma no resultado
    for (j = 0; j < dimensao; j++) {
      resultado[i] += vetor[j] * matriz[i][j];
    }
  }
}

/**
 * Fa�a uma fun��o que leia um vetor de tamanho m�ximo N e uma fun��o que leia uma 
 * matriz de dimens�es m�ximas N x N, onde N � definido atrav�s de uma constante. 
 * Fa�a uma fun��o que recebe o vetor e a matriz e produza o resultado da 
 * multiplica��o do vetor pela matriz.
 * Al�m disso fa�a um procedimento que imprime a matriz com o resultado.
 * O usu�rio pode escolher o tamanho do vetor e da matriz desejados, dentro dos limites de N.
 *
 * Multiplica��o de vetor x matriz:
 * https://www.ufrgs.br/reamat/AlgebraLinear/livro/s2-multiplicax00e7x00e3o_de_matriz_por_vetor_e_representax00e7x00e3o_matricial_parasistemas_lineares.html#:~:text=2.3%20Multiplica%C3%A7%C3%A3o%20de%20matriz%20por,dados%20pelas%20entradas%20do%20vetor%20.
 * 

 * Exemplo:
 * Entrada: 3\n1\n2\n3\n1.1\n1.2\n1.3\n2.1\n2.2\n2.3\n3.1\n3.2\n3.3\n
 * Sa�da: 7.4\n13.4\n19.4\n
 * Explica��o: Foi escolhido o tamanho 3, ent�o � um vetor de tr�s n�meros 
 * [1 
 *  2 
 *  3]
 * e uma matriz 3 x 3 com valores 
 * [1.1 1.2 1.3
 *  2.1 2.2 2.3
 *  3.1 3.2 3.3]
 * 
 * cuja multiplica��o produziu
 * 
 * 1*1,1 + 2*1,2 + 3*1,3 = [ 7.4
 * 1*2,1 + 2*2,2 + 3*2,3 =  13.4
 * 1*3,1 + 2*3,2 + 3*3,3 =  19.4]
 */
int main(int argc, char ** argv) {
  
  float vetor[DIMENSAO_MAXIMA];
  float matriz[DIMENSAO_MAXIMA][DIMENSAO_MAXIMA];
  float resultado[DIMENSAO_MAXIMA];
  int dimensao;
  
  // Intera��o com o usu�rio
  printf("Multiplicacao Vetor x Matriz.\n");
  printf("Digite o tamanho do vetor[N] e da matriz[N][N] [1:%d]: ", DIMENSAO_MAXIMA);
  scanf("%d%*c", &dimensao);
  
  // L� os dados do vetor
  leVetor(vetor, dimensao);
  
  // L� os dados da matriz
  leMatriz(matriz, dimensao, dimensao);
  
  // Multiplica o vetor pela matriz
  multiplicaVetorMatriz(vetor, matriz, dimensao, resultado);
  
  // Imprime o resultado
  imprimeVetor(resultado, dimensao);

  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}