// aula03 - algoritmos - estruturas repeticao.pdf
// Slide 19

// -------------------------------------------------------------------------------------------------
// Exerc�cio 1
// Implemente algoritmo para Imprimir os n�meros �mpares de 0 a 100.
// -------------------------------------------------------------------------------------------------
In�cio
  // Declara��o das vari�veis
  inteiro i;
  constante inteiro MAIOR_NUMERO = 100;
  booleano eImpar;
  
  // Percorre os n�meros verificando se s�o impares
  i = 0;
  enquanto i <= MAIOR_NUMERO fa�a
    eImpar = (i MOD 2) != 0;
    se eImpar ent�o
      imprime(i + " � impar.");
    fim-se
  
    i = i + 1;
  fim-enquanto
Fim

// -------------------------------------------------------------------------------------------------
// Exerc�cio 2
// Implemente um algoritmo e seu fluxograma que calcule a
// tabuada de 1 a 10 para um n�mero NUM, fornecido pelo usu�rio.
// -------------------------------------------------------------------------------------------------
In�cio
  // Declara��o das vari�veis
  inteiro numero, i;
  
  // Obtem o n�mero do usu�rio
  imprime("Digite o n�mero que deseja a tabuada: ");
  leia(numero);
  
  // Imprime a tabuada
  // @IMPORTANTE N�o � necess�rio o uso de constante nesse ponto
  // porque tabuada, em geral, � de 1 a 10 mesmo ;-)
  i = 1;
  enquanto i <= 10 fa�a
    imprime(numero + " x " + i + " = " + (num * i));
    i = i + 1;
  fim-enquanto
Fim

// -------------------------------------------------------------------------------------------------
// Exerc�cio 3
// Implemente o algoritmo que leia uma quantidade
// indeterminada de valores do usu�rio, e retorne a multiplica��o
// desses valores. O programa dever� multiplicar enquanto o
// valor fornecido pelo usu�rio for diferente de 0.
// -------------------------------------------------------------------------------------------------
In�cio
  // Declara��o das vari�veis
  real numero, totalMultiplicacao;

  // Instru��es
  imprime("Multiplica��o dos n�meros.");
  imprime("0(ZERO) encerra a multiplica��o.");

  // Leitura do n�mero
  imprime("Digite o n�mero: ")
  leia(numero);
  
  // @IMPORTANTE Esse detalhe passou despercebido durante a aula.
  // Se o usu�rio digitar 0 logo de cara, o total da multiplica��o
  // deve ser 0, mas do jeito que estava, o resultado seria 1.0, pois
  // ele n�o entraria no la�o e imprimiria o totalMultiplicacao.
  // @ERRO Do trecho abaixo, s� tinha a linha totalMultiplicacao = 1.0;
  se numero == 0 ent�o
    totalMultiplicacao = 0.0;
  sen�o
    totalMultiplicacao = 1.0;
  fim-se
  
  // Vai multiplicando at� o usu�rio digitar 0
  enquanto numero != 0 fa�a
    totalMultiplicacao = totalMultiplicacao * numero;
  
    imprime("Digite o n�mero: ")
    leia(numero);
  fim-enquanto;
  
  // Informa o total da multiplica��o
  imprime("O produto de todos os n�meros � " + totalMultiplicacao);
Fim

// -------------------------------------------------------------------------------------------------
// Exerc�cio 4
// Implemente um algoritmo e seu fluxograma que imprima todos
// os divisores de um n�mero fornecido pelo usu�rio
// -------------------------------------------------------------------------------------------------
In�cio
  // Declara��o das vari�veis
  inteiro numero, i;
  booleano eDivisor;
  
  // Solicita ao usu�rio o n�mero
  imprime("Digite o n�mero que deseja saber seus divisores: ");
  leia(numero);
  
  // Percorre todos os n�meros de 1 at� NUMERO verificando se � divisores
  i = 1;
  enquanto i <= numero fa�a
    eDivisor = (numero MOD i) == 0;
    se eDivisor ent�o
      imprime(i + " � divisor de " + numero);
    fim-se
    i = i + 1;
  fim-enquanto
Fim

// -------------------------------------------------------------------------------------------------
// Exerc�cio 5
// Implemente um algoritmo leia a nota final de 30 alunos, e
// contabilize quantos alunos foram aprovados, e quantos alunos
// foram reprovados. Al�m disso, seu algoritmo dever� imprimir o
// percentual de aprova��o da turma
// @OBSERVA��O Solicitei que fizesse o exerc�cio para qualquer
// n�mero de alunos, n�o apenas 30.
// -------------------------------------------------------------------------------------------------
In�cio
  // Declara��o das vari�veis
  inteiro i, nAlunos, nAprovados, nReprovados;
  real nota, percAprovados;
  constante inteiro NOTA_APROVACAO = 60;
  
  // Obtem o n�mero de alunos
  imprime("Digite o n�mero de alunos: ");
  leia(nAlunos);
  
  nAprovados = 0;
  i = 1;
  enquanto i <= nAlunos fa�a
    // Solicita a nota
    imprime("Digite a nota do aluno " + i + ":");
    leia(nota);
    
    // Verifica se foi aprovado
    se nota >= NOTA_APROVACAO ent�o
      nAprovados = nAprovados + 1;
    fim-se
    
    i = i + 1;
  fim-enquanto
  
  // Calcula o n�mero de reprovados e o percentual de aprova��o
  nReprovados = nAlunos - nAprovados;
  percAprovados = nAprovados * 100.0 / nAlunos;
  
  // Informa ao usu�rio
  imprime("A turma com " + nAlunos + " obteve o seguinte resultado:");
  imprime("Aprovados: " + nAprovados + " / Reprovados: " + nReprovados);
  imprime("Percentual de aprova��o: " + percAprovados + "%");
Fim

// Slide 34

// -------------------------------------------------------------------------------------------------
// Exerc�cio 6
// Implemente algoritmo para Imprimir os n�meros �mpares de 0 a 100.
// REPITA-AT�
// -------------------------------------------------------------------------------------------------
In�cio
  // Declara��o das vari�veis
  inteiro i;
  constante inteiro MAIOR_NUMERO = 100;
  booleano eImpar;
  
  // Percorre os n�meros verificando se s�o impares
  i = 0;
  repita 
    eImpar = (i MOD 2) != 0;
    se eImpar ent�o
      imprime(i + " � impar.");
    fim-se
  
    i = i + 1;
  at� i <= MAIOR_NUMERO;
Fim

// -------------------------------------------------------------------------------------------------
// Exerc�cio 6
// Implemente algoritmo para Imprimir os n�meros �mpares de 0 a 100.
// PARA
// -------------------------------------------------------------------------------------------------
In�cio
  // Declara��o das vari�veis
  inteiro i;
  constante inteiro MAIOR_NUMERO = 100;
  booleano eImpar;
  
  // Percorre os n�meros verificando se s�o impares
  para i de 0 at� MAIOR_NUMERO fa�a
    eImpar = (i MOD 2) != 0;
    se eImpar ent�o
      imprime(i + " � impar.");
    fim-se
  fim-para
Fim

// -------------------------------------------------------------------------------------------------
// Exerc�cio 7
// Implemente um algoritmo e seu fluxograma que calcule a
// tabuada de 1 a 10 para um n�mero NUM, fornecido pelo usu�rio.
// REPITA-AT�
// -------------------------------------------------------------------------------------------------
In�cio
  // Declara��o das vari�veis
  inteiro numero, i;
  
  // Obtem o n�mero do usu�rio
  imprime("Digite o n�mero que deseja a tabuada: ");
  leia(numero);
  
  // Imprime a tabuada
  // @IMPORTANTE N�o � necess�rio o uso de constante nesse ponto
  // porque tabuada, em geral, � de 1 a 10 mesmo ;-)
  i = 1;
  repita
    imprime(numero + " x " + i + " = " + (num * i));
    i = i + 1;
  at� i <= 10;
Fim

// -------------------------------------------------------------------------------------------------
// Exerc�cio 7
// Implemente um algoritmo e seu fluxograma que calcule a
// tabuada de 1 a 10 para um n�mero NUM, fornecido pelo usu�rio.
// PARA
// -------------------------------------------------------------------------------------------------
In�cio
  // Declara��o das vari�veis
  inteiro numero, i;
  
  // Obtem o n�mero do usu�rio
  imprime("Digite o n�mero que deseja a tabuada: ");
  leia(numero);
  
  // Imprime a tabuada
  // @IMPORTANTE N�o � necess�rio o uso de constante nesse ponto
  // porque tabuada, em geral, � de 1 a 10 mesmo ;-)
  para i de 0 at� 10 fa�a
    imprime(numero + " x " + i + " = " + (num * i));
  fim-para
Fim

// -------------------------------------------------------------------------------------------------
// Exerc�cio 8
// Implemente o algoritmo que leia uma quantidade
// indeterminada de valores do usu�rio, e retorne a multiplica��o
// desses valores. O programa dever� multiplicar enquanto o
// valor fornecido pelo usu�rio for diferente de 0.
// REPITA-AT�
// -------------------------------------------------------------------------------------------------
In�cio
  // Declara��o das vari�veis
  real numero, totalMultiplicacao;
  inteiro nNumerosDigitados;

  // Instru��es
  imprime("Multiplica��o dos n�meros.");
  imprime("0(ZERO) encerra a multiplica��o.");

  totalMultiplicacao = 1.0;
  numero = 1.0;
  
  // Vai multiplicando at� o usu�rio digitar 0
  nNumerosDigitados = 0;
  repita
    totalMultiplicacao = totalMultiplicacao * numero;
  
    imprime("Digite o n�mero: ")
    leia(numero);
    
    nNumerosDigitados = nNumerosDigitados + 1;
  at� numero != 0;
  
  // Verifica se s� digitou 1 n�mero. Se for, significa que o usu�rio
  // digitou 0 e portanto, o totalMultiplicacao tem que ser 0, n�o 1;
  se nNumerosDigitados == 1 ent�o
    totalMultiplicacao = 0.0;
  fim-se
  
  // Informa o total da multiplica��o
  imprime("O produto de todos os n�meros � " + totalMultiplicacao);
Fim

// -------------------------------------------------------------------------------------------------
// Exerc�cio 9
// Implemente um algoritmo e seu fluxograma que imprima todos
// os divisores de um n�mero fornecido pelo usu�rio
// REPITA-AT�
// -------------------------------------------------------------------------------------------------
In�cio
  // Declara��o das vari�veis
  inteiro numero, i;
  booleano eDivisor;
  
  // Solicita ao usu�rio o n�mero
  imprime("Digite o n�mero que deseja saber seus divisores: ");
  leia(numero);
  
  // Percorre todos os n�meros de 1 at� NUMERO verificando se � divisores
  i = 1;
  repita
    eDivisor = (numero MOD i) == 0;
    se eDivisor ent�o
      imprime(i + " � divisor de " + numero);
    fim-se
    i = i + 1;
  at� i <= numero;
Fim

// -------------------------------------------------------------------------------------------------
// Exerc�cio 9
// Implemente um algoritmo e seu fluxograma que imprima todos
// os divisores de um n�mero fornecido pelo usu�rio
// PARA
// -------------------------------------------------------------------------------------------------
In�cio
  // Declara��o das vari�veis
  inteiro numero, i;
  booleano eDivisor;
  
  // Solicita ao usu�rio o n�mero
  imprime("Digite o n�mero que deseja saber seus divisores: ");
  leia(numero);
  
  // Percorre todos os n�meros de 1 at� NUMERO verificando se � divisores
  para i de 1 at� numero fa�a
    eDivisor = (numero MOD i) == 0;
    se eDivisor ent�o
      imprime(i + " � divisor de " + numero);
    fim-se
  fim-para
Fim

// -------------------------------------------------------------------------------------------------
// Exerc�cio 10
// Implemente um algoritmo leia a nota final de 30 alunos, e
// contabilize quantos alunos foram aprovados, e quantos alunos
// foram reprovados. Al�m disso, seu algoritmo dever� imprimir o
// percentual de aprova��o da turma
// @OBSERVA��O Solicitei que fizesse o exerc�cio para qualquer
// n�mero de alunos, n�o apenas 30.
// REPITA-AT�
// -------------------------------------------------------------------------------------------------
In�cio
  // Declara��o das vari�veis
  inteiro i, nAlunos, nAprovados, nReprovados;
  real nota, percAprovados;
  constante inteiro NOTA_APROVACAO = 60;
  
  // Obtem o n�mero de alunos
  // @ATEN��O N�o funciona se digitar 0 alunos.
  // Pode assumir que o usu�rio entrou com um n�mero v�lido.
  imprime("Digite o n�mero de alunos: ");
  leia(nAlunos);
  
  nAprovados = 0;
  i = 1;
  enquanto
    // Solicita a nota
    imprime("Digite a nota do aluno " + i + ":");
    leia(nota);
    
    // Verifica se foi aprovado
    se nota >= NOTA_APROVACAO ent�o
      nAprovados = nAprovados + 1;
    fim-se
    
    i = i + 1;
  repita i <= nAlunos;
  
  // Calcula o n�mero de reprovados e o percentual de aprova��o
  nReprovados = nAlunos - nAprovados;
  percAprovados = nAprovados * 100.0 / nAlunos;
  
  // Informa ao usu�rio
  imprime("A turma com " + nAlunos + " obteve o seguinte resultado:");
  imprime("Aprovados: " + nAprovados + " / Reprovados: " + nReprovados);
  imprime("Percentual de aprova��o: " + percAprovados + "%");
Fim

// -------------------------------------------------------------------------------------------------
// Exerc�cio 10
// Implemente um algoritmo leia a nota final de 30 alunos, e
// contabilize quantos alunos foram aprovados, e quantos alunos
// foram reprovados. Al�m disso, seu algoritmo dever� imprimir o
// percentual de aprova��o da turma
// @OBSERVA��O Solicitei que fizesse o exerc�cio para qualquer
// n�mero de alunos, n�o apenas 30.
// PARA
// -------------------------------------------------------------------------------------------------
In�cio
  // Declara��o das vari�veis
  inteiro i, nAlunos, nAprovados, nReprovados;
  real nota, percAprovados;
  constante inteiro NOTA_APROVACAO = 60;
  
  // Obtem o n�mero de alunos
  // @ATEN��O N�o funciona se digitar 0 alunos.
  // Pode assumir que o usu�rio entrou com um n�mero v�lido.
  imprime("Digite o n�mero de alunos: ");
  leia(nAlunos);
  
  nAprovados = 0;
  para i de 1 at� nAlunos fa�a
    // Solicita a nota
    imprime("Digite a nota do aluno " + i + ":");
    leia(nota);
    
    // Verifica se foi aprovado
    se nota >= NOTA_APROVACAO ent�o
      nAprovados = nAprovados + 1;
    fim-se
  fim-para
  
  // Calcula o n�mero de reprovados e o percentual de aprova��o
  nReprovados = nAlunos - nAprovados;
  percAprovados = nAprovados * 100.0 / nAlunos;
  
  // Informa ao usu�rio
  imprime("A turma com " + nAlunos + " obteve o seguinte resultado:");
  imprime("Aprovados: " + nAprovados + " / Reprovados: " + nReprovados);
  imprime("Percentual de aprova��o: " + percAprovados + "%");
Fim
