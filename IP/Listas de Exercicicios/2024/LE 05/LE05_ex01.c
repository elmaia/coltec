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
  #define PRINTF(format, args...) fprintf(stderr, format, args)
#else
  #define PRINTF(format, args...) printf(format, args)
#endif

// ----------------------------------------------------------------------

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
  
  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}