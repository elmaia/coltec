/**
 * @file   LE05_ex05.c
 * @brief  Arquivo com a implementa��o de sugest�o de 
 *         solu��o do exerc�cio 05 da LE 05 de 2024.
 * @author Leandro Maia Silva
 * @date   2024-05-24
 */

/* Inclus�es */
#include <stdio.h>   // printf e scanf
#include <stdint.h>  // Para usar uint64_t ao inv�s de unsigned long long int

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

uint64_t fatorial(int n) {
  
  int i;
  uint64_t fat = 1;
  
  for(i = 1; i <= n; i++) {
    fat*=i;
  }
  
  return fat;
}

/**
 *  Fa�a uma fun��o que receba um valor N inteiro e positivo
 *  e que calcula o fatorial deste valor.
 */
int main(int argc, char ** argv) {
    
  uint64_t fat;
  int numero;
  
  // Obtem o n�mero para calcular o fatorial
  printf("Calculadora de Fatorial.\n");
  printf("Digite o numero para calcular o fatorial.\n");
  printf(":> ");
  scanf("%d", &numero);
  
  // Calcula numero!
  fat = fatorial(numero);
  
  // Mostra o resultado
  printf("%d! eh ", numero);
  PRINTF("%llu", fat);
  printf("\n");
  
  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}