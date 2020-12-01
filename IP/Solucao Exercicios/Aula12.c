/**
 * @file   Aula12.c
 * @brief  Arquivo com a implementa��o dos exerc�cios da Aula 12.
 * @author Leandro Maia Silva
 * @date   2019-08-16
 */

/* Inclus�es */
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
* Exerc�cio 01
* Implemente uma fun��o que aloque dinamicamente um vetor
* de inteiros. Essa fun��o dever� receber como par�metro um
* inteiro representando o tamanho do vetor, e retornar um
* ponteiro representando o vetor alocado.
*/
int * alocaVetorInteiros(int nElementos) {
  return (int *)malloc(sizeof(int) * nElementos);
}

// ------------------------------------------------------------------------------------------------

/**
 * Exerc�cio 02
 * Implemente uma fun��o que aloque dinamicamente uma
 * matriz de n�meros reais. Essa fun��o dever� receber como
 * par�metro dois inteiros representando o tamanho da matriz, e
 * retornar um ponteiro de ponteiros representando a matriz
 * alocada.
 */
float ** alocaMatrizReal(int nLinhas, int nColunas) {

  float ** matriz;
  int i;

  // Aloca espa�o para as linhas (ponteiros para as colunas)
  matriz = (float **)malloc(sizeof(float *) * nLinhas);

  // Aloca espa�o para as colunas (posi��es onde os valores v�o propriamente ditos)
  for (i = 0; i < nLinhas; i++) {
    // Para cada linha, aloca espa�o para as colunas
    matriz[i] = (float *)malloc(sizeof(float) * nColunas);
  }

  // Retorna o ponteiro para a matriz alocada dentro da fun��o
  return matriz;
}

// ------------------------------------------------------------------------------------------------

/**
 * Exerc�cio 03
 * Fa�a um programa que leia um vetor de um tamanho
 * escolhido pelo usu�rio e calcule a m�dia aritm�tica de seus
 * valores.
 */
void exercicio03(void) {

  int i, nElementos;
  int * valores;
  float totalValores = 0.0f, mediaAritmetica = 0.0f;

  // Workaround para jogar o \n que est� no stdin depois do scanf
  getchar();

  // L� o texto do usu�rio
  printf("Digite o quantidade de valores que serao digitados: ");
  scanf("%d", &nElementos);

  // Aloca espa�o para os valores
  valores = alocaVetorInteiros(nElementos);

  // L� os n�meros do usu�rio
  for (i = 0; i < nElementos; i++) {
    printf("Digite o inteiro a ser armazenado em valores[%d]: ", i);
    scanf("%d", &valores[i]);
  }

  // Calcula a m�dia aritm�tica
  for (i = 0; i < nElementos; i++) {
    totalValores += valores[i];
  }
  mediaAritmetica = totalValores / nElementos;

  // Imprime a m�dia aritm�tica
  printf("A media aritmetica dos %d numeros eh: %1.2f\n", nElementos, mediaAritmetica);

  // Libera o espa�o alocado
  free(valores);
}

// ------------------------------------------------------------------------------------------------

/**
 * Exerc�cio 04
 * Fa�a um programa que leia um vetor de n�meros reais de
 * tamanho escolhido pelo usu�rio e descubra qual � o aior e
 * menor valor existente no vetor, junto de seu �ndice.
 * As contantes que utilizei est�o em float.h
 * link: https://docs.microsoft.com/en-us/cpp/cpp/floating-limits?view=vs-2015
 */
void exercicio04(void) {

  int i, nElementos;
  float * valores;
  int indiceMenor, indiceMaior;
  float menorValor = FLT_MAX, maiorValor = FLT_MIN;

  // Workaround para jogar o \n que est� no stdin depois do scanf
  getchar();

  // L� o texto do usu�rio
  printf("Digite o quantidade de valores que serao digitados: ");
  scanf("%d", &nElementos);

  // Aloca espa�o para os valores
  valores = (float *)malloc(sizeof(float) * nElementos);

  // L� os n�meros do usu�rio
  for (i = 0; i < nElementos; i++) {
    printf("Digite o numero real a ser armazenado em valores[%d]: ", i);
    scanf("%f", &valores[i]);
  }

  // Procura o menor e o maior valor
  for (i = 0; i < nElementos; i++) {

    // Testa pra ver se � menor
    if (valores[i] < menorValor) {
      // Salvo o menor valor e tamb�m o �ndice onde achou o menor valor
      menorValor = valores[i];
      indiceMenor = i;
    }

    // Testa pra ver se � maior
    if (valores[i] > maiorValor) {
      // Salvo o maior valor e tamb�m o �ndice onde achou o maior valor
      maiorValor = valores[i];
      indiceMaior = i;
    }
  }

  // Imprime o maior e o menor n�mero, al�m de seus �ndices
  printf("O menor valor eh valores[%d] = %f\n", indiceMenor, menorValor);
  printf("O maior valor eh valores[%d] = %f\n", indiceMaior, maiorValor);

  // Libera o espa�o alocado
  free(valores);
}

// ------------------------------------------------------------------------------------------------

/**
 * Exerc�cio 05
 * Implemente um programa que receba uma matriz de n�meros
 * reais e retorne a soma dos elementos desta matriz. A matriz
 * dever� ser alocada dinamicamente.
 */
void exercicio05(void) {

  int i, j, nLinhas, nColunas;
  float ** matriz, somaElementos = 0.0f;

  // Workaround para jogar o \n que est� no stdin depois do scanf
  getchar();

  // Obtem as informa��es da matriz
  printf("Digite as dimensoes da matriz (nLinhas nColunas). Ex.: 2 5: ");
  scanf("%d %d", &nLinhas, &nColunas);

  // Aloca espa�o para a matriz
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

  // Libera a mem�ria alocada para a matriz
  for (i = 0; i < nLinhas; i++) {
    free(matriz[i]);
  }
  free(matriz);
}

// ------------------------------------------------------------------------------------------------

/**
 * Exerc�cio 06
 * Fa�a um programa para ler a quantidade de um total de X
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

  // Workaround para jogar o \n que est� no stdin depois do scanf
  getchar();

  // Obtem as informa��es do usu�rio
  printf("Digite o numero de lojas: ");
  scanf("%d", &nLojas);
  printf("Digite o numero de produtos: ");
  scanf("%d", &nProdutos);

  // Aloca espa�o para os valores
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

  // Exibe as informa��es para o usu�rio

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

  // Libera a mem�ria alocada para a matriz
  for (i = 0; i < nLojas; i++) {
    free(matrizLojasProdutos[i]);
  }
  free(matrizLojasProdutos);
}

// ------------------------------------------------------------------------------------------------

/**
 * Fun��o principal do programa onde o mesmo ser� iniciado.
 * @param argc N�mero de par�metros.
 * @param argv Valores dos par�metros.
 * @return SUCESSO caso o programa seja executado corretamente, ou caso contr�rio,
 * o c�digo do erro ocorrido.
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

    // Adiciono uma quebra de linha para separar cada execu��o de exerc�cio
    printf("\n");

  } while (nExercicio != 0);

  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}