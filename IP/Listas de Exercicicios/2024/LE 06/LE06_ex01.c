/**
 * @file   LE06_ex01.c
 * @brief  Arquivo com a implementa��o de sugest�o de 
 *         solu��o do exerc�cio 01 da LE 06 de 2024.
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

#define QUANTIDADE_NUMEROS   20

/**
 * Fa�a um programa que leia, via teclado, 20 valores do tipo inteiro e determine 
 * qual o menor e o maior valor, al�m disso informe o �ndice do menor e do maior.
 * Considere que todos os elementos possuem valores distintos.
 *
 * Exemplo:
 * Entrada: 5 12 -3 8 20 1 99 -50 33 6 15 0 -8 42 17 7 28 -11 65 9
 * Sa�da: -50 7 99 6
 * Explica��o: -50 � o menor valor e seu �ndice � o 7, 99 � o maior e seu �ndice � o 6
 */
int main(int argc, char ** argv) {
  
  int numeros[QUANTIDADE_NUMEROS];
  int i;
  int menor, maior, indice_menor, indice_maior;
  
  printf("Digite 20 n�meros para encontrar o maior e o menor.\n");
  printf(": ");
  for(i = 0; i < QUANTIDADE_NUMEROS; i++) {
    scanf("%d", &numeros[i]);
  }
  
  // Inicializa menor e maior com o primeiro elemento do vetor
  menor = numeros[0];
  maior = numeros[0];
  indice_menor = 0;
  indice_maior = 0;
  
  // Percorre o vetor para encontrar o menor e o maior valor
  for (i = 1; i < QUANTIDADE_NUMEROS; i++) {
    if (numeros[i] < menor) {
      menor = numeros[i];
      indice_menor = i;
    } else if (numeros[i] > maior) {
      maior = numeros[i];
      indice_maior = i;
    }
  }
  
  // Imprime os resultados
  printf("Menor valor: ");
  PRINTF("%d", menor);
  printf(" | Indice : ");
  PRINTF(" %d", indice_menor);
  printf("\n");
  printf("Maior valor: ");
  PRINTF(" %d", maior);
  printf(" | Indice : ");
  PRINTF(" %d", indice_maior);
  printf("\n");

  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}