using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using ListaEncadeada;

namespace Main {
  class Program {

    static void funcaoX() {

      try {
        Console.WriteLine("funcaoX:try");
        throw new ArgumentException("Alguma excecao");
      } catch (ArgumentException e) {
        Console.WriteLine("funcaoX:catch:ArgumentException");
      } catch {
        Console.WriteLine("funcaoX:catch");
      } finally {
        Console.WriteLine("funcaoX:finally");
      }

    }


    static void Main(string[] args) {

      funcaoX();



    }
  }
}
