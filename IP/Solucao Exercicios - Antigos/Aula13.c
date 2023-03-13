/**
 * @file   Aula13.c
 * @brief  Arquivo com a implementa��o dos exerc�cios da Aula 13.
 * @author Leandro Maia Silva
 * @date   2019-09-17
 */

/* Inclus�es */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <float.h>
#include "erros.h"

/* Tipos */
typedef uint8_t bool_t;

/* Constantes */
#define VERDADEIRO              (1 == 1)
#define FALSO                   (!VERDADEIRO)

// ------------------------------------------------------------------------------------------------

#define NOME_TAMANHO_MAXIMO (100 + 1)
#define CURSO_TAMANHO_MAXIMO (50 + 1)
#define NUMERO_NOTAS         (3)

struct aluno_s {
  char nome[NOME_TAMANHO_MAXIMO];
  char curso[CURSO_TAMANHO_MAXIMO];
  int idade;
  float notas[NUMERO_NOTAS]; // Extens�o para o exerc�cio 2
};

typedef struct aluno_s aluno_s;

/**
 * Fun��o que l� os dados do aluno.
 * @param aluno Apontador para a estrutura que receber� os dados do aluno.
 */
void leDadosAluno(aluno_s * aluno) {

  char lixo; // Vari�vel para remo��o do \n ao usar scanf

  // Obtem os dados do aluno
  printf("Entre com os dados do aluno:\n");

  // NOME
  printf("Nome: ");
  fgets(aluno->nome, NOME_TAMANHO_MAXIMO, stdin);
  aluno->nome[strlen(aluno->nome) - 1] = '\0'; // Remove o \n do final

  // Curso
  printf("Curso: ");
  fgets(aluno->curso, CURSO_TAMANHO_MAXIMO, stdin);
  aluno->curso[strlen(aluno->curso) - 1] = '\0'; // Remove o \n do final

  printf("Idade: ");
  scanf("%d%c", &aluno->idade, &lixo);
}

/**
 * Fun��o que imprime os dados de um aluno.
 * @param aluno Apontador para a estrutura onde os dados est�o armazenados.
 */
void imprimeDadosAluno(aluno_s * aluno) {
  printf("Nome: %s\n"\
         "Curso: %s\n"\
         "Idade: %d\n",
         aluno->nome, aluno->curso, aluno->idade);
}

/**
 * Exerc�cio 01
 * Fa�a um programa para leitura, via teclado, dos dados de um
 * aluno. Os dados a serem guardados na estrutura aluno s�o os
 * seguintes: nome, curso, idade. Ao final, imprima estas informa��es
 * na tela.
 */
void exercicio01(void) {

  aluno_s aluno;

  // Obtem os dados do aluno
  leDadosAluno(&aluno);

  // Imprime os dados do aluno
  imprimeDadosAluno(&aluno);
}

// ------------------------------------------------------------------------------------------------

#define NOTA_MINIMA_APROVACAO (60.0f)

/**
 * Fun��o que calcula a m�dia das notas do aluno.
 * @param aluno Apontador para a estrutura com as notas do aluno.
 * @return M�dia das notas do aluno.
 */
float calculaMediaNotas(aluno_s * aluno) {

  int i;
  float somaNotas = 0.0f;

  // Soma todas a notas para calcular a m�dia
  for (i = 0; i < NUMERO_NOTAS; i++) {
    somaNotas += (aluno->notas[i]);
  }

  // Retorna a m�dia
  return somaNotas / NUMERO_NOTAS;
}

/**
 * Fun��o que l� as notas de um aluno.
 * @param aluno Apontador para a estrutura que receber� as notas do aluno.
 */
void leNotasAluno(aluno_s * aluno) {

  int i;
  char lixo;

  // Obtem as notas das provas
  printf("Entre com as notas do aluno: \n");

  // Obtem a nota de cada prova
  for (i = 0; i < NUMERO_NOTAS; i++) {
    printf("Prova %02d: ", (i+1));
    scanf("%f%c", &(aluno->notas[i]), &lixo);
  }
}

/**
 * Exerc�cio 02
 * Considere a mesma estrutura definida anteriormente. Acrescente
 * � estrutura um vetor com as notas das tr�s provas feitas pelo aluno,
 * calcule a sua m�dia e diga se ele foi aprovado ou n�o (media >=
 * 60).
 */
void exercicio02(void) {

  aluno_s aluno;
  float media;

  // L� as notas
  leNotasAluno(&aluno);

  // Calcula a m�dia
  media = calculaMediaNotas(&aluno);

  // Mostra a nota e fala se foi aprovado ou n�o.
  printf("O aluno teve media %.2f. Resultado: ", media);
  if (media < NOTA_MINIMA_APROVACAO) {
    printf("REPROVADO");
  } else {
    printf("APROVADO");
  }
  printf("\n");
}

// ------------------------------------------------------------------------------------------------

/**
 * Imprime as notas do aluno.
 * @param aluno Apontador para a estrutura com as notas do aluno.
 */
void imprimeNotasAluno(aluno_s * aluno) {

  int i;

  printf("Notas: ");
  for (i = 0; i < NUMERO_NOTAS; i++) {
    printf("[%d]: %.2f ", (i + 1), aluno->notas[i]);
  }
  printf("\n");
}

/**
 * Fun��o que imprime os dados do aluno, suas notas e m�dia de notas.
 * @param aluno Apontador para a estrutura com os dados do aluno.
 */
void imprimeDadosAlunoNotasMedia(aluno_s * aluno) {

  // Imprime os dados do aluno, nota e m�dia
  imprimeDadosAluno(aluno);
  imprimeNotasAluno(aluno);
  printf("Media: %.2f\n", calculaMediaNotas(aluno));
}

/**
 * Exerc�cio 03
 * Altere o programa do exerc�cio 2 para que ele leia as informa��es
 * de N alunos. Imprima a m�dia de cada aluno e a m�dia geral da
 * turma.
 */
void exercicio03(void) {

  int i;
  int nAlunos;
  aluno_s * alunos;
  float somaMedias = 0.0f;

  char lixo;

  printf("Digite o numero de alunos: ");
  scanf("%d%c", &nAlunos, &lixo);

  // Aloca espa�o para os N alunos
  alunos = (aluno_s *)malloc(sizeof(aluno_s) * nAlunos);

  // L� os dados dos alunos
  for (i = 0; i < nAlunos; i++) {
    leDadosAluno(&(alunos[i]));
    leNotasAluno(&(alunos[i]));
  }

  // Imprime os dados
  printf("------------------------------------------------------------------\n");
  for (i = 0; i < nAlunos; i++) {
    imprimeDadosAlunoNotasMedia(&(alunos[i]));

    // Soma as m�dias
    somaMedias += calculaMediaNotas(&(alunos[i]));
  }

  // M�dia da turma
  printf("### Media de notas turma: %.2f\n", (somaMedias / nAlunos));

  // Libera a mem�ria alocada para os alunos
  free(alunos);
}

// ------------------------------------------------------------------------------------------------

/**
 * Fun��o que ordena os alunos por m�dia de notas.
 * ATEN��O!!! Essa fun��o MODIFICA o vetor de alunos, pois a ordena��o
 * � feita alterando o local onde os dados do aluno est� armazenado.
 * @param alunos Apontador para o local onde est�o os dados dos alunos.
 * @param nAlunos N�mero de alunos na lista de alunos.
 */
void ordenacaoPorMedia(aluno_s alunos[], int nAlunos) {

  int i, j;
  aluno_s tmp;

  for (i = 0; i < (nAlunos - 1); i++) {
    for (j = 0; j < (nAlunos - 1); j++) {
      // Se estiver fora de ordem...
      if (calculaMediaNotas(&(alunos[j])) > calculaMediaNotas(&(alunos[j + 1]))) {
        // ... troca de posicao
        tmp = alunos[j];
        alunos[j] = alunos[j + 1];
        alunos[j + 1] = tmp;
      }
    }
  }
}

/**
 * Exerc�cio 04
 * Acrescente um procedimento ao exerc�cio 3 que ordene a
 * estrutura de alunos em ordem crescente da m�dia das notas. Ao
 * final, imprima todas as informa��es na tela (ordenadas pela m�dia
 * das notas).
 */
void exercicio04(void) {

  int i;
  int nAlunos;
  aluno_s * alunos;
  float somaMedias = 0.0f;

  char lixo;

  printf("Digite o numero de alunos: ");
  scanf("%d%c", &nAlunos, &lixo);

  // Aloca espa�o para os N alunos
  alunos = (aluno_s *)malloc(sizeof(aluno_s) * nAlunos);

  // L� os dados dos alunos
  for (i = 0; i < nAlunos; i++) {
    leDadosAluno(&(alunos[i]));
    leNotasAluno(&(alunos[i]));
  }

  // Imprime os dados
  printf("------------------------------------------------------------------\n");
  for (i = 0; i < nAlunos; i++) {
    imprimeDadosAlunoNotasMedia(&(alunos[i]));

    // Soma as m�dias
    somaMedias += calculaMediaNotas(&(alunos[i]));
  }

  // M�dia da turma
  printf("### Media de notas turma: %.2f\n", (somaMedias / nAlunos));

  // Ordena os alunos por m�dia
  ordenacaoPorMedia(alunos, nAlunos);

  // Imprime ordenado por m�dia
  printf("------------------------------------------------------------------\n");
  for (i = 0; i < nAlunos; i++) {
    imprimeDadosAlunoNotasMedia(&(alunos[i]));
  }

  // Libera a mem�ria alocada para os alunos
  free(alunos);

}

// ------------------------------------------------------------------------------------------------

/**
 * Fun��o principal do programa onde o mesmo ser� iniciado.
 * @param argc N�mero de par�metros.
 * @param argv Valores dos par�metros.
 * @return SUCESSO caso o programa seja executado corretamente, ou caso contr�rio,
 * o c�digo do erro ocorrido.
 */
int main(int argc, char ** argv) {

  int nExercicio;
  char lixo;

  do {
    printf("Digite o numero do exercicio que quer executar [1:4]. 0 para sair: ");
    scanf("%d%c", &nExercicio, &lixo);

    switch (nExercicio) {
      case 0: break;
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