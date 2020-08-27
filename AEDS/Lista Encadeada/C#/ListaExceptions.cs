using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ListaEncadeada {
  class PosicaoInvalidaException : Exception {
    public PosicaoInvalidaException() : base("Posição inválida") { }
  }

  class ItemNaoEncontradoException : Exception {
    public ItemNaoEncontradoException() : base("Item Não Encontrado") { }
  }

}
