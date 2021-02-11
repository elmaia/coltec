/**
* @file   Aula14.c
* @brief  Arquivo com a implementação dos exercícios da Aula 14.
* @author Leandro Maia Silva
* @date   2021-02-10
*/

/* Inclusões */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <float.h>
#include <math.h>
#include "erros.h"

/* Tipos */
typedef uint8_t bool_t;

/* Constantes */
#define VERDADEIRO              (1 == 1)
#define FALSO                   (!VERDADEIRO)

// ------------------------------------------------------------------------------------------------

#define ARQUIVO_TAMANHO_MAXIMO_CAMINHO (255 + 1)

/**
 * Função que obtem o número de linhas em um arquivo de texto.
 * @param arquivo Descritor do arquivo 
 */
int arquivo_obtemNumeroLinhas(FILE * arquivo) {

  int nLinhas = 0;
  long posicaoOriginal;
  char caractere;

  // Salva a posição atual do arquivo
  posicaoOriginal = ftell(arquivo);

  // Posiciona no início do arquivo para iniciar a contagem
  fseek(arquivo, 0, SEEK_SET);

  // Procuro por '\n'. 
  // Esse método não é o mais eficiente mas é o mais compatível entre plataformas Windows e Linux.
  while (!feof(arquivo)) {
    fscanf(arquivo, "%c", &caractere);
    if (caractere == '\n') nLinhas++;
  }

  // Volta o arquivo para a posição original
  fseek(arquivo, posicaoOriginal, SEEK_SET);

  // Se chegou até aqui é porque atingiu o final do arquivo
  // Retorna o número de linhas contadas
  return nLinhas;
}

/**
 * Exercício 01
 * Faça uma função que retorne o número de linhas de um arquivo.
 */
void exercicio01(void) {

  FILE * arquivo;
  char caminhoArquivo[ARQUIVO_TAMANHO_MAXIMO_CAMINHO];
  int nLinhas;

  // Iterage com o usuário
  (void)printf("Digite o caminho para o arquivo que deseja contar as linhas:\n> ");
  fgets(caminhoArquivo, ARQUIVO_TAMANHO_MAXIMO_CAMINHO, stdin);
  caminhoArquivo[strlen(caminhoArquivo) - 1] = '\0';

  // Tenta abrir o arquivo
  arquivo = fopen(caminhoArquivo, "r");
  if (arquivo == NULL) {
    fprintf(stderr, "Falha ao abrir o arquivo <%s> para leitura.\n", caminhoArquivo);
    return;
  }

  // Se chegou até aqui é porque conseguiu abrir o arquivo
  nLinhas = arquivo_obtemNumeroLinhas(arquivo);

  // Fecha o arquivo
  fclose(arquivo);

  // Informa o número de linhas do arquivo
  (void)printf("O arquivo possui %d linhas.\n", nLinhas);

  printf("\n");
}

// ------------------------------------------------------------------------------------------------

/**
 * Função que conta o número de caracteres em um arquivo de texto.
 * @param arquivo Descritor do arquivo 
 */
int arquivo_obtemNumeroCaracteres(FILE * arquivo) {

  int nCaracteres = 0;
  long posicaoOriginal;
  char caractere;

  // Salva a posição atual do arquivo
  posicaoOriginal = ftell(arquivo);

  // Posiciona no início do arquivo para iniciar a contagem
  fseek(arquivo, 0, SEEK_SET);

  // Procuro por '\n' ou ' '. 
  // Esse método não é o mais eficiente mas é o mais compatível entre plataformas Windows e Linux.
  while (!feof(arquivo)) {
    fscanf(arquivo, "%c", &caractere);
    if ((caractere == '\n') || (caractere == ' ')) continue;
      nCaracteres++;
  }

  // Volta o arquivo para a posição original
  fseek(arquivo, posicaoOriginal, SEEK_SET);

  // Se chegou até aqui é porque atingiu o final do arquivo
  // Retorna o número de caracteres contados
  return nCaracteres;
}

/**
 * Exercício 02
 * Faça uma função que retorne o número de caracteres de um
 * arquivo. Espaços e quebras de linha não devem ser contados.
 */
void exercicio02(void) {

  FILE * arquivo;
  char caminhoArquivo[ARQUIVO_TAMANHO_MAXIMO_CAMINHO];
  int nLinhas;

  // Iterage com o usuário
  (void)printf("Digite o caminho para o arquivo que deseja contar os caracteres:\n> ");
  fgets(caminhoArquivo, ARQUIVO_TAMANHO_MAXIMO_CAMINHO, stdin);
  caminhoArquivo[strlen(caminhoArquivo) - 1] = '\0';

  // Tenta abrir o arquivo
  arquivo = fopen(caminhoArquivo, "r");
  if (arquivo == NULL) {
    fprintf(stderr, "Falha ao abrir o arquivo <%s> para leitura.\n", caminhoArquivo);
    return;
  }

  // Se chegou até aqui é porque conseguiu abrir o arquivo
  nLinhas = arquivo_obtemNumeroCaracteres(arquivo);

  // Fecha o arquivo
  fclose(arquivo);

  // Informa o número de linhas do arquivo
  (void)printf("O arquivo possui %d caracteres.\n", nLinhas);

  printf("\n");
}

// ------------------------------------------------------------------------------------------------

#define NOME_TAMANHO_MAXIMO             (100 + 1)
#define NUMERO_NOTAS                    (2)
#define CAMINHO_ARQUIVO_ENTRADA_ALUNOS  "./dadosAlunosEntrada.txt"
#define CAMINHO_ARQUIVO_SAIDA_ALUNOS    "./dadosAlunosSaida.bin"

/// Estrutura que representa um registro de um aluno
struct aluno_s {
  char nome[NOME_TAMANHO_MAXIMO];
  int idade;
  float notas[NUMERO_NOTAS];
};

/// Definição do tipo "Aluno";
typedef struct aluno_s aluno_t;

/**
 * Função que lê os dados do aluno no arquivo.
 * @param aluno Apontador para a estrutura que receberá os dados do aluno.
*/
void aluno_leDadosArquivo(FILE * arquivo, aluno_t * aluno) {

  // NOME
  fgets(aluno->nome, NOME_TAMANHO_MAXIMO, arquivo);
  aluno->nome[strlen(aluno->nome) - 1] = '\0'; // Remove o \n do final

  // Nota 01
  fscanf(arquivo, "%f\n", &(aluno->notas[0]));

  // Nota 02
  fscanf(arquivo, "%f\n", &(aluno->notas[1]));
}

/**
 * Função que calcula a média de notas do aluno.
 * @param aluno Apontador para a estrutura onde os dados estão armazenados.
 * @return Média das notas.
 */
float aluno_calculaMediaNotas(aluno_t * aluno) {

  int i;
  float somaNotas = 0;

  for (i = 0; i < NUMERO_NOTAS; i++) {
    somaNotas += aluno->notas[i];
  }

  return somaNotas / NUMERO_NOTAS;
}

/**
 * Função que calcula a média das notas de todos os alunos.
 * @param alunos Vetor com os registros dos alunos.
 * @param nAlunos Número de alunos no vetor.
 * @return Média das notas dos alunos.
 */
float aluno_calculaMediaTodosAlunos(aluno_t alunos[], int nAlunos) {

  int i;
  float somaMedias = 0;

  for (i = 0; i < nAlunos; i++) {
    somaMedias += aluno_calculaMediaNotas(&alunos[i]);
  }

  return somaMedias / nAlunos;
}

/**
 * Função que calcula o desvio padrão das notas dos alunos.
 * @param alunos Vetor com os registros dos alunos.
 * @param nAlunos Número de alunos no vetor.
 * @return Desvio-padrão das notas dos alunos.
 */
double aluno_calculaDesvioPadraoNotas(aluno_t alunos[], int nAlunos) {

  int i;
  float mediaNotas;
  double somatorioQuadradoDistancia = 0;

  // Calcula a média das notas, utilizada na fórmula do desvio padrão
  mediaNotas = aluno_calculaMediaTodosAlunos(alunos, nAlunos);

  for (i = 0; i < nAlunos; i++) {
    somatorioQuadradoDistancia += pow(aluno_calculaMediaNotas(&alunos[i]) - mediaNotas, 2);
  }

  return sqrt(somatorioQuadradoDistancia / nAlunos);
}

/**
 * Função que calcula a variância das médias das notas dos alunos.
 * @param alunos Vetor com os registros dos alunos.
 * @param nAlunos Número de alunos no vetor.
 * @return Desvio-padrão das notas dos alunos.
 */
double aluno_calculaVarianciaMediaNotas(aluno_t alunos[], int nAlunos) {

  int i;
  float media;
  double somatorioQuadradoDistancia = 0;

  media = aluno_calculaMediaTodosAlunos(alunos, nAlunos);

  for (i = 0; i < nAlunos; i++) {
    somatorioQuadradoDistancia += pow(aluno_calculaMediaNotas(&alunos[i]) - media, 2);
  }

  return somatorioQuadradoDistancia / (nAlunos - 1);
}

/**
 * Função que imprime os dados de um aluno.
 * @param aluno Apontador para a estrutura onde os dados estão armazenados.
 */
void aluno_imprimeDados(aluno_t * aluno) {
  printf("Nome.: %s\n"\
         "Notas: %04.2f | %04.2f\n"\
         "Media: %04.2f\n"\
         "------------------------------------------------------------------------\n",
         aluno->nome, aluno->notas[0], aluno->notas[1], aluno_calculaMediaNotas(aluno));
}

/**
 * Exercício 03
 * Faça um programa que leia de um arquivo as informações sobre
 * o nome e as 2 notas de diversos alunos. Imprima a listagem de
 * alunos e suas respectivas médias. O programa deve criar o arquivo
 * de entrada e criar um arquivo de saída com o nome e a média de
 * cada aluno. Armazene as informações dos alunos em um registro
 * (struct).
 * Exercício 04
 * Adicione ao programa anterior uma função para calcular o desvio
 * padrão e a variância das médias dos alunos. Grave essa informação
 * no final do arquivo de saída.
 */
void exercicio03e04(void) {

  int i;
  aluno_t * alunos;
  FILE * arquivo;
  int nRegistros;
  float mediaNotas, media;
  double desvioPadrao, varianciaMedias;

  // Abre o arquivo com os dados dos alunos
  arquivo = fopen(CAMINHO_ARQUIVO_ENTRADA_ALUNOS, "r");
  if (arquivo == NULL) {
    fprintf(stderr, "Falha ao abrir o arquivo <%s> para leitura.\n", CAMINHO_ARQUIVO_ENTRADA_ALUNOS);
    return;
  }

  // Lê o número de registros que o arquivo tem
  fscanf(arquivo, "%d\n", &nRegistros);

  // Aloca espaço para os dados dos alunos que serão lidos
  alunos = (aluno_t *)malloc(sizeof(aluno_t) * nRegistros);

  // Lê cada um dos N registros
  for (i = 0; i < nRegistros; i++) {
    aluno_leDadosArquivo(arquivo, &(alunos[i]));
  }
  fclose(arquivo);


  // Imprime os dados lidos do arquivo
  (void)printf("Dados dos alunos:\n");
  printf("------------------------------------------------------------------\n");
  for (i = 0; i < nRegistros; i++) {
    aluno_imprimeDados(&(alunos[i]));
  }

  mediaNotas = aluno_calculaMediaTodosAlunos(alunos, nRegistros);
  (void)printf("Media Notas.....: %10.4f\n", mediaNotas);
  desvioPadrao = aluno_calculaDesvioPadraoNotas(alunos, nRegistros);
  (void)printf("Desvio-padrao...: %10.4f\n", desvioPadrao);
  varianciaMedias = aluno_calculaVarianciaMediaNotas(alunos, nRegistros);
  (void)printf("Variancia Medias: %10.4f\n", varianciaMedias);

  // Abre o arquivo para escrever os dados dos alunos
  // Estou utilizando o modo binário para dar um exemplo de uso.
  // Utilize algum editor de arquivos binário, tipo o HxD, para visualizá-los.
  arquivo = fopen(CAMINHO_ARQUIVO_SAIDA_ALUNOS, "wb");
  if (arquivo == NULL) {
    fprintf(stderr, "Falha ao abrir o arquivo <%s> para escrita.\n", CAMINHO_ARQUIVO_SAIDA_ALUNOS);
    return;
  }

  // Grava o número de registros
  fwrite(&nRegistros, sizeof(int), 1, arquivo);

  // Grava cada registro
  for (i = 0; i < nRegistros; i++) {
    // Nome
    fwrite(alunos[i].nome, NOME_TAMANHO_MAXIMO, 1, arquivo);
    // Média
    media = aluno_calculaMediaNotas(&alunos[i]);
    fwrite(&media, sizeof(float), 1, arquivo);
  }

  // Grava o desvio-padrão e a variância das médias
  fwrite(&desvioPadrao, sizeof(double), 1, arquivo);
  fwrite(&varianciaMedias, sizeof(double), 1, arquivo);

  fclose(arquivo);

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
    case 3:
    case 4: {
      exercicio03e04();
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