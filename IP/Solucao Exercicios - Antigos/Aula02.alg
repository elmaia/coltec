// aula02 - algoritmos - estruturas condicionais.pdf
// Slides 24 e 25

// -------------------------------------------------------------------------------------------------
// Exerc�cio 1
// Escreva o algoritmo e fluxograma para ler um n�mero inteiro e
// informar se ele � par ou �mpar
// -------------------------------------------------------------------------------------------------
In�cio
  // Declara��o das vari�veis
  inteiro numero;
  booleano ePar;
  
  // Leitura dos dados
  imprime("Digite o n�mero para saber se � par ou impar:");
  leia(numero);
  
  // � par se o resto da divis�o por 2 � ZERO
  ePar = (numero MOD 2) == 0;
  
  // Informa ao usu�rio se o n�mero � par ou impar
  Se ePar ent�o
    imprime("O n�mero " + numero + " � par.");
  sen�o
    imprime("O n�mero " + numero + " � impar.");
  fim-se
Fim

// -------------------------------------------------------------------------------------------------
// Exerc�cio 2
// Escreva o algoritmo e fluxograma para ler dois inteiros e
// determinar qual � o maior entre eles ou se eles s�o iguais;
// -------------------------------------------------------------------------------------------------
In�cio
  // Declara��o das vari�veis
  inteiro numero1, numero2;
  
  // Leitura dos dados
  imprime("Digite os n�mero para compar�-los.");
  imprime("N�mero 1:");
  leia(numero1);
  imprime("N�mero 2:");
  leia(numero2);
  
  // Verifica quem � maior que quem
  se numero1 == numero2 ent�o
    imprime("N�mero 1 e N�mero 2 s�o iguais. " + numero1 + "=" + numero2);
  sen�o
    // Se n�o s�o iguais, ent�o um � maior que outro
    se numero1 > numero2 ent�o
      // N�mero 1 � maior que N�mero 2
      imprime("N�mero 1 � MAIOR que N�mero 2. " + numero1 + ">" + numero2);
    sen�o
      // N�mero 1 � menor que N�mero 2;
      imprime("N�mero 1 � MENOR que N�mero 2. " + numero1 + "<" + numero2);
    fim-se
  fim-se
Fim

// -------------------------------------------------------------------------------------------------
// Exerc�cio 3
// Desenvolva um algoritmo para ler o n�mero do dia da semana
// e imprimir o seu respectivo nome por extenso. Considerar o
// n�mero 1 como domingo, 2 para segunda etc. Caso o dia da
// semana n�o exista (menor do que 1 ou maior do que 7), exibir
// a mensagem "Dia da semana inv�lido".
// -------------------------------------------------------------------------------------------------
In�cio
  // Declara��o das vari�veis
  inteiro diaSemana;
  constante inteiro MENOR_DIA_SEMANA = 1;
  constante inteiro MAIOR_DIA_SEMANA = 7;
  
  // Solicita o n�mero do dia da semana
  imprime("Digite o n�mero do dia da semana (" + 
          MENOR_DIA_SEMANA + 
          "-" + 
          MAIOR_DIA_SEMANA
          "):");
  leia(diaSemana);
  
  // Verifica se est� nos limites corretos
  // @IMPORTANTE N�o precisa desse rigor com o caso da constante. 
  // Esse exemplo est� mais para ilustrar sua utiliza��o que utilidade
  // ou extensibilidade, propriamente dito.
  // Como a parte do SEN�O n�o � facilmente extens�vel para outros valores,
  // o uso das constantes � desnecess�rio.
  se (diaSemana < MENOR_DIA_SEMANA) E (diaSemana > MAIOR_DIA_SEMANA) ent�o
    imprime("Dia da semana inv�lido.");
  sen�o
    // @OBSERVA��O Existem maneiras mais elegantes de se fazer isso.
    // Essa poss�vel solu��o envolveria o uso de arrays, que n�o foi
    // estudado, por isso, vai com SE-SEN�O mesmo.
    se diaSemana == 1 ent�o
      imprime("Domingo");
    sen�o
      se diaSemana == 2 ent�o
        imprime("Segunda-feira");
      sen�o
        se diaSemana == 3 ent�o
          imprime("Ter�a-feira");
        sen�o
          se diaSemana == 4 ent�o
            imprime("Quarta-feira");
          sen�o
            se diaSemana == 5 ent�o
              imprime("Quinta-feira");
            sen�o
              se diaSemana == 6 ent�o
                imprime("Sexta-feira");
              sen�o
                imprime("S�bado");
              fim-se
            fim-se
          fim-se
        fim-se
      fim-se
    fim-se
  fim-se
Fim

// -------------------------------------------------------------------------------------------------
// Exerc�cio 4
// Fa�a um algoritmo para ler dois n�meros e um dos s�mbolos
// das opera��es: +, -, * e /; Imprimir o resultado da opera��o
// efetuada sobre os n�meros lidos.
// -------------------------------------------------------------------------------------------------
In�cio
  // Declara��o das vari�veis
  real numero1, numero2, resultado;
  caracter operacao;
  
  // Interage com o usu�rio
  imprime("Digite o n�mero 1:");
  leia(numero1);
  imprime("Digite o n�mero 2:");
  leia(numero2);
  imprime("Digite a opera��o (+ - * / ):");
  leia(operacao);
  
  // Se a opera��o n�o � v�lida, mostro que � inv�lida
  // @OBSERVA��O O exerc�cio n�o pede para verificar se a opera��o
  // � v�lida. Estou fazendo apenas como demonstrativo. Voc� pode
  // assumir que o usu�rio vai entrar com uma das opera��es corretamente.
  se N�O((operacao == '+') OU (operacao == '-') OU (operacao == '*') OU (operacao == '/')) ent�o
    imprime("Opera��o " + operacao + " n�o � uma opera��o v�lida.");
  sen�o
    // Realiza a opera��o dependendo da opera��o escolhida
    se operacao == '+' ent�o
      // Adi��o
      resultado = numero1 + numero2;
    sen�o
      se operacao == '-' ent�o
        // Subtra��o
        resultado = numero1 - numero2;
      sen�o
        se operacao == '*' ent�o
          // Multiplica��o
          resultado = numero1 * numero2;
        sen�o
          se operacao == '/' ent�o
            // Divis�o
            resultado = numero1 / numero2;
          sen�o
          fim-se
        fim-se
      fim-se
    fim-se
    
    // Imprime o resultado
    imprime(numero1 + operacao + numero2 + "=" + resultado);
  fim-se
Fim

// -------------------------------------------------------------------------------------------------
// Exerc�cio 5
// Fa�a o algoritmo e fluxograma que leia 3 comprimentos (x,y e
// z) e responda se eles formam um tri�ngulo, ou seja, se x < y
// + z e y < x + z e z < x + y
// -------------------------------------------------------------------------------------------------
In�cio
  // Declara��o das vari�veis
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
  
  // Verifica se � um tri�ngulo
  eTriangulo = (x < (y + z)) E (y < (x + z)) E (z < (x + y));
  
  // Informa ao usu�rio
  se eTriangulo ent�o
    imprime("Os comprimentos " + x + "," + y + "," + z + " FORMAM um tri�ngulo");
  sen�o
    imprime("Os comprimentos " + x + "," + y + "," + z + " N�O FORMAM um tri�ngulo");
  fim-se
Fim

// -------------------------------------------------------------------------------------------------
// Exerc�cio 6
// Escreva o algoritmo para o seguinte problema: tendo como
// dados de entrada a altura e o sexo de uma pessoa, construa
// um programa que calcule seu peso ideal, utilizando as
// seguintes f�rmulas:
// ? para homens: (72.7 * h) - 58 ? para mulheres: (62.1 * h) -
// 44.7 ? Informe tamb�m se a pessoa est� acima ou abaixo
// deste peso.
// -------------------------------------------------------------------------------------------------
In�cio
  // Declara��o das vari�veis
  real altura, peso, pesoIdeal;
  caracter sexo;
  
  // Obtem os dados do usu�rio
  imprime("Digite a altura em cm:")
  leia(altura);
  imprime("Digite o peso em kg:")
  leia(peso);
  imprime("Digite o sexo (M ou F):");
  leia(sexo);
  
  // Calcula o peso ideal dependendo do sexo
  se sexo == 'M' ent�o
    pesoIdeal = (72.7 * altura) - 58;
  sen�o
    pesoIdeal = (62.1 * altura) - 44.7;
  fim-se
  
  // Informa ao usu�rio a situa��o :-@
  se peso <= pesoIdeal ent�o
    imprime("Voc� est� em forma. :-)");
  sen�o
    imprime("Voc� est� acima do peso. :-(");
  fim-se
Fim
