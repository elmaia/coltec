/**
 * @file   grafo_MA.c
 * @brief  Arquivo com a implementa��o de grafos com matriz de adjac�ncia
 * @author Leandro Maia Silva
 * @date   2020-11-03
 */

/* Inclus�es */
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
 * Fun��o que cria um grafo do tipo e com o n�mero de v�rtices especificado.
 * @param grafo Apontador para o local que receber� o endere�o do grafo criado.
 * @param nVertices N�mero de v�rtices que ter� o grafo
 * @param tipo Tipo do grafo a ser criado.
 * @return SUCESSO caso o grafo seja criado corretamente, ou caso contr�rio,
 * o c�digo do erro ocorrido.
 */
erro_t grafoMA_cria(grafo_t ** grafo, uint16_t nVertices, tipoGrafo_t tipo) {

  uint32_t i, j, limite;

  // Teste dos par�metros
  if ((grafo == NULL) || (nVertices == 0)) {
    return ERRO_ARGUMENTO_INVALIDO;
  }

  // Aloco espa�o para a estrutura do grafo
  *grafo = malloc(sizeof(grafo_t));
  if (*grafo == NULL) {
    return ERRO_ALOCACAO_MEMORIA;
  }

  // Aloco espa�o para as "linhas"
  (*grafo)->dados = (custo_t **)malloc(sizeof(custo_t *) * nVertices);
  if (GRAFO_DADOS(*grafo) == NULL) {
    free(*grafo);
    return ERRO_ALOCACAO_MEMORIA;
  }

  // Aloco espa�o para as colunas
  for (i = 0; i < nVertices; i++) {

    // Defino o limite dependendo se � direcionado ou n�o
    limite = (tipo == eGrafoDirecionado ? nVertices : i + 1);

    // Aloco espa�o para as colunas
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

  // Se eu cheguei at� aqui, ent�o consegui alocar espa�o para todo o grafo

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

  // Se chegou at� aqui � porque deu tudo certo
  return SUCESSO;
}

/**
 * Fun��o que libera o espa�o gasto pelo grafo.
 * @param grafo Apontador para o local que contem o endere�o do grafo
 * a ser removido da mem�ria.
 */
void grafoMA_destroi(grafo_t ** grafo) {

  uint32_t i, limite;

  // Libero o espa�o das colunas
  for (i = 0; i < (*grafo)->nVertices; i++) {
    // Defino o limite dependendo se � direcionado ou n�o
    limite = ((*grafo)->tipo == eGrafoDirecionado ? (*grafo)->nVertices : i + 1);
    // Aloco espa�o para as colunas
    free(GRAFO_DADOS(*grafo)[i]);
  }

  // Libero o espa�o da linha
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

  // Teste para garantir que os �ndices est�o dentro dos limites da matriz
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

  // Os �ndices est�o corretos em vOrigem e vDestino
  return (GRAFO_DADOS(*grafo)[vOrigem][vDestino] == GRAFO_ARESTA_AUSENTE ? FALSO : VERDADEIRO);
}

/**
 *
 */
erro_t grafoMA_criaAresta(grafo_t ** grafo, vertice_t origem, vertice_t destino, custo_t custo) {

  vertice_t vOrigem, vDestino;

  // Verifica se a aresta j� existe
  if (grafoMA_existeAresta(grafo, origem, destino)) {
    return ERRO_ARESTA_EXISTENTE;
  }

  // Verifica se a aresta forma um self-loop
  if (origem == destino) {
    return ERRO_VERTICES_ORIGEM_DESTINO_IGUAIS;
  }

  // Se eu cheguei aqui, a aresta n�o existe e n�o � um self-loop

  // Teste para garantir que os �ndices est�o dentro dos limites da matriz
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

  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}

/**
 *
 */
erro_t grafoMA_removerAresta(grafo_t ** grafo, vertice_t origem, vertice_t destino) {

  vertice_t vOrigem, vDestino;

  // Verifica se a aresta j� existe
  if (!grafoMA_existeAresta(grafo, origem, destino)) {
    return ERRO_ARESTA_INEXISTENTE;
  }

  // Se eu cheguei aqui, a aresta existe

  // Teste para garantir que os �ndices est�o dentro dos limites da matriz
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

  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}

/**
 *
 */
erro_t grafoMA_obtemCustoAresta(grafo_t ** grafo, vertice_t origem, vertice_t destino, custo_t * custo) {

  vertice_t vOrigem, vDestino;

  // Verifica se a aresta j� existe
  if (!grafoMA_existeAresta(grafo, origem, destino)) {
    return ERRO_ARESTA_INEXISTENTE;
  }

  // Se eu cheguei aqui, a aresta existe

  // Teste para garantir que os �ndices est�o dentro dos limites da matriz
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

  // Se chegou at� aqui � porque correu tudo bem
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
      // Se for n�o direcionado (origem -- destino : custo)
      (void)printf("%5d -%c %-5d : %11d\n", 
                   i, 
                   ((*grafo)->tipo == eGrafoDirecionado ? '>' : '-'), 
                   j, 
                   GRAFO_DADOS(*grafo)[i][j]
            );
    }
  }
}