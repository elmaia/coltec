/**
 * @file   Aula04.c
 * @brief  Arquivo com a implementação dos exercícios da Aula 04.
 * @author Leandro Maia Silva
 * @date   2019-04-17
 */

/* Inclusões */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "erros.h"

/**
 * Exercício 01
 * Construir um algoritmo para ler 5 valores inteiros, calcular e
 * imprimir a soma desses valores;
 */
void exercicio01(void) {

  int val1, val2, val3, val4, val5, soma;

  // Leitura dos valores digitados pelo usuário
  printf("Vamos somar cinco valores. Digite cada valor e aperte <enter>.\n");
  scanf("%d", &val1);
  scanf("%d", &val2);
  scanf("%d", &val3);
  scanf("%d", &val4);
  scanf("%d", &val5);

  // Calcula a soma e mostra o resultado
  soma = val1 + val2 + val3 + val4 + val5;
  printf("A soma dos cinco valores e: %d\n", soma);

}

/**
 * Exercício 02
 * Construir um algoritmo para ler 6 valores reais, calcular e
 * imprimir a média aritmética desses valores;
 */
void exercicio02(void) {

  float val1, val2, val3, val4, val5, media;

  // Leitura dos valores digitados pelo usuário
  printf("Vamos calcular a media de cinco valores. Digite cada valor e aperte <enter>.\n");
  scanf("%f", &val1);
  scanf("%f", &val2);
  scanf("%f", &val3);
  scanf("%f", &val4);
  scanf("%f", &val5);

  // Calcula a média e mostra o resultado
  media = (val1 + val2 + val3 + val4 + val5) / 5;
  printf("A media dos cinco valores e: %f\n", media);

}

/**
 * Exercício 03
 * Fazer um algoritmo para gerar e imprimir o resultado do
 * número H, sendo H = 1 + 1/2 + 1/3 + 1/4 + 1/5;
 */
void exercicio03(void) {

  float H;

  // Calcula o valor de H
  H = 1 + 1.0f / 2 + 1.0f / 3 + 1.0f / 4 + 1.0f / 5;

  printf("O valor de H e: %f", H);
}

/**
 * Exercício 04
 * Calcular o aumento que será dado a um funcionário, obtendo
 * do usuário as seguintes informações : salário atual e a
 * porcentagem de aumento. Apresentar o novo valor do salário e
 * o valor do aumento;
 */
void exercicio04(void) {

  float salario, percAumento, valAumento, novoSalario;

  // Obtem os dados
  printf("Digite seu salario atual: ");
  scanf("%f", &salario);
  printf("Digite a porcentagem de aumento: ");
  scanf("%f", &percAumento);

  // Calcula o aumento, novo salario e imprime o valores
  valAumento = salario * (percAumento / 100);
  novoSalario = salario + valAumento;
  printf("Valor do aumento: %.2f\nValor do salario: %.2f\n", valAumento, novoSalario);
}

/**
 * Exercício 05
 * A nota final de um aluno é dada pela média ponderada das
 * notas das provas. Sabendo que o professor deu 3 provas, com
 * pesos 4, 3 e 3, respectivamente, calcule a nota final do aluno;
 */
#define PESO_PROVA_1 4
#define PESO_PROVA_2 3
#define PESO_PROVA_3 3
void exercicio05(void) {

  float notaProva1, notaProva2, notaProva3, notaFinal;

  // Obtem as notas das provas
  printf("Vamos calcular a nota final do aluno.\n");
  printf("Nota da Prova 1: ");
  scanf("%f", &notaProva1);
  printf("Nota da Prova 2: ");
  scanf("%f", &notaProva2);
  printf("Nota da Prova 3: ");
  scanf("%f", &notaProva3);

  // Calcula a nota final e imprime
  notaFinal = ((notaProva1 * PESO_PROVA_1) + (notaProva2 * PESO_PROVA_2) + (notaProva3 * PESO_PROVA_3)) / (PESO_PROVA_1 + PESO_PROVA_2 + PESO_PROVA_3);
  printf("A nota final e: %.2f", notaFinal);
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
  printf("Digite o numero do exercicio que quer executar [1:5]: ");
  scanf("%d", &nExercicio);

  switch (nExercicio) {
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

  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}