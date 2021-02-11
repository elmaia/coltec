/**
 * @file   Aula13.c
 * @brief  Arquivo com a implementação dos exercícios da Aula 13.
 * @author Leandro Maia Silva
 * @date   2019-09-17
 */

/* Inclusões */
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
  float notas[NUMERO_NOTAS]; // Extensão para o exercício 2
};

typedef struct aluno_s aluno_s;

/**
 * Função que lê os dados do aluno.
 * @param aluno Apontador para a estrutura que receberá os dados do aluno.
 */
void leDadosAluno(aluno_s * aluno) {

  char lixo; // Variável para remoção do \n ao usar scanf

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
 * Função que imprime os dados de um aluno.
 * @param aluno Apontador para a estrutura onde os dados estão armazenados.
 */
void imprimeDadosAluno(aluno_s * aluno) {
  printf("Nome: %s\n"\
         "Curso: %s\n"\
         "Idade: %d\n",
         aluno->nome, aluno->curso, aluno->idade);
}

/**
 * Exercício 01
 * Faça um programa para leitura, via teclado, dos dados de um
 * aluno. Os dados a serem guardados na estrutura aluno são os
 * seguintes: nome, curso, idade. Ao final, imprima estas informações
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
 * Função que calcula a média das notas do aluno.
 * @param aluno Apontador para a estrutura com as notas do aluno.
 * @return Média das notas do aluno.
 */
float calculaMediaNotas(aluno_s * aluno) {

  int i;
  float somaNotas = 0.0f;

  // Soma todas a notas para calcular a média
  for (i = 0; i < NUMERO_NOTAS; i++) {
    somaNotas += (aluno->notas[i]);
  }

  // Retorna a média
  return somaNotas / NUMERO_NOTAS;
}

/**
 * Função que lê as notas de um aluno.
 * @param aluno Apontador para a estrutura que receberá as notas do aluno.
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
 * Exercício 02
 * Considere a mesma estrutura definida anteriormente. Acrescente
 * à estrutura um vetor com as notas das três provas feitas pelo aluno,
 * calcule a sua média e diga se ele foi aprovado ou não (media >=
 * 60).
 */
void exercicio02(void) {

  aluno_s aluno;
  float media;

  // Lê as notas
  leNotasAluno(&aluno);

  // Calcula a média
  media = calculaMediaNotas(&aluno);

  // Mostra a nota e fala se foi aprovado ou não.
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
 * Função que imprime os dados do aluno, suas notas e média de notas.
 * @param aluno Apontador para a estrutura com os dados do aluno.
 */
void imprimeDadosAlunoNotasMedia(aluno_s * aluno) {

  // Imprime os dados do aluno, nota e média
  imprimeDadosAluno(aluno);
  imprimeNotasAluno(aluno);
  printf("Media: %.2f\n", calculaMediaNotas(aluno));
}

/**
 * Exercício 03
 * Altere o programa do exercício 2 para que ele leia as informações
 * de N alunos. Imprima a média de cada aluno e a média geral da
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

  // Aloca espaço para os N alunos
  alunos = (aluno_s *)malloc(sizeof(aluno_s) * nAlunos);

  // Lê os dados dos alunos
  for (i = 0; i < nAlunos; i++) {
    leDadosAluno(&(alunos[i]));
    leNotasAluno(&(alunos[i]));
  }

  // Imprime os dados
  printf("------------------------------------------------------------------\n");
  for (i = 0; i < nAlunos; i++) {
    imprimeDadosAlunoNotasMedia(&(alunos[i]));

    // Soma as médias
    somaMedias += calculaMediaNotas(&(alunos[i]));
  }

  // Média da turma
  printf("### Media de notas turma: %.2f\n", (somaMedias / nAlunos));

  // Libera a memória alocada para os alunos
  free(alunos);
}

// ------------------------------------------------------------------------------------------------

/**
 * Função que ordena os alunos por média de notas.
 * ATENÇÃO!!! Essa função MODIFICA o vetor de alunos, pois a ordenação
 * é feita alterando o local onde os dados do aluno está armazenado.
 * @param alunos Apontador para o local onde estão os dados dos alunos.
 * @param nAlunos Número de alunos na lista de alunos.
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
 * Exercício 04
 * Acrescente um procedimento ao exercício 3 que ordene a
 * estrutura de alunos em ordem crescente da média das notas. Ao
 * final, imprima todas as informações na tela (ordenadas pela média
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

  // Aloca espaço para os N alunos
  alunos = (aluno_s *)malloc(sizeof(aluno_s) * nAlunos);

  // Lê os dados dos alunos
  for (i = 0; i < nAlunos; i++) {
    leDadosAluno(&(alunos[i]));
    leNotasAluno(&(alunos[i]));
  }

  // Imprime os dados
  printf("------------------------------------------------------------------\n");
  for (i = 0; i < nAlunos; i++) {
    imprimeDadosAlunoNotasMedia(&(alunos[i]));

    // Soma as médias
    somaMedias += calculaMediaNotas(&(alunos[i]));
  }

  // Média da turma
  printf("### Media de notas turma: %.2f\n", (somaMedias / nAlunos));

  // Ordena os alunos por média
  ordenacaoPorMedia(alunos, nAlunos);

  // Imprime ordenado por média
  printf("------------------------------------------------------------------\n");
  for (i = 0; i < nAlunos; i++) {
    imprimeDadosAlunoNotasMedia(&(alunos[i]));
  }

  // Libera a memória alocada para os alunos
  free(alunos);

}

// ------------------------------------------------------------------------------------------------

/**
 * Função principal do programa onde o mesmo será iniciado.
 * @param argc Número de parâmetros.
 * @param argv Valores dos parâmetros.
 * @return SUCESSO caso o programa seja executado corretamente, ou caso contrário,
 * o código do erro ocorrido.
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

    // Adiciono uma quebra de linha para separar cada execução de exercício
    printf("\n");

  } while (nExercicio != 0);

  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}