/**
 * @file   LE10_2023.c
 * @brief  Arquivo com a implementa��o com uma sugest�o de solu��o da LE10.
 * @author Leandro Maia Silva
 * @date   2023-08-04
 */

/* Inclus�es */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Constantes */

/// Largura da coluna onde ser� exibida a matr�cula
#define MATRICULA_LARGURA_COLUNA  (10)

/// Tamanho m�ximo de um nome
#define NOME_TAMANHO_MAXIMO       (100 + 2)
/// Largura da coluna onde ser� exibido o nome
#define NOME_LARGURA_COLUNA       (30)

/// Tamanho m�ximo de um curso
#define CURSO_TAMANHO_MAXIMO      (30 + 2)
/// Largura da coluna onde ser� exibido o curso
#define CURSO_LARGURA_COLUNA      (20)

/// Largura da coluna onde ser� exibida a altura
#define ALTURA_LARGURA_COLUNA     (4)

/// N�mero de notas
#define NUMERO_NOTAS              (3)
/// Largura da coluna onde ser� exibida a nota
#define NOTAS_LARGURA_COLUNA      (6)

/* Tipos */

/// <summary>
/// Estrutura que representa um aluno (Vers�o 1)
/// </summary>
struct alunoV1_s {
  int matricula;
  char nome[NOME_TAMANHO_MAXIMO];
  char curso[CURSO_TAMANHO_MAXIMO];
  float altura;
};

/// <summary>
/// Tipo "Aluno (Vers�o 1)"
/// </summary>
typedef struct alunoV1_s alunoV1_t;

/// <summary>
/// Estrutura que representa um aluno (Vers�o 2)
/// </summary>
struct alunoV2_s {
  int matricula;
  char nome[NOME_TAMANHO_MAXIMO];
  char curso[CURSO_TAMANHO_MAXIMO];
  float altura;
  float notas[NUMERO_NOTAS];
};

/// <summary>
/// Tipo "Aluno (Vers�o 2)"
/// </summary>
typedef struct alunoV2_s alunoV2_t;

/* Erros */

/// C�digo de erro que indica que a opera��o ocorreu com sucesso
#define SUCESSO 0

/* Fun��es */

/// <summary>
/// Fun��o que remove a quebra de linha final de um texto, caso ela exista.
/// </summary>
/// <param name="texto">Texto a ser processado.</param>
void util_removeQuebraLinhaFinal(char texto[]) {

  size_t tamanho;

  tamanho = strlen(texto);
  if ((tamanho > 0) && (texto[tamanho - 1] == '\n')) {
    texto[tamanho - 1] = '\0';
  }
}

// ------------------------------------------------------------------------------------------------

/// <summary>
/// Fun��o que l� os dados de um aluno.
/// </summary>
/// <param name="aluno">Endere�o do aluno onde os dados lidos ser�o armazenados.</param>
void alunoV1_leDados(alunoV1_t* aluno) {

  printf("Matricula: ");
  (void)scanf("%d%*c", &aluno->matricula);
  printf("Nome.....: ");
  fgets(aluno->nome, NOME_TAMANHO_MAXIMO, stdin);
  util_removeQuebraLinhaFinal(aluno->nome);
  printf("Curso....: ");
  fgets(aluno->curso, CURSO_TAMANHO_MAXIMO, stdin);
  util_removeQuebraLinhaFinal(aluno->curso);
  printf("Altura...: ");
  (void)scanf("%f%*c", &aluno->altura);
}

/// <summary>
/// Fun��o que imprime os dados de um aluno.
/// </summary>
/// <param name="aluno">Endere�o do aluno cujo os dados ser�o impressos.</param>
void alunoV1_imprimeDados(alunoV1_t* aluno) {
  printf("| %*d | %-*.*s | %-*.*s | %*.2f |\n",
         MATRICULA_LARGURA_COLUNA, aluno->matricula,
         NOME_LARGURA_COLUNA, NOME_LARGURA_COLUNA, aluno->nome,
         CURSO_LARGURA_COLUNA, CURSO_LARGURA_COLUNA, aluno->curso,
         ALTURA_LARGURA_COLUNA, aluno->altura
  );
}

/// <summary>
/// Imprime uma lista de alunos em formato de tabela.
/// </summary>
/// <param name="alunos">Lista de alunos.</param>
/// <param name="nAlunos">N�mero de alunos na lista.</param>
void alunosV1_imprimeFormatoTabela(alunoV1_t alunos[], int nAlunos) {

  int i;

  // Imprime o cabe�alho
  printf("| %*.*s | %-*.*s | %-*.*s | %*.*s |\n",
    MATRICULA_LARGURA_COLUNA, MATRICULA_LARGURA_COLUNA, "Matricula",
    NOME_LARGURA_COLUNA, NOME_LARGURA_COLUNA, "Nome",
    CURSO_LARGURA_COLUNA, CURSO_LARGURA_COLUNA, "Curso",
    ALTURA_LARGURA_COLUNA, ALTURA_LARGURA_COLUNA, "Altura"
  );

  // Imprime os alunos
  for (i = 0; i < nAlunos; i++) {
    alunoV1_imprimeDados(&alunos[i]);
  }
}

/// N�mero de alunos para testar a quest�o
#define QUESTAO01_NUMERO_ALUNOS 2

/// <summary>
/// Rotina de testes da quest�o 01.
/// </summary>
void questao01(void) {

  int i;
  alunoV1_t alunos[QUESTAO01_NUMERO_ALUNOS];

  // L� os dados dos alunos
  for (i = 0; i < QUESTAO01_NUMERO_ALUNOS; i++) {
    printf("Dados do aluno %d:\n", i + 1);
    alunoV1_leDados(&alunos[i]);
  }

  // Imprime os dados
  alunosV1_imprimeFormatoTabela(alunos, QUESTAO01_NUMERO_ALUNOS);
}

// ------------------------------------------------------------------------------------------------

/// <summary>
/// Fun��o que l� os notas.
/// </summary>
/// <param name="notas">Array onde as notas ser�o armazenadas.</param>
/// <param name="nNotas">N�mero de notas a serem lidas.</param>
void alunoV2_leNotas(float notas[], int nNotas) {

  int i;

  for (i = 0; i < nNotas; i++) {
    printf("Nota %2d: ", i + 1);
    (void)scanf("%f%*c", &notas[i]);
  }
}

/// <summary>
/// Fun��o que calcula a m�dia das notas.
/// </summary>
/// <param name="notas">Array de notas.</param>
/// <param name="nNotas">N�mero de notas no array.</param>
/// <returns>M�dia das notas.</returns>
float alunoV2_calculaMediaNotas(float notas[], int nNotas) {

  int i;
  float somaNotas = 0.0f;

  for (i = 0; i < nNotas; i++) {
    somaNotas += notas[i];
  }

  return somaNotas / nNotas;
}

/// <summary>
/// Fun��o que l� os dados de um aluno.
/// </summary>
/// <param name="aluno">Endere�o do aluno onde os dados lidos ser�o armazenados.</param>
void alunoV2_leDados(alunoV2_t* aluno) {

  // L� os dados do aluno
  printf("Matricula: ");
  (void)scanf("%d%*c", &aluno->matricula);
  printf("Nome.....: ");
  fgets(aluno->nome, NOME_TAMANHO_MAXIMO, stdin);
  util_removeQuebraLinhaFinal(aluno->nome);
  printf("Curso....: ");
  fgets(aluno->curso, CURSO_TAMANHO_MAXIMO, stdin);
  util_removeQuebraLinhaFinal(aluno->curso);
  printf("Altura...: ");
  (void)scanf("%f%*c", &aluno->altura);

  // L� as notas
  alunoV2_leNotas(aluno->notas, NUMERO_NOTAS);
}

/// <summary>
/// Fun��o que imprime os dados de um aluno.
/// </summary>
/// <param name="aluno">Endere�o do aluno cujo os dados ser�o impressos.</param>
void alunoV2_imprimeDados(alunoV2_t* aluno) {

  int i;

  // Imprime os dados
  printf("| %*d | %-*.*s | %-*.*s | %*.2f |",
    MATRICULA_LARGURA_COLUNA, aluno->matricula,
    NOME_LARGURA_COLUNA, NOME_LARGURA_COLUNA, aluno->nome,
    CURSO_LARGURA_COLUNA, CURSO_LARGURA_COLUNA, aluno->curso,
    ALTURA_LARGURA_COLUNA, aluno->altura
  );

  // Imprime as notas
  for (i = 0; i < NUMERO_NOTAS; i++) {
    printf(" %*.2f |", NOTAS_LARGURA_COLUNA, aluno->notas[i]);
  }

  // Imprime a m�dia
  printf(" %*.2f |\n", NOTAS_LARGURA_COLUNA, alunoV2_calculaMediaNotas(aluno->notas, NUMERO_NOTAS));
}

/// <summary>
/// Imprime uma lista de alunos em formato de tabela.
/// </summary>
/// <param name="alunos">Lista de alunos.</param>
/// <param name="nAlunos">N�mero de alunos na lista.</param>
void alunosV2_imprimeFormatoTabela(alunoV2_t alunos[], int nAlunos) {

  int i;
  char textoNota[10];

  // Imprime o cabe�alho
  printf("| %*.*s | %-*.*s | %-*.*s | %*.*s |",
    MATRICULA_LARGURA_COLUNA, MATRICULA_LARGURA_COLUNA, "Matricula",
    NOME_LARGURA_COLUNA, NOME_LARGURA_COLUNA, "Nome",
    CURSO_LARGURA_COLUNA, CURSO_LARGURA_COLUNA, "Curso",
    ALTURA_LARGURA_COLUNA, ALTURA_LARGURA_COLUNA, "Altura"
  );
  for (i = 0; i < NUMERO_NOTAS; i++) {
    sprintf(textoNota, "Nt. %d", i + 1);
    printf(" %*.*s |",
      NOTAS_LARGURA_COLUNA, NOTAS_LARGURA_COLUNA, textoNota
    );
  }
  printf(" %*.*s |\n",
    NOTAS_LARGURA_COLUNA, NOTAS_LARGURA_COLUNA, "Media"
  );

  // Imprime os alunos
  for (i = 0; i < nAlunos; i++) {
    alunoV2_imprimeDados(&alunos[i]);
  }
}

/// N�mero de alunos para testar a quest�o
#define QUESTAO02_NUMERO_ALUNOS 2

/// <summary>
/// Rotina de testes da quest�o 02.
/// </summary>
void questao02(void) {

  int i;
  alunoV2_t alunos[QUESTAO02_NUMERO_ALUNOS];

  // L� os dados dos alunos
  for (i = 0; i < QUESTAO02_NUMERO_ALUNOS; i++) {
    printf("Dados do aluno %d:\n", i + 1);
    alunoV2_leDados(&alunos[i]);
  }

  // Imprime os dados
  alunosV2_imprimeFormatoTabela(alunos, QUESTAO02_NUMERO_ALUNOS);

}

// ------------------------------------------------------------------------------------------------

/// <summary>
/// Rotina de testes da quest�o 03.
/// </summary>
void questao03(void) {

  alunoV2_t* alunos = NULL, *novoAlunos;
  int nAlunos = 0;
  char opcao;

  do {

    // Op��es
    printf("Deseja inserir mais um aluno [S/N]? ");
    (void)scanf("%c%*c", &opcao);

    switch (opcao) {
      case 'S':
      case 's':
        // Aloca espa�o para mais um aluno
        novoAlunos = (alunoV2_t*)realloc(alunos, (nAlunos + 1) * sizeof(alunoV2_t));
        if (novoAlunos == NULL) {
          // Mostra mensagem de erro
          perror("Memoria insuficiente.\n");
          // Libera a mem�ria alocada
          free(alunos);
          return;
        }
        // Atualiza a localiza��o de alunos (para evitar warning na linha do realloc
        alunos = novoAlunos;
        // L� os dados do aluno
        alunoV2_leDados(&alunos[nAlunos]);
        // Atualiza o n�mero de alunos
        nAlunos++;
        break;
      case 'N':
      case 'n':
        break;
      default:
        printf("Opcao invalida.\n");
    }

  } while ((opcao != 'n') && (opcao != 'N'));

  // Agora imprime os registros
  printf("\n");
  alunosV2_imprimeFormatoTabela(alunos, nAlunos);
  printf("\n");

  // Libera a mem�ria alocada
  free(alunos);
}

/// <summary>
/// Fun��o principal do programa.
/// </summary>
/// <param name="argc">N�mero de argumentos.</param>
/// <param name="argv">Valores dos argumentos.</param>
/// <returns>C�digo de erro indicando o ocorrido no programa.</returns>
int main(int argc, char** argv) {

  int opcao;

  do {

    // Menu
    printf("\nEscolha o exercicio para executar [1:3].\n");
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
    default:
      printf("Opcao invalida.\n");
    }

  } while (opcao != 0);

  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}