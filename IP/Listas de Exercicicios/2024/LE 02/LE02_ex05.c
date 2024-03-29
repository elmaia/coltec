/**
 * @file   LE02_ex05.c
 * @brief  Arquivo com a implementa��o de sugest�o de 
 *         solu��o do exerc�cio 05 da LE 02 de 2024.
 * @author Leandro Maia Silva
 * @date   2024-03-28
 */

/* Inclus�es */
#include <stdio.h>   // printf e scanf

/* Constantes */

// Constante que associa o c�digo de erro 0 ao significado de sucesso
#define SUCESSO  0

// N�mero de notas.
// Por enquanto a constante n�o aplica real melhoria no c�digo, mas � bom
// praticar o n�o uso de constantes literais.
#define NUMERO_DE_NOTAS 3

/**
 * Fa�a um programa que leia as notas de tr�s provas de
 * tr�s alunos e imprime em forma de tabela (um aluno por linha, uma nota
 * por coluna) os valores lidos al�m do conceito dele.
 * Todas as notas devem ter duas casas decimais e elas devem ser separadas
 * por uma tabula��o.
 * Conceitos: A[90:100] ; B[80:90[ ; C[70:80[ ; D[60:70[ ; R[0:60[
 */
int main(int argc, char ** argv){
  
  float aluno1_nota1, aluno1_nota2, aluno1_nota3, aluno1_media;
  float aluno2_nota1, aluno2_nota2, aluno2_nota3, aluno2_media;
  float aluno3_nota1, aluno3_nota2, aluno3_nota3, aluno3_media;
  char aluno1_conceito, aluno2_conceito, aluno3_conceito;
  
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
  
  // Calcula as m�dias
  aluno1_media = (aluno1_nota1 + aluno1_nota2 + aluno1_nota3) / NUMERO_DE_NOTAS;
  aluno2_media = (aluno2_nota1 + aluno2_nota2 + aluno2_nota3) / NUMERO_DE_NOTAS;
  aluno3_media = (aluno3_nota1 + aluno3_nota2 + aluno3_nota3) / NUMERO_DE_NOTAS;
  
  // Calcula os conceitos
  
  // Aluno 1
  if      (aluno1_media >= 90) { aluno1_conceito = 'A'; }
  else if (aluno1_media >= 80) { aluno1_conceito = 'B'; }
  else if (aluno1_media >= 70) { aluno1_conceito = 'C'; }
  else if (aluno1_media >= 60) { aluno1_conceito = 'D'; }
  else                         { aluno1_conceito = 'R'; }
  // Aluno 2
  if      (aluno2_media >= 90) { aluno2_conceito = 'A'; }
  else if (aluno2_media >= 80) { aluno2_conceito = 'B'; }
  else if (aluno2_media >= 70) { aluno2_conceito = 'C'; }
  else if (aluno2_media >= 60) { aluno2_conceito = 'D'; }
  else                         { aluno2_conceito = 'R'; }
  // Aluno 3
  if      (aluno3_media >= 90) { aluno3_conceito = 'A'; }
  else if (aluno3_media >= 80) { aluno3_conceito = 'B'; }
  else if (aluno3_media >= 70) { aluno3_conceito = 'C'; }
  else if (aluno3_media >= 60) { aluno3_conceito = 'D'; }
  else                         { aluno3_conceito = 'R'; }
  
  // Imprime as notas em forma de tabela
  printf("Notas:\n");
  printf("Aluno %d\t%.2f\t%.2f\t%.2f\t%c\n",1, aluno1_nota1, aluno1_nota2, aluno1_nota3, aluno1_conceito);
  printf("Aluno %d\t%.2f\t%.2f\t%.2f\t%c\n",2, aluno2_nota1, aluno2_nota2, aluno2_nota3, aluno2_conceito);
  printf("Aluno %d\t%.2f\t%.2f\t%.2f\t%c\n",3, aluno3_nota1, aluno3_nota2, aluno3_nota3, aluno3_conceito);  
  
  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}