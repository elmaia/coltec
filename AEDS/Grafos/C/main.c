/**
 * @file   main.c
 * @brief  Arquivo com a implentação das funções de entrada no sistema.
 * @author Leandro Maia Silva
 * @date   2020-11-03
 */

/* Inclusões */
#include "erros.h"
#include "grafo_MA.h"

int main(int argc, char ** argv) {

  grafo_t * grafo;
  erro_t erro;

  erro = grafoMA_cria(&grafo, 3, eGrafoNaoDirecionado);


  erro = grafoMA_criaAresta(&grafo, 1, 2, 88);

  grafoMA_imprime(&grafo);

  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}