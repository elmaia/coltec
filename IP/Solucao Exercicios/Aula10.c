/**
* @file   Aula10.c
* @brief  Arquivo com a implementa��o dos exerc�cios da Aula 08.
* @author Leandro Maia Silva
* @date   2019-06-17
*/

/* Inclus�es */
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
* Exerc�cio 01
* Fazer um programa para contar o n�mero de espa�os em brancos de
* uma string.
*/
void exercicio01(void) {

  unsigned int i;
  int nEspacos = 0;
  char texto[TAMANHO_MAXIMO_STRING];

  // Workaround para jogar o \n que est� no stdin depois do scanf
  getchar(); 
             
  // L� o texto do usu�rio
  printf("Digite o texto (ate 100 caracteres): ");
  fgets(texto, TAMANHO_MAXIMO_STRING, stdin);

  // Conta o n�mero de espa�os
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
 * Exerc�cio 02
 * Fazer um programa para imprimir uma string, recebida como entrada
 * do usu�rio, sem os espa�os em branco.
 */
void exercicio02(void) {

  unsigned int i;
  char texto[TAMANHO_MAXIMO_STRING];

  // Workaround para jogar o \n que est� no stdin depois do scanf
  getchar();

  // L� o texto do usu�rio
  printf("Digite o texto (ate 100 caracteres): ");
  fgets(texto, TAMANHO_MAXIMO_STRING, stdin);

  // Imprime todos os caracteres, exceto espa�o (' ')
  for (i = 0; i < strlen(texto); i++) {
    if (texto[i] == ' ') { continue; }

    // Se chegou aqui, n�o � espa�o, ent�o imprime.
    printf("%c", texto[i]);
  }
}

// ------------------------------------------------------------------------------------------------

static const char LISTA_VOGAIS[] = {'A','a','E','e','I','i','O','o','U','u'};

/**
 * Fun��o que verifica se uma determinada letra � uma vogal.
 * @param letra Letra a ser verificada.
 * @return VERDADEIRO caso a letra seja uma vogal, ou caso contr�rio, FALSO.
 */
bool_t eVogal(char letra) {

  unsigned int i;

  for (i = 0; i < sizeof(LISTA_VOGAIS); i++) {
    if (letra == LISTA_VOGAIS[i]) return VERDADEIRO;
  }

  // Se chegou at� aqui � porque n�o encontrou
  return FALSO;
}

/**
 * Exerc�cio 03
 * Fazer um programa para contar o n�mero de vogais numa string.
 */
void exercicio03(void) {

  unsigned int i;
  int nVogais = 0;
  char texto[TAMANHO_MAXIMO_STRING];

  // Workaround para jogar o \n que est� no stdin depois do scanf
  getchar();

  // L� o texto do usu�rio
  printf("Digite o texto (ate 100 caracteres): ");
  fgets(texto, TAMANHO_MAXIMO_STRING, stdin);

  // Conta o n�mero de vogais
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
 * Exerc�cio 04
 * Escrever um programa para ler uma string (com mais de uma palavra)
 * e fa�a com que a primeira letra de cada palavra que em mai�scula. Para
 * isso, basta subtrair 32 do elemento que deseja alterar para mai�sculo.
 */
void exercicio04(void) {

  unsigned int i;
  char texto[TAMANHO_MAXIMO_STRING];
  bool_t encontrouEspaco = VERDADEIRO;

  // Workaround para jogar o \n que est� no stdin depois do scanf
  getchar();

  // L� o texto do usu�rio
  printf("Digite o texto (ate 100 caracteres): ");
  fgets(texto, TAMANHO_MAXIMO_STRING, stdin);

  // O primeiro caractere depois de espa�o fica mai�sculo
  for (i = 0; i < strlen(texto); i++) {
    if (texto[i] == ' ') { 
      encontrouEspaco = VERDADEIRO;
      continue; 
    }

    // Se encontrou espa�o, troca para mai�scula
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
 * Exerc�cio 05
 * Escreva um programa que receba uma string de tamanho m�ximo 100,
 * e verique se � um pal�ndromo. Uma palavra � dita ser um pal�ndromo se
 * a sequ�ncia de seus caracteres da esquerda para a direita � igual a
 * sequ�ncia de seus caracteres da direita para a esquerda. Ex: arara, asa.
 */
void exercicio05(void) {

  char texto[TAMANHO_MAXIMO_STRING];
  bool_t ePalindromo = VERDADEIRO;

  char * endFrenteTras;
  char * endTrasFrente;

  // Workaround para jogar o \n que est� no stdin depois do scanf
  getchar();

  // L� o texto do usu�rio
  printf("Digite o texto (ate 100 caracteres): ");
  endFrenteTras = fgets(texto, TAMANHO_MAXIMO_STRING, stdin);

  // Come�ando de tr�s pra frente, � o in�cio + tamanho do texto - \n -1
  endTrasFrente = endFrenteTras + strlen(endFrenteTras) - 2;

  while (endFrenteTras < endTrasFrente) {

    if (*endFrenteTras != *endTrasFrente) {
      ePalindromo = FALSO;
      break;
    }

    endFrenteTras++;
    endTrasFrente--;
  }

  // Mostra se � ou n�o
  if (ePalindromo) {
    printf("O texto digitado EH palindromo.\n");
  } else {
    printf("O texto digitado NAO EH palindromo.\n");
  }

}

// ------------------------------------------------------------------------------------------------

/**
 * Exerc�cio 06
 * Um pal�ndromo, al�m de uma palavra, pode ser uma frase ou qualquer outra
 * sequ�ncia de unidades que tenha a propriedade de poder ser lida tanto da
 * direita para a esquerda como da esquerda para a direita. Em um pal�ndromo,
 * normalmente s�o desconsiderados os sinais ortogr�cos, assim como o espa�os
 * entre palavras. Alguns exemplos de pal�ndromos s�o:
 * - Socorram-me, subi no onibus em Marrocos
 * - Anotaram a data da maratona
 * - Dammit, I'm mad!
 * Fa�a um programa que leia uma frase e determine se ela � um pal�ndromo. Use
 * fun��es e/ou procedimentos.
 */
void exercicio06(void) {

  char texto[TAMANHO_MAXIMO_STRING];
  bool_t ePalindromo = VERDADEIRO;

  char * endFrenteTras;
  char * endTrasFrente;
  char char1, char2;

  // Workaround para jogar o \n que est� no stdin depois do scanf
  getchar();

  // L� o texto do usu�rio
  printf("Digite o texto (ate 100 caracteres): ");
  endFrenteTras = fgets(texto, TAMANHO_MAXIMO_STRING, stdin);

  // Come�ando de tr�s pra frente, � o in�cio + tamanho do texto - \n -1
  endTrasFrente = endFrenteTras + strlen(endFrenteTras) - 2;

  while (endFrenteTras < endTrasFrente) {

    // Se n�o for letra ou n�mero, ignoro
    if (!isalnum(*endFrenteTras)) {
      endFrenteTras++;
      continue;
    }
    if (!isalnum(*endTrasFrente)) {
      endTrasFrente--;
      continue;
    }

    // Se chegou at� aqui, ent�o ambos s�o caracteres v�lidos
    char1 = *endFrenteTras;
    char2 = *endTrasFrente;

    // Converte o caractere para min�sculo
    if (islower(char1)) char1 -= 0x20;
    if (islower(char2)) char2 -= 0x20;

    if (char1 != char2) {
      ePalindromo = FALSO;
      break;
    }

    endFrenteTras++;
    endTrasFrente--;
  }

  // Mostra se � ou n�o
  if (ePalindromo) {
    printf("O texto digitado EH palindromo.\n");
  }
  else {
    printf("O texto digitado NAO EH palindromo.\n");
  }

}

// ------------------------------------------------------------------------------------------------

/**
 * Fun��o principal do programa onde o mesmo ser� iniciado.
 * @param argc N�mero de par�metros.
 * @param argv Valores dos par�metros.
 * @return SUCESSO caso o programa seja executado corretamente, ou caso contr�rio,
 * o c�digo do erro ocorrido.
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

    // Adiciono uma quebra de linha para separar cada execu��o de exerc�cio
    printf("\n");

  } while (nExercicio != 0);

  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}