// Aula01
// Slide 37

// -------------------------------------------------------------------------------------------------
// Exerc�cio 1
// Fa�a um programa que leia e imprima o nome, idade e sexo do
// usu�rio;
// -------------------------------------------------------------------------------------------------
In�cio
  // Declara��o das vari�veis
  string: nome;
  inteiro: idade;
  caracter: sexo;
  
  // Leitura dos dados
  imprime("Digite o nome:");
  leia(nome);
  imprime("Digite a idade:");
  leia(idade);
  imprime("Digite o sexo:");
  leia(sexo);
  
  // Sa�da para o usu�rio
  imprime(nome + " tem " + idade + " anos e � do sexo " + sexo);
Fim

// -------------------------------------------------------------------------------------------------
// Exerc�cio 2
// Fa�a um programa que leia o nome de um aluno e a sua nota
// de tr�s provas. Em seguida, imprima o nome do aluno junto
// da m�dia das notas;
// -------------------------------------------------------------------------------------------------
In�cio
  // Declara��o das vari�veis
  string: nome;
  real: nota1, nota2, nota3, mediaNotas;
  
  // Leitura dos dados
  imprime("Digite o nome do aluno:");
  leia(nome);
  imprime("Digite a nota da Prova 1:");
  leia(nota1);
  imprime("Digite a nota da Prova 2:");
  leia(nota1);
  imprime("Digite a nota da Prova 3:");
  leia(nota1);
  
  // Calcula a m�dia das notas das tr�s provas
  /* Observa��o: Esse trecho n�o � modific�vel para que suporte
     mais do que tr�s notas, por isso a constante literal 3
     n�o representa uma coisa terr�vel no c�digo. */
  mediaNotas = (nota1 + nota2 + nota3) / 3;
  
  // Sa�da para o usu�rio
  imprime("Aluno:" + nome + " / M�dia Provas:" + mediaNotas);
Fim

// -------------------------------------------------------------------------------------------------
// Exerc�cio 3
// Fa�a um algoritmo que leia o numerador e o denominador de
// uma fra��o e transforme-o em um n�mero decimal.
// -------------------------------------------------------------------------------------------------
In�cio
  // Declara��o das vari�veis
  inteiro: numerador, denominador;
  real: numDecimal;
  
  // Leitura dos dados
  imprime("Digite o numerador:");
  leia(numerador);
  imprime("Digite o denominador");
  leia(denominador);
  
  // Transforma em decimal
  /* Truque: A divis�o de INTEIRO/INTEIRO d� inteiro em C, por isso � necess�rio
     transformar um dos dois em REAL antes de realizar a divis�o.
     No entanto, obrigado ao aluno Davi da 105 de 2022 que observou isso, em
     algoritmos existe um operador de divis�o inteira chamado DIV, por essa
     raz�o, utilizar barra (/) para dividir j� faz exatamente o que a quest�o pede.
     @IMPORTANTE N�o � poss�vel dividir por ZERO, ent�o o correto � n�o deixar
     essa divis�o acontecer, caso o denominador seja ZERO. No entanto, nesse
     momento do curso, n�o � poss�vel testar isso. Mas esteja atento para
     que, futuramente, o teste seja feito corretamente.
  */
  numDecimal = numerador / denominador;
  
  // Sa�da para o usu�rio
  imprime("N�mero em decimal:" + numDecimal);
Fim
