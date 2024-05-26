/**
 * @file   LE05_ex02.c
 * @brief  Arquivo com a implementação de sugestão de 
 *         solução do exercício 02 da LE 05 de 2024.
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
  #define PRINTF(format, ...) fprintf(stderr, format, __VA_ARGS__)
#else
  #define PRINTF(format, ...) printf(format, __VA_ARGS__)
#endif

// ----------------------------------------------------------------------

#define DIAS_ANO  365
#define DIAS_MES   30

int idadeEmDias(int anos, int meses, int dias) {
  return anos * DIAS_ANO + meses * DIAS_MES + dias;
}

/**
 *  Faça uma função que receba a idade de uma pessoa em
 *  anos, meses e dias e retorna essa idade expressa em dias.
 *  Considere cada ano como 365 dias e cada mês como 30 dias.
 */
int main(int argc, char ** argv) {
    
  int anos, meses, dias;
  int idadeDias;
  
  // Obtem os dados do usuário
  printf("Calculadora de dias de vida.\n");
  printf("Digite a quantidade de anos, meses e dias desde o seu nascimento.\n");
  printf("Anos: ");
  scanf("%d", &anos);
  printf("Meses: ");
  scanf("%d", &meses);
  printf("Dias: ");
  scanf("%d", &dias);
  
  // Calcula o número de dias
  idadeDias = idadeEmDias(anos, meses, dias);
  
  // Mostra o resultado para o usuário
  printf("Voce ja viveu ");
  PRINTF("%d", idadeDias);
  printf(" dias desde o seu nascimento.\n");
  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}