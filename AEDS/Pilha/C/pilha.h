/**
 * @file   pilha.h
 * @brief  Arquivo com as definições comuns a todos os tipos de pilha.
 * @author Leandro Maia Silva
 * @date   2020-08-18
 */

#pragma once

#ifndef __PILHA_h__
#define __PILHA_h__

/* Inclusões */

/* Constantes */

/// Número máximo de erros de lista permitidos
#define PILHA_ERROS_MAXIMO                (16)
/// Valor inicial a partir dos quais os erros de lista aparecem
#define PILHA_ERROS_OFFSET                (144) // [0x90:0x9F] / [144-159]

/* Erros */
#define ERRO_PILHA_VAZIA                  (PILHA_ERROS_OFFSET + 0)
#define ERRO_PILHA_ITEM_NAO_ENCONTRADO    (PILHA_ERROS_OFFSET + 1)
#define ERRO_PILHA_CHEIA                  (PILHA_ERROS_OFFSET + 2)

/* Tipos */

/// Tipo que representa os dados armazenados no item da PILHA
typedef int dadosItem;

#endif // __PILHA_h__
