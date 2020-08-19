/**
 * @file   tipos.h
 * @brief  Arquivo com a definição de tipos globais.
 * @author Leandro Maia Silva
 * @date   2020-02-19
 */

#pragma once

#ifndef __TIPOS_h__
#define __TIPOS_h__

/// Definição de verdadeiro e falso
#define VERDADEIRO (1== 1)
#define FALSO      (!VERDADEIRO)

/// Representação de um tipo booleano
typedef unsigned char bool_t;

/// Representação de um tipo que armazena um código de erro
typedef unsigned char erro_t;

#endif // __TIPOS_h__

