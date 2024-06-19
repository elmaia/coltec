/**
 * @file   LE07_ex02.c
 * @brief  Arquivo com a implementa��o de sugest�o de 
 *         solu��o do exerc�cio 02 da LE 07 de 2024.
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
 * Imprime um texto sem imprimir os espa�os em branco.
 * @param texto Texto a ser impresso.
 */
void imprimeTextoSemEspacos(char texto[]) {
  
  int i;
  
  // Imprime todos os caracteres, exceto espa�o (' ')
  for (i = 0; i < strlen(texto); i++) {
    if (texto[i] == ' ') { continue; }

    // Se chegou aqui, n�o � espa�o, ent�o imprime.
    PRINTF("%c", texto[i]);
  }
}

// Tamanho m�ximo do texto, considerando a quebra de linha e o '\0'
#define SOBRECARGA_TEXTO     (1)
#define TEXTO_TAMANHO_MAXIMO (100 + SOBRECARGA_TEXTO)

/**
 * Fa�a uma fun��o que leia um string e que a imprima
 * removendo todos os espa�os em branco existentes.
 * Exemplo:
 * Entrada: �Introducao a Programacao\n�
 * Sa�da: �IntroducaoaProgramacao�
 */
int main(int argc, char ** argv) {
  
  char texto[TEXTO_TAMANHO_MAXIMO];
  
  // Intera��o com o usu�rio
  printf("Remove Espacos em Branco\n");
  printf("Digite o texto a ser analizado (Ate %d caracteres)\n: ", TEXTO_TAMANHO_MAXIMO -SOBRECARGA_TEXTO);
  fgets(texto, TEXTO_TAMANHO_MAXIMO, stdin);
  util_removeQuebraLinhaFinal(texto);
  
  // Imprime sem os espa�os
  imprimeTextoSemEspacos(texto);

  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}