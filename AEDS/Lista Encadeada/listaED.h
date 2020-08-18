/**
* @file   listaED.h
* @brief  Arquivo com a definição do TAD Lista Duplamente Encadeada.
* @author Leandro Maia Silva
* @date   2020-08-17
*/

#pragma once

#ifndef __LISTA_ED_h__
#define __LISTA_ED_h__

/* Inclusões */
#include <stdint.h>
#include "tipos.h"
#include "lista.h"

/* Tipos */

/// Estrutura com as informações de uma lista
struct listaED_s {
  void * primeiro;
  uint32_t nItens;
};

/// Tipo "Lista"
typedef struct listaED_s listaED_t;

/* Funções exportadas */
listaED_t * listaED_cria(void);
void listaED_destroi(listaED_t * lista);
erro_t listaED_insereInicio(listaED_t * lista, dadosItem info);
erro_t listaED_insereFinal(listaED_t * lista, dadosItem info);
erro_t listaED_insereNesimaPosicao(listaED_t * lista, dadosItem info, uint32_t posicao);
erro_t listaED_removeElemento(listaED_t * lista, dadosItem info);
erro_t listaED_removePosicao(listaED_t * lista, uint32_t posicao);
erro_t listaED_busca(listaED_t * lista, dadosItem info, uint32_t * posicao);
bool_t listaED_estaVazia(listaED_t * lista);
void listaED_imprime(listaED_t * lista);

#endif // __LISTA_ED_h__
