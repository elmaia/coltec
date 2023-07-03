#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define SUCESSO 0

// ----------------------------------------------------------------------------

float adicao(float parcelaA, float parcelaB) {
  return parcelaA + parcelaB;
}

float multiplicacao(float fatorA, float fatorB) {
  return fatorA * fatorB;
}

float divisao(float dividendo, float divisor) {
  return dividendo / divisor;
}

/**
 * Fa�a um programa que apresente o seguinte menu para o
 * usu�rio:
 * Escolha uma op��o de calculo para dois numeros:
 * 1 � Soma
 * 2 � Produto
 * 3 � Quociente
 * 0 � Sair
 * Opcao:
 * O menu acima deve ser apresentado para o usu�rio enquanto ele n�o
 * escolher a op��o 0 (sair do programa). O usu�rio fornecer� 2 n�meros se
 * escolher as op��es de c�lculo 1, 2 ou 3. Para cada op��o de c�lculo deve
 * existir (obrigatoriamente) uma fun��o definida (soma, produto e
 * quociente dos dois n�meros fornecidos pelo usu�rio). O resultado do
 * c�lculo deve ser escrito na tela.
 */
void questao01(void) {
  
  int opcao;
  float a, b;

  do {

    printf("Calculadora simples.\n");
    printf("1 - Soma\n");
    printf("2 - Produto\n");
    printf("3 - Quociente\n");
    printf("0 - Sair\n");
    printf("Opcao: ");
    scanf("%d%*c", &opcao);

    switch (opcao) {
    case 0: // Sair
      break;
    case 1: // Soma
      printf("Digite os numeros para somar: ");
      scanf("%f %f", &a, &b);
      printf("%f + %f = %f\n", a, b, adicao(a, b));
      break;
    case 2: // Produto
      printf("Digite os numeros para multiplicar: ");
      scanf("%f %f", &a, &b);
      printf("%f * %f = %f\n", a, b, multiplicacao(a, b));
      break;
    case 3: // Quociente
      printf("Digite os numeros para dividir: ");
      scanf("%f %f", &a, &b);
      printf("%f / %f = %f\n", a, b, divisao(a, b));
      break;
    default:
      printf("Opcao invalida.\n");
    }

  } while (opcao != 0);
}

// ----------------------------------------------------------------------------

#define DIAS_ANO  365
#define DIAS_MES   30

int idadeEmDias(int anos, int meses, int dias) {
  return anos * DIAS_ANO + meses * DIAS_MES + dias;
}

/**
 Fa�a uma fun��o que receba a idade de uma pessoa em
 anos, meses e dias e retorna essa idade expressa em dias.
 Considere cada ano como 365 dias e cada m�s como 30 dias.
 */
void questao02(void) {
  
  int anos, meses, dias;
  int idadeDias;
  
  // Obtem os dados do usu�rio
  printf("Calculadora de dias de vida.\n");
  printf("Digite a quantidade de anos, meses e dias desde o seu nascimento.\n");
  printf("Anos: ");
  scanf("%d", &anos);
  printf("Meses: ");
  scanf("%d", &meses);
  printf("Dias: ");
  scanf("%d", &dias);
  
  // Calcula o n�mero de dias
  idadeDias = idadeEmDias(anos, meses, dias);
  
  // Mostra o resultado para o usu�rio
  printf("Voce ja viveu %d dias desde o seu nascimento.\n", idadeDias);
}

// ----------------------------------------------------------------------------

#define MINUTO_SEGUNDOS    60
#define HORAS_SEGUNDOS     (60 * MINUTO_SEGUNDOS)

void imprimeDuracaoExperimento(int tempoSegundos) {
  
  int horas, minutos, segundos;
  
  // Obtem as horas
  horas = tempoSegundos / HORAS_SEGUNDOS;
  tempoSegundos -= (horas * HORAS_SEGUNDOS);
  
  // Do tempo restante, obtem os minutos
  minutos = tempoSegundos / MINUTO_SEGUNDOS;
  tempoSegundos -= (minutos * MINUTO_SEGUNDOS);
  
  // O tempo restante j� � a quantidade de segundos
  segundos = tempoSegundos;
  
  // Mostra o resultado
  printf("Tempo experimento: %02d:%02d:%02d", horas, minutos, segundos);  
}

/**
 * Fa�a um procedimento que receba por par�metro o tempo
 * de dura��o de um experimento expresso em segundos e imprima na tela esse
 * mesmo tempo em horas, minutos e segundos.
 */ 
void questao03(void) {
  
  int tempoExperimento;
  
  // Obtem o tempo do experimento
  printf("Calcula de Tempo do Experimento.\n");
  printf("Digite a duracao, em segundos, do experimento.\n");
  printf(":> ");
  scanf("%d", &tempoExperimento);
  
  // Imprime o tempo em formato HH:MM:SS
  imprimeDuracaoExperimento(tempoExperimento);
}

// ----------------------------------------------------------------------------

bool ehPrimo(unsigned int numero) {
  
  unsigned int i;
  
  // Verifica se � 1, pois 1 n�o � primo.
  if (numero == 1) return false;
  
  for(i = 1; i < numero; i++) {
    // Verifica se � divisor
    if ((numero % i) == 0) return false;
  }
  
  // Se chegou at� aqui � porque � divis�vel apenas por 1 e ele mesmo
  return true;
}

/**
 * Implemente uma fun��o que receba um n�mero inteiro como
 * entrada e verifique se esse n�mero � primo ou n�o.
 */
void questao04(void) {
  
  unsigned int numero;
  
  printf("Teste de numero Primo.\n");
  printf("Digite o numero pra saber se eh primo.\n");
  printf(":> ");
  scanf("%u", &numero);
  
  // Verifica se � primo
  if (ehPrimo(numero)) {
    printf("O numero %u eh primo.", numero);
  } else {
    printf("O numero %u NAO eh primo.", numero);
  }
}

// ----------------------------------------------------------------------------

uint64_t fatorial(int n) {
  
  int i;
  uint64_t fat = 1;
  
  for(i = 1; i < n; i++) {
    fat*=i;
  }
  
  return fat;  
}

/**
 * Fa�a uma fun��o que receba um valor N inteiro e positivo
 * e que calcula o fatorial deste valor.
 */
void questao05(void) {
  
  uint64_t fat;
  int numero;
  
  // Obtem o n�mero para calcular o fatorial
  printf("Calculadora de Fatorial.\n");
  printf("Digite o numero para calcular o fatorial.\n");
  printf(":> ");
  scanf("%d", numero);
  
  // Calcula numero!
  fat = fatorial(numero);
  
  // Mostra o resultado
  printf("%d! eh %llu\n", numero, fat);
  
}

// ----------------------------------------------------------------------------

uint64_t elementoTrianguloPascal(int linha, int coluna) {
  
  uint64_t elemento;
  
  // elemento = linha! / (coluna! * (linha - coluna)!)
  elemento = fatorial(linha) / (fatorial(coluna) * fatorial(linha - coluna));
  
  return elemento;
}

#define TRIANGULO_PASCAL_ALTURA_MAXIMA         10
#define TRIANGULO_PASCAL_MAIOR_VALOR          252
#define TRIANGULO_PASCAL_LARGURA_MAIOR_VALOR    3

/**
 * Fa�a uma fun��o que calcule um elemento do tri�ngulo de Pascal.
 * Utilize essa fun��o para imprimir o tri�ngulo com alturas variando de 0 a 10.
 */
void questao06(void) {
  
  int altura;
  int i, j;
  
  // Obtem a altura
  printf("Triangulo de Pascal.\n");
  printf("Digite a altura [0:%d]: ", TRIANGULO_PASCAL_ALTURA_MAXIMA);
  scanf("%d%*c", &altura);
  
  // Verifica a faixa
  if ((altura < 0) || (altura > TRIANGULO_PASCAL_ALTURA_MAXIMA)) {
    printf("Altura invalida.\n");
    return;
  }
  
  // Imprime o triangulo
  for(i = 0; i <= altura; i++) {
    for(j = 0; j <= i; j++) {
      printf("%*llu ", TRIANGULO_PASCAL_LARGURA_MAIOR_VALOR, elementoTrianguloPascal(i,j));
    }
    
    // Imprime a quebra de linha
    printf("\n");
  }
}

// ----------------------------------------------------------------------------
#define NUMERO_NOTAS 3

float calculaMedia(float nota1, float nota2, float nota3) {
  return (nota1 + nota2 + nota3) / NUMERO_NOTAS;
}

#define APROVACAO_NOTA_MINIMA  60.0f

bool estaAprovado(float nota) {
  return (nota >= APROVACAO_NOTA_MINIMA);
}

/**
 * Fa�a uma fun��o que recebe tr�s notas de um aluno e calcula sua m�dia. 
 * Tamb�m fa�a uma fun��o que verifica se um aluno foi aprovado.
 * Fa�a um programa que leia tr�s notas de N alunos e contabilize quantos
 * alunos foram aprovados e quantos foram reprovados. Al�m disso, seu
 * programa dever� imprimir o percentual de aprova��o da turma.
 * Para contar como aprovado, a nota deve ser igual ou superior � 60 pontos.
 */
void questao07(void) {
  
  int i;
  int nAlunos;
  int nAlunosAprovados = 0;
  float nota1, nota2, nota3;
  float media;
  float percAprovacao;
  
  
  printf("Notas dos Alunos.\n");
  printf("Digite o numero de alunos: ");
  scanf("%d%*c", &nAlunos);
  
  // Obtem as notas dos alunos
  for(i = 0; i < nAlunos; i++) {
    printf("Notas do aluno %d.\n", i + 1);
    printf("Nota 01: ");
    scanf("%f%*c", &nota1);
    printf("Nota 02: ");
    scanf("%f%*c", &nota2);
    printf("Nota 03: ");
    scanf("%f%*c", &nota3);
    
    // Obtem a m�dia
    media = calculaMedia(nota1, nota2, nota3);
    
    // Verifica se foi aprovado
    if (estaAprovado(media)) {
      nAlunosAprovados++;
    }
  }
  
  // Calcula o percentual de aprova��o
  percAprovacao = ((float)nAlunosAprovados / nAlunos) * 100;
  
  // Mostra as estatisticas
  printf("Estatisticas.\n");
  printf("N alunos....: %4d\n", nAlunos);
  printf("N aprovados.: %4d | Perc: %6.2f\n", nAlunosAprovados, percAprovacao);
  printf("N reprovados: %4d | Perc: %6.2f\n", nAlunos - nAlunosAprovados, 100.0f - percAprovacao);
}

// ----------------------------------------------------------------------------

int numeroFibonacci(int termo) {
  
  int i;
  int Fn, Fn1 = 0, Fn2 = 1;

  for (i = 0; i < termo; i++) {

    // Calcula o termo atual
    Fn = Fn1 + Fn2;

    // Atualiza os termos
    Fn2 = Fn1;
    Fn1 = Fn;
  }
  
  // Retorna o n�mero
  return Fn;
}

/**
 * Fazer uma fun��o para calcular o n�mero de Fibonacci.
 * Em seguida fa�a um programa para calcular e mostrar os N primeiros termos
 * da s�rie de Fibonacci. O n�mero N � fornecido pelo usu�rio. A s�rie de
 * Fibonacci � : 1 1 2 3 5 8 13 ... Isto � f1 = f2 = 1, f3 = f1 + f2, f4 = f2 + f3
 */
void questao08(void) {

  int tamanho;
  int i;

  // Intera��o com o usu�rio
  printf("Serie de Fibonacci.\n");
  printf("Digite o numero de termos da serie: ");
  (void)scanf("%d", &tamanho);

  for (i = 1; i <= tamanho; i++) {
    // Mostra o n�mero da serie
    printf("%d ", numeroFibonacci(i));
  }
  printf("\n");
}

// ----------------------------------------------------------------------------

int main(int argc, char** argv) {

  int opcao;

  do {

    // Menu
    printf("\nEscolha o exercicio para executar [1:8].\n");
    printf("Digite 0 para sair.\n");
    printf("Opcao: ");
    (void)scanf(" %d%*c", &opcao);

    switch (opcao) {
      case 0:
        break;
      case 1:
        questao01();
        break;
      case 2:
        questao02();
        break;
      case 3:
        questao03();
        break;
      case 4:
        questao04();
        break;
      case 5:
        questao05();
        break;
      case 6:
        questao06();
        break;
      case 7:
        questao07();
        break;
      case 8:
        questao08();
        break;
      default:
        printf("Opcao invalida.\n");
    }

  } while (opcao != 0);

  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}