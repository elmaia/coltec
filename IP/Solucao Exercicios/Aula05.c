/**
 * @file   Aula05.c
 * @brief  Arquivo com a implementa��o dos exerc�cios da Aula 05.
 * @author Leandro Maia Silva
 * @date   2019-06-01
 */

/* Inclus�es */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "erros.h"

/**
 * Exerc�cio 01
 * Ler um n�mero inteiro e informar se ele � par ou �mpar;
 */
void exercicio01(void) {

  int numero;
  int ePar;

  // Obtenho o n�mero
  printf("Digite um numero para saber se eh par ou impar: ");
  scanf("%d", &numero);

  // Verifica se � par
  ePar = (numero % 2) == 0;

  // Imprime o resultado
  if (ePar) {
    printf("O numero %d eh PAR.\n", numero);
  } else {
    printf("O numero %d eh IMPAR.\n", numero);
  }
}

/**
 * Exerc�cio 02
 * Fa�a um programa para ler dois inteiros e determinar qual � o
 * maior entre eles ou se eles s�o iguais.
 */
void exercicio02(void) {

  int numero1, numero2;

  // Obtenho os n�meros
  printf("Digite dois numeros separados par espaco para compara-los (Ex: 8 15) : ");
  scanf("%d %d", &numero1, &numero2);

  // Realizo as compara��es e imprimo a informa��o conforme resultado
  if (numero1 == numero2) {
    printf("Os numeros %d e %d sao IGUAIS.\n", numero1, numero2);
  } else {
    if (numero1 < numero2) {
      printf("Entre os numeros %d e %d, o maior eh o %d.\n", numero1, numero2, numero2);
    } else {
      printf("Entre os numeros %d e %d, o maior eh o %d.\n", numero1, numero2, numero1);
    }
  }
}

/**
 * Exerc�cio 03
 * Desenvolver um algoritmo para ler o n�mero do dia da semana
 * e imprimir o seu respectivo nome por extenso. Considerar o
 * n�mero 1 como domingo, 2 para segunda etc. Caso o dia da
 * semana n�o exista (menor do que 1 ou maior do que 7), exibir
 * a mensagem "Dia da semana inv�lido";
 */
void exercicio03(void) {

  int diaSemana;

  // Obtem o dia da semana
  printf("Digite o numero referente ao dia da semana para obter seu nome [1:7]: ");
  scanf("%d", &diaSemana);

  // Imprime o dia da semana conforme o numero
  switch (diaSemana) {
    case 1:
      printf("Domingo\n");
      break;
    case 2:
      printf("Segunda-feira\n");
      break;
    case 3:
      printf("Terca-feira\n");
      break;
    case 4:
      printf("Quarta-feira\n");
      break;
    case 5:
      printf("Quinta-feira\n");
      break;
    case 6:
      printf("Sexta-feira\n");
      break;
    case 7:
      printf("Sabado\n");
      break;

    default:
      printf("Dia da semana invalido\n");
      break;
  }
}

/**
 * Exerc�cio 04
 * Fazer um algoritmo para ler dois n�meros e um dos s�mbolos
 * das opera��es: +, -, * e /. Imprimir o resultado da opera��o
 * efetuada sobre os n�meros lidos;
 */
void exercicio04(void) {

  float numero1, numero2;
  char operador;

  // Obtem a expressao
  printf("Digite a expressao simples a ser calculada (Ex: 2.3 * 2.1): ");
  scanf("%f %c %f", &numero1, &operador, &numero2);

  switch (operador) {
  case '+':
    printf("%f %c %f = %f", numero1, operador, numero2, numero1 + numero2);
    break;
  case '-':
    printf("%f %c %f = %f", numero1, operador, numero2, numero1 - numero2);
    break;
  case '*':
  case 'x':
  case 'X':
    printf("%f %c %f = %f", numero1, operador, numero2, numero1 * numero2);
    break;
  case '/':
    printf("%f %c %f = %f", numero1, operador, numero2, numero1 / numero2);
    break;

  default:
    printf("Operacao invalida.\n");
    break;
  }    
}

/**
 * Exerc�cio 05
 * Fa�a um programa que leia 3 comprimentos (x,y e z) e
 * responda se eles formam um tri�ngulo, ou seja, se x < y + z e
 * y < x + z e z < x + y;
 */
void exercicio05(void) {

  float x, y, z;
  int eTriangulo;

  // Obtem os lados
  printf("Digite os comprimentos dos segmentos para verificar se forma um triangulo (Ex: 1.0 1.0. 2.0): ");
  scanf("%f %f %f", &x, &y, &z);

  // Verifica se � um triangulo
  eTriangulo = (x < y + z) && (y < x + z) && (z < x + y);

  // Mostra o resultado
  if (eTriangulo) {
    printf("Os comprimentos %f, %f e %f FORMAM um triangulo.\n", x, y, z);
  } else {
    printf("Os comprimentos %f, %f e %f NAO FORMAM um triangulo.\n", x, y, z);
  }
}

/**
 * Exerc�cio 06
 * Tendo como dados de entrada a altura e o sexo de uma
 * pessoa, construa um programa que calcule seu peso ideal,
 * utilizando as seguintes f�rmulas: para homens: (72.7*h)-58
 * para mulheres: (62.1*h)-44.7 Informe tamb�m se a pessoa
 * est� acima ou abaixo deste peso.
 */
void exercicio06(void) {

  float altura, peso, pesoIdeal;
  char sexo;

  // Obtem os dados
  printf("Digite sua altura em metros: ");
  scanf("%f", &altura);
  printf("Digite seu peso atual em kg: ");
  scanf("%f", &peso);
  printf("Digite seu sexo (M ou F): ");
  scanf(" %c", &sexo);

  // Calcula o peso ideal
  if ((sexo == 'M') || (sexo == 'm')) {
    pesoIdeal = (72.7f * altura) - 58;
  } else {
    pesoIdeal = (62.1f * altura) - 44.7f;
  }

  // Verifica a situa��o dela e informa
  printf("Seu peso ideal eh %.2f e esta pesando %.2f. ", pesoIdeal, peso);
  if (peso > pesoIdeal) {
    printf("Voce esta acima do peso.\n");
  } else {
    printf("Voce esta no pesoa ideal ou abaixo.\n");
  }
}


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
    printf("Digite o numero do exercicio que quer executar [1:6]. 0 para sair: ");
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