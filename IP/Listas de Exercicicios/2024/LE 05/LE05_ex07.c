/**
 * @file   LE05_ex07.c
 * @brief  Arquivo com a implementação de sugestão de 
 *         solução do exercício 07 da LE 05 de 2024.
 * @author Leandro Maia Silva
 * @date   2024-05-24
 */

/* Inclusões */
#include <stdio.h>   // printf e scanf

/* Constantes */

// Constante que associa o código de erro 0 ao significado de sucesso
#define SUCESSO  0

// ----------------------------------------------------------------------

/**
 * Macro para utilização do canal de saída de erro como
 * saída de texto para testes automáticos.
 */
#ifdef TESTADOR
  #define PRINTF(format, args...) fprintf(stderr, format, args)
#else
  #define PRINTF(format, args...) printf(format, args)
#endif

// ----------------------------------------------------------------------

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
  
  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}