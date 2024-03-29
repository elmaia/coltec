/**
 * @file   LE03_2023.c
 * @brief  Arquivo com a implementa��o de sugest�o de solu��o da LE02.
 * @author Leandro Maia Silva
 * @date   2023-04-30
 */

/* Inclus�es */
#include <stdio.h>   // printf e scanf
#include <stdint.h>  // MAIOR_POSITIVO

/* Constantes */

// Constante que associa o c�digo de erro 0 ao significado de sucesso
#define SUCESSO  0

/**
 *
 */
void exercicio04(void) {
  
  int n;
  int i;
  int fatorial = 1;

  // Intera��o o usu�rio para obter o n�mero de termos
  printf("Digite o N para calcular F!: ");
  scanf("%d", &n);

  // Calcula o N!
  for (i = 1; i <= n; i++) {
    fatorial *= i;
  }

  // Mostra o N!
  printf("%d! = %d\n", n, fatorial);
}

/**
 *
 */

// Nota para aprova��o
#define NOTA_APROVACAO  60
 
void exercicio07(void) {
  
  int nAlunos;
  int i, retorno, nAlunosAprovados = 0;
  float nota;

  // Intera��o com o usu�rio
  printf("Digite o numero de alunos: ");
  retorno = scanf("%d", &nAlunos);

  // Obtenho a nota dos N alunos
  for (i = 0; i < nAlunos; i++) {

    // Obtenho a nota do aluno
    printf("Digite a nota do aluno %d: ", (i + 1));
    retorno = scanf("%f", &nota);

    // Se a nota � suficiente para aprova��o, conta nos aprovados
    if (nota >= NOTA_APROVACAO) {
      nAlunosAprovados++;
    }
  }

  // Mostro o resultado final
  printf("Foram obtidas as notas de %d alunos.\n", nAlunos);
  printf("Desses alunos, %d foram aprovados, reprentando %.2f%%.\n", nAlunosAprovados, 
    ((float)nAlunosAprovados / nAlunos) * 100);

}

/**
 *
 */
void exercicio08(void) {
  
  float E = 0;
  int i, j, retorno;
  int tamanho;
  float termoAtual, i_fatorial = 1;

  // Intera��o com o usu�rio
  printf("Digite o numero de termos de E: ");
  retorno = scanf("%d", &tamanho);

  // Calcula o valor de E com N termos
  for (i = 1; i <= tamanho; i++) {

    i_fatorial = 1;

    // Calcula o i!
    for (j = 1; j <= i; j++) {
      i_fatorial *= j;
    }

    // Calculo do termo atual
    termoAtual = 1 / i_fatorial;

    // Somo o termo atual no E
    E+= termoAtual;
  }

  // Mostra o valor do E
  printf("E : %f\n", E);  
}

/**
 *
 */
 
// Maior n�mero positivo com sinal
#define MAIOR_POSITIVO INT32_MAX
 
void exercicio09(void) {
  
  int numero, retorno;
  int maiorAtual = 0;
  int menorAtual = MAIOR_POSITIVO;


  // Interra��o com o usu�rio
  printf("Digite uma sequencia de numeros inteiros positivos.\n"\
         "A cada numero, de <enter>.\n"\
         "O valor zero finaliza a sequencia.\n"\
         "Ao final sera exibido o maior e o menor numero da sequencia.\n");

  // La�o enquanto o usu�rio digitar n�meros maiores ou iguais a zero
  do {

    printf("Numero:> ");
    retorno = scanf("%d", &numero);

    // Se o n�mero atual � maior que o j� conhecido, troca
    if (numero > maiorAtual) {
      maiorAtual = numero;
    }

    // Se o n�mero atual � menor que o j� conhecido, troca
    if ((numero > 0) && (numero < menorAtual)) {
      menorAtual = numero;
    }



  } while (numero > 0);

  // Verifica se houve alguma troca
  if (menorAtual == MAIOR_POSITIVO) {
    // N�o houve troca
    printf("Sequencia vazia :-(\n");
  }
  else {

    // Mostra o maior e o menor valor encontrado
    printf("Resultado:\n"\
      "Maior: %d\n"\
      "Menor: %d\n",
      maiorAtual, menorAtual);
  }  
}

/**
 *
 */
void exercicio10(void) {
  
  int tamanho;
  int i, retorno;
  int Fn, Fn1 = 0, Fn2 = 1;

  // Intera��o com o usu�rio
  printf("Digite o numero de termos da serie de Fibonacci: ");
  retorno = scanf("%d", &tamanho);

  for (i = 0; i < tamanho; i++) {

    // Calcula o termo atual
    Fn = Fn1 + Fn2;

    // Mostra o n�mero da sequencia
    printf("%d ", Fn);

    // Atualiza os termos
    Fn2 = Fn1;
    Fn1 = Fn;
  }
  printf("\n");
}

/**
* Fun��o principal do programa onde o mesmo ser� iniciado.
* @param argc N�mero de par�metros.
* @param argv Valores dos par�metros.
* @return SUCESSO caso o programa seja executado corretamente, ou caso contr�rio,
* o c�digo do erro ocorrido.
*/
int main(int argc, char ** argv) {

  int nExercicio;

  do {
    printf("Digite o numero do exercicio que quer executar [1:10]. 0 para sair: ");
    scanf("%d", &nExercicio);

    switch (nExercicio) {
      case 0: break;
      case 1:
      case 2:
      case 3:
      case 5:
      case 6:
        printf("Nao resolvido ainda :-(\n");
        break;
      case 4:
        exercicio04();
        break;
      case 7:
        exercicio07();
        break;
      case 8:
        exercicio08();
        break;
      case 9:
        exercicio09();
        break;
      case 10:
        exercicio10();
        break;
      default: {
        printf("Voce escolheu um exercicio invalido.\n");
      }
    }

    // Adiciono uma quebra de linha para separar cada execu��o de exerc�cio
    printf("\n");

  } while (nExercicio != 0);

  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}