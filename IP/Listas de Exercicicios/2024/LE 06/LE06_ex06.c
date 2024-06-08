/**
 * @file   LE06_ex01.c
 * @brief  Arquivo com a implementa��o de sugest�o de 
 *         solu��o do exerc�cio 06 da LE 06 de 2024.
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

#define VETOR_TAMANHO_MAXIMO    10

/**
 * Multiplica um vetor de tamanho especificado por um escalar e coloca
 * em um vetor de resultado.
 * @param vetor Vetor de n�mero a ser multiplicado.
 * @param tamanho Quantidade de n�meros no vetor.
 * @param escalar Valor escalar que multiplicar� o vetor.
 * @param resultado Vetor que receber� o resultado da multiplica��o.
 */
void multiplicaVetorEscalar(float vetor[], int tamanho, float escalar, float resultado[]) {
  
  int i;
  
  // Multiplica��o do vetor pelo escalar
  for (i = 0; i < tamanho; i++) {
    resultado[i] = vetor[i] * escalar;
  }  
}

/**
 * Quest�o 02:
 * Desenvolva um programa que leia um vetor de n�meros reais, um escalar e 
 * imprima o resultado da multiplica��o do vetor pelo escalar, com duas casas decimais.
 * Aten��o! Voc� deve determinar o m�ximo para que o exerc�cio seja fact�vel 
 * com o assunto estudado at� o momento.
 * 
 * Exemplo: 
 * Entrada: 5\n2 3.5 0 1.8 4\n3
 * Sa�da: 6.00 -10.50 0.00 5.40 12.00
 * Explica��o: Foi lido um vetor de tamanho 5 com os valores [2 3.5 0 1.8  4], al�m do escalar 3. 
 * Cada um dos n�meros foi multiplicado por 3 (escalar) e a sa�da � o vetor [6.00 -10.50 0.00 5.40 12.00]
 *
 * Quest�o 06:
 * Fa�a uma c�pia da quest�o 02 e crie uma fun��o que, dado um vetor, seu tamanho e um escalar, 
 * calcule o resultado da multiplica��o do vetor pelo escalar.
 * Modifique a quest�o para encontrar a solu��o usando a fun��o criada.
 */
int main(int argc, char ** argv) {
  
  float vetor[VETOR_TAMANHO_MAXIMO];
  float escalar;
  float resultado[VETOR_TAMANHO_MAXIMO];
  int tamanho;
  int i;
  
  // Leitura do tamanho do vetor
  printf("Digite o tamanho do vetor [1:%d]: ", VETOR_TAMANHO_MAXIMO);
  scanf("%d", &tamanho);

  // Leitura dos elementos do vetor
  printf("Digite os elementos do vetor:\n");
  for (i = 0; i < tamanho; i++) {
      printf("Vetor[%d]: ", i);
      scanf("%f", &vetor[i]);
  }

  // Leitura do escalar
  printf("Digite o valor do escalar: ");
  scanf("%f", &escalar);
  
  // Calcula o produto do vetor pelo escalar
  multiplicaVetorEscalar(vetor, tamanho, escalar, resultado);

  // Imprime o resultado
  printf("Resultado da multiplicacao:\n");
  printf("[");
  for (i = 0; i < tamanho; i++) {
    PRINTF("%.2f ", resultado[i]);
  }
  printf("]\n");

  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}