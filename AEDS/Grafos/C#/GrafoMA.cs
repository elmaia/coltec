using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace COLTEC.AEDS.Grafos {

  /// <summary>
  /// Numeração de tipos de grafos.
  /// </summary>
  enum TipoGrafo {
    Direcionado,
    NaoDirecionado
  };

  /// <summary>
  /// Representação de um grafo implementado com Matriz de Adjacências.
  /// </summary>
  class GrafoMA {

    /* Atributos */
    private TipoGrafo tipo;
    private UInt16 nVertices;
    private UInt32 nArestas;
    private Int32[][] dados;

    /// <summary>
    /// Valor de uma célula da matriz que representa que a aresta está ausente.
    /// </summary>
    private static readonly Int32 ARESTA_AUSENTE = Int32.MinValue;

    /// <summary>
    /// Construtor do grafo representado através de Matriz de Adjacência.
    /// </summary>
    /// <param name="nVertices">Número de vértices do grafo.</param>
    /// <param name="tipo">Tipo do grafo.</param>
    public GrafoMA(UInt16 nVertices, TipoGrafo tipo) {

      // Verifica se o número de vértices é válido
      if (nVertices == 0) throw new ArgumentException("nVertices nao pode conter valor 0");

      // Salva as informações do grafo
      this.nVertices = nVertices;
      this.tipo = tipo;
      this.nArestas = 0;

      // Crio espaço para as linhas
      this.dados = new Int32[nVertices][];

      for (UInt16 i = 0; i < nVertices; i++) {

        // Defino o limite dependendo se é direcionado ou não
        UInt16 limite = (tipo == TipoGrafo.Direcionado ? nVertices : (UInt16)(i + 1));

        // Crio e inicializo a linha com todas as células sem aresta
        this.dados[i] = Enumerable.Repeat<Int32>(ARESTA_AUSENTE, limite).ToArray();
      }
    }

    /// <summary>
    /// Propriedade que retorna o número de vértices do grafo
    /// </summary>
    public UInt16 NumVertices {  get { return this.nVertices; } }

    /// <summary>
    /// Propriedade que retorna o número de arestas do grafo
    /// </summary>
    public UInt32 NumArestas {  get { return this.nArestas; } }

    /// <summary>
    /// Função auxiliar para ajuste das coordenadas dos vértices na matriz.
    /// </summary>
    /// <param name="origem">Vértice de origem.</param>
    /// <param name="destino">Vértice de destino.</param>
    /// <param name="origemAj">Local que receberá o vértice de origem ajustado.</param>
    /// <param name="destinoAj">Local que receberá o vértice de destino ajustado.</param>
    private void AjustarVertices(UInt16 origem, UInt16 destino, out UInt16 origemAj, out UInt16 destinoAj) {
      if (this.tipo == TipoGrafo.Direcionado) {
        origemAj = origem;
        destinoAj = destino;
      } else {
        if (origem < destino) {
          origemAj = destino;
          destinoAj = origem;
        } else {
          origemAj = origem;
          destinoAj = destino;
        }
      }
    }

    /// <summary>
    /// Verifica se uma aresta existe.
    /// </summary>
    /// <param name="origem">Vértice de origem.</param>
    /// <param name="destino">Vértice de destino.</param>
    /// <returns>Verdadeiro caso a aresta exista, ou falso caso contrário.</returns>
    public bool ExisteAresta(UInt16 origem, UInt16 destino) {

      UInt16 vOrigem, vDestino;

      // Verifica se os índices dos vértice estão dentro dos limites
      if ((origem >= this.nVertices) || (destino >= this.nVertices)) {
        throw new ArgumentException("Indice do vertice fora dos limites do grafo");
      }

      // Ajusta os vértices dependendo do tipo do grafo
      AjustarVertices(origem, destino, out vOrigem, out vDestino);

      // Retorna se a aresta existe ou não
      return this.dados[vOrigem][vDestino] != ARESTA_AUSENTE;
    }

    /// <summary>
    /// Cria uma aresta no grafo.
    /// </summary>
    /// <param name="origem">Vértice de origem.</param>
    /// <param name="destino">Vértice de destino.</param>
    /// <param name="custo">Custo da aresta a ser criada.</param>
    public void CriarAresta(UInt16 origem, UInt16 destino, Int32 custo) {

      bool existeAresta;
      UInt16 vOrigem, vDestino;

      // Verifica se a aresta já existe
      existeAresta = ExisteAresta(origem, destino);
      if (existeAresta) throw new Exception("Aresta Existente");

      // Verifica se a aresta forma um self-loop
      if (origem == destino) throw new Exception("Vertices de origem e destino sao iguais");

      // Se eu cheguei aqui, a aresta não existe e não é um self-loop

      // Ajusta os vértices dependendo do tipo do grafo
      AjustarVertices(origem, destino, out vOrigem, out vDestino);

      // Crio a aresta com o custo especificado
      this.dados[vOrigem][vDestino] = custo;
      this.nArestas++;
    }

    /// <summary>
    /// Remove uma aresta no grafo.
    /// </summary>
    /// <param name="origem">Vértice de origem.</param>
    /// <param name="destino">Vértice de destino.</param>
    public void RemoverAresta(UInt16 origem, UInt16 destino) {

      bool existeAresta;
      UInt16 vOrigem, vDestino;

      // Verifica se a aresta já existe
      existeAresta = ExisteAresta(origem, destino);
      if (!existeAresta) throw new Exception("Aresta inexistente");

      // Se eu cheguei aqui, a aresta existe

      // Ajusta os vértices dependendo do tipo do grafo
      AjustarVertices(origem, destino, out vOrigem, out vDestino);

      // Removo a aresta com o custo especificado
      this.dados[vOrigem][vDestino] = ARESTA_AUSENTE;
      this.nArestas--;
    }

    /// <summary>
    /// Obtem o custo de uma determinada aresta.
    /// </summary>
    /// <param name="origem">Vértice de origem da aresta.</param>
    /// <param name="destino">Vértice de destino da aresta.</param>
    /// <returns>Custo da aresta.</returns>
    public Int32 ObtemCustoAresta(UInt16 origem, UInt16 destino) {

      bool existeAresta;
      UInt16 vOrigem, vDestino;

      // Verifica se a aresta já existe
      existeAresta = ExisteAresta(origem, destino);
      if (!existeAresta) throw new Exception("Aresta inexistente");

      // Se eu cheguei aqui, a aresta existe

      // Ajusta os vértices dependendo do tipo do grafo
      AjustarVertices(origem, destino, out vOrigem, out vDestino);

      // Removo a aresta com o custo especificado
      return this.dados[vOrigem][vDestino];
    }

    /// <summary>
    /// Obtem a lista de vértices adjacentes a um determinado vértice.
    /// </summary>
    /// <param name="vertice">Vértice cuja lista será obtida.</param>
    /// <returns>A lista de vértices adjacentes.</returns>
    public UInt16[] ObtemVerticesAdjacentes(UInt16 vertice) {

      List<UInt16> verticesAdj = new List<UInt16>();
      UInt16 vOrigem, vDestino;


      // Verifica se o índice do vértice é válido
      if (vertice >= this.nVertices) throw new ArgumentException("Vertice invalido");

      // Caminho e vou colocando na lista o índice do vértice
      for (UInt16 i = 0; i < this.nVertices; i++) {

        // Ajusta os vértices dependendo do tipo do grafo
        AjustarVertices(vertice, i, out vOrigem, out vDestino);

        if (this.dados[vOrigem][vDestino] != ARESTA_AUSENTE) {
          verticesAdj.Add(i);
        }
      }

      // Depois de coletado os vértices adjacentes, retorno a lista
      return verticesAdj.ToArray();
    }

    /// <summary>
    /// Imprime o grafo e suas informações.
    /// </summary>
    public void ImprimeGrafo() {

      UInt32 i, j, limite;

      Console.WriteLine(":: Imprimindo Grafo");
      Console.WriteLine("Tipo do grafo .....: {0}", this.tipo == TipoGrafo.Direcionado ? "Direcionado" : "Nao Direcionado");
      Console.WriteLine("Numero de Vertices : {0,-5}", this.nVertices);
      Console.WriteLine("Numero de Arestas  : {0,-5}", this.nArestas);
      Console.WriteLine("-------------------------------------------");
      Console.WriteLine("Orig. -{0} Dest. : {1,11}", (this.tipo == TipoGrafo.Direcionado ? '>' : '-'), "Custo");

      for (i = 0; i < this.nVertices; i++) {
        limite = (this.tipo == TipoGrafo.Direcionado ? this.nVertices : i + 1);
        for (j = 0; j < limite; j++) {

          // Não quero imprimir aresta inexistente
          if (this.dados[i][j] == ARESTA_AUSENTE) continue;

          // Se for direcionado     (origem -> destino : custo)
          // Se for não direcionado (origem -- destino : custo)
          Console.Write("{0,5} -{1} {2,-5} : {3,11}\n",
                       i,
                       (this.tipo == TipoGrafo.Direcionado ? '>' : '-'),
                       j,
                       this.dados[i][j]
                );
        }
      }

      Console.Write("-------------------------------------------\n");
    }

    /// <summary>
    /// Imprime as listas de adjacências de todos os vértices do grafo.
    /// </summary>
    public void ImprimeListasAdjacencias() {

      Console.WriteLine("::  Imprimindo Listas de Adjacencias do Grafo");
      Console.WriteLine("Tipo do grafo .....: {0}", this.tipo == TipoGrafo.Direcionado ? "Direcionado" : "Nao Direcionado");
      Console.WriteLine("Numero de Vertices : {0,-5}", this.nVertices);
      Console.WriteLine("Numero de Arestas  : {0,-5}", this.nArestas);
      Console.WriteLine("-------------------------------------------");
      Console.WriteLine("Vert. : Vertices Adjacentes");

      // Para cada vértice, obtem a lista de adjacência e imprime
      for (UInt16 i = 0; i < this.nVertices; i++) {

        // Obtem a lista de vértices adjacentes ao vértice atual
        var listaVerticesAdj = ObtemVerticesAdjacentes(i);

        // Imprime o vértice e sua lista de adjacência
        Console.Write($"{i,5} : ");
        foreach(UInt16 vAdj in listaVerticesAdj) {
          Console.Write("{0} ", vAdj);
        }
        Console.Write("\n");
      }

      Console.Write("-------------------------------------------\n");
    }

  }
}
