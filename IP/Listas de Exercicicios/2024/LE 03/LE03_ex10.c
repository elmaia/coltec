/**
 * @file   LE03_ex10.c
 * @brief  Arquivo com a implementação de sugestão de 
 *         solução do exercício 10 da LE 03 de 2024.
 * @author Leandro Maia Silva
 * @date   2024-03-28
 */

/* Inclusões */
#include <stdio.h>   // printf e scanf
#include <stdint.h>  // MAIOR_POSITIVO

/* Constantes */

// Constante que associa o código de erro 0 ao significado de sucesso
#define SUCESSO  0

// Maior número positivo com sinal
#define MAIOR_POSITIVO INT32_MAX

/**
 * Faça um programa que, dado um conjunto de valores
 * inteiros e positivos (fornecidos um a um pelo usuário), determine qual
 * o menor e o maior valor do conjunto. O final do conjunto de valores é
 * conhecido através do valor zero, que não deve ser considerado.
 */
int main(int argc, char ** argv) {
  
  int numero, retorno;
  int maiorAtual = 0;
  int menorAtual = MAIOR_POSITIVO;


  // Interração com o usuário
  printf("Digite uma sequencia de numeros inteiros positivos.\n"\
         "A cada numero, de <enter>.\n"\
         "O valor zero finaliza a sequencia.\n"\
         "Ao final sera exibido o maior e o menor numero da sequencia.\n");

  // Laço enquanto o usuário digitar números maiores ou iguais a zero
  do {

    printf("Numero:> ");
    retorno = scanf("%d", &numero);

    // Se o número atual é maior que o já conhecido, troca
    if (numero > maiorAtual) {
      maiorAtual = numero;
    }

    // Se o número atual é menor que o já conhecido, troca
    if ((numero > 0) && (numero < menorAtual)) {
      menorAtual = numero;
    }



  } while (numero > 0);

  // Verifica se houve alguma troca
  if (menorAtual == MAIOR_POSITIVO) {
    // Não houve troca
    printf("Sequencia vazia :-(\n");
  }
  else {

    // Mostra o maior e o menor valor encontrado
    printf("Resultado:\n"\
      "Maior: %d\n"\
      "Menor: %d\n",
      maiorAtual, menorAtual);
  }
  
  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}