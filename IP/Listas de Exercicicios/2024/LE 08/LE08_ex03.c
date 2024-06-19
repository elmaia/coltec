/**
 * @file   LE08_ex03.c
 * @brief  Arquivo com a implementação de sugestão de 
 *         solução do exercício 03 da LE 08 de 2024.
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

#define DIMENSAO_MAXIMA  (10)

/**
 * Função que lê os dados de uma matriz.
 * @param matriz Matriz onde os dados lidos serão armazenados.
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
 * Funçao que lê os dados de um vetor.
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
 * Função que imprime um vetor.
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
 * Função que multiplica um vetor por uma matriz
 * @param vetor Vetor que será multiplicado.
 * @param matriz Matriz que será multiplicada.
 * @param dimensao Dimensão do vetor e da matriz quadrada.
 * @param resultado Vetor onde o resultado será armazenado.
 */
float multiplicaVetorMatriz(float vetor[], float matriz[][DIMENSAO_MAXIMA], int dimensao, float resultado[]) {
  
  int i, j;
  
  for (i = 0; i < dimensao; i++) {
    
    // Inicia a linha do resultado com 0
    resultado[i] = 0.0f;
    
    // Faz a multiplicação e soma no resultado
    for (j = 0; j < dimensao; j++) {
      resultado[i] += vetor[j] * matriz[i][j];
    }
  }
}

/**
 * Faça uma função que leia um vetor de tamanho máximo N e uma função que leia uma 
 * matriz de dimensões máximas N x N, onde N é definido através de uma constante. 
 * Faça uma função que recebe o vetor e a matriz e produza o resultado da 
 * multiplicação do vetor pela matriz.
 * Além disso faça um procedimento que imprime a matriz com o resultado.
 * O usuário pode escolher o tamanho do vetor e da matriz desejados, dentro dos limites de N.
 *
 * Multiplicação de vetor x matriz:
 * https://www.ufrgs.br/reamat/AlgebraLinear/livro/s2-multiplicax00e7x00e3o_de_matriz_por_vetor_e_representax00e7x00e3o_matricial_parasistemas_lineares.html#:~:text=2.3%20Multiplica%C3%A7%C3%A3o%20de%20matriz%20por,dados%20pelas%20entradas%20do%20vetor%20.
 * 

 * Exemplo:
 * Entrada: 3\n1\n2\n3\n1.1\n1.2\n1.3\n2.1\n2.2\n2.3\n3.1\n3.2\n3.3\n
 * Saída: 7.4\n13.4\n19.4\n
 * Explicação: Foi escolhido o tamanho 3, então é um vetor de três números 
 * [1 
 *  2 
 *  3]
 * e uma matriz 3 x 3 com valores 
 * [1.1 1.2 1.3
 *  2.1 2.2 2.3
 *  3.1 3.2 3.3]
 * 
 * cuja multiplicação produziu
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
  
  // Interação com o usuário
  printf("Multiplicacao Vetor x Matriz.\n");
  printf("Digite o tamanho do vetor[N] e da matriz[N][N] [1:%d]: ", DIMENSAO_MAXIMA);
  scanf("%d%*c", &dimensao);
  
  // Lê os dados do vetor
  leVetor(vetor, dimensao);
  
  // Lê os dados da matriz
  leMatriz(matriz, dimensao, dimensao);
  
  // Multiplica o vetor pela matriz
  multiplicaVetorMatriz(vetor, matriz, dimensao, resultado);
  
  // Imprime o resultado
  imprimeVetor(resultado, dimensao);

  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}