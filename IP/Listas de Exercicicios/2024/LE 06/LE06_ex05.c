/**
 * @file   LE06_ex01.c
 * @brief  Arquivo com a implementa��o de sugest�o de 
 *         solu��o do exerc�cio 05 da LE 06 de 2024.
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

// Valor do �ndice caso o valor procurado n�o seja encontrado
#define INDICE_VALOR_NAO_ENCONTRADO  -1

/**
 *  Procura o menor valor em um vetor
 *  @param numeros Vetor de n�meros.
 *  @param quantidade Quantidade de elementos no vetor. 
 *                    Deve ser maior que 0.
 *  @return Menor valor encontrado no vetor.
 */
int menorValor(int numeros[], int quantidade) {
  
  int i;
  int menor = numeros[0];
  
  for(i = 1; i < quantidade; i++) {
    if (numeros[i] < menor) {
      menor = numeros[i];
    }
  }
  
  // Retorna o menor valor
  return menor;
}

/**
 *  Procura o maior valor em um vetor
 *  @param numeros Vetor de n�meros.
 *  @param quantidade Quantidade de elementos no vetor. 
 *                    Deve ser maior que 0.
 *  @return Maior valor encontrado no vetor.
 */
int maiorValor(int numeros[], int quantidade) {
  
  int i;
  int maior = numeros[0];
  
  for(i = 1; i < quantidade; i++) {
    if (numeros[i] > maior) {
      maior = numeros[i];
    }
  }
  
  // Retorna o maior valor
  return maior;
}

/**
 *  Procura o �ndice do valor presente em um vetor.
 *  @param numeros Vetor de n�meros.
 *  @param quantidade Quantidade de elementos no vetor. 
 *  @param valor Valor a ser procurado no vetor.
 *  @return Menor valor encontrado no vetor.
 */

int indiceValor(int numeros[], int quantidade, int valor) {
  
  int indice = INDICE_VALOR_NAO_ENCONTRADO;
  int i;
  
  for(i = 0; i < quantidade; i++) {
    if (numeros[i] == valor) return i;
  }  
  
  // Se chegou at� aqui � porque n�o encontrou
  return INDICE_VALOR_NAO_ENCONTRADO;  
}

/**
 * Quest�o 01:
 * Fa�a um programa que leia, via teclado, 20 valores do tipo inteiro e determine 
 * qual o menor e o maior valor, al�m disso informe o �ndice do menor e do maior.
 * Considere que todos os elementos possuem valores distintos.
 *
 * Exemplo:
 * Entrada: 5 12 -3 8 20 1 99 -50 33 6 15 0 -8 42 17 7 28 -11 65 9
 * Sa�da: -50 7 99 6
 * Explica��o: -50 � o menor valor e seu �ndice � o 7, 99 � o maior e seu �ndice � o 6
 *
 * Quest�o 05:
 * Fa�a uma c�pia da quest�o 01 e crie tr�s fun��es que:
 * 1) dado um vetor e seu tamanho, determine o menor valor presente.
 * 2) dado um vetor e seu tamanho, determine o maior valor presente.
 * 3) dado um vetor, seu tamanho e um valor, determine o �ndice onde esse valor foi encontrado no vetor.
 * Modifique a quest�o para encontrar a solu��o usando as tr�s fun��es criadas.
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
  
  // Obtem o menor, maior e seus �ndices
  menor = menorValor(numeros, QUANTIDADE_NUMEROS);
  maior = maiorValor(numeros, QUANTIDADE_NUMEROS);
  indice_menor = indiceValor(numeros, QUANTIDADE_NUMEROS, menor);
  indice_maior = indiceValor(numeros, QUANTIDADE_NUMEROS, maior);
  
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