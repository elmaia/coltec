/**
 * @file   LE05_ex07.c
 * @brief  Arquivo com a implementação de sugestão de 
 *         solução do exercício 07 da LE 05 de 2024.
 * @author Leandro Maia Silva
 * @date   2024-05-24
 */

/* Inclusões */
#include <stdio.h>   // printf e scanf
#include <stdbool.h> // bool, true e false

/* Constantes */

// Constante que associa o código de erro 0 ao significado de sucesso
#define SUCESSO  0

// ----------------------------------------------------------------------

/**
 * Macro para utilização do canal de saída de erro como
 * saída de texto para testes automáticos.
 */
#ifdef TESTADOR
  #define PRINTF(format, ...) fprintf(stderr, format, __VA_ARGS__)
#else
  #define PRINTF(format, ...) printf(format, __VA_ARGS__)
#endif

// ----------------------------------------------------------------------

/* Constantes */

// Número de notas dos alunos
#define NUMERO_NOTAS 3

// Nota mínima para aprovação
#define APROVACAO_NOTA_MINIMA  60.0f

float calculaMedia(float nota1, float nota2, float nota3) {
  return (nota1 + nota2 + nota3) / NUMERO_NOTAS;
}

bool estaAprovado(float nota) {
  return (nota >= APROVACAO_NOTA_MINIMA);
}

/**
 *  Faça uma função que recebe três notas de um aluno e
 *  calcula sua média. Também faça uma função que verifica se um aluno foi
 *  aprovado.
 *  Faça um programa que leia três notas de N alunos e contabilize quantos
 *  alunos foram aprovados e quantos foram reprovados. Além disso, seu
 *  programa deverá imprimir o percentual de aprovação da turma.
 *  Para contar como aprovado, a nota deve ser igual ou superior à 60 pontos.
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
    
    // Obtem a média
    media = calculaMedia(nota1, nota2, nota3);
    
    // Verifica se foi aprovado
    if (estaAprovado(media)) {
      nAlunosAprovados++;
    }
  }
  
  // Calcula o percentual de aprovação
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
  
  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}