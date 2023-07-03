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
 * Faça um programa que apresente o seguinte menu para o
 * usuário:
 * Escolha uma opção de calculo para dois numeros:
 * 1 – Soma
 * 2 – Produto
 * 3 – Quociente
 * 0 – Sair
 * Opcao:
 * O menu acima deve ser apresentado para o usuário enquanto ele não
 * escolher a opção 0 (sair do programa). O usuário fornecerá 2 números se
 * escolher as opções de cálculo 1, 2 ou 3. Para cada opção de cálculo deve
 * existir (obrigatoriamente) uma função definida (soma, produto e
 * quociente dos dois números fornecidos pelo usuário). O resultado do
 * cálculo deve ser escrito na tela.
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
 Faça uma função que receba a idade de uma pessoa em
 anos, meses e dias e retorna essa idade expressa em dias.
 Considere cada ano como 365 dias e cada mês como 30 dias.
 */
void questao02(void) {
  
  int anos, meses, dias;
  int idadeDias;
  
  // Obtem os dados do usuário
  printf("Calculadora de dias de vida.\n");
  printf("Digite a quantidade de anos, meses e dias desde o seu nascimento.\n");
  printf("Anos: ");
  scanf("%d", &anos);
  printf("Meses: ");
  scanf("%d", &meses);
  printf("Dias: ");
  scanf("%d", &dias);
  
  // Calcula o número de dias
  idadeDias = idadeEmDias(anos, meses, dias);
  
  // Mostra o resultado para o usuário
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
  
  // O tempo restante já é a quantidade de segundos
  segundos = tempoSegundos;
  
  // Mostra o resultado
  printf("Tempo experimento: %02d:%02d:%02d", horas, minutos, segundos);  
}

/**
 * Faça um procedimento que receba por parâmetro o tempo
 * de duração de um experimento expresso em segundos e imprima na tela esse
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
  
  // Verifica se é 1, pois 1 não é primo.
  if (numero == 1) return false;
  
  for(i = 1; i < numero; i++) {
    // Verifica se é divisor
    if ((numero % i) == 0) return false;
  }
  
  // Se chegou até aqui é porque é divisível apenas por 1 e ele mesmo
  return true;
}

/**
 * Implemente uma função que receba um número inteiro como
 * entrada e verifique se esse número é primo ou não.
 */
void questao04(void) {
  
  unsigned int numero;
  
  printf("Teste de numero Primo.\n");
  printf("Digite o numero pra saber se eh primo.\n");
  printf(":> ");
  scanf("%u", &numero);
  
  // Verifica se é primo
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
 * Faça uma função que receba um valor N inteiro e positivo
 * e que calcula o fatorial deste valor.
 */
void questao05(void) {
  
  uint64_t fat;
  int numero;
  
  // Obtem o número para calcular o fatorial
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
 * Faça uma função que calcule um elemento do triângulo de Pascal.
 * Utilize essa função para imprimir o triângulo com alturas variando de 0 a 10.
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
 * Faça uma função que recebe três notas de um aluno e calcula sua média. 
 * Também faça uma função que verifica se um aluno foi aprovado.
 * Faça um programa que leia três notas de N alunos e contabilize quantos
 * alunos foram aprovados e quantos foram reprovados. Além disso, seu
 * programa deverá imprimir o percentual de aprovação da turma.
 * Para contar como aprovado, a nota deve ser igual ou superior à 60 pontos.
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
    
    // Obtem a média
    media = calculaMedia(nota1, nota2, nota3);
    
    // Verifica se foi aprovado
    if (estaAprovado(media)) {
      nAlunosAprovados++;
    }
  }
  
  // Calcula o percentual de aprovação
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
  
  // Retorna o número
  return Fn;
}

/**
 * Fazer uma função para calcular o número de Fibonacci.
 * Em seguida faça um programa para calcular e mostrar os N primeiros termos
 * da série de Fibonacci. O número N é fornecido pelo usuário. A série de
 * Fibonacci é : 1 1 2 3 5 8 13 ... Isto é f1 = f2 = 1, f3 = f1 + f2, f4 = f2 + f3
 */
void questao08(void) {

  int tamanho;
  int i;

  // Interação com o usuário
  printf("Serie de Fibonacci.\n");
  printf("Digite o numero de termos da serie: ");
  (void)scanf("%d", &tamanho);

  for (i = 1; i <= tamanho; i++) {
    // Mostra o número da serie
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

  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}