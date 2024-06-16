/**
 * @file   LE07_ex04.c
 * @brief  Arquivo com a implementa��o de sugest�o de 
 *         solu��o do exerc�cio 04 da LE 07 de 2024.
 * @author Leandro Maia Silva
 * @date   2024-06-16
 */

/* Inclus�es */
#include <stdio.h>   // printf e scanf
#include <string.h>  // Fun��es de manipula��o de strings
#include <stdbool.h> // Para o tipo bool e as constantes true e false
#include <ctype.h>   // Fun��es de manipula��o de caracteres

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
 * Fun��o que faz a inicial de cada palavra do texto ficar em mai�scula.
 * @param texto Texto a ser alterado.
 */
void converteTextoIniciaisMaiusculas(char texto[]) {
  
  unsigned int i;
  bool encontrouEspaco = true;

  // L� o texto do usu�rio

  // O primeiro caractere depois de espa�o fica mai�sculo
  for (i = 0; i < strlen(texto); i++) {
    if (texto[i] == ' ') { 
      encontrouEspaco = true;
      continue; 
    }

    // Se encontrou espa�o, troca para mai�scula
    if (encontrouEspaco) {
      texto[i] = toupper(texto[i]);
      encontrouEspaco = false;
    }
  }
}

// Tamanho m�ximo do texto, considerando a quebra de linha e o '\0'
#define SOBRECARGA_TEXTO     (1)
#define TEXTO_TAMANHO_MAXIMO (100 + SOBRECARGA_TEXTO)

/**
 * Fa�a uma fun��o que leia uma string de mais de uma
 * palavra e que fa�a com que cada palavra da string lida seja come�ada com
 * uma letra mai�scula.
 * Aten��o porque a letra pode j� ser mai�scula.
 * Exemplo:
 * Entrada: �Introducao a Programacao\n�
 * Sa�da: �Introducao A Programacao�
 */
int main(int argc, char ** argv) {
  
  char texto[TEXTO_TAMANHO_MAXIMO];
  
  // Intera��o com o usu�rio
  printf("Texto Iniciais Maiusculas\n");
  printf("Digite o texto a ser analizado (Ate %d caracteres)\n: ", TEXTO_TAMANHO_MAXIMO -SOBRECARGA_TEXTO);
  fgets(texto, TEXTO_TAMANHO_MAXIMO, stdin);
  util_removeQuebraLinhaFinal(texto);
  
  // Converte o texto para Title Case
  converteTextoIniciaisMaiusculas(texto);
  
  // Imprime o texto
  printf(": ");
  PRINTF("%s", texto);
  printf("\n");
  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}