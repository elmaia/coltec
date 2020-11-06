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
 * Fun��o auxiliar para ajuste das coordenadas dos v�rtices na matriz.
 * @param grafo Apontador para o grafo.
 * @param origem V�rtice de origem.
 * @param destino V�rtice de destino.
 * @param vOrigem Apontador para o local que receber� o v�rtice de origem ajustado.
 * @param vDestino Apontador para o local que receber� o v�rtice de destino ajustado.
 */
static inline void grafoMA_ajustaVertices(grafo_t * grafo, vertice_t origem, vertice_t destino, vertice_t * origemAj, vertice_t * destinoAj) {

  // Teste para garantir que os �ndices est�o dentro dos limites da matriz
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
  (*grafo)->nArestas = 0;
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
 * Fun��o que verifica se uma aresta existe.
 * @param grafo Apontador para o grafo.
 * @param origem V�rtice de origem.
 * @param destino V�rtice de destino.
 * @param existe Apontador para o local onde a resposta para a verifica��o
 * da exist�ncia da aresta ser� armazenada.
 * @return SUCESSO caso a verifica��o aconte�a corretamente, ou caso contr�rio,
 * o c�digo do erro ocorrido.
 */
erro_t grafoMA_existeAresta(grafo_t * grafo, vertice_t origem, vertice_t destino, bool_t * existe) {

  vertice_t vOrigem, vDestino;

  if ((origem >= grafo->nVertices) || (destino >= grafo->nVertices)) {
    return ERRO_VERTICE_INVALIDO;
  }

  // Ajusta os v�rtices dependendo do tipo do grafo
  grafoMA_ajustaVertices(grafo, origem, destino, &vOrigem, &vDestino);

  // Os �ndices est�o corretos em vOrigem e vDestino
  *existe = (GRAFO_DADOS(grafo)[vOrigem][vDestino] == GRAFO_ARESTA_AUSENTE ? FALSO : VERDADEIRO);

  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}

/**
 * Fun��o que cria uma aresta no grafo.
 * @param grafo Apontador para o grafo onde a aresta ser� criada.
 * @param origem V�rtice de origem.
 * @param destino V�rtice de destino.
 * @param custo Custo da aresta a ser criada.
 * @return SUCESSO caso a aresta seja criada corretamente, ou caso contr�rio,
 * o c�digo do erro ocorrido.
 */
erro_t grafoMA_criaAresta(grafo_t * grafo, vertice_t origem, vertice_t destino, custo_t custo) {

  erro_t erro;
  bool_t existeAresta;
  vertice_t vOrigem, vDestino;

  // Verifica se a aresta j� existe
  erro = grafoMA_existeAresta(grafo, origem, destino, &existeAresta);
  if (erro != SUCESSO) return erro;
  if (existeAresta) return ERRO_ARESTA_EXISTENTE;

  // Verifica se a aresta forma um self-loop
  if (origem == destino) {
    return ERRO_VERTICES_ORIGEM_DESTINO_IGUAIS;
  }

  // Se eu cheguei aqui, a aresta n�o existe e n�o � um self-loop

  // Ajusta os v�rtices dependendo do tipo do grafo
  grafoMA_ajustaVertices(grafo, origem, destino, &vOrigem, &vDestino);

  // Crio a aresta com o custo especificado
  GRAFO_DADOS(grafo)[vOrigem][vDestino] = custo;
  grafo->nArestas++;

  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}

/**
 * Fun��o que remove uma aresta no grafo.
 * @param grafo Apontador para o grafo onde a aresta ser� removida.
 * @param origem V�rtice de origem.
 * @param destino V�rtice de destino.
 * @return SUCESSO caso a aresta seja removida corretamente, ou caso contr�rio,
 * o c�digo do erro ocorrido.
 */
erro_t grafoMA_removerAresta(grafo_t * grafo, vertice_t origem, vertice_t destino) {

  erro_t erro;
  bool_t existeAresta;
  vertice_t vOrigem, vDestino;

  // Verifica se a aresta j� existe
  erro = grafoMA_existeAresta(grafo, origem, destino, &existeAresta);
  if (erro != SUCESSO) return erro;
  if (!existeAresta) return ERRO_ARESTA_INEXISTENTE;

  // Se eu cheguei aqui, a aresta existe

  // Ajusta os v�rtices dependendo do tipo do grafo
  grafoMA_ajustaVertices(grafo, origem, destino, &vOrigem, &vDestino);

  // Removo a aresta com o custo especificado
  GRAFO_DADOS(grafo)[vOrigem][vDestino] = GRAFO_ARESTA_AUSENTE;
  grafo->nArestas--;

  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}

/**
 * Fun��o que obtem o custo de uma determinada aresta.
 * @param grafo Apontador para o grafo.
 * @param origem V�rtice de origem da aresta.
 * @param destino V�rtice de destino da aresta.
 * @param custo Apontador para o local onde o custo da aresta ser� armazenado.
 * @return SUCESSO caso o custo da aresta seja obtido corretamente, ou caso
 * contr�rio, o c�digo do erro ocorrido.
 */
erro_t grafoMA_obtemCustoAresta(grafo_t * grafo, vertice_t origem, vertice_t destino, custo_t * custo) {

  erro_t erro;
  bool_t existeAresta;
  vertice_t vOrigem, vDestino;

  // Verifica se a aresta j� existe
  erro = grafoMA_existeAresta(grafo, origem, destino, &existeAresta);
  if (erro != SUCESSO) return erro;
  if (!existeAresta) return ERRO_ARESTA_INEXISTENTE;

  // Se eu cheguei aqui, a aresta existe

  // Ajusta os v�rtices dependendo do tipo do grafo
  grafoMA_ajustaVertices(grafo, origem, destino, &vOrigem, &vDestino);

  // Removo a aresta com o custo especificado
  *custo = GRAFO_DADOS(grafo)[vOrigem][vDestino];

  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}

/**
 * Fun��o que obtem a lista de v�rtices adjacentes a um determinado v�rtice.
 * @param grafo Apontador para o grafo.
 * @param vertice V�rtice cuja lista ser� obtida.
 * @param verticesAdj Apontador para o local que receber� a lista de v�rtices
 * adjacentes.
 * @param nVerticesAdj Apontador para o local que receber� o n�mero de 
 * v�rtices adjacentes.
 * @return SUCESSO caso a lista de v�rtices adjacentes seja obtida corretamente, 
 * ou caso contr�rio, o c�digo do erro ocorrido.
 */
erro_t grafoMA_obtemVerticesAdjacentes(grafo_t * grafo, vertice_t vertice, vertice_t ** verticesAdj, uint16_t * nVerticesAdj) {

  erro_t erro;
  uint16_t i;
  vertice_t * addrLista;
  bool_t existeAresta;
  vertice_t vOrigem, vDestino;

  // Teste dos par�metros
  if (verticesAdj == NULL) {
    return ERRO_ARGUMENTO_INVALIDO;
  }

  // Verifica se o �ndice do v�rtice � v�lido
  if (vertice >= grafo->nVertices) {
    return ERRO_VERTICE_INVALIDO;
  }

  // 1a passada : Contagem do n�mero de v�rtices adjacentes
  *nVerticesAdj = 0;
  for (i = 0; i < grafo->nVertices; i++) {

    // Verifica se a aresta existe
    erro = grafoMA_existeAresta(grafo, vertice, i, &existeAresta);
    if (erro != SUCESSO) return erro;
    if (existeAresta) {
      (*nVerticesAdj)++;
    }
  }

  // Se n�o tem v�rtices adjacentes, ent�o a lista � nula
  if (*nVerticesAdj == 0) {
    *verticesAdj = NULL;
    return SUCESSO;
  }

  // 2a passada: Sei quantos v�rtices s�o, ent�o coloco eles no lugar

  // Crio espa�o para a lista
  *verticesAdj = (vertice_t *)malloc((*nVerticesAdj) * sizeof(vertice_t));
  if (*verticesAdj == NULL) {
    return ERRO_ALOCACAO_MEMORIA;
  }

  // Caminho e vou colocando na lista o �ndice do v�rtice
  addrLista = *verticesAdj;
  for (i = 0; i < grafo->nVertices; i++) {

    // Ajusta os v�rtices dependendo do tipo do grafo
    grafoMA_ajustaVertices(grafo, vertice, i, &vOrigem, &vDestino);

    if (GRAFO_DADOS(grafo)[vOrigem][vDestino] != GRAFO_ARESTA_AUSENTE) {
      *(addrLista++) = i;
    }
  }

  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}

/**
 * Fun��o auxiliar para imprimir uma lista de v�rtices em linha.
 * @param listaVertices Apontador para o in�cio da lista.
 * @param nVertices N�mero de v�rtices presentes na lista.
 */
static void grafoMA_imprimeListaVertices(vertice_t * listaVertices, uint16_t nVertices) {
  while (nVertices-- > 0) {
    (void)printf("%d ", *(listaVertices++));
  }
}

/**
 * Fun��o que imprime o grafo e suas informa��es.
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

      // N�o quero imprimir aresta inexistente
      if (GRAFO_DADOS(grafo)[i][j] == GRAFO_ARESTA_AUSENTE) continue;

      // Se for direcionado     (origem -> destino : custo)
      // Se for n�o direcionado (origem -- destino : custo)
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
 * Fun��o que imprime as listas de adjac�ncias de todos os v�rtices do grafo.
 * @param grafo Apontador para o grafo.
 * @return SUCESSO caso as listas de adjac�ncias sejam impressas corretamente,
 * ou caso contr�rio, o c�digo do erro ocorrido.
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

  // Para cada v�rtice, obtem a lista de adjac�ncia e imprime
  for (i = 0; i < grafo->nVertices; i++) {

    // Obtem a lista de v�rtices adjacentes ao v�rtice atual
    erro = grafoMA_obtemVerticesAdjacentes(grafo, i, &listaVerticesAdj, &nVerticesAdj);
    if (erro != SUCESSO) return erro;

    // Imprime o v�rtice e sua lista de adjac�ncia
    (void)printf("%5d : ", i);
    grafoMA_imprimeListaVertices(listaVerticesAdj, nVerticesAdj);
    (void)printf("\n");

    // Libera a mem�ria da lista
    free(listaVerticesAdj);
  }

  (void)printf("-------------------------------------------\n");

  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}