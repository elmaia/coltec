// Aula03_A.pdf
// Slide 19

// -------------------------------------------------------------------------------------------------
// Exercício 1
// Implemente algoritmo para Imprimir os números ímpares de 0 a 100.
// -------------------------------------------------------------------------------------------------
Início
  // Declaração das variáveis
  inteiro i;
  constante inteiro MAIOR_NUMERO = 100;
  booleano eImpar;
  
  // Percorre os números verificando se são impares
  i = 0;
  enquanto i <= MAIOR_NUMERO faça
    eImpar = (i MOD 2) != 0;
    se eImpar então
      imprime(i + " é impar.");
    fim-se
  
    i = i + 1;
  fim-enquanto
Fim

// -------------------------------------------------------------------------------------------------
// Exercício 2
// Implemente um algoritmo e seu fluxograma que calcule a
// tabuada de 1 a 10 para um número NUM, fornecido pelo usuário.
// -------------------------------------------------------------------------------------------------
Início
  // Declaração das variáveis
  inteiro numero, i;
  
  // Obtem o número do usuário
  imprime("Digite o número que deseja a tabuada: ");
  leia(numero);
  
  // Imprime a tabuada
  // @IMPORTANTE Não é necessário o uso de constante nesse ponto
  // porque tabuada, em geral, é de 1 a 10 mesmo ;-)
  i = 1;
  enquanto i <= 10 faça
    imprime(numero + " x " + i + " = " + (num * i));
    i = i + 1;
  fim-enquanto
Fim

// -------------------------------------------------------------------------------------------------
// Exercício 3
// Implemente o algoritmo que leia uma quantidade
// indeterminada de valores do usuário, e retorne a multiplicação
// desses valores. O programa deverá multiplicar enquanto o
// valor fornecido pelo usuário for diferente de 0.
// -------------------------------------------------------------------------------------------------
Início
  // Declaração das variáveis
  real numero, totalMultiplicacao;

  // Instruções
  imprime("Multiplicação dos números.");
  imprime("0(ZERO) encerra a multiplicação.");

  // Leitura do número
  imprime("Digite o número: ")
  leia(numero);
  
  // @IMPORTANTE Esse detalhe passou despercebido durante a aula.
  // Se o usuário digitar 0 logo de cara, o total da multiplicação
  // deve ser 0, mas do jeito que estava, o resultado seria 1.0, pois
  // ele não entraria no laço e imprimiria o totalMultiplicacao.
  // @ERRO Do trecho abaixo, só tinha a linha totalMultiplicacao = 1.0;
  se numero == 0 então
    totalMultiplicacao = 0.0;
  senão
    totalMultiplicacao = 1.0;
  fim-se
  
  // Vai multiplicando até o usuário digitar 0
  enquanto numero != 0 faça
    totalMultiplicacao = totalMultiplicacao * numero;
  
    imprime("Digite o número: ")
    leia(numero);
  fim-enquanto;
  
  // Informa o total da multiplicação
  imprime("O produto de todos os números é " + totalMultiplicacao);
Fim

// -------------------------------------------------------------------------------------------------
// Exercício 4
// Implemente um algoritmo e seu fluxograma que imprima todos
// os divisores de um número fornecido pelo usuário
// -------------------------------------------------------------------------------------------------
Início
  // Declaração das variáveis
  inteiro numero, i;
  booleano eDivisor;
  
  // Solicita ao usuário o número
  imprime("Digite o número que deseja saber seus divisores: ");
  leia(numero);
  
  // Percorre todos os números de 1 até NUMERO verificando se é divisores
  i = 1;
  enquanto i <= numero faça
    eDivisor = (numero MOD i) == 0;
    se eDivisor então
      imprime(i + " é divisor de " + numero);
    fim-se
    i = i + 1;
  fim-enquanto
Fim

// -------------------------------------------------------------------------------------------------
// Exercício 5
// Implemente um algoritmo leia a nota final de 30 alunos, e
// contabilize quantos alunos foram aprovados, e quantos alunos
// foram reprovados. Além disso, seu algoritmo deverá imprimir o
// percentual de aprovação da turma
// @OBSERVAÇÃO Solicitei que fizesse o exercício para qualquer
// número de alunos, não apenas 30.
// -------------------------------------------------------------------------------------------------
Início
  // Declaração das variáveis
  inteiro i, nAlunos, nAprovados, nReprovados;
  real nota, percAprovados;
  constante inteiro NOTA_APROVACAO = 60;
  
  // Obtem o número de alunos
  imprime("Digite o número de alunos: ");
  leia(nAlunos);
  
  nAprovados = 0;
  i = 1;
  enquanto i <= nAlunos faça
    // Solicita a nota
    imprime("Digite a nota do aluno " + i + ":");
    leia(nota);
    
    // Verifica se foi aprovado
    se nota >= NOTA_APROVACAO então
      nAprovados = nAprovados + 1;
    fim-se
    
    i = i + 1;
  fim-enquanto
  
  // Calcula o número de reprovados e o percentual de aprovação
  nReprovados = nAlunos - nAprovados;
  percAprovados = nAprovados * 100.0 / nAlunos;
  
  // Informa ao usuário
  imprime("A turma com " + nAlunos + " obteve o seguinte resultado:");
  imprime("Aprovados: " + nAprovados + " / Reprovados: " + nReprovados);
  imprime("Percentual de aprovação: " + percAprovados + "%");
Fim
