using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ListaEncadeada {
  class PosicaoInvalidaException : ArgumentOutOfRangeException {
    public PosicaoInvalidaException() : base("Posição inválida") { }
  }

  class ItemNaoEncontradoException : ApplicationException {
    public ItemNaoEncontradoException() : base("Item Não Encontrado") { }
  }

}
