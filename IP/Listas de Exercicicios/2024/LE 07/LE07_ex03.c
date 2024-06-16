/**
 * @file   LE07_ex03.c
 * @brief  Arquivo com a implementação de sugestão de 
 *         solução do exercício 03 da LE 07 de 2024.
 * @author Leandro Maia Silva
 * @date   2024-06-16
 */

/* Inclusões */
#include <stdio.h>   // printf e scanf
#include <string.h>  // Funções de manipulação de strings
#include <stdbool.h> // Para o tipo bool e as constantes true e false

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

// Lista de vogais
static const char LISTA_VOGAIS[] = {'A','a','E','e','I','i','O','o','U','u'};

/**
 * Função que verifica se uma determinada letra é uma vogal.
 * @param letra Letra a ser verificada.
 * @return VERDADEIRO caso a letra seja uma vogal, ou caso contrário, FALSO.
 */
bool ehVogal(char letra) {

  unsigned int i;

  for (i = 0; i < sizeof(LISTA_VOGAIS); i++) {
    if (letra == LISTA_VOGAIS[i]) return true;
  }

  // Se chegou até aqui é porque não encontrou
  return false;
}

/**
 * Função que conta a quantidade de vogais que o texto possui.
 * @param texto Texto a ser analisado.
 * @return Quantidade de vogais.
 */
unsigned int contaVogais(char texto[]) {
  
  int i;
  unsigned int nVogais = 0;
  
  // Conta o número de vogais
  for (i = 0; i < strlen(texto); i++) {
    if (ehVogal(texto[i])) {
      nVogais++;
    }
  }
  
  // Retorna a quantidade de vogais encontradas
  return nVogais;
}

// Tamanho máximo do texto, considerando a quebra de linha e o '\0'
#define SOBRECARGA_TEXTO     (1)
#define TEXTO_TAMANHO_MAXIMO (100 + SOBRECARGA_TEXTO)

/**
 * Faça uma função que leia uma string e conte o número de vogais presentes nela.
 * Exemplo:
 * Entrada: “Introducao a Programacao\n”
 * Saída: 11
 */
int main(int argc, char ** argv) {
  
  char texto[TEXTO_TAMANHO_MAXIMO];
  unsigned int nVogais;
  
  // Interação com o usuário
  printf("Numero de espacos em branco\n");
  printf("Digite o texto a ser analizado (Ate %d caracteres)\n: ", TEXTO_TAMANHO_MAXIMO -SOBRECARGA_TEXTO);
  fgets(texto, TEXTO_TAMANHO_MAXIMO, stdin);
  util_removeQuebraLinhaFinal(texto);
  
  // Obtem a quantidade de espaços em branco contido no texto
  nVogais = contaVogais(texto);
  
  // Mostra o resultado
  printf("O texto digitado possui ");
  PRINTF("%u", nVogais);
  printf(" vogal(is).\n");
  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}