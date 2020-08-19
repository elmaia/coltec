/**
 * @file   listaORD.h
 * @brief  Arquivo com a definição do TAD Lista Encadeada Simples Ordenada.
 * @author Leandro Maia Silva
 * @date   2020-08-18
 */

#pragma once

#ifndef __LISTA_ORD_h__
#define __LISTA_ORD_h__

/* Inclusões */
#include <stdint.h>
#include "tipos.h"
#include "lista.h"

/* Tipos */

/// Estrutura com as informações de uma lista
struct listaORD_s {
  void * primeiro;
  uint32_t nItens;
  ComparaDadosItem_f comparador;
};

/// Tipo "Lista"
typedef struct listaORD_s listaORD_t;

/* Funções exportadas */
listaORD_t * listaORD_cria(ComparaDadosItem_f funcComparar);
void listaORD_destroi(listaORD_t * lista);
erro_t listaORD_insere(listaORD_t * lista, dadosItem info);
erro_t listaORD_removeElemento(listaORD_t * lista, dadosItem info);
erro_t listaORD_removePosicao(listaORD_t * lista, uint32_t posicao);
erro_t listaORD_busca(listaORD_t * lista, dadosItem info, uint32_t * posicao);
bool_t listaORD_estaVazia(listaORD_t * lista);
void listaORD_imprime(listaORD_t * lista);

#endif // __LISTA_ORD_h__
