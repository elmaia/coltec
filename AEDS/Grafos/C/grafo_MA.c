/**
 * @file   grafo_MA.c
 * @brief  Arquivo com a implementação de grafos com matriz de adjacência
 * @author Leandro Maia Silva
 * @date   2020-11-03
 */

/* Inclusões */
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "tipos.h"
#include "erros.h"
#include "grafos.h"
#include "grafo_MA.h"

// Macro para acesso aos dados do grafo
#define GRAFO_DADOS(x) ((custo_t **)((x)->dados))

/**
 * Função que cria um grafo do tipo e com o número de vértices especificado.
 * @param grafo Apontador para o local que receberá o endereço do grafo criado.
 * @param nVertices Número de vértices que terá o grafo
 * @param tipo Tipo do grafo a ser criado.
 * @return SUCESSO caso o grafo seja criado corretamente, ou caso contrário,
 * o código do erro ocorrido.
 */
erro_t grafoMA_cria(grafo_t ** grafo, uint16_t nVertices, tipoGrafo_t tipo) {

  uint32_t i, j, limite;

  // Teste dos parâmetros
  if ((grafo == NULL) || (nVertices == 0)) {
    return ERRO_ARGUMENTO_INVALIDO;
  }

  // Aloco espaço para a estrutura do grafo
  *grafo = malloc(sizeof(grafo_t));
  if (*grafo == NULL) {
    return ERRO_ALOCACAO_MEMORIA;
  }

  // Aloco espaço para as "linhas"
  (*grafo)->dados = (custo_t **)malloc(sizeof(custo_t *) * nVertices);
  if (GRAFO_DADOS(*grafo) == NULL) {
    free(*grafo);
    return ERRO_ALOCACAO_MEMORIA;
  }

  // Aloco espaço para as colunas
  for (i = 0; i < nVertices; i++) {

    // Defino o limite dependendo se é direcionado ou não
    limite = (tipo == eGrafoDirecionado ? nVertices : i + 1);

    // Aloco espaço para as colunas
    GRAFO_DADOS(*grafo)[i] = (custo_t *)malloc(sizeof(custo_t) * limite);
    if (GRAFO_DADOS(*grafo)[i] == NULL) {
      for (j = 0; j < i; j++) {
        free(GRAFO_DADOS(*grafo)[j]);
      }
      free(GRAFO_DADOS(*grafo));
      free(*grafo);
      return ERRO_ALOCACAO_MEMORIA;
    }
  }

  // Se eu cheguei até aqui, então consegui alocar espaço para todo o grafo

  // Inicializa o grafo
  for (i = 0; i < nVertices; i++) {
    limite = (tipo == eGrafoDirecionado ? nVertices : i + 1);
    for (j = 0; j < limite; j++) {
      GRAFO_DADOS(*grafo)[i][j] = GRAFO_ARESTA_AUSENTE;
    }
  }

  // Inicializar os campos da estrutura
  (*grafo)->nVertices = nVertices;
  (*grafo)->tipo = tipo;

  // Se chegou até aqui é porque deu tudo certo
  return SUCESSO;
}

/**
 * Função que libera o espaço gasto pelo grafo.
 * @param grafo Apontador para o local que contem o endereço do grafo
 * a ser removido da memória.
 */
void grafoMA_destroi(grafo_t ** grafo) {

  uint32_t i, limite;

  // Libero o espaço das colunas
  for (i = 0; i < (*grafo)->nVertices; i++) {
    // Defino o limite dependendo se é direcionado ou não
    limite = ((*grafo)->tipo == eGrafoDirecionado ? (*grafo)->nVertices : i + 1);
    // Aloco espaço para as colunas
    free(GRAFO_DADOS(*grafo)[i]);
  }

  // Libero o espaço da linha
  free(GRAFO_DADOS(*grafo));

  // Libero o grafo
  free(*grafo);
}

/**
 *
 */
bool_t grafoMA_existeAresta(grafo_t ** grafo, vertice_t origem, vertice_t destino) {

  vertice_t vOrigem, vDestino;

  if ((origem > (*grafo)->nVertices) || (destino > (*grafo)->nVertices)) {
    return ERRO_VERTICE_INVALIDO;
  }

  // Teste para garantir que os índices estão dentro dos limites da matriz
  if ((*grafo)->tipo == eGrafoDirecionado) {
    vOrigem = origem;
    vDestino = destino;
  } else {
    if (origem < destino) {
      vOrigem = destino;
      vDestino = origem;
    } else {
      vOrigem = origem;
      vDestino = destino;
    }
  }

  // Os índices estão corretos em vOrigem e vDestino
  return (GRAFO_DADOS(*grafo)[vOrigem][vDestino] == GRAFO_ARESTA_AUSENTE ? FALSO : VERDADEIRO);
}

/**
 *
 */
erro_t grafoMA_criaAresta(grafo_t ** grafo, vertice_t origem, vertice_t destino, custo_t custo) {

  vertice_t vOrigem, vDestino;

  // Verifica se a aresta já existe
  if (grafoMA_existeAresta(grafo, origem, destino)) {
    return ERRO_ARESTA_EXISTENTE;
  }

  // Verifica se a aresta forma um self-loop
  if (origem == destino) {
    return ERRO_VERTICES_ORIGEM_DESTINO_IGUAIS;
  }

  // Se eu cheguei aqui, a aresta não existe e não é um self-loop

  // Teste para garantir que os índices estão dentro dos limites da matriz
  if ((*grafo)->tipo == eGrafoDirecionado) {
    vOrigem = origem;
    vDestino = destino;
  }
  else {
    if (origem < destino) {
      vOrigem = destino;
      vDestino = origem;
    }
    else {
      vOrigem = origem;
      vDestino = destino;
    }
  }

  // Crio a aresta com o custo especificado
  GRAFO_DADOS(*grafo)[vOrigem][vDestino] = custo;

  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}

/**
 *
 */
erro_t grafoMA_removerAresta(grafo_t ** grafo, vertice_t origem, vertice_t destino) {

  vertice_t vOrigem, vDestino;

  // Verifica se a aresta já existe
  if (!grafoMA_existeAresta(grafo, origem, destino)) {
    return ERRO_ARESTA_INEXISTENTE;
  }

  // Se eu cheguei aqui, a aresta existe

  // Teste para garantir que os índices estão dentro dos limites da matriz
  if ((*grafo)->tipo == eGrafoDirecionado) {
    vOrigem = origem;
    vDestino = destino;
  }
  else {
    if (origem < destino) {
      vOrigem = destino;
      vDestino = origem;
    }
    else {
      vOrigem = origem;
      vDestino = destino;
    }
  }

  // Removo a aresta com o custo especificado
  GRAFO_DADOS(*grafo)[vOrigem][vDestino] = GRAFO_ARESTA_AUSENTE;

  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}

/**
 *
 */
erro_t grafoMA_obtemCustoAresta(grafo_t ** grafo, vertice_t origem, vertice_t destino, custo_t * custo) {

  vertice_t vOrigem, vDestino;

  // Verifica se a aresta já existe
  if (!grafoMA_existeAresta(grafo, origem, destino)) {
    return ERRO_ARESTA_INEXISTENTE;
  }

  // Se eu cheguei aqui, a aresta existe

  // Teste para garantir que os índices estão dentro dos limites da matriz
  if ((*grafo)->tipo == eGrafoDirecionado) {
    vOrigem = origem;
    vDestino = destino;
  }
  else {
    if (origem < destino) {
      vOrigem = destino;
      vDestino = origem;
    }
    else {
      vOrigem = origem;
      vDestino = destino;
    }
  }

  // Removo a aresta com o custo especificado
  *custo = GRAFO_DADOS(*grafo)[vOrigem][vDestino];

  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}

void grafoMA_imprime(grafo_t ** grafo) {

  uint32_t i, j, limite;

  (void)printf("Imprimindo Grafo: Numero de Vertices: %-5d\n", (*grafo)->nVertices);
  (void)printf("-------------------------------------------\n");

  for (i = 0; i < (*grafo)->nVertices; i++) {
    limite = ((*grafo)->tipo == eGrafoDirecionado ? (*grafo)->nVertices : i + 1);
    for (j = 0; j < limite; j++) {

      // Se for direcionado     (origem -> destino : custo)
      // Se for não direcionado (origem -- destino : custo)
      (void)printf("%5d -%c %-5d : %11d\n", 
                   i, 
                   ((*grafo)->tipo == eGrafoDirecionado ? '>' : '-'), 
                   j, 
                   GRAFO_DADOS(*grafo)[i][j]
            );
    }
  }
}