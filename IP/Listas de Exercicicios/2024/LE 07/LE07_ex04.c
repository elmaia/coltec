/**
 * @file   LE07_ex04.c
 * @brief  Arquivo com a implementação de sugestão de 
 *         solução do exercício 04 da LE 07 de 2024.
 * @author Leandro Maia Silva
 * @date   2024-06-16
 */

/* Inclusões */
#include <stdio.h>   // printf e scanf
#include <string.h>  // Funções de manipulação de strings
#include <stdbool.h> // Para o tipo bool e as constantes true e false
#include <ctype.h>   // Funções de manipulação de caracteres

/* Constantes */

// Constante que associa o código de erro 0 ao significado de sucesso
#define SUCESSO  0

// ----------------------------------------------------------------------

/**
 * Macro para utilização do canal de saída de erro como
 * saída de texto para testes automáticos.
 */
#ifdef TESTADOR
  #define PRINTF(format, ...) fprintf(stderr, format, __VA_ARGS__)
#else
  #define PRINTF(format, ...) printf(format, __VA_ARGS__)
#endif

// ----------------------------------------------------------------------

/**
 * Função para remover a quebra de linha final, caso exista, de uma cadeia de caracteres.
 * @param texto Texto a ser sua quebra de linha final removida.
 */
void util_removeQuebraLinhaFinal(char texto[]) {
  
  int tamanho = strlen(texto);
  
  if ((tamanho > 0) && (texto[tamanho -1] == '\n')) {
    texto[tamanho - 1] = '\0';
  }  
}

/**
 * Função que faz a inicial de cada palavra do texto ficar em maiúscula.
 * @param texto Texto a ser alterado.
 */
void converteTextoIniciaisMaiusculas(char texto[]) {
  
  unsigned int i;
  bool encontrouEspaco = true;

  // Lê o texto do usuário

  // O primeiro caractere depois de espaço fica maiúsculo
  for (i = 0; i < strlen(texto); i++) {
    if (texto[i] == ' ') { 
      encontrouEspaco = true;
      continue; 
    }

    // Se encontrou espaço, troca para maiúscula
    if (encontrouEspaco) {
      texto[i] = toupper(texto[i]);
      encontrouEspaco = false;
    }
  }
}

// Tamanho máximo do texto, considerando a quebra de linha e o '\0'
#define SOBRECARGA_TEXTO     (1)
#define TEXTO_TAMANHO_MAXIMO (100 + SOBRECARGA_TEXTO)

/**
 * Faça uma função que leia uma string de mais de uma
 * palavra e que faça com que cada palavra da string lida seja começada com
 * uma letra maiúscula.
 * Atenção porque a letra pode já ser maiúscula.
 * Exemplo:
 * Entrada: “Introducao a Programacao\n”
 * Saída: “Introducao A Programacao”
 */
int main(int argc, char ** argv) {
  
  char texto[TEXTO_TAMANHO_MAXIMO];
  
  // Interação com o usuário
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
  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}