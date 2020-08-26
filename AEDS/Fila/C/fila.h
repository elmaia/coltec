/**
 * @file   fila.h
 * @brief  Arquivo com as definições comuns a todos os tipos de fila.
 * @author Leandro Maia Silva
 * @date   2020-08-25
 */

#pragma once

#ifndef __FILA_h__
#define __FILA_h__

/* Inclusões */

/* Constantes */

/// Número máximo de erros de lista permitidos
#define FILA_ERROS_MAXIMO                (16)
/// Valor inicial a partir dos quais os erros de lista aparecem
#define FILA_ERROS_OFFSET                (160) // [0xA0:0xAF] / [160-175]

/* Erros */
#define ERRO_FILA_VAZIA                  (FILA_ERROS_OFFSET + 0)
#define ERRO_FILA_ITEM_NAO_ENCONTRADO    (FILA_ERROS_OFFSET + 1)
#define ERRO_FILA_CHEIA                  (FILA_ERROS_OFFSET + 2)

/* Tipos */

/// Tipo que representa os dados armazenados no item da fila
typedef int dadosItem;

#endif // __FILA_h__
