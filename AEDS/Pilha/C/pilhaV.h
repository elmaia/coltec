/**
 * @file   pilhaV.h
 * @brief  Arquivo com a definição do TAD Pilha utilizando Vetor.
 * @author Leandro Maia Silva
 * @date   2020-08-18
 */

#pragma once

#ifndef __PILHA_V_h__
#define __PILHA_V_h__

/* Inclusões */
#include <stdint.h>
#include "tipos.h"
#include "pilha.h"

/* Tipos */

/// Estrutura com as informações de uma pilha
struct pilhaV_s {
  void * itens;
  uint32_t nItens;
  uint32_t capacidade;
};

/// Tipo "Pilha"
typedef struct pilhaV_s pilhaV_t;

/* Funções exportadas */
pilhaV_t * pilhaV_cria(uint32_t capacidade);
void pilhaV_destroi(pilhaV_t * pilha);
erro_t pilhaV_empilha(pilhaV_t * pilha, dadosItem info);
erro_t pilhaV_desempilha(pilhaV_t * pilha, dadosItem * info);
erro_t pilhaV_topo(pilhaV_t * pilha, dadosItem * topo);
erro_t pilhaV_busca(pilhaV_t * pilha, dadosItem info, uint32_t * posicao);
bool_t pilhaV_estaVazia(pilhaV_t * pilha);
void pilhaV_imprime(pilhaV_t * pilha);

#endif // __PILHA_V_h__
