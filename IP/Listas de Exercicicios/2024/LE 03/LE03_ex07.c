/**
 * @file   LE03_ex07.c
 * @brief  Arquivo com a implementa��o de sugest�o de 
 *         solu��o do exerc�cio 07 da LE 03 de 2024.
 * @author Leandro Maia Silva
 * @date   2024-03-28
 */

/* Inclus�es */
#include <stdio.h>   // printf e scanf

/* Constantes */

// Constante que associa o c�digo de erro 0 ao significado de sucesso
#define SUCESSO  0

// Nota para aprova��o
#define NOTA_APROVACAO  60

/**
 * Fa�a um programa que leia a nota final de N alunos e
 * contabilize quantos alunos foram aprovados e quantos foram reprovados.
 * Al�m disso, seu programa dever� imprimir o percentual de aprova��o da
 * turma.
 * Para contar como aprovado, a nota deve ser igual ou superior � 60 pontos.
 */
int main(int argc, char ** argv){
  
  int nAlunos;
  int i, retorno, nAlunosAprovados = 0;
  float nota;

  // Intera��o com o usu�rio
  printf("Digite o numero de alunos: ");
  retorno = scanf("%d", &nAlunos);

  // Obtenho a nota dos N alunos
  for (i = 0; i < nAlunos; i++) {

    // Obtenho a nota do aluno
    printf("Digite a nota do aluno %d: ", (i + 1));
    retorno = scanf("%f", &nota);

    // Se a nota � suficiente para aprova��o, conta nos aprovados
    if (nota >= NOTA_APROVACAO) {
      nAlunosAprovados++;
    }
  }

  // Mostro o resultado final
  printf("Foram obtidas as notas de %d alunos.\n", nAlunos);
  printf("Desses alunos, %d foram aprovados, reprentando %.2f%%.\n", nAlunosAprovados, 
    ((float)nAlunosAprovados / nAlunos) * 100);

  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}