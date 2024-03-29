/**
 * @file   Aula11.c
 * @brief  Arquivo com a implementação dos exercícios da Aula 11.
 * @author Leandro Maia Silva
 * @date   2019-08-18
 */

/* Inclusões */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <float.h>
#include "erros.h"

// ------------------------------------------------------------------------------------------------

#define Q1_NUMERO_DE_LINHAS  (5)
#define Q1_NUMERO_DE_COLUNAS (5)

/**
 * Procedimento que imprime a transposta da matriz.
 * @param matriz Matriz a ter sua transposta impressa.
 */
void ex1_imprimeTransposta(float matriz[Q1_NUMERO_DE_LINHAS][Q1_NUMERO_DE_COLUNAS]) {

  int i, j;

  // Percorre a matriz invertendo as linhas com as colunas
  for (i = 0; i < Q1_NUMERO_DE_LINHAS; i++) {
    for (j = 0; j < Q1_NUMERO_DE_COLUNAS; j++) {
      printf("matriz[%d][%d]: %f\n", i, j, matriz[j][i]);
    }
  }
}

/**
 * Exercício 01
 * Faça um programa que leia uma matriz 5x5 e um procedimento
 * que imprima sua transposta.
 */
void exercicio01(void) {

  int i, j;
  float matriz[Q1_NUMERO_DE_LINHAS][Q1_NUMERO_DE_COLUNAS];

  // Workaround para jogar o \n que está no stdin depois do scanf
  getchar();

  // Obtem os valores
  printf("Entre com os valores reais da matriz:\n");
  for (i = 0; i < Q1_NUMERO_DE_LINHAS; i++) {
    for (j = 0; j < Q1_NUMERO_DE_COLUNAS; j++) {
      printf("matriz[%d][%d]: ", i, j);
      scanf("%f", &matriz[i][j]);
    }
  }

  // Imprime a transposta
  ex1_imprimeTransposta(matriz);
}

// ------------------------------------------------------------------------------------------------

#define Q2_NUMERO_DE_LINHAS  (5)
#define Q2_NUMERO_DE_COLUNAS (5)

/**
 * Exercício 02
 * Crie uma função que receba uma matriz de números reais e
 * retorne a soma dos elementos desta matriz.
 */
void exercicio02(void) {

  int i, j;
  float matriz[Q2_NUMERO_DE_LINHAS][Q2_NUMERO_DE_COLUNAS];
  float somaElementos = 0.0f;

  // Workaround para jogar o \n que está no stdin depois do scanf
  getchar();

  // Obtem os valores
  printf("Entre com os valores reais da matriz:\n");
  for (i = 0; i < Q2_NUMERO_DE_LINHAS; i++) {
    for (j = 0; j < Q2_NUMERO_DE_COLUNAS; j++) {
      printf("matriz[%d][%d]: ", i, j);
      scanf("%f", &matriz[i][j]);
    }
  }

  // Percorre toda a matriz somando os elementos
  for (i = 0; i < Q2_NUMERO_DE_LINHAS; i++) {
    for (j = 0; j < Q2_NUMERO_DE_COLUNAS; j++) {
      somaElementos += matriz[i][j];
    }
  }

  // Mostra a soma dos elementos
  printf("A soma de todos os elementos da matriz eh: %f", somaElementos);
}

// ------------------------------------------------------------------------------------------------

#define MATRIZ_LINHAS   (5)
#define MATRIZ_COLUNAS  (5)
#define DIMENSAO_VETOR  (MATRIZ_COLUNAS)

/**
 * Multiplica uma matriz pelo vetor. O vetor deve ter a mesma dimensão
 * do número de colunas da matriz e o resultado o menos número de linhas
 * da matriz.
 * @param matriz Matriz a ser multiplicada pelo vetor.
 * @param vetor Vetora ser multiplicado pela matriz.
 * @param resultado Local onde o resultado da multiplicação da matriz
 * pelo vetor será armazenado.
 */
void ex3_multiplicaMatrizVetor(float matriz[MATRIZ_LINHAS][MATRIZ_COLUNAS],
                               float vetor[DIMENSAO_VETOR],
                               float resultado[MATRIZ_LINHAS]) {

  int i, j;

  for (i = 0; i < MATRIZ_LINHAS; i++) {
    resultado[i] = 0.0f;
    for (j = 0; j < MATRIZ_COLUNAS; j++) {
      resultado[i] += (vetor[j] * matriz[i][j]);
    }
  }

}

/**
 * Exercício 03
 * Faça um programa que leia um vetor de dimensão 5 e uma
 * matriz quadrada de dimensão 5. Crie um procedimento que
 * multiplique o vetor pela matriz. Imprima o resultado.
 */
void exercicio03(void) {

  int i, j;
  float vetor[DIMENSAO_VETOR], resultado[MATRIZ_LINHAS];
  float matriz[MATRIZ_LINHAS][MATRIZ_COLUNAS];
  float somaElementos = 0.0f;

  // Workaround para jogar o \n que está no stdin depois do scanf
  getchar();

  // Obtem os valores
  printf("Entre com os valores reais do vetor:\n");
  for (i = 0; i < DIMENSAO_VETOR; i++) {
    printf("vetor[%d]: ", i);
    scanf("%f", &vetor[i]);
  }

  printf("Entre com os valores reais da matriz:\n");
  for (i = 0; i < MATRIZ_LINHAS; i++) {
    for (j = 0; j < MATRIZ_COLUNAS; j++) {
      printf("matriz[%d][%d]: ", i, j);
      scanf("%f", &matriz[i][j]);
    }
  }

  // Multiplica a matriz pelo vetor
  ex3_multiplicaMatrizVetor(matriz, vetor, resultado);

  // Imprime o resultador
  for (i = 0; i < MATRIZ_LINHAS; i++) {
    printf("resultado[%d]: %f\n", i, resultado[i]);
  }
}

// ------------------------------------------------------------------------------------------------

#define NUMERO_DE_LOJAS    (7)
#define NUMERO_DE_PRODUTOS (5)

/**
 * Exercício 04
 * Faça um programa para ler a quantidade de um total de 5
 * produtos que uma empresa tem em suas 7 lojas e imprimir em uma
 * tabela:
 * a) o total de cada produto nestas lojas
 * b) a loja que tem menos produtos
 */
void exercicio04(void) {

  int i, j, indiceLojaMenosProdutos;
  int matrizLojasProdutos[NUMERO_DE_LOJAS][NUMERO_DE_PRODUTOS];
  int totalProdutoNasLojas, totalProdutosNaLoja;
  int totalLojaMenosProdutos = INT_MAX;

  // Workaround para jogar o \n que está no stdin depois do scanf
  getchar();

  // Obtem os valores
  printf("Entre o numero de produtos por loja:\n");
  for (i = 0; i < NUMERO_DE_LOJAS; i++) {
    for (j = 0; j < NUMERO_DE_PRODUTOS; j++) {
      printf("Loja %d / Produto %d: ", i, j);
      scanf("%d", &matrizLojasProdutos[i][j]);
    }
  }

  // Exibe as informações para o usuário

  // Total de cada produto nestas lojas (SOMA DAS COLUNAS)
  for (i = 0; i < NUMERO_DE_PRODUTOS; i++) {

    // Coleta os dados do produto andando em todas as lojas 
    totalProdutoNasLojas = 0;
    for (j = 0; j < NUMERO_DE_LOJAS; j++) {
      totalProdutoNasLojas += matrizLojasProdutos[j][i];
    }

    printf("Total de produtos <%d> : %d\n", i, totalProdutoNasLojas);
  }

  // A loja que tem menos produtos (SOMA DAS LINHAS)
  for (i = 0; i < NUMERO_DE_LOJAS; i++) {

    // Coleta os dados da loja andando em todos os produtos
    totalProdutosNaLoja = 0;
    for (j = 0; j < NUMERO_DE_PRODUTOS; j++) {
      totalProdutosNaLoja += matrizLojasProdutos[i][j];
    }

    // Verifica se a loja atual tem menos produtos que a menor delas
    if (totalProdutosNaLoja < totalLojaMenosProdutos) {
      totalLojaMenosProdutos = totalProdutosNaLoja;
      indiceLojaMenosProdutos = i;
    }
  }

  printf("A loja %d possui menos produtos com total de %d produtos.\n", 
         indiceLojaMenosProdutos, totalLojaMenosProdutos);
}

// ------------------------------------------------------------------------------------------------

/**
 * Função principal do programa onde o mesmo será iniciado.
 * @param argc Número de parâmetros.
 * @param argv Valores dos parâmetros.
 * @return SUCESSO caso o programa seja executado corretamente, ou caso contrário,
 * o código do erro ocorrido.
 */
int main(int argc, char ** argv) {

  int nExercicio;

  do {
    printf("Digite o numero do exercicio que quer executar [1:4]. 0 para sair: ");
    scanf("%d", &nExercicio);

    switch (nExercicio) {
      case 0: break;
      case 1: {
        exercicio01();
        break;
      }
      case 2: {
        exercicio02();
        break;
      }
      case 3: {
        exercicio03();
        break;
      }
      case 4: {
        exercicio04();
        break;
      }
      default: {
        printf("Voce escolheu um exercicio invalido.\n");
      }
    }

    // Adiciono uma quebra de linha para separar cada execução de exercício
    printf("\n");

  } while (nExercicio != 0);

  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}