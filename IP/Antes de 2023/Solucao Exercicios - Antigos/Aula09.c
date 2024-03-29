/**
 * @file   Aula09.c
 * @brief  Arquivo com a implementação dos exercícios da Aula 09.
 * @author Leandro Maia Silva
 * @date   2019-06-03
 */

/* Inclusões */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "erros.h"

/**
 * Exercício 01
 * Faça um programa que leia, via teclado, 20 valores do tipo
 * inteiro e determine qual o menor valor existente no vetor e
 * imprima o valor e seu índice no vetor;
 */
#define TAMANHO_VETOR  (20)
#define MAIOR_VALOR_32b (0x7FFFFFFF)
void exercicio01(void) {

  int i, indiceMenor, menorValor;
  int valores[TAMANHO_VETOR];

  // Obtem os valores
  for (i = 0; i < TAMANHO_VETOR; i++) {
    printf("Digite o %do valor: ", (i+1));
    scanf("%d", &valores[i]);
  }

  // Procura o menor valor e determina o índice
  menorValor = MAIOR_VALOR_32b;
  for (i = 0; i < TAMANHO_VETOR; i++) {
    // Verifica se o valor atual é menor que o menor.
    // Se for, salva o índice e o valor.
    if (valores[i] < menorValor) {
      menorValor = valores[i];
      indiceMenor = i;
    }
  }

  // Imprime o resultado.
  printf("O menor valor do vetor eh %d e esta no indice %d.\n", menorValor, indiceMenor);
}

// ------------------------------------------------------------------------------------------------

/**
 * Exercício 02
 * Desenvolva um programa que leia um vetor de números reais,
 * um escalar e imprima o resultado da multiplicação do vetor
 * pelo escalar.
 */
#define MAIOR_VETOR  (100)
void exercicio02(void) {

  int tamanhoVetor, i;
  float valores[MAIOR_VETOR], escalar;

  // Obtem os valores
  printf("Qual sera o tamanho do seu vetor [1:%d]?", MAIOR_VETOR);
  scanf("%d", &tamanhoVetor);

  // Lê os valores
  for (i = 0; i < tamanhoVetor; i++) {
    printf("Digite o %do valor: ", (i + 1));
    scanf("%f", &valores[i]);
  }

  // Obtem o escalar
  printf("Qual o valor do escalar? ");
  scanf("%f", &escalar);

  // Multiplica o vetor pelo scalar
  for (i = 0; i < tamanhoVetor; i++) {
    valores[i] *= escalar;
  }

  // Imprime o vetor
  for (i = 0; i < tamanhoVetor; i++) {
    printf("Vetor[%d] x Escalar = %f\n", i, valores[i]);
  }
}

// ------------------------------------------------------------------------------------------------

/**
 * Exercício 03
 * Faça um programa que leia 2 vetores de tamanho 10 e calcule
 * o produto escalar deles.
 */
#define TAMANHO_VETORES (10)
void exercicio03(void) {

  int i;
  float vetor1[TAMANHO_VETORES], vetor2[TAMANHO_VETORES];
  float produtoEscalar = 0.0f;

  // Obtem os dados
  printf("Voce ira preencher dois vetores de 10 posicoes para calcular o produto escalar.\n");
  printf("Vetor1:\n");
  for (i = 0; i < TAMANHO_VETORES; i++) {
    printf("Vetor1[%d]: ", i);
    scanf("%f", &vetor1[i]);
  }
  printf("Vetor2:\n");
  for (i = 0; i < TAMANHO_VETORES; i++) {
    printf("Vetor2[%d]: ", i);
    scanf("%f", &vetor2[i]);
  }

  // Calcula o produto escalar dos dois vetores
  for (i = 0; i < TAMANHO_VETORES; i++) {
    produtoEscalar += vetor1[i] * vetor2[i];
  }

  // Imprime o produto escalar
  printf("Vetor1.Vetor2 = %f", produtoEscalar);


}

// ------------------------------------------------------------------------------------------------

/**
 * Exercício 04
 * Faça um programa que leia um vetor de um tamanho escolhido
 * pelo usuário e calcule a média aritmética de seus valores.
 */
#define MAIOR_VETOR_POSSIVEL  (100)
void exercicio04(void) {

  int tamanhoVetor, i;
  float valores[MAIOR_VETOR_POSSIVEL], somaValores, mediaAritmetica;

  // Obtem os valores
  printf("Qual sera o tamanho do seu vetor [1:%d]?", MAIOR_VETOR_POSSIVEL);
  scanf("%d", &tamanhoVetor);

  // Lê os valores
  for (i = 0; i < tamanhoVetor; i++) {
    printf("Valores[%d]: ", i);
    scanf("%f", &valores[i]);
  }

  // Calcula a média aritmética
  somaValores = 0.0f;
  for (i = 0; i < tamanhoVetor; i++) {
    somaValores += valores[i];
  }
  mediaAritmetica = somaValores / tamanhoVetor;


  // Imprime a média
  printf("Media aritmetica: %f", mediaAritmetica);
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