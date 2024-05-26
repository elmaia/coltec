/**
 * @file   LE05_ex03.c
 * @brief  Arquivo com a implementação de sugestão de 
 *         solução do exercício 03 da LE 05 de 2024.
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

#define MINUTO_SEGUNDOS    60
#define HORAS_SEGUNDOS     (60 * MINUTO_SEGUNDOS)

void imprimeDuracaoExperimento(int tempoSegundos) {
  
  int horas, minutos, segundos;
  
  // Obtem as horas
  horas = tempoSegundos / HORAS_SEGUNDOS;
  tempoSegundos -= (horas * HORAS_SEGUNDOS);
  
  // Do tempo restante, obtem os minutos
  minutos = tempoSegundos / MINUTO_SEGUNDOS;
  tempoSegundos -= (minutos * MINUTO_SEGUNDOS);
  
  // O tempo restante já é a quantidade de segundos
  segundos = tempoSegundos;
  
  // Mostra o resultado
  printf("Tempo experimento: ");
  PRINTF("%02d:%02d:%02d", horas, minutos, segundos);
  printf("\n");
}

/**
 *  Faça um procedimento que receba por parâmetro o tempo
 *  de duração de um experimento expresso em segundos e imprima na tela esse
 *  mesmo tempo em horas, minutos e segundos.
 */
int main(int argc, char ** argv) {
    
  int tempoExperimento;
  
  // Obtem o tempo do experimento
  printf("Calculadora de Tempo do Experimento.\n");
  printf("Digite a duracao, em segundos, do experimento.\n");
  printf(":> ");
  scanf("%d", &tempoExperimento);
  
  // Imprime o tempo em formato HH:MM:SS
  imprimeDuracaoExperimento(tempoExperimento);  
  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}