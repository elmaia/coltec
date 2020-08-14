/**
* @file   lista.h
* @brief  Arquivo com as definições comuns a todos os tipos de lista.
* @author Leandro Maia Silva
* @date   2020-08-13
*/

#pragma once

#ifndef __LISTA_h__
#define __LISTA_h__

/* Inclusões */

/* Constantes */

/// Número máximo de erros de lista permitidos
#define LISTA_ERROS_MAXIMO                (16)
/// Valor inicial a partir dos quais os erros de lista aparecem
#define LISTA_ERROS_OFFSET                (128) // [0x80:0x8F] / [128-143]

/* Erros */
#define ERRO_LISTA_POSICAO_INVALIDA       (LISTA_ERROS_OFFSET + 0)
#define ERRO_LISTA_ITEM_NAO_ENCONTRADO    (LISTA_ERROS_OFFSET + 1)

/* Tipos */

/// Tipo que representa os dados armazenados no item da lista
typedef int dadosItem;

#endif // __LISTA_h__
