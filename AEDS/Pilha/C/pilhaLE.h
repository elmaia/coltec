/**
 * @file   pilhaLE.h
 * @brief  Arquivo com a definição do TAD Pilha utilizando Lista Encadeada.
 * @author Leandro Maia Silva
 * @date   2020-08-18
 */

#pragma once

#ifndef __PILHA_LE_h__
#define __PILHA_LE_h__

/* Inclusões */
#include <stdint.h>
#include "tipos.h"
#include "pilha.h"

/* Tipos */

/// Estrutura com as informações de uma pilha
struct pilhaLE_s {
  void * topo;
  uint32_t nItens;
};

/// Tipo "Pilha"
typedef struct pilhaLE_s pilhaLE_t;

/* Funções exportadas */
pilhaLE_t * pilhaLE_cria(void);
void pilhaLE_destroi(pilhaLE_t * pilha);
erro_t pilhaLE_empilha(pilhaLE_t * pilha, dadosItem info);
erro_t pilhaLE_desempilha(pilhaLE_t * pilha, dadosItem * info);
erro_t pilhaLE_topo(pilhaLE_t * pilha, dadosItem * topo);
erro_t pilhaLE_busca(pilhaLE_t * pilha, dadosItem info, uint32_t * posicao);
bool_t pilhaLE_estaVazia(pilhaLE_t * pilha);
void pilhaLE_imprime(pilhaLE_t * pilha);

#endif // __PILHA_LE_h__
