/**
 * @file   LE07_ex06.c
 * @brief  Arquivo com a implementação de sugestão de 
 *         solução do exercício 06 da LE 07 de 2024.
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
 * Função que verifica se um texto é um palíndromo.
 * @param texto Texto a ser analisado.
 * @return VERDADEIRO caso o texto seja um palíndromo, ou FALSO caso contrário.
 */
bool verificaPalindromo(char texto[]) {
  
  // Começa palíndromo e se mantém até que alguma letra altere essa condição.
  bool ePalindromo = true;

  int posFrenteTras;
  int posTrasFrente;

  posFrenteTras = 0;

  // Começando de trás pra frente, é o início + tamanho do texto -1
  posTrasFrente = strlen(texto) - 1;

  while (posFrenteTras < posTrasFrente) {
    
    // Verifica se as posições possuem caracteres válidos (letras, não símbolos e números)
    if (!isalpha(texto[posFrenteTras])) {
      posFrenteTras++;
      continue;
    }
    if (!isalpha(texto[posTrasFrente])) {
      posTrasFrente--;
      continue;
    }

    // Se chegou até aqui, então estão comparando caracteres válidos
    // Faço a comparação sempre de minúsculo para evitar diferença entre A e a
    if (tolower(texto[posFrenteTras]) != tolower(texto[posTrasFrente])) {
      ePalindromo = false;
      break;
    }

    posFrenteTras++;
    posTrasFrente--;
  }
  
  // Retorna se é palíndromo ou não
  return ePalindromo;
}

// Tamanho máximo do texto, considerando a quebra de linha e o '\0'
#define SOBRECARGA_TEXTO     (1)
#define TEXTO_TAMANHO_MAXIMO (100 + SOBRECARGA_TEXTO)

/**
 * Faça uma função que leia uma string e determine se ela
 * é um palíndromo.
 * Um palíndromo, além de uma palavra (como no exercício anterior), pode
 * ser uma frase que tenha a propriedade de possuir a mesma sequência da
 * direita para esquerda quando da esquerda pra direita, excluindo os
 * separadores, hifens, virgulas e etc.
 * Exemplos:
 * Entrada: “Socorram-me, subi no onibus em Marrocos\n”
 * Saída: “Sim”
 * Entrada: “Anotaram a data da maratona\n”
 * Saída: “Sim”
 * Entrada: “Dammit, I'm mad!\n”
 * Saída: “Sim”
 * Entrada: “Introducao a Programacao\n”
 * Saída: “Nao"
 */
int main(int argc, char ** argv) {
  
  char texto[TEXTO_TAMANHO_MAXIMO];
  bool ehPalindromo;
  
  // Interação com o usuário
  printf("Texto Palindromo\n");
  printf("Digite o texto a ser analizado (Ate %d caracteres)\n: ", TEXTO_TAMANHO_MAXIMO -SOBRECARGA_TEXTO);
  fgets(texto, TEXTO_TAMANHO_MAXIMO, stdin);
  util_removeQuebraLinhaFinal(texto);  
  
  // Verifica se o texto é um palíndromo
  ehPalindromo = verificaPalindromo(texto);
  
  // Imprime se eh palíndromo
  printf("O texto <%s> eh palindromo? ", texto);
  PRINTF("%s", ehPalindromo ? "Sim" : "Nao");
  printf("\n");

  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}