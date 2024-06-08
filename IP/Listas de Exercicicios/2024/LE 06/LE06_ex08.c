/**
 * @file   LE06_ex08.c
 * @brief  Arquivo com a implementa��o de sugest�o de 
 *         solu��o do exerc�cio 08 da LE 06 de 2024.
 * @author Leandro Maia Silva
 * @date   2024-06-08
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

/**
 * Calcula o n-�simo termo da s�rie de Fibonacci.
 * @param termo Termo desejado.
 * @return Valor do termo.
 */
unsigned long long int numeroFibonacci(int termo) {
  
  int i;
  unsigned long long int Fn, Fn1 = 0, Fn2 = 1;

  for (i = 0; i < termo; i++) {

    // Calcula o termo atual
    Fn = Fn1 + Fn2;

    // Atualiza os termos
    Fn2 = Fn1;
    Fn1 = Fn;
  }
  
  // Retorna o n�mero
  return Fn;
}

/**
 * Fazer uma fun��o para calcular os N primeiros n�meros de Fibonacci. 
 * Essa fun��o deve receber um vetor e seu tamanho.
 * Em seguida fa�a um programa para calcular e mostrar os N primeiros 
 * termos da s�rie de Fibonacci. O n�mero N � fornecido pelo usu�rio. 
 * A s�rie de Fibonacci � : 1 1 2 3 5 8 13 ... 
 * Isto � f1 = f2 = 1, f3 = f1 + f2, f4 = f2 + f3
 */
int main(int argc, char ** argv) {
    
  int tamanho;
  int i;

  // Intera��o com o usu�rio
  printf("Serie de Fibonacci.\n");
  printf("Digite o numero de termos da serie: ");
  (void)scanf("%d", &tamanho);

  for (i = 1; i <= tamanho; i++) {
    // Mostra o n�mero da serie
    PRINTF("%llu ", numeroFibonacci(i));
  }
  printf("\n");  
  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}