/**
 * @file   LE03_ex10.c
 * @brief  Arquivo com a implementa��o de sugest�o de 
 *         solu��o do exerc�cio 10 da LE 03 de 2024.
 * @author Leandro Maia Silva
 * @date   2024-03-28
 */

/* Inclus�es */
#include <stdio.h>   // printf e scanf
#include <stdint.h>  // MAIOR_POSITIVO

/* Constantes */

// Constante que associa o c�digo de erro 0 ao significado de sucesso
#define SUCESSO  0

// Maior n�mero positivo com sinal
#define MAIOR_POSITIVO INT32_MAX

/**
 * Fa�a um programa que, dado um conjunto de valores
 * inteiros e positivos (fornecidos um a um pelo usu�rio), determine qual
 * o menor e o maior valor do conjunto. O final do conjunto de valores �
 * conhecido atrav�s do valor zero, que n�o deve ser considerado.
 */
int main(int argc, char ** argv) {
  
  int numero, retorno;
  int maiorAtual = 0;
  int menorAtual = MAIOR_POSITIVO;


  // Interra��o com o usu�rio
  printf("Digite uma sequencia de numeros inteiros positivos.\n"\
         "A cada numero, de <enter>.\n"\
         "O valor zero finaliza a sequencia.\n"\
         "Ao final sera exibido o maior e o menor numero da sequencia.\n");

  // La�o enquanto o usu�rio digitar n�meros maiores ou iguais a zero
  do {

    printf("Numero:> ");
    retorno = scanf("%d", &numero);

    // Se o n�mero atual � maior que o j� conhecido, troca
    if (numero > maiorAtual) {
      maiorAtual = numero;
    }

    // Se o n�mero atual � menor que o j� conhecido, troca
    if ((numero > 0) && (numero < menorAtual)) {
      menorAtual = numero;
    }



  } while (numero > 0);

  // Verifica se houve alguma troca
  if (menorAtual == MAIOR_POSITIVO) {
    // N�o houve troca
    printf("Sequencia vazia :-(\n");
  }
  else {

    // Mostra o maior e o menor valor encontrado
    printf("Resultado:\n"\
      "Maior: %d\n"\
      "Menor: %d\n",
      maiorAtual, menorAtual);
  }
  
  // Se chegou at� aqui � porque correu tudo bem
  return SUCESSO;
}