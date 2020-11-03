/**
 * @file   grafos.h
 * @brief  Arquivo com a definição dos tipos e funções relacionados a grafos.
 * @author Leandro Maia Silva
 * @date   2020-11-03
 */

#pragma once
#ifndef __GRAFOS_h__
#define __GRAFOS_h__

/* Inclusões */
#include <stdint.h>

/* Tipos */

// Tipo que representa um custo de uma aresta
typedef int32_t custo_t;

// Enumeração com as possibilidade de tipos de grafo
enum tipoGrafo_e {
  eGrafoNaoDirecionado,
  eGrafoDirecionado
};

// Tipo que representa o "tipo do grafo"
typedef enum tipoGrafo_e tipoGrafo_t;

// Tipo que representa o "índice de um vértice"
typedef uint16_t vertice_t;

// Estrutura com as informações do tipo grafo
struct grafo_s {
  // Dados do grafo
  void * dados;
  // Número de vértices do grafo [1:65535]
  uint16_t nVertices;
  // Tipo do grafo (Não direcionado ou direcionado)
  tipoGrafo_t tipo;
};

// Tipo representando um "grafo"
typedef struct grafo_s grafo_t;

/* Constantes */

// Número de erros reservados para erros de grafos
#define NUMERO_ERROS_GRAFOS     (16)
// Offset indicando a partir de qual número começam os erros de grafos
#define ERRO_GRAFOS_OFFSET      (32)

// Erro indicando que o índice do vértice é inválido
#define ERRO_VERTICE_INVALIDO   (ERRO_GRAFOS_OFFSET + 0)

// Valor indicando a ausência de aresta
#define GRAFO_ARESTA_AUSENTE          (0x80000000)
// Valor indicando o custo infinito
#define GRAFO_ARESTA_CUSTO_INFINITO   (0x7FFFFFFF)

/* Erros */

/* Funções Exportadas */

#endif // __GRAFOS_h__