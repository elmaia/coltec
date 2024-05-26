/**
 * @file   LE05_ex06.c
 * @brief  Arquivo com a implementa��o de sugest�o de 
 *         solu��o do exerc�cio 06 da LE 05 de 2024.
 * @author Leandro Maia Silva
 * @date   2024-05-24
 */

/* Inclus�es */
#include <stdio.h>   // printf e scanf
#include <stdint.h>  // Para usar uint64_t ao inv�s de unsigned long long int

/* Constantes */

// Constante que associa o c�digo de erro 0 ao significado de sucesso
#define SUCESSO                 0
// Constante que associa o c�digo de erro 1 � entrada inv�lida
#define ERRO_ENTRADA_INVALIDA  1

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

#define TRIANGULO_PASCAL_ALTURA_MAXIMA         10
#define TRIANGULO_PASCAL_MAIOR_VALOR          252
#define TRIANGULO_PASCAL_LARGURA_MAIOR_VALOR    3

uint64_t elementoTrianguloPascal(int linha, int coluna) {
  
  uint64_t elemento;
  
  // elemento = linha! / (coluna! * (linha - coluna)!)
  elemento = fatorial(linha) / (fatorial(coluna) * fatorial(linha - coluna));
  
  return elemento;
}

void imprimeTrianguloPascal(int altura) {
    
  int i, j;
    
  // Imprime o triangulo
  for(i = 0; i <= altura; i++) {
    for(j = 0; j <= i; j++) {
      PRINTF(" %*llu", TRIANGULO_PASCAL_LARGURA_MAIOR_VALOR, elementoTrianguloPascal(i,j));
    }
    
    // Imprime a quebra de linha
    PRINTF("%s","\n");
  }}

/**
 *  Fa�a uma fun��o que calcule um elemento do tri�ngulo de Pascal.
 *  Utilize essa fun��o para imprimir o tri�ngulo com alturas variando de 0
 *  a 10.
 */
int main(int argc, char ** argv) {
    
  int altura;

  // Obtem a altura
  printf("Triangulo de Pascal.\n");
  printf("Digite a altura [0:%d]: ", TRIANGULO_PASCAL_ALTURA_MAXIMA);
  scanf("%d", &altura);
  
  // Verifica a faixa
  if ((altura < 0) || (altura > TRIANGULO_PASCAL_ALTURA_MAXIMA)) {
    PRINTF("%s", "Altura invalida");
    printf(".\n");
    return ERRO_ENTRADA_INVALIDA;
  }
  
  // Imprime o tri�ngulo de pascal
  imprimeTrianguloPascal(altura);
  
  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}