/**
 * @file   erros.h
 * @brief  Arquivo com a definição dos erros gerais.
 * @author Leandro Maia Silva
 * @date   2020-11-03
 */

#pragma once
#ifndef __ERROS_h__
#define __ERROS_h__

// Número de erros reservados para erros gerais
#define NUMERO_ERROS_GERAIS     (32)
// Offset indicando a partir de qual número começam os erros de grafos
#define ERRO_GERAIS_OFFSET      (0)

// Código de erro indicando que a operação foi realizada conforme o esperado
#define SUCESSO                               (ERRO_GERAIS_OFFSET + 0)
// Código de erro indicando que não foi possível alocar a memória solicitada
#define ERRO_ALOCACAO_MEMORIA                 (ERRO_GERAIS_OFFSET + 1)
// Código de erro indicando que o argumento não é válido
#define ERRO_ARGUMENTO_INVALIDO               (ERRO_GERAIS_OFFSET + 2)
// Código de erro indicando que a aresta já existe
#define ERRO_ARESTA_EXISTENTE                 (ERRO_GERAIS_OFFSET + 3)
// Código de erro indicando que origem e destino são iguais
#define ERRO_VERTICES_ORIGEM_DESTINO_IGUAIS   (ERRO_GERAIS_OFFSET + 4)
// Código de erro indicando que a aresta não existe
#define ERRO_ARESTA_INEXISTENTE               (ERRO_GERAIS_OFFSET + 5)

/* Tipos */

// Tipo que representa um código de erro
typedef unsigned char erro_t;

#endif // __ERROS_h__