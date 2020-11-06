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
 * Função auxiliar para ajuste das coordenadas dos vértices na matriz.
 * @param grafo Apontador para o grafo.
 * @param origem Vértice de origem.
 * @param destino Vértice de destino.
 * @param vOrigem Apontador para o local que receberá o vértice de origem ajustado.
 * @param vDestino Apontador para o local que receberá o vértice de destino ajustado.
 */
static inline void grafoMA_ajustaVertices(grafo_t * grafo, vertice_t origem, vertice_t destino, vertice_t * origemAj, vertice_t * destinoAj) {

  // Teste para garantir que os índices estão dentro dos limites da matriz
  if (grafo->tipo == eGrafoDirecionado) {
    *origemAj = origem;
    *destinoAj = destino;
  }
  else {
    if (origem < destino) {
      *origemAj = destino;
      *destinoAj = origem;
    }
    else {
      *origemAj = origem;
      *destinoAj = destino;
    }
  }
}

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
  (*grafo)->nArestas = 0;
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
 * Função que verifica se uma aresta existe.
 * @param grafo Apontador para o grafo.
 * @param origem Vértice de origem.
 * @param destino Vértice de destino.
 * @param existe Apontador para o local onde a resposta para a verificação
 * da existência da aresta será armazenada.
 * @return SUCESSO caso a verificação aconteça corretamente, ou caso contrário,
 * o código do erro ocorrido.
 */
erro_t grafoMA_existeAresta(grafo_t * grafo, vertice_t origem, vertice_t destino, bool_t * existe) {

  vertice_t vOrigem, vDestino;

  if ((origem >= grafo->nVertices) || (destino >= grafo->nVertices)) {
    return ERRO_VERTICE_INVALIDO;
  }

  // Ajusta os vértices dependendo do tipo do grafo
  grafoMA_ajustaVertices(grafo, origem, destino, &vOrigem, &vDestino);

  // Os índices estão corretos em vOrigem e vDestino
  *existe = (GRAFO_DADOS(grafo)[vOrigem][vDestino] == GRAFO_ARESTA_AUSENTE ? FALSO : VERDADEIRO);

  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}

/**
 * Função que cria uma aresta no grafo.
 * @param grafo Apontador para o grafo onde a aresta será criada.
 * @param origem Vértice de origem.
 * @param destino Vértice de destino.
 * @param custo Custo da aresta a ser criada.
 * @return SUCESSO caso a aresta seja criada corretamente, ou caso contrário,
 * o código do erro ocorrido.
 */
erro_t grafoMA_criaAresta(grafo_t * grafo, vertice_t origem, vertice_t destino, custo_t custo) {

  erro_t erro;
  bool_t existeAresta;
  vertice_t vOrigem, vDestino;

  // Verifica se a aresta já existe
  erro = grafoMA_existeAresta(grafo, origem, destino, &existeAresta);
  if (erro != SUCESSO) return erro;
  if (existeAresta) return ERRO_ARESTA_EXISTENTE;

  // Verifica se a aresta forma um self-loop
  if (origem == destino) {
    return ERRO_VERTICES_ORIGEM_DESTINO_IGUAIS;
  }

  // Se eu cheguei aqui, a aresta não existe e não é um self-loop

  // Ajusta os vértices dependendo do tipo do grafo
  grafoMA_ajustaVertices(grafo, origem, destino, &vOrigem, &vDestino);

  // Crio a aresta com o custo especificado
  GRAFO_DADOS(grafo)[vOrigem][vDestino] = custo;
  grafo->nArestas++;

  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}

/**
 * Função que remove uma aresta no grafo.
 * @param grafo Apontador para o grafo onde a aresta será removida.
 * @param origem Vértice de origem.
 * @param destino Vértice de destino.
 * @return SUCESSO caso a aresta seja removida corretamente, ou caso contrário,
 * o código do erro ocorrido.
 */
erro_t grafoMA_removerAresta(grafo_t * grafo, vertice_t origem, vertice_t destino) {

  erro_t erro;
  bool_t existeAresta;
  vertice_t vOrigem, vDestino;

  // Verifica se a aresta já existe
  erro = grafoMA_existeAresta(grafo, origem, destino, &existeAresta);
  if (erro != SUCESSO) return erro;
  if (!existeAresta) return ERRO_ARESTA_INEXISTENTE;

  // Se eu cheguei aqui, a aresta existe

  // Ajusta os vértices dependendo do tipo do grafo
  grafoMA_ajustaVertices(grafo, origem, destino, &vOrigem, &vDestino);

  // Removo a aresta com o custo especificado
  GRAFO_DADOS(grafo)[vOrigem][vDestino] = GRAFO_ARESTA_AUSENTE;
  grafo->nArestas--;

  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}

/**
 * Função que obtem o custo de uma determinada aresta.
 * @param grafo Apontador para o grafo.
 * @param origem Vértice de origem da aresta.
 * @param destino Vértice de destino da aresta.
 * @param custo Apontador para o local onde o custo da aresta será armazenado.
 * @return SUCESSO caso o custo da aresta seja obtido corretamente, ou caso
 * contrário, o código do erro ocorrido.
 */
erro_t grafoMA_obtemCustoAresta(grafo_t * grafo, vertice_t origem, vertice_t destino, custo_t * custo) {

  erro_t erro;
  bool_t existeAresta;
  vertice_t vOrigem, vDestino;

  // Verifica se a aresta já existe
  erro = grafoMA_existeAresta(grafo, origem, destino, &existeAresta);
  if (erro != SUCESSO) return erro;
  if (!existeAresta) return ERRO_ARESTA_INEXISTENTE;

  // Se eu cheguei aqui, a aresta existe

  // Ajusta os vértices dependendo do tipo do grafo
  grafoMA_ajustaVertices(grafo, origem, destino, &vOrigem, &vDestino);

  // Removo a aresta com o custo especificado
  *custo = GRAFO_DADOS(grafo)[vOrigem][vDestino];

  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}

/**
 * Função que obtem a lista de vértices adjacentes a um determinado vértice.
 * @param grafo Apontador para o grafo.
 * @param vertice Vértice cuja lista será obtida.
 * @param verticesAdj Apontador para o local que receberá a lista de vértices
 * adjacentes.
 * @param nVerticesAdj Apontador para o local que receberá o número de 
 * vértices adjacentes.
 * @return SUCESSO caso a lista de vértices adjacentes seja obtida corretamente, 
 * ou caso contrário, o código do erro ocorrido.
 */
erro_t grafoMA_obtemVerticesAdjacentes(grafo_t * grafo, vertice_t vertice, vertice_t ** verticesAdj, uint16_t * nVerticesAdj) {

  erro_t erro;
  uint16_t i;
  vertice_t * addrLista;
  bool_t existeAresta;
  vertice_t vOrigem, vDestino;

  // Teste dos parâmetros
  if (verticesAdj == NULL) {
    return ERRO_ARGUMENTO_INVALIDO;
  }

  // Verifica se o índice do vértice é válido
  if (vertice >= grafo->nVertices) {
    return ERRO_VERTICE_INVALIDO;
  }

  // 1a passada : Contagem do número de vértices adjacentes
  *nVerticesAdj = 0;
  for (i = 0; i < grafo->nVertices; i++) {

    // Verifica se a aresta existe
    erro = grafoMA_existeAresta(grafo, vertice, i, &existeAresta);
    if (erro != SUCESSO) return erro;
    if (existeAresta) {
      (*nVerticesAdj)++;
    }
  }

  // Se não tem vértices adjacentes, então a lista é nula
  if (*nVerticesAdj == 0) {
    *verticesAdj = NULL;
    return SUCESSO;
  }

  // 2a passada: Sei quantos vértices são, então coloco eles no lugar

  // Crio espaço para a lista
  *verticesAdj = (vertice_t *)malloc((*nVerticesAdj) * sizeof(vertice_t));
  if (*verticesAdj == NULL) {
    return ERRO_ALOCACAO_MEMORIA;
  }

  // Caminho e vou colocando na lista o índice do vértice
  addrLista = *verticesAdj;
  for (i = 0; i < grafo->nVertices; i++) {

    // Ajusta os vértices dependendo do tipo do grafo
    grafoMA_ajustaVertices(grafo, vertice, i, &vOrigem, &vDestino);

    if (GRAFO_DADOS(grafo)[vOrigem][vDestino] != GRAFO_ARESTA_AUSENTE) {
      *(addrLista++) = i;
    }
  }

  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}

/**
 * Função auxiliar para imprimir uma lista de vértices em linha.
 * @param listaVertices Apontador para o início da lista.
 * @param nVertices Número de vértices presentes na lista.
 */
static void grafoMA_imprimeListaVertices(vertice_t * listaVertices, uint16_t nVertices) {
  while (nVertices-- > 0) {
    (void)printf("%d ", *(listaVertices++));
  }
}

/**
 * Função que imprime o grafo e suas informações.
 * @param grafo Apontador para o grafo a ser impresso.
 */
void grafoMA_imprime(grafo_t * grafo) {

  uint32_t i, j, limite;

  (void)printf(":: Imprimindo Grafo\n");
  (void)printf("Tipo do grafo .....: %s\n", grafo->tipo == eGrafoDirecionado ? "Direcionado" : "Nao Direcionado");
  (void)printf("Numero de Vertices : %-5d\n", grafo->nVertices);
  (void)printf("Numero de Arestas  : %-5d\n", grafo->nArestas);
  (void)printf("-------------------------------------------\n");

  for (i = 0; i < grafo->nVertices; i++) {
    limite = (grafo->tipo == eGrafoDirecionado ? grafo->nVertices : i + 1);
    for (j = 0; j < limite; j++) {

      // Não quero imprimir aresta inexistente
      if (GRAFO_DADOS(grafo)[i][j] == GRAFO_ARESTA_AUSENTE) continue;

      // Se for direcionado     (origem -> destino : custo)
      // Se for não direcionado (origem -- destino : custo)
      (void)printf("%5d -%c %-5d : %11d\n", 
                   i, 
                   (grafo->tipo == eGrafoDirecionado ? '>' : '-'), 
                   j, 
                   GRAFO_DADOS(grafo)[i][j]
            );
    }
  }

  (void)printf("-------------------------------------------\n");
}

/**
 * Função que imprime as listas de adjacências de todos os vértices do grafo.
 * @param grafo Apontador para o grafo.
 * @return SUCESSO caso as listas de adjacências sejam impressas corretamente,
 * ou caso contrário, o código do erro ocorrido.
 */
erro_t grafoMA_imprimeListasAdjacencias(grafo_t * grafo) {

  uint32_t i;
  erro_t erro;
  vertice_t * listaVerticesAdj;
  uint16_t nVerticesAdj;

  (void)printf(":: Imprimindo Listas de Adjacencias do Grafo\n");
  (void)printf("Tipo do grafo .....: %s\n", grafo->tipo == eGrafoDirecionado ? "Direcionado" : "Nao Direcionado");
  (void)printf("Numero de Vertices : %-5d\n", grafo->nVertices);
  (void)printf("Numero de Arestas  : %-5d\n", grafo->nArestas);
  (void)printf("-------------------------------------------\n");

  // Para cada vértice, obtem a lista de adjacência e imprime
  for (i = 0; i < grafo->nVertices; i++) {

    // Obtem a lista de vértices adjacentes ao vértice atual
    erro = grafoMA_obtemVerticesAdjacentes(grafo, i, &listaVerticesAdj, &nVerticesAdj);
    if (erro != SUCESSO) return erro;

    // Imprime o vértice e sua lista de adjacência
    (void)printf("%5d : ", i);
    grafoMA_imprimeListaVertices(listaVerticesAdj, nVerticesAdj);
    (void)printf("\n");

    // Libera a memória da lista
    free(listaVerticesAdj);
  }

  (void)printf("-------------------------------------------\n");

  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}