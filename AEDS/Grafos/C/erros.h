/**
 * @file   erros.h
 * @brief  Arquivo com a defini��o dos erros gerais.
 * @author Leandro Maia Silva
 * @date   2020-11-03
 */

#pragma once
#ifndef __ERROS_h__
#define __ERROS_h__

// N�mero de erros reservados para erros gerais
#define NUMERO_ERROS_GERAIS     (32)
// Offset indicando a partir de qual n�mero come�am os erros de grafos
#define ERRO_GERAIS_OFFSET      (0)

// C�digo de erro indicando que a opera��o foi realizada conforme o esperado
#define SUCESSO                               (ERRO_GERAIS_OFFSET + 0)
// C�digo de erro indicando que n�o foi poss�vel alocar a mem�ria solicitada
#define ERRO_ALOCACAO_MEMORIA                 (ERRO_GERAIS_OFFSET + 1)
// C�digo de erro indicando que o argumento n�o � v�lido
#define ERRO_ARGUMENTO_INVALIDO               (ERRO_GERAIS_OFFSET + 2)
// C�digo de erro indicando que a aresta j� existe
#define ERRO_ARESTA_EXISTENTE                 (ERRO_GERAIS_OFFSET + 3)
// C�digo de erro indicando que origem e destino s�o iguais
#define ERRO_VERTICES_ORIGEM_DESTINO_IGUAIS   (ERRO_GERAIS_OFFSET + 4)
// C�digo de erro indicando que a aresta n�o existe
#define ERRO_ARESTA_INEXISTENTE               (ERRO_GERAIS_OFFSET + 5)

/* Tipos */

// Tipo que representa um c�digo de erro
typedef unsigned char erro_t;

#endif // __ERROS_h__