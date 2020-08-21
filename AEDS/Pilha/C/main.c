/**
 * @file   main.c
 * @brief  Arquivo com a implementação das funções de entrada do programa.
 * @author Leandro Maia
 * @date   2020-08-13
 */

/* Inclusões */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "tipos.h"
#include "erros.h"
#include "pilhaV.h"
#include "pilhaLE.h"

/**
 * Função que faz alguns testes na pilha com vetor.
 */
void testaPilhaVetor(void) {

  erro_t erro;
  pilhaV_t * pilha;
  dadosItem valor;
  uint32_t posicao;

  (void)printf("Criacao e impressao da pilha\n");
  pilha = pilhaV_cria(5);
  pilhaV_imprime(pilha);
  (void)printf("Pilha esta vazia? %s\n", pilhaV_estaVazia(pilha) ? "SIM" : "NAO");

  (void)printf("\nInserir os valores 1, 2 e 3.\n");
  erro = pilhaV_empilha(pilha, 1);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }
  erro = pilhaV_empilha(pilha, 2);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }
  erro = pilhaV_empilha(pilha, 3);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }

  (void)printf("\nPilha apos inserir os tres valores\n");
  pilhaV_imprime(pilha);

  (void)printf("\nRemover o elemento do topo\n");
  erro = pilhaV_desempilha(pilha, &valor);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }
  (void)printf("Foi removido o valor %d da pilha\n", valor);

  (void)printf("\nInserir os valores 4, 5 e 6.\n");
  erro = pilhaV_empilha(pilha, 4);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }
  erro = pilhaV_empilha(pilha, 5);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }
  erro = pilhaV_empilha(pilha, 6);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }

  (void)printf("\nPilha apos inserir os tres valores\n");
  pilhaV_imprime(pilha);

  (void)printf("\nTentativa de inserir mais um elemento na pilha cheia\n");
  erro = pilhaV_empilha(pilha, 7);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
  }
  pilhaV_imprime(pilha);

  (void)printf("\nRemocao de todos os itens da pilha\n");
  erro = pilhaV_desempilha(pilha, &valor);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }
  erro = pilhaV_desempilha(pilha, &valor);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }
  erro = pilhaV_desempilha(pilha, &valor);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }
  erro = pilhaV_desempilha(pilha, &valor);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }
  erro = pilhaV_desempilha(pilha, &valor);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }
  pilhaV_imprime(pilha);

  (void)printf("\nTentativa de remover mais um elemento na pilha vazia\n");
  erro = pilhaV_desempilha(pilha, &valor);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
  }
  pilhaV_imprime(pilha);

  (void)printf("\nInserir os valores 8, 9 e 10.\n");
  erro = pilhaV_empilha(pilha, 8);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }
  erro = pilhaV_empilha(pilha, 9);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }
  erro = pilhaV_empilha(pilha, 10);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }
  (void)printf("\nPilha apos inserir os tres valores\n");
  pilhaV_imprime(pilha);

  erro = pilhaV_topo(pilha, &valor);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }
  (void)printf("O valor que esta no topo eh: %d\n", valor);

  (void)printf("Vou procurar pelo valor 8 na pilha\n");
  erro = pilhaV_busca(pilha, 8, &posicao);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }
  (void)printf("O valor 8 esta na posicao %d\n", posicao);

  (void)printf("Vou entar procurar pelo valor 1 na pilha\n");
  erro = pilhaV_busca(pilha, 1, &posicao);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }

  pilhaV_imprime(pilha);
  (void)printf("Pilha esta vazia? %s\n", pilhaV_estaVazia(pilha) ? "SIM" : "NAO");


  // Label que irá agir como um Finally, ou seja, independente de erro ou não,
  // ele é executado
fim:

  // Destroi a pilha
  (void)printf("\nDestruicao da pilha\n");
  pilhaV_destroi(pilha);

}

/**
 * Função que faz alguns testes na pilha com vetor.
 */
void testaPilhaLista(void) {

  erro_t erro;
  pilhaLE_t * pilha;
  dadosItem valor;
  uint32_t posicao;

  (void)printf("Criacao e impressao da pilha\n");
  pilha = pilhaLE_cria();
  pilhaLE_imprime(pilha);
  (void)printf("Pilha esta vazia? %s\n", pilhaLE_estaVazia(pilha) ? "SIM" : "NAO");

  (void)printf("\nInserir os valores 1, 2 e 3.\n");
  erro = pilhaLE_empilha(pilha, 1);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }
  erro = pilhaLE_empilha(pilha, 2);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }
  erro = pilhaLE_empilha(pilha, 3);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }

  (void)printf("\nPilha apos inserir os tres valores\n");
  pilhaLE_imprime(pilha);

  (void)printf("\nRemover o elemento do topo\n");
  erro = pilhaLE_desempilha(pilha, &valor);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }
  (void)printf("Foi removido o valor %d da pilha\n", valor);

  (void)printf("\nInserir os valores 4, 5 e 6.\n");
  erro = pilhaLE_empilha(pilha, 4);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }
  erro = pilhaLE_empilha(pilha, 5);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }
  erro = pilhaLE_empilha(pilha, 6);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }

  (void)printf("\nPilha apos inserir os tres valores\n");
  pilhaLE_imprime(pilha);

  (void)printf("\nTentativa de inserir mais um elemento na pilha\n");
  erro = pilhaLE_empilha(pilha, 7);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
  }
  pilhaLE_imprime(pilha);

  (void)printf("\nRemocao de todos os itens da pilha\n");
  erro = pilhaLE_desempilha(pilha, &valor);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }
  erro = pilhaLE_desempilha(pilha, &valor);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }
  erro = pilhaLE_desempilha(pilha, &valor);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }
  erro = pilhaLE_desempilha(pilha, &valor);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }
  erro = pilhaLE_desempilha(pilha, &valor);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }
  erro = pilhaLE_desempilha(pilha, &valor);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }
  pilhaLE_imprime(pilha);

  (void)printf("\nTentativa de remover mais um elemento na pilha vazia\n");
  erro = pilhaLE_desempilha(pilha, &valor);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
  }
  pilhaLE_imprime(pilha);

  (void)printf("\nInserir os valores 8, 9 e 10.\n");
  erro = pilhaLE_empilha(pilha, 8);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }
  erro = pilhaLE_empilha(pilha, 9);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }
  erro = pilhaLE_empilha(pilha, 10);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }
  (void)printf("\nPilha apos inserir os tres valores\n");
  pilhaLE_imprime(pilha);

  erro = pilhaLE_topo(pilha, &valor);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }
  (void)printf("O valor que esta no topo eh: %d\n", valor);

  (void)printf("Vou procurar pelo valor 8 na pilha\n");
  erro = pilhaLE_busca(pilha, 8, &posicao);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }
  (void)printf("O valor 8 esta na posicao %d\n", posicao);

  (void)printf("Vou entar procurar pelo valor 1 na pilha\n");
  erro = pilhaLE_busca(pilha, 1, &posicao);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }

  pilhaLE_imprime(pilha);
  (void)printf("Pilha esta vazia? %s\n", pilhaLE_estaVazia(pilha) ? "SIM" : "NAO");


  // Label que irá agir como um Finally, ou seja, independente de erro ou não,
  // ele é executado
fim:

  // Destroi a pilha
  (void)printf("\nDestruicao da pilha\n");
  pilhaLE_destroi(pilha);

}


/**
 * Ponto de entrada do programa.
 * @param argc Número de argumentos.
 * @param argv Valores dos argumentos.
 * @return SUCESSO caso o programa termine corretamente, ou caso contrário,
 * o código do erro ocorrido.
 */
int main(int argc, char ** argv) {

  testaPilhaVetor();
  testaPilhaLista();

  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}