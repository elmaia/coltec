/**
 * @file   LE05_ex07.c
 * @brief  Arquivo com a implementa��o de sugest�o de 
 *         solu��o do exerc�cio 07 da LE 05 de 2024.
 * @author Leandro Maia Silva
 * @date   2024-05-24
 */

/* Inclus�es */
#include <stdio.h>   // printf e scanf
#include <stdbool.h> // bool, true e false

/* Constantes */

// Constante que associa o c�digo de erro 0 ao significado de sucesso
#define SUCESSO  0

// ----------------------------------------------------------------------

/**
 * Macro para utiliza��o do canal de sa�da de erro como
 * sa�da de texto para testes autom�ticos.
 */
#ifdef TESTADOR
  #define PRINTF(format, ...) fprintf(stderr, format, __VA_ARGS__)
#else
  #define PRINTF(format, ...) printf(format, __VA_ARGS__)
#endif

// ----------------------------------------------------------------------

/* Constantes */

// N�mero de notas dos alunos
#define NUMERO_NOTAS 3

// Nota m�nima para aprova��o
#define APROVACAO_NOTA_MINIMA  60.0f

float calculaMedia(float nota1, float nota2, float nota3) {
  return (nota1 + nota2 + nota3) / NUMERO_NOTAS;
}

bool estaAprovado(float nota) {
  return (nota >= APROVACAO_NOTA_MINIMA);
}

/**
 *  Fa�a uma fun��o que recebe tr�s notas de um aluno e
 *  calcula sua m�dia. Tamb�m fa�a uma fun��o que verifica se um aluno foi
 *  aprovado.
 *  Fa�a um programa que leia tr�s notas de N alunos e contabilize quantos
 *  alunos foram aprovados e quantos foram reprovados. Al�m disso, seu
 *  programa dever� imprimir o percentual de aprova��o da turma.
 *  Para contar como aprovado, a nota deve ser igual ou superior � 60 pontos.
 */
int main(int argc, char ** argv) {
    
  int i;
  int nAlunos;
  int nAlunosAprovados = 0;
  float nota1, nota2, nota3;
  float media;
  float percAprovacao;
  
  printf("Notas dos Alunos.\n");
  printf("Digite o numero de alunos: ");
  scanf("%d%*c", &nAlunos);
  
  // Obtem as notas dos alunos
  for(i = 0; i < nAlunos; i++) {
    printf("Notas do aluno %d.\n", i + 1);
    printf("Nota 01: ");
    scanf("%f%*c", &nota1);
    printf("Nota 02: ");
    scanf("%f%*c", &nota2);
    printf("Nota 03: ");
    scanf("%f%*c", &nota3);
    
    // Obtem a m�dia
    media = calculaMedia(nota1, nota2, nota3);
    
    // Verifica se foi aprovado
    if (estaAprovado(media)) {
      nAlunosAprovados++;
    }
  }
  
  // Calcula o percentual de aprova��o
  percAprovacao = ((float)nAlunosAprovados / nAlunos) * 100;
  
  // Mostra as estatisticas
  printf("Estatisticas.\n");
  printf("N alunos....: ");
  PRINTF("%4d", nAlunos);
  printf("\n");
  printf("N aprovados.:");
  PRINTF(" %4d", nAlunosAprovados);
  printf(" | Perc:");
  PRINTF(" %6.2f", percAprovacao);
  printf("\n");
  printf("N reprovados:");
  PRINTF(" %4d", nAlunos - nAlunosAprovados);
  printf(" | Perc:");
  PRINTF(" %6.2f", 100.0f - percAprovacao);
  printf("\n");
  
  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}