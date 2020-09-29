/**
 * @file   main.c
 * @brief  Arquivo com a implementação da função principal do programa.
 * @author Leandro Maia Silva
 * @date   2019-04-13
 */

/* Inclusões */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "erros.h"


/**
 * Função principal do programa onde o mesmo será iniciado.
 * @param argc Número de parâmetros.
 * @param argv Valores dos parâmetros.
 * @return SUCESSO caso o programa seja executado corretamente, ou caso contrário,
 * o código do erro ocorrido.
 */
int main(int argc, char ** argv) {

  printf("Hello World!!!");

  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}