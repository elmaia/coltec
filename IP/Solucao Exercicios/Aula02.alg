// aula02 - algoritmos - estruturas condicionais.pdf
// Slides 24 e 25

// -------------------------------------------------------------------------------------------------
// Exercício 1
// Escreva o algoritmo e fluxograma para ler um número inteiro e
// informar se ele é par ou ímpar
// -------------------------------------------------------------------------------------------------
Início
  // Declaração das variáveis
  inteiro numero;
  booleano ePar;
  
  // Leitura dos dados
  imprime("Digite o número para saber se é par ou impar:");
  leia(numero);
  
  // É par se o resto da divisão por 2 é ZERO
  ePar = (numero MOD 2) == 0;
  
  // Informa ao usuário se o número é par ou impar
  Se ePar então
    imprime("O número " + numero + " é par.");
  senão
    imprime("O número " + numero + " é impar.");
  fim-se
Fim

// -------------------------------------------------------------------------------------------------
// Exercício 2
// Escreva o algoritmo e fluxograma para ler dois inteiros e
// determinar qual é o maior entre eles ou se eles são iguais;
// -------------------------------------------------------------------------------------------------
Início
  // Declaração das variáveis
  inteiro numero1, numero2;
  
  // Leitura dos dados
  imprime("Digite os número para compará-los.");
  imprime("Número 1:");
  leia(numero1);
  imprime("Número 2:");
  leia(numero2);
  
  // Verifica quem é maior que quem
  se numero1 == numero2 então
    imprime("Número 1 e Número 2 são iguais. " + numero1 + "=" + numero2);
  senão
    // Se não são iguais, então um é maior que outro
    se numero1 > numero2 então
      // Número 1 é maior que Número 2
      imprime("Número 1 é MAIOR que Número 2. " + numero1 + ">" + numero2);
    senão
      // Número 1 é menor que Número 2;
      imprime("Número 1 é MENOR que Número 2. " + numero1 + "<" + numero2);
    fim-se
  fim-se
Fim

// -------------------------------------------------------------------------------------------------
// Exercício 3
// Desenvolva um algoritmo para ler o número do dia da semana
// e imprimir o seu respectivo nome por extenso. Considerar o
// número 1 como domingo, 2 para segunda etc. Caso o dia da
// semana não exista (menor do que 1 ou maior do que 7), exibir
// a mensagem "Dia da semana inválido".
// -------------------------------------------------------------------------------------------------
Início
  // Declaração das variáveis
  inteiro diaSemana;
  constante inteiro MENOR_DIA_SEMANA = 1;
  constante inteiro MAIOR_DIA_SEMANA = 7;
  
  // Solicita o número do dia da semana
  imprime("Digite o número do dia da semana (" + 
          MENOR_DIA_SEMANA + 
          "-" + 
          MAIOR_DIA_SEMANA
          "):");
  leia(diaSemana);
  
  // Verifica se está nos limites corretos
  // @IMPORTANTE Não precisa desse rigor com o caso da constante. 
  // Esse exemplo está mais para ilustrar sua utilização que utilidade
  // ou extensibilidade, propriamente dito.
  // Como a parte do SENÃO não é facilmente extensível para outros valores,
  // o uso das constantes é desnecessário.
  se (diaSemana < MENOR_DIA_SEMANA) E (diaSemana > MAIOR_DIA_SEMANA) então
    imprime("Dia da semana inválido.");
  senão
    // @OBSERVAÇÃO Existem maneiras mais elegantes de se fazer isso.
    // Essa possível solução envolveria o uso de arrays, que não foi
    // estudado, por isso, vai com SE-SENÃO mesmo.
    se diaSemana == 1 então
      imprime("Domingo");
    senão
      se diaSemana == 2 então
        imprime("Segunda-feira");
      senão
        se diaSemana == 3 então
          imprime("Terça-feira");
        senão
          se diaSemana == 4 então
            imprime("Quarta-feira");
          senão
            se diaSemana == 5 então
              imprime("Quinta-feira");
            senão
              se diaSemana == 6 então
                imprime("Sexta-feira");
              senão
                imprime("Sábado");
              fim-se
            fim-se
          fim-se
        fim-se
      fim-se
    fim-se
  fim-se
Fim

// -------------------------------------------------------------------------------------------------
// Exercício 4
// Faça um algoritmo para ler dois números e um dos símbolos
// das operações: +, -, * e /; Imprimir o resultado da operação
// efetuada sobre os números lidos.
// -------------------------------------------------------------------------------------------------
Início
  // Declaração das variáveis
  real numero1, numero2, resultado;
  caracter operacao;
  
  // Interage com o usuário
  imprime("Digite o número 1:");
  leia(numero1);
  imprime("Digite o número 2:");
  leia(numero2);
  imprime("Digite a operação (+ - * / ):");
  leia(operacao);
  
  // Se a operação não é válida, mostro que é inválida
  // @OBSERVAÇÃO O exercício não pede para verificar se a operação
  // é válida. Estou fazendo apenas como demonstrativo. Você pode
  // assumir que o usuário vai entrar com uma das operações corretamente.
  se NÃO((operacao == '+') OU (operacao == '-') OU (operacao == '*') OU (operacao == '/')) então
    imprime("Operação " + operacao + " não é uma operação válida.");
  senão
    // Realiza a operação dependendo da operação escolhida
    se operacao == '+' então
      // Adição
      resultado = numero1 + numero2;
    senão
      se operacao == '-' então
        // Subtração
        resultado = numero1 - numero2;
      senão
        se operacao == '*' então
          // Multiplicação
          resultado = numero1 * numero2;
        senão
          se operacao == '/' então
            // Divisão
            resultado = numero1 / numero2;
          senão
          fim-se
        fim-se
      fim-se
    fim-se
    
    // Imprime o resultado
    imprime(numero1 + operacao + numero2 + "=" + resultado);
  fim-se
Fim

// -------------------------------------------------------------------------------------------------
// Exercício 5
// Faça o algoritmo e fluxograma que leia 3 comprimentos (x,y e
// z) e responda se eles formam um triângulo, ou seja, se x < y
// + z e y < x + z e z < x + y
// -------------------------------------------------------------------------------------------------
Início
  // Declaração das variáveis
  real x, y, z;
  booleano eTriangulo;
  
  // Obtem os comprimentos dos lados
  imprime("Digite os comprimentos dos lados:");
  imprime("Lado 1:");
  leia(x);
  imprime("Lado 2:");
  leia(y);
  imprime("Lado 3:");
  leia(z);
  
  // Verifica se é um triângulo
  eTriangulo = (x < (y + z)) E (y < (x + z)) E (z < (x + y));
  
  // Informa ao usuário
  se eTriangulo então
    imprime("Os comprimentos " + x + "," + y + "," + z + " FORMAM um triângulo");
  senão
    imprime("Os comprimentos " + x + "," + y + "," + z + " NÃO FORMAM um triângulo");
  fim-se
Fim

// -------------------------------------------------------------------------------------------------
// Exercício 6
// Escreva o algoritmo para o seguinte problema: tendo como
// dados de entrada a altura e o sexo de uma pessoa, construa
// um programa que calcule seu peso ideal, utilizando as
// seguintes fórmulas:
// ? para homens: (72.7 * h) - 58 ? para mulheres: (62.1 * h) -
// 44.7 ? Informe também se a pessoa está acima ou abaixo
// deste peso.
// -------------------------------------------------------------------------------------------------
Início
  // Declaração das variáveis
  real altura, peso, pesoIdeal;
  caracter sexo;
  
  // Obtem os dados do usuário
  imprime("Digite a altura em cm:")
  leia(altura);
  imprime("Digite o peso em kg:")
  leia(peso);
  imprime("Digite o sexo (M ou F):");
  leia(sexo);
  
  // Calcula o peso ideal dependendo do sexo
  se sexo == 'M' então
    pesoIdeal = (72.7 * altura) - 58;
  senão
    pesoIdeal = (62.1 * altura) - 44.7;
  fim-se
  
  // Informa ao usuário a situação :-@
  se peso <= pesoIdeal então
    imprime("Você está em forma. :-)");
  senão
    imprime("Você está acima do peso. :-(");
  fim-se
Fim
