/**
 * @file   Aula12.c
 * @brief  Arquivo com a implementação dos exercícios da Aula 12.
 * @author Leandro Maia Silva
 * @date   2019-08-16
 */

/* Inclusões */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <float.h>
#include "erros.h"

/* Tipos */
typedef uint8_t bool_t;

/* Constantes */
#define VERDADEIRO              (1 == 1)
#define FALSO                   (!VERDADEIRO)
#define TAMANHO_MAXIMO_STRING   (100 + 1)

// ------------------------------------------------------------------------------------------------

/**
* Exercício 01
* Implemente uma função que aloque dinamicamente um vetor
* de inteiros. Essa função deverá receber como parâmetro um
* inteiro representando o tamanho do vetor, e retornar um
* ponteiro representando o vetor alocado.
*/
int * alocaVetorInteiros(int nElementos) {
  return (int *)malloc(sizeof(int) * nElementos);
}

// ------------------------------------------------------------------------------------------------

/**
 * Exercício 02
 * Implemente uma função que aloque dinamicamente uma
 * matriz de números reais. Essa função deverá receber como
 * parâmetro dois inteiros representando o tamanho da matriz, e
 * retornar um ponteiro de ponteiros representando a matriz
 * alocada.
 */
float ** alocaMatrizReal(int nLinhas, int nColunas) {

  float ** matriz;
  int i;

  // Aloca espaço para as linhas (ponteiros para as colunas)
  matriz = (float **)malloc(sizeof(float *) * nLinhas);

  // Aloca espaço para as colunas (posições onde os valores vão propriamente ditos)
  for (i = 0; i < nLinhas; i++) {
    // Para cada linha, aloca espaço para as colunas
    matriz[i] = (float *)malloc(sizeof(float) * nColunas);
  }

  // Retorna o ponteiro para a matriz alocada dentro da função
  return matriz;
}

// ------------------------------------------------------------------------------------------------

/**
 * Exercício 03
 * Faça um programa que leia um vetor de um tamanho
 * escolhido pelo usuário e calcule a média aritmética de seus
 * valores.
 */
void exercicio03(void) {

  int i, nElementos;
  int * valores;
  float totalValores = 0.0f, mediaAritmetica = 0.0f;

  // Workaround para jogar o \n que está no stdin depois do scanf
  getchar();

  // Lê o texto do usuário
  printf("Digite o quantidade de valores que serao digitados: ");
  scanf("%d", &nElementos);

  // Aloca espaço para os valores
  valores = alocaVetorInteiros(nElementos);

  // Lê os números do usuário
  for (i = 0; i < nElementos; i++) {
    printf("Digite o inteiro a ser armazenado em valores[%d]: ", i);
    scanf("%d", &valores[i]);
  }

  // Calcula a média aritmética
  for (i = 0; i < nElementos; i++) {
    totalValores += valores[i];
  }
  mediaAritmetica = totalValores / nElementos;

  // Imprime a média aritmética
  printf("A media aritmetica dos %d numeros eh: %1.2f\n", nElementos, mediaAritmetica);

  // Libera o espaço alocado
  free(valores);
}

// ------------------------------------------------------------------------------------------------

/**
 * Exercício 04
 * Faça um programa que leia um vetor de números reais de
 * tamanho escolhido pelo usuário e descubra qual é o aior e
 * menor valor existente no vetor, junto de seu índice.
 * As contantes que utilizei estão em float.h
 * link: https://docs.microsoft.com/en-us/cpp/cpp/floating-limits?view=vs-2015
 */
void exercicio04(void) {

  int i, nElementos;
  float * valores;
  int indiceMenor, indiceMaior;
  float menorValor = FLT_MAX, maiorValor = FLT_MIN;

  // Workaround para jogar o \n que está no stdin depois do scanf
  getchar();

  // Lê o texto do usuário
  printf("Digite o quantidade de valores que serao digitados: ");
  scanf("%d", &nElementos);

  // Aloca espaço para os valores
  valores = (float *)malloc(sizeof(float) * nElementos);

  // Lê os números do usuário
  for (i = 0; i < nElementos; i++) {
    printf("Digite o numero real a ser armazenado em valores[%d]: ", i);
    scanf("%f", &valores[i]);
  }

  // Procura o menor e o maior valor
  for (i = 0; i < nElementos; i++) {

    // Testa pra ver se é menor
    if (valores[i] < menorValor) {
      // Salvo o menor valor e também o índice onde achou o menor valor
      menorValor = valores[i];
      indiceMenor = i;
    }

    // Testa pra ver se é maior
    if (valores[i] > maiorValor) {
      // Salvo o maior valor e também o índice onde achou o maior valor
      maiorValor = valores[i];
      indiceMaior = i;
    }
  }

  // Imprime o maior e o menor número, além de seus índices
  printf("O menor valor eh valores[%d] = %f\n", indiceMenor, menorValor);
  printf("O maior valor eh valores[%d] = %f\n", indiceMaior, maiorValor);

  // Libera o espaço alocado
  free(valores);
}

// ------------------------------------------------------------------------------------------------

/**
 * Exercício 05
 * Implemente um programa que receba uma matriz de números
 * reais e retorne a soma dos elementos desta matriz. A matriz
 * deverá ser alocada dinamicamente.
 */
void exercicio05(void) {

  int i, j, nLinhas, nColunas;
  float ** matriz, somaElementos = 0.0f;

  // Workaround para jogar o \n que está no stdin depois do scanf
  getchar();

  // Obtem as informações da matriz
  printf("Digite as dimensoes da matriz (nLinhas nColunas). Ex.: 2 5: ");
  scanf("%d %d", &nLinhas, &nColunas);

  // Aloca espaço para a matriz
  matriz = alocaMatrizReal(nLinhas, nColunas);

  // Obtem os valores
  printf("Entre com os valores reais da matriz:\n");
  for (i = 0; i < nLinhas; i++) {
    for (j = 0; j < nColunas; j++) {
      printf("matriz[%d][%d]: ", i, j);
      scanf("%f", &matriz[i][j]);
    }
  }

  // Percorre toda a matriz somando os elementos
  for (i = 0; i < nLinhas; i++) {
    for (j = 0; j < nColunas; j++) {
      somaElementos += matriz[i][j];
    }
  }

  // Mostra a soma dos elementos
  printf("A soma de todos os elementos da matriz eh: %f", somaElementos);

  // Libera a memória alocada para a matriz
  for (i = 0; i < nLinhas; i++) {
    free(matriz[i]);
  }
  free(matriz);
}

// ------------------------------------------------------------------------------------------------

/**
 * Exercício 06
 * Faça um programa para ler a quantidade de um total de X
 * produtos que uma empresa tem em suas Y lojas e imprimir em
 * uma tabela:
 * - 1 o total de cada produto nestas lojas
 * - 2 a loja que tem menos produtos
 */
void exercicio06(void) {

  int i, j, nLojas, nProdutos, indiceLojaMenosProdutos;
  int ** matrizLojasProdutos;
  int totalProdutoNasLojas, totalProdutosNaLoja;
  int totalLojaMenosProdutos = INT_MAX;

  // Workaround para jogar o \n que está no stdin depois do scanf
  getchar();

  // Obtem as informações do usuário
  printf("Digite o numero de lojas: ");
  scanf("%d", &nLojas);
  printf("Digite o numero de produtos: ");
  scanf("%d", &nProdutos);

  // Aloca espaço para os valores
  matrizLojasProdutos = (int **)malloc(sizeof(int *) * nLojas);
  for (i = 0; i < nLojas; i++) {
    matrizLojasProdutos[i] = (int *)malloc(sizeof(int) * nProdutos);
  }

  // Obtem os valores
  printf("Entre o numero de produtos por loja:\n");
  for (i = 0; i < nLojas; i++) {
    for (j = 0; j < nProdutos; j++) {
      printf("Loja %d / Produto %d: ", i, j);
      scanf("%d", &matrizLojasProdutos[i][j]);
    }
  }

  // Exibe as informações para o usuário

  // Total de cada produto nestas lojas (SOMA DAS COLUNAS)
  for (i = 0; i < nProdutos; i++) {

    // Coleta os dados do produto andando em todas as lojas 
    totalProdutoNasLojas = 0;
    for (j = 0; j < nLojas; j++) {
      totalProdutoNasLojas += matrizLojasProdutos[j][i];
    }

    printf("Total de produtos <%d> : %d\n", i, totalProdutoNasLojas);
  }

  // A loja que tem menos produtos (SOMA DAS LINHAS)
  for (i = 0; i < nLojas; i++) {

    // Coleta os dados da loja andando em todos os produtos
    totalProdutosNaLoja = 0;
    for (j = 0; j < nProdutos; j++) {
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

  // Libera a memória alocada para a matriz
  for (i = 0; i < nLojas; i++) {
    free(matrizLojasProdutos[i]);
  }
  free(matrizLojasProdutos);
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
    printf("Digite o numero do exercicio que quer executar [3:6]. 0 para sair: ");
    scanf("%d", &nExercicio);

    switch (nExercicio) {
      case 0: break;
      case 3: {
        exercicio03();
        break;
      }
      case 4: {
        exercicio04();
        break;
      }
      case 5: {
        exercicio05();
        break;
      }
      case 6: {
        exercicio06();
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