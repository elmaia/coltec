/**
 * @file   main.c
 * @brief  Arquivo com a implementa��o da fun��o principal do programa.
 * @author Leandro Maia Silva
 * @date   2019-04-13
 */

/* Inclus�es */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "erros.h"


/**
 * Fun��o principal do programa onde o mesmo ser� iniciado.
 * @param argc N�mero de par�metros.
 * @param argv Valores dos par�metros.
 * @return SUCESSO caso o programa seja executado corretamente, ou caso contr�rio,
 * o c�digo do erro ocorrido.
 */
int main(int argc, char ** argv) {

  printf("Hello World!!!");

  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}