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
  #define PRINTF(format, args...) fprintf(stderr, format, args)
#else
  #define PRINTF(format, args...) printf(format, args)
#endif

// ----------------------------------------------------------------------

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
  
  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}