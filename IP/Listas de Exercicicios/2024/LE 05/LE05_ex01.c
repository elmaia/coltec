/**
 * @file   LE05_ex01.c
 * @brief  Arquivo com a implementação de sugestão de 
 *         solução do exercício 01 da LE 05 de 2024.
 * @author Leandro Maia Silva
 * @date   2024-05-24
 */

/* Inclusões */
#include <stdio.h>   // printf e scanf

/* Constantes */

// Constante que associa o código de erro 0 ao significado de sucesso
#define SUCESSO  0

// ----------------------------------------------------------------------

/**
 * Macro para utilização do canal de saída de erro como
 * saída de texto para testes automáticos.
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
 *  Faça um programa que apresente o seguinte menu para o
 *  usuário:
 *  Escolha uma opção de calculo para dois numeros:
 *  1 – Soma
 *  2 – Produto
 *  3 – Quociente
 *  0 – Sair
 *  Opcao:
 *  O menu acima deve ser apresentado para o usuário enquanto ele não
 *  escolher a opção 0 (sair do programa). O usuário fornecerá 2 números se
 *  escolher as opções de cálculo 1, 2 ou 3. Para cada opção de cálculo deve
 *  existir (obrigatoriamente) uma função definida (soma, produto e
 *  quociente dos dois números fornecidos pelo usuário). O resultado do
 *  cálculo deve ser escrito na tela.
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
  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}