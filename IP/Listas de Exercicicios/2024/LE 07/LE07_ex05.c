/**
 * @file   LE07_ex05.c
 * @brief  Arquivo com a implementa��o de sugest�o de 
 *         solu��o do exerc�cio 05 da LE 07 de 2024.
 * @author Leandro Maia Silva
 * @date   2024-06-16
 */

/* Inclus�es */
#include <stdio.h>   // printf e scanf
#include <string.h>  // Fun��es de manipula��o de strings
#include <stdbool.h> // Para o tipo bool e as constantes true e false

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
 * Fun��o para remover a quebra de linha final, caso exista, de uma cadeia de caracteres.
 * @param texto Texto a ser sua quebra de linha final removida.
 */
void util_removeQuebraLinhaFinal(char texto[]) {
  
  int tamanho = strlen(texto);
  
  if ((tamanho > 0) && (texto[tamanho -1] == '\n')) {
    texto[tamanho - 1] = '\0';
  }  
}

/**
 * Fun��o que verifica se uma palavra � um pal�ndromo.
 * @param texto Texto a ser analisado.
 * @return VERDADEIRO caso o texto seja um pal�ndromo, ou FALSO caso contr�rio.
 */
bool verificaPalindromo(char texto[]) {
  
  // Come�a pal�ndromo e se mant�m at� que alguma letra altere essa condi��o.
  bool ePalindromo = true;

  int posFrenteTras;
  int posTrasFrente;

  posFrenteTras = 0;

  // Come�ando de tr�s pra frente, � o in�cio + tamanho do texto -1
  posTrasFrente = strlen(texto) - 1;

  while (posFrenteTras < posTrasFrente) {

    if (texto[posFrenteTras] != texto[posTrasFrente]) {
      ePalindromo = false;
      break;
    }

    posFrenteTras++;
    posTrasFrente--;
  }
  
  // Retorna se � pal�ndromo ou n�o
  return ePalindromo;
}

// Tamanho m�ximo do texto, considerando a quebra de linha e o '\0'
#define SOBRECARGA_TEXTO     (1)
#define TEXTO_TAMANHO_MAXIMO (100 + SOBRECARGA_TEXTO)

/**
 * Fa�a uma fun��o que leia uma palavra e determine se ela � um pal�ndromo.
 * Uma palavra � dita ser um pal�ndromo se a sequ�ncia de caracteres da
 * esquerda para direita � a mesma da direita para esquerda.
 * Exemplos:
 * Entrada: �asa\n�
 * Sa�da: �Sim�
 * Entrada: �arara\n�
 * Sa�da: �Sim�
 * Entrada: �Programacao�
 * Sa�da: �Nao"
 */
int main(int argc, char ** argv) {
  
  char texto[TEXTO_TAMANHO_MAXIMO];
  bool ehPalindromo;
  
  // Intera��o com o usu�rio
  printf("Palavra Palindromo\n");
  printf("Digite o texto a ser analizado (Ate %d caracteres)\n: ", TEXTO_TAMANHO_MAXIMO -SOBRECARGA_TEXTO);
  fgets(texto, TEXTO_TAMANHO_MAXIMO, stdin);
  util_removeQuebraLinhaFinal(texto);  
  
  // Verifica se o texto � um pal�ndromo
  ehPalindromo = verificaPalindromo(texto);
  
  // Imprime se eh pal�ndromo
  printf("A palavra <%s> eh palindromo? ", texto);
  PRINTF("%s", ehPalindromo ? "Sim" : "Nao");
  printf("\n");

  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}