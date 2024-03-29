/**
 * @file   LE09_2023.c
 * @brief  Arquivo com a implementa��o com uma sugest�o de solu��o da LE09.
 * @author Leandro Maia Silva
 * @date   2023-06-19
 */

/* Inclus�es */
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

/* Constantes */

// Constante que associa o c�digo de erro 0 ao significado de sucesso
#define SUCESSO  0

// ------------------------------------------------------------------------------------------------

/// <summary>
/// Fun��o que aloca dinamicamente um vetor de inteiros de [tamanho] especificado
/// e retorna o endere�o onde foi alocado.
/// </summary>
/// <param name="tamanho">Tamanho do vetor.</param>
/// <returns>Endere�o inicial do vetor.</returns>
int * alocaVetorInteiros(int tamanho) {
  return malloc(tamanho * sizeof(int));
}

/// <summary>
/// Quest�o 01) Fa�a uma fun��o que aloque dinamicamente um vetor de
/// inteiros.Essa fun��o deve receber como par�metro um inteiro
/// representando o tamanho do vetor e retornar um ponteiro com o endere�o
/// inicial do vetor alocado.
/// </summary>
/// <param name=""></param>
void exercicio01(void) {

}

// ------------------------------------------------------------------------------------------------

/// <summary>
/// Fun��o que aloca dinamicamente uma matriz de n�meros de ponto flutuante com
/// dimens�es [nLinhas] x [nColunas] e retorna o endere�o onde foi alocada.
/// </summary>
/// <param name="nLinhas">N�mero de linhas da matriz.</param>
/// <param name="nColunas">N�mero de colunas da matriz.</param>
/// <returns>Endere�o inicial da matriz.</returns>
float** alocaMatrizPontoFlutuante(int nLinhas, int nColunas) {

  int i;
  float** matriz;

  // Verifica o n�mero de linhas e colunas
  if ((nLinhas <= 0) || (nColunas <= 0)) return NULL;

  // Aloca espa�o para as linhas
  matriz = (float**)malloc(nLinhas * sizeof(float*));
  if (matriz == NULL) return NULL;

  // Para cada linha, aloca o espa�o para as colunas
  for (i = 0; i < nLinhas; i++) {
    matriz[i] = (float*)malloc(nColunas * sizeof(float));
  }

  // Retorna o endere�o inicial da matriz
  return matriz;
}

/// <summary>
/// Fun��o que caminha na [matriz] e guarda em suas posi��es os valores
/// digitados pelo usu�rio.
/// </summary>
/// <param name="matriz">Endere�o inicial da matriz.</param>
/// <param name="nLinhas">N�mero de linhas da matriz.</param>
/// <param name="nColunas">N�mero de colunas da matriz.</param>
void leMatrizPontoFlutuante(float** matriz, int nLinhas, int nColunas) {

  int i, j;

  // Percorre todas as posi��es da matriz e guarda os valores digitados
  // pelo usu�rio.
  for (i = 0; i < nLinhas; i++) {
    for (j = 0; j < nColunas; j++) {
      printf("[%2d][%2d] :> ", i, j);
      (void)scanf("%f", &matriz[i][j]);
    }
  }
}

/// <summary>
/// Fa�a uma fun��o que aloque dinamicamente uma matriz de
/// n�meros reais.Essa fun��o dever� receber como par�metro dois n�meros
/// inteiros representando o tamanho da matriz e retornar um ponteiro com o
/// endere�o inicial da matriz.
/// </summary>
/// <param name=""></param>
void exercicio02(void) {

}

// ------------------------------------------------------------------------------------------------

/// <summary>
/// Fun��o que aloca dinamicamente um vetor de ponto flutuante de [tamanho] especificado
/// e retorna o endere�o onde foi alocado.
/// </summary>
/// <param name="tamanho">Tamanho do vetor</param>
/// <returns>Endere�o inicial do vetor.</returns>
float* alocaVetorPontoFlutuante(int tamanho) {
  return malloc(tamanho * sizeof(float));
}

/// <summary>
/// Fun��o que l� os dados de usu�rio e preenche o [vetor].
/// </summary>
/// <param name="vetor">Endere�o inicial do vetor.</param>
/// <param name="tamanho">Tamanho do vetor.</param>
void leVetorPontoFlutuante(float vetor[], int tamanho) {

  int i;

  // L� os dados do vetor
  for (i = 0; i < tamanho; i++) {
    printf(":> ");
    (void)scanf("%f", &vetor[i]);
  }
}

/// <summary>
/// Fun��o que calcula a m�dia aritm�tica dos elementos do [vetor].
/// </summary>
/// <param name="vetor">Endere�o inicial do vetor.</param>
/// <param name="tamanho">Tamanho do vetor.</param>
/// <returns>M�dia aritm�tica.</returns>
float mediaAritmetica(float vetor[], int tamanho) {

  int i;
  float soma = 0;

  // Soma todos os elementos do vetor
  for (i = 0; i < tamanho; i++) {
    soma += vetor[i];
  }

  // Retorna a m�dia
  return soma / tamanho;
}

/// <summary>
/// Fa�a uma fun��o que leia um vetor de um tamanho qualquer.
/// Fa�a uma fun��o que recebe um vetor e calcule e m�dia aritm�tica dos
/// elementos desse vetor.
/// </summary>
/// <param name=""></param>
void exercicio03(void) {

}

// ------------------------------------------------------------------------------------------------

/// <summary>
/// Fun��o que obtem o maior elemento do [vetor].
/// </summary>
/// <param name="vetor"><Endere�o inicial do vetor./param>
/// <param name="tamanho">Tamanho do vetor.</param>
/// <param name="maior">Endere�o do local onde o valor do maior elemento ser� guardado.</param>
/// <returns>Posi��o no [vetor] onde o [maior] valor foi encontrado.</returns>
int obtemMaiorElemento(float vetor[], int tamanho, float* maior) {

  int i;
  float maiorAtual = FLT_MIN;
  int posMaiorAtual = 0;

  // Percorre os elementos do vetor procurando o maior
  for (i = 0; i < tamanho; i++) {

    // Se o maior atual n�o for o maior, troca
    if (maiorAtual < vetor[i]) {

      // Atualiza o maior e salva sua posi��o
      maiorAtual = vetor[i];
      posMaiorAtual = i;
    }
  }

  // Coloca o maior elemento encontrado e retorna sua posi��o
  *maior = maiorAtual;
  return posMaiorAtual;
}

/// <summary>
/// Fa�a uma fun��o que leia um vetor de n�meros reais de
/// tamanho escolhido pelo usu�rio e descubra qual � o maior elemento do
/// vetor, junto com seu �ndice.
/// Essa fun��o deve receber um endere�o onde o maior valor ser� guardado e
/// deve retornar o �ndice onde foi encontrado.
/// Assuma que esse vetor nunca possa estar vazio!
/// </summary>
/// <param name=""></param>
void exercicio04(void) {

  float* vetor;
  int tamanho;
  float maior;
  int indiceMaior;

  // Obtem o tamannho do vetor
  printf("Digite o tamanho do vetor: ");
  (void)scanf("%d", &tamanho);

  // Aloca espa�o para o vetor
  vetor = alocaVetorPontoFlutuante(tamanho);
  if (vetor == NULL) {
    perror("Erro ao alocar espaco na memoria.");
    return;
  }

  // L� os dados do usu�rio
  leVetorPontoFlutuante(vetor, tamanho);

  // Encontra o maior elemento
  indiceMaior = obtemMaiorElemento(vetor, tamanho, &maior);

  // Informa ao usu�rio
  printf("O maior elemento eh <%f> e esta na posicao %d.\n", maior, indiceMaior);
}

// ------------------------------------------------------------------------------------------------

/// <summary>
/// Fun��o que soma todos os elementos da [matriz].
/// </summary>
/// <param name="matriz">Endere�o inicial da matriz.</param>
/// <param name="nLinhas">N�mero de linhas da matriz.</param>
/// <param name="nColunas">N�mero de colunas da matriz.</param>
/// <returns>Soma dos elementos da matriz.</returns>
float somaElementosMatriz(float** matriz, int nLinhas, int nColunas) {

  int i, j;
  float soma = 0;

  // Percorre a matriz inteira somando os elementos
  for (i = 0; i < nLinhas; i++) {
    for (j = 0; j < nColunas; j++) {
      soma += matriz[i][j];
    }
  }

  // Retorna a soma dos elementos
  return soma;
}

/// <summary>
/// Implemente uma fun��o que receba uma matriz de dimens�es
/// quaisquer N x M e retorne a soma dos elementos dessa matriz.Assuma que
/// essa matriz seja alocada dinamicamente.
/// </summary>
/// <param name=""></param>
void questao05(void) {

  float** matriz;
  int nLinhas, nColunas;
  float soma;

  // Obtem as dimens�es da matriz
  printf("Digite as dimensoes da matriz [nLinhas nColunas]: ");
  (void)scanf("%d %d", &nLinhas, &nColunas);

  // Aloca espa�o para a matriz
  matriz = alocaMatrizPontoFlutuante(nLinhas, nColunas);

  // L� os elementos da matriz.
  leMatrizPontoFlutuante(matriz, nLinhas, nColunas);

  // Obtem a soma dos elementos da matriz
  soma = somaElementosMatriz(matriz, nLinhas, nColunas);

  // Mostra o resultado da soma
  printf("A soma dos elementos da matriz tem valor %f.\n", soma);
}

// ------------------------------------------------------------------------------------------------

/// <summary>
/// Fun��o que aloca dinamicamente uma matriz de n�meros de inteiros com
/// dimens�es [nLinhas] x [nColunas] e retorna o endere�o onde foi alocada.
/// </summary>
/// <param name="nLinhas">N�mero de linhas da matriz.</param>
/// <param name="nColunas">N�mero de colunas da matriz.</param>
/// <returns>Endere�o inicial da matriz.</returns>
int** alocaMatrizInteiros(int nLinhas, int nColunas) {

  int i;
  int** matriz;

  // Verifica o n�mero de linhas e colunas
  if ((nLinhas <= 0) || (nColunas <= 0)) return NULL;

  // Aloca espa�o para as linhas
  matriz = (int**)malloc(nLinhas * sizeof(int*));
  if (matriz == NULL) return NULL;

  // Para cada linha, aloca o espa�o para as colunas
  for (i = 0; i < nLinhas; i++) {
    matriz[i] = (int*)malloc(nColunas * sizeof(int));
  }

  // Retorna o endere�o inicial da matriz
  return matriz;
}

/// <summary>
/// Fun��o que caminha na [matriz] e guarda em suas posi��es os valores
/// digitados pelo usu�rio.
/// </summary>
/// <param name="matriz">Endere�o inicial da matriz.</param>
/// <param name="nLinhas">N�mero de linhas da matriz.</param>
/// <param name="nColunas">N�mero de colunas da matriz.</param>
void leMatrizInteiros(int** matriz, int nLinhas, int nColunas) {

  int i, j;

  // Percorre todas as posi��es da matriz e guarda os valores digitados
  // pelo usu�rio.
  for (i = 0; i < nLinhas; i++) {
    for (j = 0; j < nColunas; j++) {
      printf("[%2d][%2d] :> ", i, j);
      (void)scanf("%d", &matriz[i][j]);
    }
  }
}

/// <summary>
/// Fa�a um programa que leia a quantidade de um total de X
/// produtos que uma empresa tem em suas Y lojas e imprimir em formato de
/// tabela :
/// � O total de cada produto nessas lojas
/// � A loja que tem menos produtos.
/// </summary>
/// <param name=""></param>
void questao06(void) {

  int nLojas, nProdutos;
  int** matrizLojasProdutos;

  // Obtem o n�mero de lojas e n�mero de produtos
  printf("Numero de lojas: ");
  (void)scanf("%d", &nLojas);
  printf("Numero de produtos: ");
  (void)scanf("%d", &nProdutos);

  // Aloca espa�o para a matriz [nLojas] x [nProdutos];
  matrizLojasProdutos = alocaMatrizInteiros(nLojas, nProdutos);

  // Obtem os valores
  printf("Digite a quantidade de produtos por loja.\n");
  printf("Linha : Loja / Coluna : Produto\n");
  leMatrizInteiros(matrizLojasProdutos, nLojas, nProdutos);
}