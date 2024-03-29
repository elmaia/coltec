/**
 * @file   LE03_ex08.c
 * @brief  Arquivo com a implementa��o de sugest�o de 
 *         solu��o do exerc�cio 08 da LE 03 de 2024.
 * @author Leandro Maia Silva
 * @date   2024-03-28
 */

/* Inclus�es */
#include <stdio.h>   // printf e scanf

/* Constantes */

// Constante que associa o c�digo de erro 0 ao significado de sucesso
#define SUCESSO  0

/**
 * Escrever um programa que l� um valor N inteiro e positivo
 * e que calcula e escreve o valor de E: E = 1 + 1/2! + 1/3! + ... + 1/N!
 * Aten��o: Se fizer exatamente como est� escrito acima, o resultado ser� 1.
 */
int main(int argc, char ** argv) {
  
  float E = 0;
  int i, j, retorno;
  int tamanho;
  float termoAtual, i_fatorial = 1;

  // Intera��o com o usu�rio
  printf("Digite o numero de termos de E: ");
  retorno = scanf("%d", &tamanho);

  // Calcula o valor de E com N termos
  for (i = 1; i <= tamanho; i++) {

    i_fatorial = 1;

    // Calcula o i!
    for (j = 1; j <= i; j++) {
      i_fatorial *= j;
    }

    // Calculo do termo atual
    termoAtual = 1 / i_fatorial;

    // Somo o termo atual no E
    E+= termoAtual;
  }

  // Mostra o valor do E
  printf("E : %f\n", E);
  
  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}