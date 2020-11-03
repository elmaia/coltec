/**
 * @file   grafo_MA.h
 * @brief  Arquivo com a definição dos tipos e funções relacionados a grafos
 *         representados com Matriz de Adjacência.
 * @author Leandro Maia Silva
 * @date   2020-11-03
 */

#pragma once
#ifndef __GRAFOS_MA_h__
#define __GRAFOS_MA_h__

/* Inclusões */
#include <stdint.h>
#include "tipos.h"
#include "erros.h"
#include "grafos.h"

/* Tipos */

/* Constantes */

/* Erros */

/* Funções Exportadas */
erro_t grafoMA_cria(grafo_t ** grafo, uint16_t nVertices, tipoGrafo_t tipo);
void grafoMA_destroi(grafo_t ** grafo);
bool_t grafoMA_existeAresta(grafo_t ** grafo, vertice_t origem, vertice_t destino);
erro_t grafoMA_criaAresta(grafo_t ** grafo, vertice_t origem, vertice_t destino, custo_t custo);
erro_t grafoMA_removerAresta(grafo_t ** grafo, vertice_t origem, vertice_t destino);
erro_t grafoMA_obtemCustoAresta(grafo_t ** grafo, vertice_t origem, vertice_t destino, custo_t * custo);
void grafoMA_imprime(grafo_t ** grafo);

#endif // __GRAFOS_MA_h__