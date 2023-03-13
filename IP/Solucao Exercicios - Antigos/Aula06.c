/**
 * @file   Aula06.c
 * @brief  Arquivo com a implementação dos exercícios da Aula 06.
 * @author Leandro Maia Silva
 * @date   2019-06-01
 */

/* Inclusões */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "erros.h"

/**
 * Exercício 01
 * Elabore um programa que calcule N! (fatorial de N), sendo que o
 * valor inteiro de N é fornecido pelo usuário.
 */
void exercicio01(void) {

  int i, numero;
  uint64_t fatorial;

  printf("Digite o numero para calcular o fatorial: ");
  scanf("%d", &numero);

  // Calcula o fatorial
  fatorial = 1;
  for (i = 2; i <= numero; i++) {
    fatorial *= i;
  }

  // Imprime
  printf("%d!: %llu\n", numero, fatorial);
}

/**
 * Exercício 02
 * Escrever um algoritmo que lê um valor N inteiro e positivo e que
 * calcula e escreve o valor de E: E = 1 + 1/2! + 1/3! + ... + 1/N!
 */
void exercicio02(void) {

  int N, divisor;
  float E;
  int i, j;

  // Obtem o valor
  printf("Digite o numero N a ter seu E calculado: ");
  scanf("%d", &N);

  // Calcula o E
  E = 1.0f;
  for (i = 2; i <= N; i++) {
    divisor = 1;
    for (j = 1; j <= i; j++) {
      divisor *= j;
    }
    E += (1.0f / divisor);
  }

  // Mostra o resultado
  printf("O numero E de %d eh: %f\n", N, E);
}

/**
 * Exercício 03
 * Faça um programa que, dado um conjunto de valores inteiros e
 * positivos (fornecidos um a um pelo usuário), determine qual o
 * menor e o maior valor do conjunto. O final do conjunto de valores é
 * conhecido através do valor zero, que não deve ser considerado.
 */
#define MENOR_NEGATIVO_32b (0x80000000)
#define MAIOR_POSITIVO_32b (0x7FFFFFFF)
void exercicio03(void) {

  int numero;
  int32_t menor = MAIOR_POSITIVO_32b;
  int32_t maior = MENOR_NEGATIVO_32b;

  printf("Digite a serie de numeros.\n"\
         "Para cada um de um <enter>.\n"\
         "A serie encerra com o valor 0 (ZERO).\n");

  do {

    scanf("%d", &numero);

    if (numero != 0) {
      // Se o número for maior que o maior conhecido, então ele é o novo maior
      if (numero > maior) {
        maior = numero;
      }

      // Se o número for menor que o menor conhecido, então ele é o novo menor
      if (numero < menor) {
        menor = numero;
      }
    }

  } while (numero != 0);

  // Mostra o resultado
  printf("O menor numero eh %d.\n"\
         "O maior numero eh %d.\n", menor, maior);
}

/**
 * Exercício 04
 * Fazer um programa para calcular e mostrar os N primeiros termos
 * da série de Fibonacci. O número N é fornecido pelo usuário. A série
 * de Fibonacci é : 1 1 2 3 5 8 13 ... Isto é f1 = f2 = 1, f3 = f1 + f2,
 * f4 = f2 + f3...
 */
void exercicio04(void) {

  int nFibonacci, i;
  uint64_t n, n1, n2;

  // Obtem o numero desejado
  printf("Digite o numero para calcular seu numero de Fibonacci: ");
  scanf("%d", &nFibonacci);

  // Inicia o valor de N-1 e N-2 para funcionar com qualquer N;
  n1 = 0; n2 = 1;

  // Vai calculando o F(N) e imprimindo
  for (i = 1; i <= nFibonacci; i++) {

    // Calcula N
    n = n1 + n2;

    // Atualiza N-1 e N-2 para a próxima iteração
    n2 = n1;
    n1 = n;

    printf("F(%d) : %llu\n", i, n);
  }

}

/**
 * Exercício 05
 * A conversão de graus Fahrenheit para Centígrados é obtida pela
 * fórmula C = 9*(F-32)/5. Escreva um programa que calcule e
 * escreva uma tabela de graus centígrados em função de graus
 * Fahrenheit que variem de 50 a 150 de 1 em 1. */
#define MENOR_FAHRENHEIT  (50)
#define MAIOR_FAHRENHEIT  (150)
void exercicio05(void) {

  int F;
  float C;

  printf("Tabela de conversao Fahrenheit -> Centigrados\n"\
         "---------------------------------------------\n");

  // Calcula e imprime a tabela
  for (F = MENOR_FAHRENHEIT; F <= MAIOR_FAHRENHEIT; F++) {
    C = 9.0f * (F - 32.0f) / 5.0f;
    printf("F: %03d | C: %.2f\n", F, C);
  }
}

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
    printf("Digite o numero do exercicio que quer executar [1:5]. 0 para sair: ");
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
    case 5: {
      exercicio05();
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