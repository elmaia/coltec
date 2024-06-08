/**
 * @file   LE06_ex01.c
 * @brief  Arquivo com a implementa��o de sugest�o de 
 *         solu��o do exerc�cio 04 da LE 06 de 2024.
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
 * Fa�a um programa que leia um vetor de um tamanho escolhido
 * pelo usu�rio e calcule a m�dia aritm�tica de seus valores, com duas casas decimais.
 * Aten��o! Voc� deve determinar o m�ximo para que o exerc�cio seja fact�vel 
 * com o assunto estudado at� o momento.
 * 
 * Exemplo:
 * Entrada: 4\n5.5 8.2 6.0 7.3
 * Sa�da: 6.75
 * Explica��o: Foi lido um vetor de tamanho 4 com os valores [5.5 8.2 6.0 7.3], cuja 
 * m�dia aritm�tica destes valores � 6.75.
 */
int main(int argc, char ** argv) {
  
  int tamanho, i;
  float vetor[VETOR_TAMANHO_MAXIMO], soma = 0.0, media;

  // Leitura do tamanho do vetor
  printf("Digite o tamanho do vetor [1:%d]: ", VETOR_TAMANHO_MAXIMO);
  scanf("%d", &tamanho);

  // Leitura dos elementos do vetor
  printf("Digite os elementos do vetor:\n");
  for (i = 0; i < tamanho; i++) {
      printf("Vetor[%d]: ", i );
      scanf("%f", &vetor[i]);
      
      // Soma o valor lido 
      soma += vetor[i];
  }

  // C�lculo da m�dia
  media = soma / tamanho;

  // Impress�o da m�dia com duas casas decimais
  printf("A media aritmetica dos valores eh: ");
  PRINTF("%.2f", media);
  printf("\n");

  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}