/**
 * @file   Aula15.c
 * @brief  Arquivo com a implementa��o dos exerc�cios da Aula 15.
 * @author Leandro Maia Silva
 * @date   2019-10-10
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

// ------------------------------------------------------------------------------------------------

void imprimeIntervaloFechado(int a, int b) {

  // Verifica se A e B s�o v�lidos
  if (a > b) {
    printf("A > B. Valores invalidos.\n");
    return;
  }

  // Imprime A
  printf("%d ", a);

  // Verifica se h� mais coisa pra fazer
  if (a < b) {
    imprimeIntervaloFechado(a + 1, b);
  } else {
    printf("\n");
  }
}

/**
 * Exerc�cio 01
 * Fa�a um procedimento recursivo que receba dois valores
 * inteiros a e b e imprima o intervalo fechado entre eles. Se a for
 * maior que b mostrar mensagem de erro.
 */
void exercicio01(void) {

  int a, b;
  char lixo;

  // Interage com o usu�rio
  printf("Digite dois valores para imprimir o intervalo fechado entre eles. Ex: 3 7: ");
  scanf("%d %d%c", &a, &b, &lixo);

  imprimeIntervaloFechado(a, b);

}

// ------------------------------------------------------------------------------------------------

int elementoMaximo(int vetor[], int nElementos) {

  int maior;
  
  if (nElementos == 0) return INT_MIN;

  maior = elementoMaximo(&vetor[1], nElementos - 1);

  if (vetor[0] < maior) {
    return maior;
  } else {
    return vetor[0];
  }
}

int somaElementos(int vetor[], int nElementos) {

  // Caso base:
  // Se n�o tem elementos, ent�o a soma � 0.
  if (nElementos == 0) {
    return 0;
  }

  // Passo recursivo: 
  // Se nElementos > 0, ent�o soma = atual + soma(proximo, nElementos -1);
  return vetor[0] + somaElementos(&vetor[1], nElementos -1);
}

float mediaAritmeticaRec(int vetor[], int nElementos, int nElementosInicial) {

  // Caso base:
  // Se n�o tem elementos, ent�o a m�dia � 0
  if (nElementos == 0) {
    return 0.0f;
  }

  // Passo recursivo:
  // Se nElementos > 0, ent�o m�dia = atual/nElementosInicial + media(proximo, nElementos -1)
  return vetor[0] / ((1.0f) * nElementosInicial) + mediaAritmeticaRec(&vetor[1], nElementos - 1, nElementosInicial);
}

float mediaAritmeticaV1(int vetor[], int nElementos) {
  return mediaAritmeticaRec(vetor, nElementos, nElementos);
}

float mediaAritmeticaV2(int vetor[], int nElementos) {
  return somaElementos(vetor, nElementos) / ((1.0f) * nElementos);
}

/**
 * Exerc�cio 02
 * Seja S um vetor de inteiros. Descreva fun��es recursivas para
 * calcular:
 * 1 o elemento m�ximo de S;
 * 2 a soma dos elementos de S;
 * 3 m�dia aritm�tica dos elementos de S.
 */
void exercicio02(void) {

  int vetorTeste[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

  printf("Elemento Maximo ..: %d\n", elementoMaximo(vetorTeste, (sizeof(vetorTeste) / sizeof(int))));
  printf("Soma Elemento.....: %d\n", somaElementos(vetorTeste, (sizeof(vetorTeste) / sizeof(int))));
  printf("Media Elementos V1: %f\n", mediaAritmeticaV1(vetorTeste, (sizeof(vetorTeste) / sizeof(int))));
  printf("Media Elementos V2: %f\n", mediaAritmeticaV2(vetorTeste, (sizeof(vetorTeste) / sizeof(int))));

}

// ------------------------------------------------------------------------------------------------

int fibonacci(int n) {
  if ((n == 1) || (n == 2)) {
    return 1;
  }

  return fibonacci(n - 1) + fibonacci(n - 2);
}

/**
 * Exerc�cio 03
 * Escreva uma fun��o recursiva para calcular o N-�simo n�mero
 * da sequ�ncia de Fibonacci.
 */
void exercicio03(void) {

  int n;
  char lixo;

  // Interage com o usu�rio
  printf("Digite o N para calcular o N-esimo na sequencia de Fibonacci: ");
  scanf("%d%c", &n, &lixo);

  printf("O %d-esimo numero de Fibonacci eh: %d\n", n, fibonacci(n));
}

// ------------------------------------------------------------------------------------------------

int numDigitos(int numero) {

  if (numero < 10) return 1;

  return 1 + numDigitos(numero / 10);
}

/**
 * Exerc�cio 04
 * Escreva uma fun��o recursiva para determinar o n�mero de
 * d�gitos de um inteiro N.
 */
void exercicio04(void) {

  int n;
  char lixo;

  // Interage com o usu�rio
  printf("Digite o numero para saber quantos digitos: ");
  scanf("%d%c", &n, &lixo);

  printf("O numero %d tem %d digitos\n", n, numDigitos(n));
}

// ------------------------------------------------------------------------------------------------

int buscaNumeroRec(int vetor[], int nElementos, int numero, int posAtual) {

  // Se n�o tem elementos, n�o encontrou
  if (nElementos == 0) {
    return -1;
  }

  // Verifica se o elemento atual � o desejado
  if (vetor[posAtual] == numero) return posAtual;

  // Se n�o �, continua procurar
  return buscaNumeroRec(vetor, nElementos - 1, numero, posAtual + 1);
}

int buscaNumero(int vetor[], int nElementos, int numero) {
  return buscaNumeroRec(vetor, nElementos, numero, 0);
}

/**
 * Exerc�cio 05
 * Escreva uma fun��o recursiva que busque por um determinado
 * elemento em um vetor de inteiros.
 */
void exercicio05(void) {

  int i, nElementos;
  int vetorTeste[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };

  nElementos = (sizeof(vetorTeste) / sizeof(int));

  for (i = 0; i < nElementos; i++) {
    printf("Posicao do Numero %d ..: %d\n", vetorTeste[i], buscaNumero(vetorTeste, nElementos, vetorTeste[i]));
  }
  printf("Posicao do Numero %d ..: %d\n", 11, buscaNumero(vetorTeste, nElementos, 11));
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
  char lixo;

  do {
    printf("Digite o numero do exercicio que quer executar [1:5]. 0 para sair: ");
    scanf("%d%c", &nExercicio, &lixo);

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

    // Adiciono uma quebra de linha para separar cada execu��o de exerc�cio
    printf("\n");

  } while (nExercicio != 0);

  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}