/**
 * @file   LE07_ex02.c
 * @brief  Arquivo com a implementação de sugestão de 
 *         solução do exercício 02 da LE 07 de 2024.
 * @author Leandro Maia Silva
 * @date   2024-06-16
 */

/* Inclusões */
#include <stdio.h>   // printf e scanf
#include <string.h>  // Funções de manipulação de strings

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
 * Imprime um texto sem imprimir os espaços em branco.
 * @param texto Texto a ser impresso.
 */
void imprimeTextoSemEspacos(char texto[]) {
  
  int i;
  
  // Imprime todos os caracteres, exceto espaço (' ')
  for (i = 0; i < strlen(texto); i++) {
    if (texto[i] == ' ') { continue; }

    // Se chegou aqui, não é espaço, então imprime.
    PRINTF("%c", texto[i]);
  }
}

// Tamanho máximo do texto, considerando a quebra de linha e o '\0'
#define SOBRECARGA_TEXTO     (1)
#define TEXTO_TAMANHO_MAXIMO (100 + SOBRECARGA_TEXTO)

/**
 * Faça uma função que leia um string e que a imprima
 * removendo todos os espaços em branco existentes.
 * Exemplo:
 * Entrada: “Introducao a Programacao\n”
 * Saída: “IntroducaoaProgramacao”
 */
int main(int argc, char ** argv) {
  
  char texto[TEXTO_TAMANHO_MAXIMO];
  
  // Interação com o usuário
  printf("Remove Espacos em Branco\n");
  printf("Digite o texto a ser analizado (Ate %d caracteres)\n: ", TEXTO_TAMANHO_MAXIMO -SOBRECARGA_TEXTO);
  fgets(texto, TEXTO_TAMANHO_MAXIMO, stdin);
  util_removeQuebraLinhaFinal(texto);
  
  // Imprime sem os espaços
  imprimeTextoSemEspacos(texto);

  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}