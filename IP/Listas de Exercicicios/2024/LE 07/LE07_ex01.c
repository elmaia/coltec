/**
 * @file   LE07_ex01.c
 * @brief  Arquivo com a implementa��o de sugest�o de 
 *         solu��o do exerc�cio 01 da LE 07 de 2024.
 * @author Leandro Maia Silva
 * @date   2024-06-16
 */

/* Inclus�es */
#include <stdio.h>   // printf e scanf
#include <string.h>  // Fun��es de manipula��o de strings

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
 * Fun��o que conta quantidade de espa�os em branco o texto possui.
 * @param texto Texto a ser analisado.
 * @return Quantidade de espa�os em branco.
 */
unsigned int contaEspacosBranco(char texto[]) {
  
  int i;
  unsigned int nEspacos = 0;
  
  // Conta o n�mero de espa�os
  for (i = 0; i < strlen(texto); i++) {
    if (texto[i] == ' ') { 
      nEspacos++;  
    }
  }
  
  // Retorna a quantidade de espa�os em branco encontrados
  return nEspacos;
}



// Tamanho m�ximo do texto, considerando a quebra de linha e o '\0'
#define SOBRECARGA_TEXTO     (1)
#define TEXTO_TAMANHO_MAXIMO (100 + SOBRECARGA_TEXTO)

/**
 * Fa�a uma fun��o que leia uma string e conte quantos espa�os em branco ela possui.
 * Exemplo:
 * Entrada: �Introducao a Programacao\n�
 * Sa�da: 2
 */
int main(int argc, char ** argv) {
  
  char texto[TEXTO_TAMANHO_MAXIMO];
  unsigned int nEspacosBranco;
  
  // Intera��o com o usu�rio
  printf("Numero de espacos em branco\n");
  printf("Digite o texto a ser analizado (Ate %d caracteres)\n: ", TEXTO_TAMANHO_MAXIMO -SOBRECARGA_TEXTO);
  fgets(texto, TEXTO_TAMANHO_MAXIMO, stdin);
  util_removeQuebraLinhaFinal(texto);
  
  // Obtem a quantidade de espa�os em branco contido no texto
  nEspacosBranco = contaEspacosBranco(texto);
  
  // Mostra o resultado
  printf("O texto digitado possui ");
  PRINTF("%u", nEspacosBranco);
  printf(" espaco(s).\n");

  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}