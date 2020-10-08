/**
* @file   Aula10.c
* @brief  Arquivo com a implementação dos exercícios da Aula 08.
* @author Leandro Maia Silva
* @date   2019-06-17
*/

/* Inclusões */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include "erros.h"

/* Tipos */
typedef uint8_t bool_t;

/* Constantes */
#define VERDADEIRO              (1 == 1)
#define FALSO                   (!VERDADEIRO)
#define TAMANHO_MAXIMO_STRING   (100 + 1)

// ------------------------------------------------------------------------------------------------

/**
* Exercício 01
* Fazer um programa para contar o número de espaços em brancos de
* uma string.
*/
void exercicio01(void) {

  unsigned int i;
  int nEspacos = 0;
  char texto[TAMANHO_MAXIMO_STRING];

  // Workaround para jogar o \n que está no stdin depois do scanf
  getchar(); 
             
  // Lê o texto do usuário
  printf("Digite o texto (ate 100 caracteres): ");
  fgets(texto, TAMANHO_MAXIMO_STRING, stdin);

  // Conta o número de espaços
  for (i = 0; i < strlen(texto); i++) {
    if (texto[i] == ' ') { 
      nEspacos++;  
    }
  }

  // Mostra o resultado
  printf("O texto digitado possui %u espaco(s).\n", nEspacos);
}

// ------------------------------------------------------------------------------------------------

/**
 * Exercício 02
 * Fazer um programa para imprimir uma string, recebida como entrada
 * do usuário, sem os espaços em branco.
 */
void exercicio02(void) {

  unsigned int i;
  char texto[TAMANHO_MAXIMO_STRING];

  // Workaround para jogar o \n que está no stdin depois do scanf
  getchar();

  // Lê o texto do usuário
  printf("Digite o texto (ate 100 caracteres): ");
  fgets(texto, TAMANHO_MAXIMO_STRING, stdin);

  // Imprime todos os caracteres, exceto espaço (' ')
  for (i = 0; i < strlen(texto); i++) {
    if (texto[i] == ' ') { continue; }

    // Se chegou aqui, não é espaço, então imprime.
    printf("%c", texto[i]);
  }
}

// ------------------------------------------------------------------------------------------------

static const char LISTA_VOGAIS[] = {'A','a','E','e','I','i','O','o','U','u'};

/**
 * Função que verifica se uma determinada letra é uma vogal.
 * @param letra Letra a ser verificada.
 * @return VERDADEIRO caso a letra seja uma vogal, ou caso contrário, FALSO.
 */
bool_t eVogal(char letra) {

  unsigned int i;

  for (i = 0; i < sizeof(LISTA_VOGAIS); i++) {
    if (letra == LISTA_VOGAIS[i]) return VERDADEIRO;
  }

  // Se chegou até aqui é porque não encontrou
  return FALSO;
}

/**
 * Exercício 03
 * Fazer um programa para contar o número de vogais numa string.
 */
void exercicio03(void) {

  unsigned int i;
  int nVogais = 0;
  char texto[TAMANHO_MAXIMO_STRING];

  // Workaround para jogar o \n que está no stdin depois do scanf
  getchar();

  // Lê o texto do usuário
  printf("Digite o texto (ate 100 caracteres): ");
  fgets(texto, TAMANHO_MAXIMO_STRING, stdin);

  // Conta o número de vogais
  for (i = 0; i < strlen(texto); i++) {
    if (eVogal(texto[i])) {
      nVogais++;
    }
  }

  // Mostra o resultado
  printf("O texto digitado possui %u vogal(is).\n", nVogais);

}

// ------------------------------------------------------------------------------------------------

/**
 * Exercício 04
 * Escrever um programa para ler uma string (com mais de uma palavra)
 * e faça com que a primeira letra de cada palavra que em maiúscula. Para
 * isso, basta subtrair 32 do elemento que deseja alterar para maiúsculo.
 */
void exercicio04(void) {

  unsigned int i;
  char texto[TAMANHO_MAXIMO_STRING];
  bool_t encontrouEspaco = VERDADEIRO;

  // Workaround para jogar o \n que está no stdin depois do scanf
  getchar();

  // Lê o texto do usuário
  printf("Digite o texto (ate 100 caracteres): ");
  fgets(texto, TAMANHO_MAXIMO_STRING, stdin);

  // O primeiro caractere depois de espaço fica maiúsculo
  for (i = 0; i < strlen(texto); i++) {
    if (texto[i] == ' ') { 
      encontrouEspaco = VERDADEIRO;
      continue; 
    }

    // Se encontrou espaço, troca para maiúscula
    if (encontrouEspaco) {
      if (texto[i] >= 'a' && texto[i] <= 'z') {
        texto[i] -= 0x20;
      }
      encontrouEspaco = FALSO;
    }

  }

  // Imprime o texto convertido
  printf("Texto convertido: %s", texto);
}

// ------------------------------------------------------------------------------------------------

/**
 * Exercício 05
 * Escreva um programa que receba uma string de tamanho máximo 100,
 * e verique se é um palíndromo. Uma palavra é dita ser um palíndromo se
 * a sequência de seus caracteres da esquerda para a direita é igual a
 * sequência de seus caracteres da direita para a esquerda. Ex: arara, asa.
 */
void exercicio05(void) {

  char texto[TAMANHO_MAXIMO_STRING];
  bool_t ePalindromo = VERDADEIRO;

  char * endFrenteTras;
  char * endTrasFrente;

  // Workaround para jogar o \n que está no stdin depois do scanf
  getchar();

  // Lê o texto do usuário
  printf("Digite o texto (ate 100 caracteres): ");
  endFrenteTras = fgets(texto, TAMANHO_MAXIMO_STRING, stdin);

  // Começando de trás pra frente, é o início + tamanho do texto - \n -1
  endTrasFrente = endFrenteTras + strlen(endFrenteTras) - 2;

  while (endFrenteTras < endTrasFrente) {

    if (*endFrenteTras != *endTrasFrente) {
      ePalindromo = FALSO;
      break;
    }

    endFrenteTras++;
    endTrasFrente--;
  }

  // Mostra se é ou não
  if (ePalindromo) {
    printf("O texto digitado EH palindromo.\n");
  } else {
    printf("O texto digitado NAO EH palindromo.\n");
  }

}

// ------------------------------------------------------------------------------------------------

/**
 * Exercício 06
 * Um palíndromo, além de uma palavra, pode ser uma frase ou qualquer outra
 * sequência de unidades que tenha a propriedade de poder ser lida tanto da
 * direita para a esquerda como da esquerda para a direita. Em um palíndromo,
 * normalmente são desconsiderados os sinais ortográcos, assim como o espaços
 * entre palavras. Alguns exemplos de palíndromos são:
 * - Socorram-me, subi no onibus em Marrocos
 * - Anotaram a data da maratona
 * - Dammit, I'm mad!
 * Faça um programa que leia uma frase e determine se ela é um palíndromo. Use
 * funções e/ou procedimentos.
 */
void exercicio06(void) {

  char texto[TAMANHO_MAXIMO_STRING];
  bool_t ePalindromo = VERDADEIRO;

  char * endFrenteTras;
  char * endTrasFrente;
  char char1, char2;

  // Workaround para jogar o \n que está no stdin depois do scanf
  getchar();

  // Lê o texto do usuário
  printf("Digite o texto (ate 100 caracteres): ");
  endFrenteTras = fgets(texto, TAMANHO_MAXIMO_STRING, stdin);

  // Começando de trás pra frente, é o início + tamanho do texto - \n -1
  endTrasFrente = endFrenteTras + strlen(endFrenteTras) - 2;

  while (endFrenteTras < endTrasFrente) {

    // Se não for letra ou número, ignoro
    if (!isalnum(*endFrenteTras)) {
      endFrenteTras++;
      continue;
    }
    if (!isalnum(*endTrasFrente)) {
      endTrasFrente--;
      continue;
    }

    // Se chegou até aqui, então ambos são caracteres válidos
    char1 = *endFrenteTras;
    char2 = *endTrasFrente;

    // Converte o caractere para minúsculo
    if (islower(char1)) char1 -= 0x20;
    if (islower(char2)) char2 -= 0x20;

    if (char1 != char2) {
      ePalindromo = FALSO;
      break;
    }

    endFrenteTras++;
    endTrasFrente--;
  }

  // Mostra se é ou não
  if (ePalindromo) {
    printf("O texto digitado EH palindromo.\n");
  }
  else {
    printf("O texto digitado NAO EH palindromo.\n");
  }

}

// ------------------------------------------------------------------------------------------------

/**
 * Função principal do programa onde o mesmo será iniciado.
 * @param argc Número de parâmetros.
 * @param argv Valores dos parâmetros.
 * @return SUCESSO caso o programa seja executado corretamente, ou caso contrário,
 * o código do erro ocorrido.
 */
int main(int argc, char ** argv) {

  int nExercicio;

  do {
    printf("Digite o numero do exercicio que quer executar [1:6]. 0 para sair: ");
    scanf("%d", &nExercicio);

    switch (nExercicio) {
      case 0: break;
      case 1: {
        exercicio01();
        break;
      }
      case 2: {
        exercicio02();
        break;
      }
      case 3: {
        exercicio03();
        break;
      }
      case 4: {
        exercicio04();
        break;
      }
      case 5: {
        exercicio05();
        break;
      }
      case 6: {
        exercicio06();
        break;
      }
      default: {
        printf("Voce escolheu um exercicio invalido.\n");
      }
    }

    // Adiciono uma quebra de linha para separar cada execução de exercício
    printf("\n");

  } while (nExercicio != 0);

  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}