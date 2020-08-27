using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ListaEncadeada {

  /// <summary>
  /// Classe com a implementação de uma Lista Encadeada Simples.
  /// </summary>
  /// <typeparam name="Dado"></typeparam>
  class ListaES<Dado> where Dado : IComparable {

    /// <summary>
    /// Classe privada para armazenar um item da Lista Encadeada Simples.
    /// </summary>
    /// <typeparam name="DadoItem"></typeparam>
    private class ItemLista<DadoItem> where DadoItem : IComparable {

      /// <summary>
      /// Atributo com as informação do item da lista.
      /// </summary>
      private DadoItem info;

      /// <summary>
      /// Atributo com a referência para o próximo item da lista.
      /// </summary>
      private ItemLista<DadoItem> proximo;

      /// <summary>
      /// Propriedade com a referência para o próximo item da lista.
      /// </summary>
      public ItemLista<DadoItem> Proximo {
        get { return this.proximo; }
        set { this.proximo = value; }
      }

      /// <summary>
      /// Propriedade com o dado do item armazenado.
      /// </summary>
      public DadoItem Info {
        get { return this.info; }
        set { this.info = value; }
      }

      /// <summary>
      /// Construtor de um item da lista.
      /// </summary>
      /// <param name="dado">Dado a ser armazenado no item da lista.</param>
      public ItemLista(DadoItem dado) {
        this.info = dado;
        this.proximo = null;
      }

    }

    /// <summary>
    /// Atributo que armazena o número de itens da lista.
    /// </summary>
    private UInt32 nItens;

    /// <summary>
    /// Atributo que armazena a referência para o primeiro item da lista.
    /// </summary>
    private ItemLista<Dado> primeiro;

    /// <summary>
    /// Propriedade com o número de itens armazenados na lista.
    /// </summary>
    public UInt32 NumeroItens {
      get { return this.nItens; }
    }

    /// <summary>
    /// Propriedade que informa se a lista está vazia ou não.
    /// </summary>
    public bool Vazia {
      get { return this.nItens == 0; }
    }

    /// <summary>
    /// Construtor da Lista Encadeada Simples.
    /// </summary>
    public ListaES() {
      this.nItens = 0;
      this.primeiro = null;
    }

    /// <summary>
    /// Método que obtem o elemento da lista que está na N-ésima posição.
    /// </summary>
    /// <param name="posicao">Posição do item desejado.</param>
    /// <returns>Item da lista desejado.</returns>
    private ItemLista<Dado> ObtemElementoPosicao(UInt32 posicao) {

      ItemLista<Dado> atual;

      // Verifica se a lista possui elementos suficientes
      if (posicao > this.nItens) throw new PosicaoInvalidaException();

      // Começa a percorrer a lista a partir do primeiro elemento
      atual = this.primeiro;
      while (posicao-- != 0) {
        atual = atual.Proximo;
      }

      // Se chegou até aqui é porque correu tudo bem
      return atual;
    }

    /// <summary>
    /// Método que insere o dado no início da lista.
    /// </summary>
    /// <param name="dado">Dado a ser inserida na lista.</param>
    public void InsereInicio(Dado dado) {
      InsereNesimaPosicao(dado, 0);
    }

    /// <summary>
    /// Método que insere o dado no fim da lista.
    /// </summary>
    /// <param name="dado">Dado a ser inserida na lista.</param>
    public void InsereFinal(Dado dado) {
      InsereNesimaPosicao(dado, this.nItens);
    }

    /// <summary>
    /// Método que insere um dado na posição especificada na lista.
    /// </summary>
    /// <param name="dado">Dado a ser inserida na lista.</param>
    /// <param name="posicao">Posição onde a informação será inserida. O valor deve estar 
    /// entre[0..NumeroItens]</param>
    public void InsereNesimaPosicao(Dado dado, UInt32 posicao) {

      ItemLista<Dado> novoItem, anterior;

      // Verifico se a posição faz sentido com o número atual de itens na lista
      if (posicao > this.nItens) throw new PosicaoInvalidaException();

      // Cria um novo elemento e inicializa o item
      novoItem =  new ItemLista<Dado>(dado);

      // Se for a posição ZERO, então o novo item será o novo primeiro item
      if (posicao == 0) {
        novoItem.Proximo = this.primeiro;
        this.primeiro = novoItem;
      }
      // .. senão, então eu busco o item da posição N-1 para ligar o novo item.
      else {

        // Busco o item anterior para fazer a ligação
        anterior = ObtemElementoPosicao(posicao - 1);

        // Faço a ligação
        novoItem.Proximo = anterior.Proximo;
        anterior.Proximo = novoItem;
      }

      // Se chegou até aqui é porque o novo item foi inserido com sucesso na lista
      this.nItens++;
    }

    /// <summary>
    /// Remove um item da lista.
    /// </summary>
    /// <param name="dado">Informação do item a ser removido.</param>
    public void RemoveElemento(Dado dado) {

      ItemLista<Dado> anterior = null;
      ItemLista<Dado> elementoARemover = this.primeiro;

      // Percore os elementos da lista procurando aquele cuja informação é a desejada
      while (elementoARemover != null) {
        if (elementoARemover.Info.CompareTo(dado) == 0) break;
        anterior = elementoARemover;
        elementoARemover = elementoARemover.Proximo;
      }

      // Verifica se o item foi encontrado, ou seja, se o elementoARemover não é nulo
      if (elementoARemover == null) throw new ItemNaoEncontradoException();

      // Se chegou aqui é porque encontrou o item desejado e ele está no elementoARemover
      // Se o anterior é nulo, então é porque o item encontrado é o primeiro da lista ...
      if (anterior == null) {
        this.primeiro = elementoARemover.Proximo;
      }
      // ... senão, então ele pode estar em qualquer lugar, mas garantidamente não é o primeiro
      else {
        anterior.Proximo = elementoARemover.Proximo;
      }

      // Se chegou até aqui é porque o item foi removido corretamente da lista
      this.nItens--;
    }

    /// <summary>
    /// Método que remove um item da lista na posição especificada.
    /// </summary>
    /// <param name="posicao">Posição do item a ser removido.</param>
    /// <returns>Dado do item armazenado na posição especificada.</returns>
    public Dado RemovePosicao(UInt32 posicao) {

      ItemLista<Dado> elementoARemover, anterior;

      // Verifico se a posição faz sentido com o número atual de itens na lista
      if (posicao >= this.nItens) throw new PosicaoInvalidaException();

      // Aqui, garantidamente, eu tenho pelo menos um elemento na lista

        // Se for o primeiro da lista, então basta pulá-lo
      if (posicao == 0) {
        elementoARemover = this.primeiro;
        this.primeiro = elementoARemover.Proximo;
      }
      // .. senão, eu busco o anterior e pulo o elemento a ser removido
      else {

        // Busco o item anterior para fazer a ligação
        anterior = ObtemElementoPosicao(posicao - 1);

        // Pulo o elemento a ser removido
        elementoARemover = anterior.Proximo;
        anterior.Proximo = elementoARemover.Proximo;
      }

      // Se chegou até aqui é porque o item foi pulado e removido com sucesso na lista
      this.nItens--;
      return elementoARemover.Info;
    }

    /// <summary>
    /// Função que busca um item na lista.
    /// </summary>
    /// <param name="dado">Dado a ser procurado na lista.</param>
    /// <param name="posicao">Referência para o local que receberá a posição caso o item seja encontrado.</param>
    /// <returns>Verdadeiro caso o dado seja encontrado na lista, ou falso caso contrário.</returns>
    public bool Busca(Dado dado, out UInt32 posicao) {

      UInt32 pos = 0;
      ItemLista<Dado> proximo = this.primeiro;

      // Percore os elementos da lista procurando aquele cuja informação é a desejada
      while (proximo != null) {
        if (proximo.Info.CompareTo(dado) == 0) break;
        proximo = proximo.Proximo;
        pos++;
      }

      // O elemento que está no próximo é o item encontrado.
      // Caso a lista tenha chegado no final e nenhum item foi encontrado, então
      // o próximo é NULL
      // Caso a lista esteja vazia, então o próximo é NULL desde o início.
      if (proximo == null) {
        posicao = 0;
        return false;
      }

      // Se chegou até aqui é porque o item foi encontrado e sua posição está em pos
      posicao = pos;
      return true;
    }

    /// <summary>
    /// Método que imprime todos os itens da lista.
    /// </summary>
    public void Imprime() {

      UInt32 i;
      ItemLista<Dado> atual;
      ItemLista<Dado> proximo = this.primeiro;

      Console.WriteLine("Lista com %u item(s)", this.nItens);
      Console.WriteLine("Impressao da lista\n" +
                        "------------------");

      // Imprime posição e o valor de cada item da lista
      for (i = 0; i < this.nItens; i++) {

        // Controla os links da lista
        atual = proximo;
        proximo = atual.Proximo;

        Console.WriteLine("Pos: {0} / Valor: {1}", i, atual.Info.ToString());
      }

      Console.WriteLine("------------------");
    }
  }
}
