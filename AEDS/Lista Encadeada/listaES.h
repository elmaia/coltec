/**
 * @file   listaES.h
 * @brief  Arquivo com a definição do TAD Lista Encadeada Simples.
 * @author Leandro Maia Silva
 * @date   2020-02-19
 */

#pragma once

#ifndef __LISTA_ES_h__
#define __LISTA_ES_h__

/* Inclusões */
#include <stdint.h>
#include "tipos.h"
#include "lista.h"

/* Tipos */

/// Estrutura com as informações de uma lista
struct listaES_s {
  void * primeiro;
  uint32_t nItens;
};

/// Tipo "Lista"
typedef struct listaES_s listaES_t;

/* Funções exportadas */
listaES_t * listaES_cria(void);
void listaES_destroi(listaES_t * lista);
erro_t listaES_insereInicio(listaES_t * lista, dadosItem info);
erro_t listaES_insereFinal(listaES_t * lista, dadosItem info);
erro_t listaES_insereNesimaPosicao(listaES_t * lista, dadosItem info, uint32_t posicao);
erro_t listaES_removeElemento(listaES_t * lista, dadosItem info);
erro_t listaES_removePosicao(listaES_t * lista, uint32_t posicao);
erro_t listaES_busca(listaES_t * lista, dadosItem info, uint32_t * posicao);
bool_t listaES_estaVazia(listaES_t * lista);
void listaES_imprime(listaES_t * lista);

#endif // __LISTA_ES_h__
