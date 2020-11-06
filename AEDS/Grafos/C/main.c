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

  erro = grafoMA_cria(&grafo, 3, eGrafoDirecionado);


  erro = grafoMA_criaAresta(grafo, 0, 1, 88);
  erro = grafoMA_criaAresta(grafo, 0, 2, 85);
  erro = grafoMA_criaAresta(grafo, 1, 2, 19);
  erro = grafoMA_criaAresta(grafo, 2, 1, 8);


  grafoMA_imprime(grafo);
  grafoMA_imprimeListasAdjacencias(grafo);

  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}