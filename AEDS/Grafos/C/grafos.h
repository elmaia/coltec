/**
 * @file   grafos.h
 * @brief  Arquivo com a defini��o dos tipos e fun��es relacionados a grafos.
 * @author Leandro Maia Silva
 * @date   2020-11-03
 */

#pragma once
#ifndef __GRAFOS_h__
#define __GRAFOS_h__

/* Inclus�es */
#include <stdint.h>

/* Tipos */

// Tipo que representa um custo de uma aresta
typedef int32_t custo_t;

// Enumera��o com as possibilidade de tipos de grafo
enum tipoGrafo_e {
  eGrafoNaoDirecionado,
  eGrafoDirecionado
};

// Tipo que representa o "tipo do grafo"
typedef enum tipoGrafo_e tipoGrafo_t;

// Tipo que representa o "�ndice de um v�rtice"
typedef uint16_t vertice_t;

// Estrutura com as informa��es do tipo grafo
struct grafo_s {
  // Dados do grafo
  void * dados;
  // N�mero de v�rtices do grafo [1:65535]
  uint16_t nVertices;
  // Tipo do grafo (N�o direcionado ou direcionado)
  tipoGrafo_t tipo;
};

// Tipo representando um "grafo"
typedef struct grafo_s grafo_t;

/* Constantes */

// N�mero de erros reservados para erros de grafos
#define NUMERO_ERROS_GRAFOS     (16)
// Offset indicando a partir de qual n�mero come�am os erros de grafos
#define ERRO_GRAFOS_OFFSET      (32)

// Erro indicando que o �ndice do v�rtice � inv�lido
#define ERRO_VERTICE_INVALIDO   (ERRO_GRAFOS_OFFSET + 0)

// Valor indicando a aus�ncia de aresta
#define GRAFO_ARESTA_AUSENTE          (0x80000000)
// Valor indicando o custo infinito
#define GRAFO_ARESTA_CUSTO_INFINITO   (0x7FFFFFFF)

/* Erros */

/* Fun��es Exportadas */

#endif // __GRAFOS_h__