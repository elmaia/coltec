using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using COLTEC.AEDS.Grafos;

namespace Grafos {
  class Program {
    static void Main(string[] args) {

      GrafoMA g = new GrafoMA(3, TipoGrafo.Direcionado);

      g.CriarAresta(0, 1, 88);
      g.CriarAresta(0, 2, 85);
      g.CriarAresta(1, 2, 19);
      g.CriarAresta(2, 1, 8);


      g.ImprimeGrafo();
      g.ImprimeListasAdjacencias();

    }
  }
}
