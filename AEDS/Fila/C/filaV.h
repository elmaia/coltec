/**
 * @file   filaV.h
 * @brief  Arquivo com a definição do TAD Fila utilizando Vetor.
 * @author Leandro Maia Silva
 * @date   2020-08-25
 */

#pragma once

#ifndef __FILA_V_h__
#define __FILA_V_h__

/* Inclusões */
#include <stdint.h>
#include "tipos.h"
#include "fila.h"

/* Tipos */

/// Estrutura com as informações de uma fila
struct filaV_s {
  void * itens;
  uint32_t primeiro;
  uint32_t ultimo;
  uint32_t nItens;
  uint32_t capacidade;
};

/// Tipo "fila"
typedef struct filaV_s filaV_t;

/* Funções exportadas */
filaV_t * filaV_cria(uint32_t capacidade);
void filaV_destroi(filaV_t * fila);
erro_t filaV_insere(filaV_t * fila, dadosItem info);
erro_t filaV_remove(filaV_t * fila, dadosItem * info);
erro_t filaV_primeiro(filaV_t * fila, dadosItem * primeiro);
erro_t filaV_busca(filaV_t * fila, dadosItem info, uint32_t * posicao);
bool_t filaV_estaVazia(filaV_t * fila);
void filaV_imprime(filaV_t * fila);

#endif // __FILA_V_h__
