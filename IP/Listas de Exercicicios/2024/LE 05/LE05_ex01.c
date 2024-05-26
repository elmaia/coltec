/**
 * @file   LE05_ex01.c
 * @brief  Arquivo com a implementa��o de sugest�o de 
 *         solu��o do exerc�cio 01 da LE 05 de 2024.
 * @author Leandro Maia Silva
 * @date   2024-05-24
 */

/* Inclus�es */
#include <stdio.h>   // printf e scanf

/* Constantes */

// Constante que associa o c�digo de erro 0 ao significado de sucesso
#define SUCESSO  0

// ----------------------------------------------------------------------

/**
 * Macro para utiliza��o do canal de sa�da de erro como
 * sa�da de texto para testes autom�ticos.
 */
#ifdef TESTADOR
  #define PRINTF(format, ...) fprintf(stderr, format, __VA_ARGS__)
#else
  #define PRINTF(format, ...) printf(format, __VA_ARGS__)
#endif

// ----------------------------------------------------------------------

float adicao(float parcelaA, float parcelaB) {
  return parcelaA + parcelaB;
}

float multiplicacao(float fatorA, float fatorB) {
  return fatorA * fatorB;
}

float divisao(float dividendo, float divisor) {
  return dividendo / divisor;
}


/**
 *  Fa�a um programa que apresente o seguinte menu para o
 *  usu�rio:
 *  Escolha uma op��o de calculo para dois numeros:
 *  1 � Soma
 *  2 � Produto
 *  3 � Quociente
 *  0 � Sair
 *  Opcao:
 *  O menu acima deve ser apresentado para o usu�rio enquanto ele n�o
 *  escolher a op��o 0 (sair do programa). O usu�rio fornecer� 2 n�meros se
 *  escolher as op��es de c�lculo 1, 2 ou 3. Para cada op��o de c�lculo deve
 *  existir (obrigatoriamente) uma fun��o definida (soma, produto e
 *  quociente dos dois n�meros fornecidos pelo usu�rio). O resultado do
 *  c�lculo deve ser escrito na tela.
 */
int main(int argc, char ** argv) {
    
  int opcao;
  float a, b;

  do {

    printf("Calculadora simples.\n");
    printf("1 - Soma\n");
    printf("2 - Produto\n");
    printf("3 - Quociente\n");
    printf("0 - Sair\n");
    printf("Opcao: ");
    scanf("%d%*c", &opcao);

    switch (opcao) {
    case 0: // Sair
      break;
    case 1: // Soma
      printf("Digite os numeros para somar: ");
      scanf("%f %f", &a, &b);
      printf("%f + %f = ", a, b);
      PRINTF("%f", adicao(a, b));
      printf("\n");
      break;
    case 2: // Produto
      printf("Digite os numeros para multiplicar: ");
      scanf("%f %f", &a, &b);
      printf("%f * %f = ", a, b);
      PRINTF("%f", multiplicacao(a, b));
      printf("\n");
      break;
    case 3: // Quociente
      printf("Digite os numeros para dividir: ");
      scanf("%f %f", &a, &b);
      printf("%f / %f = ", a, b);
      PRINTF("%f", divisao(a, b));
      printf("\n");
      break;
    default:
      printf("Opcao invalida.\n");
    }

  } while (opcao != 0);  
  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}