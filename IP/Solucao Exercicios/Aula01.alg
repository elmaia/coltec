// Aula01
// Slide 37

// -------------------------------------------------------------------------------------------------
// Exercício 1
// Faça um programa que leia e imprima o nome, idade e sexo do
// usuário;
// -------------------------------------------------------------------------------------------------
Início
  // Declaração das variáveis
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
  
  // Saída para o usuário
  imprime(nome + " tem " + idade + " anos e é do sexo " + sexo);
Fim

// -------------------------------------------------------------------------------------------------
// Exercício 2
// Faça um programa que leia o nome de um aluno e a sua nota
// de três provas. Em seguida, imprima o nome do aluno junto
// da média das notas;
// -------------------------------------------------------------------------------------------------
Início
  // Declaração das variáveis
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
  
  // Calcula a média das notas das três provas
  /* Observação: Esse trecho não é modificável para que suporte
     mais do que três notas, por isso a constante literal 3
     não representa uma coisa terrível no código. */
  mediaNotas = (nota1 + nota2 + nota3) / 3;
  
  // Saída para o usuário
  imprime("Aluno:" + nome + " / Média Provas:" + mediaNotas);
Fim

// -------------------------------------------------------------------------------------------------
// Exercício 3
// Faça um algoritmo que leia o numerador e o denominador de
// uma fração e transforme-o em um número decimal.
// -------------------------------------------------------------------------------------------------
Início
  // Declaração das variáveis
  inteiro: numerador, denominador;
  real: numDecimal;
  
  // Leitura dos dados
  imprime("Digite o numerador:");
  leia(numerador);
  imprime("Digite o denominador");
  leia(denominador);
  
  // Transforma em decimal
  /* Truque: A divisão de INTEIRO/INTEIRO dá inteiro, por isso é necessário
     transformar um dos dois em REAL antes de realizar a divisão.
     @IMPORTANTE Não é possível dividir por ZERO, então o correto é não deixar
     essa divisão acontecer, caso o denominador seja ZERO. No entanto, nesse
     momento do curso, não é possível testar isso. Mas esteja atento para
     que, futuramente, o teste seja feito corretamente.
  */
  numDecimal = numerador * 1.0 / denominador;
  
  // Saída para o usuário
  imprime("Número em decimal:" + numDecimal);
Fim
