/**
 * @file   LE01_ex07.c
 * @brief  Arquivo com a implementação de sugestão de 
 *         solução do exercício 07 da LE 01 de 2024.
 * @author Leandro Maia Silva
 * @date   2024-03-28
 */

/* Inclusões */
#include <stdio.h>

/* Constantes */

// Constante que associa o código de erro 0 ao significado de sucesso
#define SUCESSO  0

/**
 * Faça um programa que leia as notas de três provas de
 * três alunos e imprime em forma de tabela (um aluno por linha, uma nota
 * por coluna) os valores lidos.
 * Todas as notas devem ter duas casas decimais e elas devem ser separadas
 * por uma tabulação.
 */
int main(int argc, char ** argv){
  
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

  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}