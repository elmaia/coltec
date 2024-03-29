/**
 * @file   LE09_2023.c
 * @brief  Arquivo com a implementação com uma sugestão de solução da LE09.
 * @author Leandro Maia Silva
 * @date   2023-06-19
 */

/* Inclusões */
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

/* Constantes */

// Constante que associa o código de erro 0 ao significado de sucesso
#define SUCESSO  0

// ------------------------------------------------------------------------------------------------

/// <summary>
/// Função que aloca dinamicamente um vetor de inteiros de [tamanho] especificado
/// e retorna o endereço onde foi alocado.
/// </summary>
/// <param name="tamanho">Tamanho do vetor.</param>
/// <returns>Endereço inicial do vetor.</returns>
int * alocaVetorInteiros(int tamanho) {
  return malloc(tamanho * sizeof(int));
}

/// <summary>
/// Questão 01) Faça uma função que aloque dinamicamente um vetor de
/// inteiros.Essa função deve receber como parâmetro um inteiro
/// representando o tamanho do vetor e retornar um ponteiro com o endereço
/// inicial do vetor alocado.
/// </summary>
/// <param name=""></param>
void exercicio01(void) {

}

// ------------------------------------------------------------------------------------------------

/// <summary>
/// Função que aloca dinamicamente uma matriz de números de ponto flutuante com
/// dimensões [nLinhas] x [nColunas] e retorna o endereço onde foi alocada.
/// </summary>
/// <param name="nLinhas">Número de linhas da matriz.</param>
/// <param name="nColunas">Número de colunas da matriz.</param>
/// <returns>Endereço inicial da matriz.</returns>
float** alocaMatrizPontoFlutuante(int nLinhas, int nColunas) {

  int i;
  float** matriz;

  // Verifica o número de linhas e colunas
  if ((nLinhas <= 0) || (nColunas <= 0)) return NULL;

  // Aloca espaço para as linhas
  matriz = (float**)malloc(nLinhas * sizeof(float*));
  if (matriz == NULL) return NULL;

  // Para cada linha, aloca o espaço para as colunas
  for (i = 0; i < nLinhas; i++) {
    matriz[i] = (float*)malloc(nColunas * sizeof(float));
  }

  // Retorna o endereço inicial da matriz
  return matriz;
}

/// <summary>
/// Função que caminha na [matriz] e guarda em suas posições os valores
/// digitados pelo usuário.
/// </summary>
/// <param name="matriz">Endereço inicial da matriz.</param>
/// <param name="nLinhas">Número de linhas da matriz.</param>
/// <param name="nColunas">Número de colunas da matriz.</param>
void leMatrizPontoFlutuante(float** matriz, int nLinhas, int nColunas) {

  int i, j;

  // Percorre todas as posições da matriz e guarda os valores digitados
  // pelo usuário.
  for (i = 0; i < nLinhas; i++) {
    for (j = 0; j < nColunas; j++) {
      printf("[%2d][%2d] :> ", i, j);
      (void)scanf("%f", &matriz[i][j]);
    }
  }
}

/// <summary>
/// Faça uma função que aloque dinamicamente uma matriz de
/// números reais.Essa função deverá receber como parâmetro dois números
/// inteiros representando o tamanho da matriz e retornar um ponteiro com o
/// endereço inicial da matriz.
/// </summary>
/// <param name=""></param>
void exercicio02(void) {

}

// ------------------------------------------------------------------------------------------------

/// <summary>
/// Função que aloca dinamicamente um vetor de ponto flutuante de [tamanho] especificado
/// e retorna o endereço onde foi alocado.
/// </summary>
/// <param name="tamanho">Tamanho do vetor</param>
/// <returns>Endereço inicial do vetor.</returns>
float* alocaVetorPontoFlutuante(int tamanho) {
  return malloc(tamanho * sizeof(float));
}

/// <summary>
/// Função que lê os dados de usuário e preenche o [vetor].
/// </summary>
/// <param name="vetor">Endereço inicial do vetor.</param>
/// <param name="tamanho">Tamanho do vetor.</param>
void leVetorPontoFlutuante(float vetor[], int tamanho) {

  int i;

  // Lê os dados do vetor
  for (i = 0; i < tamanho; i++) {
    printf(":> ");
    (void)scanf("%f", &vetor[i]);
  }
}

/// <summary>
/// Função que calcula a média aritmética dos elementos do [vetor].
/// </summary>
/// <param name="vetor">Endereço inicial do vetor.</param>
/// <param name="tamanho">Tamanho do vetor.</param>
/// <returns>Média aritmética.</returns>
float mediaAritmetica(float vetor[], int tamanho) {

  int i;
  float soma = 0;

  // Soma todos os elementos do vetor
  for (i = 0; i < tamanho; i++) {
    soma += vetor[i];
  }

  // Retorna a média
  return soma / tamanho;
}

/// <summary>
/// Faça uma função que leia um vetor de um tamanho qualquer.
/// Faça uma função que recebe um vetor e calcule e média aritmética dos
/// elementos desse vetor.
/// </summary>
/// <param name=""></param>
void exercicio03(void) {

}

// ------------------------------------------------------------------------------------------------

/// <summary>
/// Função que obtem o maior elemento do [vetor].
/// </summary>
/// <param name="vetor"><Endereço inicial do vetor./param>
/// <param name="tamanho">Tamanho do vetor.</param>
/// <param name="maior">Endereço do local onde o valor do maior elemento será guardado.</param>
/// <returns>Posição no [vetor] onde o [maior] valor foi encontrado.</returns>
int obtemMaiorElemento(float vetor[], int tamanho, float* maior) {

  int i;
  float maiorAtual = FLT_MIN;
  int posMaiorAtual = 0;

  // Percorre os elementos do vetor procurando o maior
  for (i = 0; i < tamanho; i++) {

    // Se o maior atual não for o maior, troca
    if (maiorAtual < vetor[i]) {

      // Atualiza o maior e salva sua posição
      maiorAtual = vetor[i];
      posMaiorAtual = i;
    }
  }

  // Coloca o maior elemento encontrado e retorna sua posição
  *maior = maiorAtual;
  return posMaiorAtual;
}

/// <summary>
/// Faça uma função que leia um vetor de números reais de
/// tamanho escolhido pelo usuário e descubra qual é o maior elemento do
/// vetor, junto com seu índice.
/// Essa função deve receber um endereço onde o maior valor será guardado e
/// deve retornar o índice onde foi encontrado.
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

  // Aloca espaço para o vetor
  vetor = alocaVetorPontoFlutuante(tamanho);
  if (vetor == NULL) {
    perror("Erro ao alocar espaco na memoria.");
    return;
  }

  // Lê os dados do usuário
  leVetorPontoFlutuante(vetor, tamanho);

  // Encontra o maior elemento
  indiceMaior = obtemMaiorElemento(vetor, tamanho, &maior);

  // Informa ao usuário
  printf("O maior elemento eh <%f> e esta na posicao %d.\n", maior, indiceMaior);
}

// ------------------------------------------------------------------------------------------------

/// <summary>
/// Função que soma todos os elementos da [matriz].
/// </summary>
/// <param name="matriz">Endereço inicial da matriz.</param>
/// <param name="nLinhas">Número de linhas da matriz.</param>
/// <param name="nColunas">Número de colunas da matriz.</param>
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
/// Implemente uma função que receba uma matriz de dimensões
/// quaisquer N x M e retorne a soma dos elementos dessa matriz.Assuma que
/// essa matriz seja alocada dinamicamente.
/// </summary>
/// <param name=""></param>
void questao05(void) {

  float** matriz;
  int nLinhas, nColunas;
  float soma;

  // Obtem as dimensões da matriz
  printf("Digite as dimensoes da matriz [nLinhas nColunas]: ");
  (void)scanf("%d %d", &nLinhas, &nColunas);

  // Aloca espaço para a matriz
  matriz = alocaMatrizPontoFlutuante(nLinhas, nColunas);

  // Lê os elementos da matriz.
  leMatrizPontoFlutuante(matriz, nLinhas, nColunas);

  // Obtem a soma dos elementos da matriz
  soma = somaElementosMatriz(matriz, nLinhas, nColunas);

  // Mostra o resultado da soma
  printf("A soma dos elementos da matriz tem valor %f.\n", soma);
}

// ------------------------------------------------------------------------------------------------

/// <summary>
/// Função que aloca dinamicamente uma matriz de números de inteiros com
/// dimensões [nLinhas] x [nColunas] e retorna o endereço onde foi alocada.
/// </summary>
/// <param name="nLinhas">Número de linhas da matriz.</param>
/// <param name="nColunas">Número de colunas da matriz.</param>
/// <returns>Endereço inicial da matriz.</returns>
int** alocaMatrizInteiros(int nLinhas, int nColunas) {

  int i;
  int** matriz;

  // Verifica o número de linhas e colunas
  if ((nLinhas <= 0) || (nColunas <= 0)) return NULL;

  // Aloca espaço para as linhas
  matriz = (int**)malloc(nLinhas * sizeof(int*));
  if (matriz == NULL) return NULL;

  // Para cada linha, aloca o espaço para as colunas
  for (i = 0; i < nLinhas; i++) {
    matriz[i] = (int*)malloc(nColunas * sizeof(int));
  }

  // Retorna o endereço inicial da matriz
  return matriz;
}

/// <summary>
/// Função que caminha na [matriz] e guarda em suas posições os valores
/// digitados pelo usuário.
/// </summary>
/// <param name="matriz">Endereço inicial da matriz.</param>
/// <param name="nLinhas">Número de linhas da matriz.</param>
/// <param name="nColunas">Número de colunas da matriz.</param>
void leMatrizInteiros(int** matriz, int nLinhas, int nColunas) {

  int i, j;

  // Percorre todas as posições da matriz e guarda os valores digitados
  // pelo usuário.
  for (i = 0; i < nLinhas; i++) {
    for (j = 0; j < nColunas; j++) {
      printf("[%2d][%2d] :> ", i, j);
      (void)scanf("%d", &matriz[i][j]);
    }
  }
}

/// <summary>
/// Faça um programa que leia a quantidade de um total de X
/// produtos que uma empresa tem em suas Y lojas e imprimir em formato de
/// tabela :
/// • O total de cada produto nessas lojas
/// • A loja que tem menos produtos.
/// </summary>
/// <param name=""></param>
void questao06(void) {

  int nLojas, nProdutos;
  int** matrizLojasProdutos;

  // Obtem o número de lojas e número de produtos
  printf("Numero de lojas: ");
  (void)scanf("%d", &nLojas);
  printf("Numero de produtos: ");
  (void)scanf("%d", &nProdutos);

  // Aloca espaço para a matriz [nLojas] x [nProdutos];
  matrizLojasProdutos = alocaMatrizInteiros(nLojas, nProdutos);

  // Obtem os valores
  printf("Digite a quantidade de produtos por loja.\n");
  printf("Linha : Loja / Coluna : Produto\n");
  leMatrizInteiros(matrizLojasProdutos, nLojas, nProdutos);
}