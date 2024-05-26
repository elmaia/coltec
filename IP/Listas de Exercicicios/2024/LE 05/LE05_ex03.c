/**
 * @file   LE05_ex03.c
 * @brief  Arquivo com a implementa��o de sugest�o de 
 *         solu��o do exerc�cio 03 da LE 05 de 2024.
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
  
  // O tempo restante j� � a quantidade de segundos
  segundos = tempoSegundos;
  
  // Mostra o resultado
  printf("Tempo experimento: ");
  PRINTF("%02d:%02d:%02d", horas, minutos, segundos);
  printf("\n");
}

/**
 *  Fa�a um procedimento que receba por par�metro o tempo
 *  de dura��o de um experimento expresso em segundos e imprima na tela esse
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
  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}