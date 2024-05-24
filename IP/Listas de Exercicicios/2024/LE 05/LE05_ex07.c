/**
 * @file   LE05_ex07.c
 * @brief  Arquivo com a implementa��o de sugest�o de 
 *         solu��o do exerc�cio 07 da LE 05 de 2024.
 * @author Leandro Maia Silva
 * @date   2024-05-24
 */

/* Inclus�es */
#include <stdio.h>   // printf e scanf

/* Constantes */

// Constante que associa o c�digo de erro 0 ao significado de sucesso
#define SUCESSO  0

// ----------------------------------------------------------------------

/**
 * Macro para utiliza��o do canal de sa�da de erro como
 * sa�da de texto para testes autom�ticos.
 */
#ifdef TESTADOR
  #define PRINTF(format, args...) fprintf(stderr, format, args)
#else
  #define PRINTF(format, args...) printf(format, args)
#endif

// ----------------------------------------------------------------------

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
  
  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}