/**
 * @file   LE07_ex01.c
 * @brief  Arquivo com a implementação de sugestão de 
 *         solução do exercício 01 da LE 07 de 2024.
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
 * Função que conta quantidade de espaços em branco o texto possui.
 * @param texto Texto a ser analisado.
 * @return Quantidade de espaços em branco.
 */
unsigned int contaEspacosBranco(char texto[]) {
  
  int i;
  unsigned int nEspacos = 0;
  
  // Conta o número de espaços
  for (i = 0; i < strlen(texto); i++) {
    if (texto[i] == ' ') { 
      nEspacos++;  
    }
  }
  
  // Retorna a quantidade de espaços em branco encontrados
  return nEspacos;
}



// Tamanho máximo do texto, considerando a quebra de linha e o '\0'
#define SOBRECARGA_TEXTO     (1)
#define TEXTO_TAMANHO_MAXIMO (100 + SOBRECARGA_TEXTO)

/**
 * Faça uma função que leia uma string e conte quantos espaços em branco ela possui.
 * Exemplo:
 * Entrada: “Introducao a Programacao\n”
 * Saída: 2
 */
int main(int argc, char ** argv) {
  
  char texto[TEXTO_TAMANHO_MAXIMO];
  unsigned int nEspacosBranco;
  
  // Interação com o usuário
  printf("Numero de espacos em branco\n");
  printf("Digite o texto a ser analizado (Ate %d caracteres)\n: ", TEXTO_TAMANHO_MAXIMO -SOBRECARGA_TEXTO);
  fgets(texto, TEXTO_TAMANHO_MAXIMO, stdin);
  util_removeQuebraLinhaFinal(texto);
  
  // Obtem a quantidade de espaços em branco contido no texto
  nEspacosBranco = contaEspacosBranco(texto);
  
  // Mostra o resultado
  printf("O texto digitado possui ");
  PRINTF("%u", nEspacosBranco);
  printf(" espaco(s).\n");

  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}