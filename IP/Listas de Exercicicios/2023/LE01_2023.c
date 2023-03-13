/**
 * @file   LE01_2023.c
 * @brief  Arquivo com a implementa��o de sugest�o de solu��o da LE01.
 * @author Leandro Maia Silva
 * @date   2023-03-13
 */

/* Inclus�es */
#include <stdio.h>

/* Constantes */

// Constante que associa o c�digo de erro 0 ao significado de sucesso
#define SUCESSO  0

/*************************************************************************************************
 * Informa��o!                                                                                   *
 * A sugest�o de solu��o da LE01 usa fun��es e switch/case.                                      *
 * Esses t�picos n�o foram vistos at� o momento, no entanto, para quest�es de compreens�o, basta *
 * olhar cada parte do arquivo como  sendo o corpo do MAIN.                                      *
 *************************************************************************************************/

/**
 * Fa�a o fluxograma e um programa que leia o numerador e
 * o denominador de uma fra��o e imprima ambos seguido do resultado.
 * Considere que todos os n�meros s�o de ponto flutuante.
 */
void exercicio01(void) {
  
  float numerador, denominador, resultado;
  
  // Obtem os valores do usu�rio
  printf("Entre com os valores para calcular o resultado.\n");
  printf("Numerador: ");
  scanf("%f", &numerador);
  printf("Denominador: ");
  scanf("%f", &denominador);
  
  // Calcula e imprime o resultado
  resultado = numerador / denominador;
  printf("%f / %f = %f\n", numerador, denominador, resultado);
}

/**
 * Fa�a o fluxograma e um programa que leia cinco valores
 * inteiros, calcule e imprima a soma deles.
 */
void exercicio02(void) {
  
  int val1, val2, val3, val4, val5, soma;

  // Leitura dos valores digitados pelo usu�rio
  printf("Vamos somar cinco valores. Digite cada valor e aperte <enter>.\n");
  scanf("%d", &val1);
  scanf("%d", &val2);
  scanf("%d", &val3);
  scanf("%d", &val4);
  scanf("%d", &val5);

  // Calcula a soma e mostra o resultado
  soma = val1 + val2 + val3 + val4 + val5;
  printf("A soma dos cinco valores e: %d\n", soma);
}

/**
 * Fa�a o fluxograma e um programa para ler seis valores
 * reais, calcular e imprimir a m�dia aritm�tica deles.
 */
void exercicio03(void) {
  
  float val1, val2, val3, val4, val5, val6, media;

  // Leitura dos valores digitados pelo usu�rio
  printf("Vamos calcular a media de seis valores. Digite cada valor e aperte <enter>.\n");
  scanf("%f", &val1);
  scanf("%f", &val2);
  scanf("%f", &val3);
  scanf("%f", &val4);
  scanf("%f", &val5);
  scanf("%f", &val6);

  // Calcula a m�dia e mostra o resultado
  media = (val1 + val2 + val3 + val4 + val5 + val6) / 6;
  printf("A media dos seis valores e: %f\n", media);
}

/**
 * Fa�a o fluxograma e um programa para calcular e imprimir
 * o valor de H, sendo H = 1/1 + 1/2 + 1/3 + 1/4 + 1/5
 */
void exercicio04(void) {

  float H;

  // Calcula o valor de H
  H = 1 + 1.0f / 2 + 1.0f / 3 + 1.0f / 4 + 1.0f / 5;

  printf("O valor de H e: %f", H);
}

/**
 * Fa�a o fluxograma e um programa que calcule o novo
 * sal�rio de um funcion�rio. Voc� dever� obter o sal�rio atual e o
 * percentual de aumento que ser� dado ao funcion�rio.
 */
void exercicio05(void) {

  float salario, percAumento, valAumento, novoSalario;

  // Obtem os dados
  printf("Digite seu salario atual: ");
  scanf("%f", &salario);
  printf("Digite a porcentagem de aumento: ");
  scanf("%f", &percAumento);

  // Calcula o aumento, novo salario e imprime o valores
  valAumento = salario * (percAumento / 100);
  novoSalario = salario + valAumento;
  printf("Valor do aumento: %.2f\nValor do salario: %.2f\n", valAumento, novoSalario);
}

/**
 * Fa�a um programa que leia o numerador e o denominador
 * de uma fra��o e imprima ambos seguido do resultado, sendo todos com tr�s
 * casas decimais. Considere que todos os n�meros s�o de ponto flutuante.
 */
void exercicio06(void) {
  
  float numerador, denominador, resultado;
  
  // Obtem os valores do usu�rio
  printf("Entre com os valores para calcular o resultado.\n");
  printf("Numerador: ");
  scanf("%f", &numerador);
  printf("Denominador: ");
  scanf("%f", &denominador);
  
  // Calcula e imprime o resultado
  resultado = numerador / denominador;
  printf("%.3f / %.3f = %.3f\n", numerador, denominador, resultado);
}

/**
 * Fa�a um programa que leia as notas de tr�s provas de
 * tr�s alunos e imprime em forma de tabela (um aluno por linha, uma nota
 * por coluna) os valores lidos.
 * Todas as notas devem ter duas casas decimais e elas devem ser separadas
 * por uma tabula��o.
 */
void exercicio07(void) {
  
  float aluno1_nota1, aluno1_nota2, aluno1_nota3;
  float aluno2_nota1, aluno2_nota2, aluno2_nota3;
  float aluno3_nota1, aluno3_nota2, aluno3_nota3;
  
  // Obtem as notas dos alunos
  printf("Vamos ler as notas de tres alunos.\n");
  printf("Aluno 1 - Nota 1: ");
  scanf("%f", &aluno1_nota1);
  printf("Aluno 1 - Nota 2: ");
  scanf("%f", &aluno1_nota2);
  printf("Aluno 1 - Nota 3: ");
  scanf("%f", &aluno1_nota3);
  printf("Aluno 2 - Nota 1: ");
  scanf("%f", &aluno2_nota1);
  printf("Aluno 2 - Nota 2: ");
  scanf("%f", &aluno2_nota2);
  printf("Aluno 2 - Nota 3: ");
  scanf("%f", &aluno2_nota3);
  printf("Aluno 3 - Nota 1: ");
  scanf("%f", &aluno3_nota1);
  printf("Aluno 3 - Nota 2: ");
  scanf("%f", &aluno3_nota2);
  printf("Aluno 3 - Nota 3: ");
  scanf("%f", &aluno3_nota3);
  
  // Imprime as notas em forma de tabela
  printf("Notas:\n");
  printf("Aluno %d\t%.2f\t%.2f\t%.2f\n",1, aluno1_nota1, aluno1_nota2, aluno1_nota3);
  printf("Aluno %d\t%.2f\t%.2f\t%.2f\n",2, aluno2_nota1, aluno2_nota2, aluno2_nota3);
  printf("Aluno %d\t%.2f\t%.2f\t%.2f\n",3, aluno3_nota1, aluno3_nota2, aluno3_nota3);
}

/**
 * Fa�a um programa que leia, nesta ordem, a idade (valor
 * inteiro) de uma pessoa e o sexo (caractere) e em seguida imprima os
 * valores lidos.
 */
void exercicio08(void) {
  
  int idade;
  char sexo;
  
  // Obtem os dados do usu�rio
  printf("Digite a idade: ");
  scanf("%d", &idade);
  printf("Digite o sexo: ");
  scanf(" %c", &sexo);  // <--- O espa�o no inicio remove a quebra de linha que ficou
                        // Essa � uma de v�rias solu��es poss�veis. Para entender
                        // � necess�rio consultar a refer�ncia e ver que o espa�o (' ')
                        // remove quaisquer caracteres "whitespaces", incluindo o '\n'
  
  // Imprime os valores lidos
  printf("Idade: %d\t Sexo: %c\n", idade, sexo);
  
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
  printf("Digite o numero do exercicio que quer executar [1:8]: ");
  scanf("%d%*c", &nExercicio);

  switch (nExercicio) {
    case 1: {
      exercicio01();
      break;
    }
    case 2: {
      exercicio02();
      break;
    }
    case 3: {
      exercicio03();
      break;
    }
    case 4: {
      exercicio04();
      break;
    }
    case 5: {
      exercicio05();
      break;
    }
    case 6: {
      exercicio06();
      break;
    }
    case 7: {
      exercicio07();
      break;
    }
    case 8: {
      exercicio08();
      break;
    }
    default: {
      printf("Voce escolheu um exercicio invalido.\n");
    }
  }

  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}