/**
* @file   Aula08.c
* @brief  Arquivo com a implementa��o dos exerc�cios da Aula 08.
* @author Leandro Maia Silva
* @date   2019-06-03
*/

/* Inclus�es */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "erros.h"

/* Tipos */
typedef uint8_t bool_t;

/* Constantes */
#define VERDADEIRO (1 == 1)
#define FALSO      (!VERDADEIRO)

// ------------------------------------------------------------------------------------------------

/**
 * Fun��o que calcula a soma de dois n�meros.
 * @param A Parcela A.
 * @param B Parcela B.
 * @return Soma de A e B.
 */
int soma(int A, int B) {
  return A + B;
}

/**
 * Fun��o que calcula o produto de dois n�meros.
 * @param A Fator A.
 * @param B Fator B.
 * @return Produto de A e B.
 */
int produto(int A, int B) {
  return A * B;
}
/**
 * Fun��o que calcula a divis�o de dois n�meros.
 * @param dividendo Dividendo.
 * @param divisor Divisor.
 * @return Quociente..
 */
int quociente(int dividendo, int divisor) {
  return dividendo / divisor;
}


/**
 * Exerc�cio 01
 */
void exercicio01(void) {

  int opcao;
  int A, B, resultado;

  do {

    // Imprime o menu de opcao
    printf("Escolha a opcao:\n"\
           "1 - Soma\n"\
           "2 - Produto\n"\
           "3 - Quociente\n"\
           "4 - Sair\n");
    printf("Digite a opcao [1:4]: ");
    scanf("%d", &opcao);

    // Se a op��o for v�lida, ent�o l� A e B
    if ((opcao >= 1) && (opcao <= 3)) {
      printf("Digite os dois numeros (Ex: 1500 8885): ");
      scanf("%d %d", &A, &B);
    }

    switch (opcao) {
      case 1:
        resultado = soma(A, B);
        break;
      case 2:
        resultado = produto(A, B);
        break;
      case 3:
        resultado = quociente(A, B);
        break;
      case 4: return;
      default:
        printf("Voce escolheu uma opcao invalido.\n");
        break;
    }

    // Se chegou aqui, ent�o realizou a opera��o
    printf("O resultado eh: %d\n", resultado);
  } while (opcao != 4);
}

// ------------------------------------------------------------------------------------------------

/**
 * Fun��o que verifica se um ano � bissexto.
 * @param ano Ano a ser verificado
 * @return VERDADEIRO caso o ano seja bissexto, ou FALSO caso contr�rio.
 */
bool_t ehBissexto(uint16_t ano) {
  if ((((ano % 4) == 0) && !((ano % 100) == 0)) || (ano % 400) == 0) {
    return VERDADEIRO;
  } else {
    return FALSO;
  }
}

/**
 * Calcula o n�mero de dias de uma pessoa.
 * @param anos N�mero de anos.
 * @param meses N�mero de meses.
 * @param dias N�mero de dias.
 * @return N�mero de dias.
 */
#define NUMERO_DIAS_MES  (30)
#define NUMERO_DIAS_ANO  (365)
uint16_t idadeEmDias(uint8_t anos, uint8_t meses, uint8_t dias) {
  return ((uint16_t)anos * NUMERO_DIAS_ANO) + ((uint16_t)meses * NUMERO_DIAS_MES) + dias;
}

/**
 * Exerc�cio 02
 * Fa�a uma fun��o que receba a idade de uma pessoa em anos,
 * meses e dias e retorna essa idade expressa em dias.
 */
void exercicio02(void) {

  uint8_t anos, meses, dias;
  uint16_t diasTotal;

  // Obtem os dados
  printf("Digite a idade em anos, meses e dias (Ex: 33 6 3): ");
  scanf("%hhd %hhd %hhd", &anos, &meses, &dias);


  // Calcula o n�mero total de dias
  diasTotal = idadeEmDias(anos, meses, dias);

  // Imprime
  printf("A idade de %hhd anos, %hhd meses e %hhd dias corresponde a um total de %hd dias.\n", anos, meses, dias, diasTotal);
}

// ------------------------------------------------------------------------------------------------

/**
 * Exerc�cio 03
 * Fa�a um procedimento que receba por par�metro o tempo de
 * dura��o de um experimento expresso em segundos e imprima
 * na tela esse mesmo tempo em horas, minutos e segundos.
 */
#define MINUTO_EM_SEGUNDOS (60)
#define HORA_EM_SEGUNDOS   (60 * MINUTO_EM_SEGUNDOS)
void exercicio03(void) {

  int tempo_s, tempoOriginal;
  int horas, minutos, segundos;

  // Obtem o n�mero
  printf("Digite o tempo do experimento em segundos: ");
  scanf("%d", &tempo_s);

  // Salva o tempo para imprimir depois
  tempoOriginal = tempo_s;

  // Calcula as horas, minutos e segundos
  horas = tempo_s / HORA_EM_SEGUNDOS;
  tempo_s = tempo_s % HORA_EM_SEGUNDOS;
  minutos = tempo_s / MINUTO_EM_SEGUNDOS;
  tempo_s = tempo_s % MINUTO_EM_SEGUNDOS;
  segundos = tempo_s;

  // Imprime o tempo
  printf("Tempo %ds : %02dh,%02dm,%02ds\n", tempoOriginal, horas, minutos, segundos);
}

// ------------------------------------------------------------------------------------------------

/**
 * Fun��o que verifica se o n�mero � primo ou n�o.
 * @param numero N�mero a ser verificado.
 * @return VERDADEIRO se o n�mero for primo, ou FALSO caso contr�rio.
 */
bool_t ehPrimo(uint32_t numero) {

  uint32_t i;

  // Se o n�mero for 1, ele n�o � primo
  if (numero == 1) return FALSO;

  // Procuro de 2 at� o n�mero desejado -1
  for (i = 2; i < numero; i++) {
    if ((numero % i) == 0) return FALSO;
  }

  // Se chegou at� aqui � porque � primo
  return VERDADEIRO;
}

/**
 * Exerc�cio 04
 * Implemente uma fun��o que receba um n�mero inteiro como
 * entrada e verique se esse n�mero � primo ou n�o. Um
 * n�mero � primo quando este possui apenas dois divisores (1 e
 * ele mesmo).
 */
void exercicio04(void) {

  uint32_t numero;
  bool_t ePrimo;

  printf("Digite o numero para verificar se eh primo: ");
  scanf("%u", &numero);

  // Verifica se � primo
  ePrimo = ehPrimo(numero);

  // Imprime
  if (ePrimo) {
    printf("%u EH primo.\n", numero);
  } else {
    printf("%u NAO EH primo.\n", numero);
  }
}

// ------------------------------------------------------------------------------------------------

/**
 * Fun��o que calcula o fatorial de um n�mero.
 * @param numero N�mero a ter seu fatorial calculado
 * @return Fatorial do n�mero.
 */
uint64_t fatorial(uint8_t numero) {

  uint8_t i;
  uint64_t fatorial;

  // Calcula o fatorial
  fatorial = 1;
  for (i = 2; i <= numero; i++) {
    fatorial *= i;
  }

  // Retorna o fatorial calculado
  return fatorial;
}

/**
 * Exerc�cio 05
 * Fa�a uma fun��o que receba um valor N inteiro e positivo e
 * que calcula o fatorial deste valor. Retorne o resultado.
 */
void exercicio05(void) {

  int numero;
  uint64_t valFatorial;

  printf("Digite o numero para calcular o fatorial: ");
  scanf("%d", &numero);

  // Calcula o fatorial
  valFatorial = fatorial((uint8_t)numero);

  // Imprime
  printf("%d!: %llu\n", numero, valFatorial);

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

    // Adiciono uma quebra de linha para separar cada execu��o de exerc�cio
    printf("\n");

  } while (nExercicio != 0);

  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}