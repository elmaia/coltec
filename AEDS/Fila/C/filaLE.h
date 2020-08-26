/**
 * @file   filaLE.h
 * @brief  Arquivo com a definição do TAD Fila utilizando Lista Encadeada.
 * @author Leandro Maia Silva
 * @date   2020-08-25
 */

#pragma once

#ifndef __FILA_LE_h__
#define __FILA_LE_h__

/* Inclusões */
#include <stdint.h>
#include "tipos.h"
#include "fila.h"

/* Tipos */

/// Estrutura com as informações de uma fila
struct filaLE_s {
  void * primeiro;
  void * ultimo;
  uint32_t nItens;
};

/// Tipo "fila"
typedef struct filaLE_s filaLE_t;

/* Funções exportadas */
filaLE_t * filaLE_cria(void);
void filaLE_destroi(filaLE_t * fila);
erro_t filaLE_insere(filaLE_t * fila, dadosItem info);
erro_t filaLE_remove(filaLE_t * fila, dadosItem * info);
erro_t filaLE_primeiro(filaLE_t * fila, dadosItem * primeiro);
erro_t filaLE_busca(filaLE_t * fila, dadosItem info, uint32_t * posicao);
bool_t filaLE_estaVazia(filaLE_t * fila);
void filaLE_imprime(filaLE_t * fila);

#endif // __FILA_LE_h__
