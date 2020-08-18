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
#include "listaES.h"
#include "listaED.h"

/**
 * Função que faz alguns testes na lista encadeada simples.
 */
void testeListaEncadeadaSimples(void) {

  erro_t erro;
  listaES_t * lista;
  uint32_t posicao;

  (void)printf("\nCria a lista e imprime para garantir que esta vazia\n");
  lista = listaES_cria();
  listaES_imprime(lista);
  (void)printf("A lista esta vazia? %s\n", ( listaES_estaVazia(lista) ? "SIM" : "NAO" ));

  (void)printf("\nInsere no inicio 1 e 2, entao vai ficar 2 1\n");
  erro = listaES_insereInicio(lista, 1);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }
  erro = listaES_insereInicio(lista, 2);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }
  (void)printf("\n* Lista apos inserir no inicio os item 1 e 2\n");
  listaES_imprime(lista);

  (void)printf("\nInsere no final 9 e 10, então vai ficar 9 10\n");
  erro = listaES_insereFinal(lista, 9);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }
  erro = listaES_insereFinal(lista, 10);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }
  (void)printf("\n* Lista apos inserir no final os item 9 e 10\n");
  listaES_imprime(lista);

  (void)printf("\nInsere na posicao 1 o item 3\n");
  erro = listaES_insereNesimaPosicao(lista, 3, 1);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }
  (void)printf("\nInsere na posicao 2 o item 5\n");
  erro = listaES_insereNesimaPosicao(lista, 5, 2);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }
  (void)printf("\nInsere na posicao 3 o item 7\n");
  erro = listaES_insereNesimaPosicao(lista, 7, 3);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }
  (void)printf("\n* Lista apos inserir os itens 3, 5 e 7 nas posicoes 1, 2 e 3 \n");
  listaES_imprime(lista);

  (void)printf("\nTentativa de remocao do item de valor 2\n");
  erro = listaES_removeElemento(lista, 2);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }
  (void)printf("\n* Lista apos remover o elemento 2\n");
  listaES_imprime(lista);

  (void)printf("\nTentativa de remocao do item de valor 1\n");
  erro = listaES_removeElemento(lista, 1);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }
  (void)printf("\n* Lista apos remover o elemento 1\n");
  listaES_imprime(lista);

  (void)printf("\nTentativa de remocao do item de valor 10\n");
  erro = listaES_removeElemento(lista, 10);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }
  (void)printf("\n* Lista apos remover o elemento 10\n");
  listaES_imprime(lista);

  (void)printf("\nTentativa de remocao do item de valor 10 novamente\n");
  erro = listaES_removeElemento(lista, 10);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
  }
  (void)printf("\n* Lista apos falhar em remover o elemento 10 novamente\n");
  listaES_imprime(lista);

  (void)printf("\nTentativa de remocao do item da posicao 2\n");
  erro = listaES_removePosicao(lista, 2);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
  }
  (void)printf("\n* Lista apos remover o elemento da posicao 2\n");
  listaES_imprime(lista);

  (void)printf("\nTentativa de remocao do item da posicao 0\n");
  erro = listaES_removePosicao(lista, 0);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
  }
  (void)printf("\n* Lista apos remover o elemento da posicao 0\n");
  listaES_imprime(lista);

  (void)printf("\nTentativa de remocao do item da posicao 1\n");
  erro = listaES_removePosicao(lista, 1);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
  }
  (void)printf("\n* Lista apos remover o elemento da posicao 1\n");
  listaES_imprime(lista);

  (void)printf("\nTentativa de remocao do item da posicao 1 novamente com a lista de 1 elemento\n");
  erro = listaES_removePosicao(lista, 1);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
  }
  (void)printf("\n* Lista apos falhar em remover o elemento 1 em uma lista com 1 elemento\n");
  listaES_imprime(lista);

  (void)printf("\nTentativa de encontrar o elemento de valor 0\n");
  erro = listaES_busca(lista, 0, &posicao);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
  }
  else {
    (void)printf("Foi encontrado o elemento 1 na posicao %u\n", posicao);
  }

  (void)printf("\nTentativa de encontrar o elemento de valor 5\n");
  erro = listaES_busca(lista, 5, &posicao);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
  }
  else {
    (void)printf("Foi encontrado o elemento 0 na posicao %u\n", posicao);
  }

  (void)printf("\nEstado da lista\n");
  (void)printf("A lista esta vazia? %s\n", (listaES_estaVazia(lista) ? "SIM" : "NAO"));


  // Label que irá agir como um Finally, ou seja, independente de erro ou não,
  // ele é executado
fim:

  // Destroi a lista
  (void)printf("\nDestruicao da lista\n");
  listaES_destroi(lista);
}

/**
* Função que faz alguns testes na lista encadeada dupla.
*/
void testeListaEncadeadaDupla(void) {

  erro_t erro;
  listaED_t * lista;
  uint32_t posicao;

  (void)printf("\nCria a lista e imprime para garantir que esta vazia\n");
  lista = listaED_cria();
  listaED_imprime(lista);
  (void)printf("A lista esta vazia? %s\n", (listaED_estaVazia(lista) ? "SIM" : "NAO"));

  (void)printf("\nInsere no inicio 1 e 2, entao vai ficar 2 1\n");
  erro = listaED_insereInicio(lista, 1);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }
  erro = listaED_insereInicio(lista, 2);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }
  (void)printf("\n* Lista apos inserir no inicio os item 1 e 2\n");
  listaED_imprime(lista);

  (void)printf("\nInsere no final 9 e 10, então vai ficar 9 10\n");
  erro = listaED_insereFinal(lista, 9);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }
  erro = listaED_insereFinal(lista, 10);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }
  (void)printf("\n* Lista apos inserir no final os item 9 e 10\n");
  listaED_imprime(lista);

  (void)printf("\nInsere na posicao 1 o item 3\n");
  erro = listaED_insereNesimaPosicao(lista, 3, 1);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }
  (void)printf("\nInsere na posicao 2 o item 5\n");
  erro = listaED_insereNesimaPosicao(lista, 5, 2);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }
  (void)printf("\nInsere na posicao 3 o item 7\n");
  erro = listaED_insereNesimaPosicao(lista, 7, 3);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }
  (void)printf("\n* Lista apos inserir os itens 3, 5 e 7 nas posicoes 1, 2 e 3 \n");
  listaED_imprime(lista);

  (void)printf("\nTentativa de remocao do item de valor 2\n");
  erro = listaED_removeElemento(lista, 2);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }
  (void)printf("\n* Lista apos remover o elemento 2\n");
  listaED_imprime(lista);

  (void)printf("\nTentativa de remocao do item de valor 1\n");
  erro = listaED_removeElemento(lista, 1);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }
  (void)printf("\n* Lista apos remover o elemento 1\n");
  listaED_imprime(lista);

  (void)printf("\nTentativa de remocao do item de valor 10\n");
  erro = listaED_removeElemento(lista, 10);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
    goto fim;
  }
  (void)printf("\n* Lista apos remover o elemento 10\n");
  listaED_imprime(lista);

  (void)printf("\nTentativa de remocao do item de valor 10 novamente\n");
  erro = listaED_removeElemento(lista, 10);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
  }
  (void)printf("\n* Lista apos falhar em remover o elemento 10 novamente\n");
  listaED_imprime(lista);

  (void)printf("\nTentativa de remocao do item da posicao 2\n");
  erro = listaED_removePosicao(lista, 2);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
  }
  (void)printf("\n* Lista apos remover o elemento da posicao 2\n");
  listaED_imprime(lista);

  (void)printf("\nTentativa de remocao do item da posicao 0\n");
  erro = listaED_removePosicao(lista, 0);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
  }
  (void)printf("\n* Lista apos remover o elemento da posicao 0\n");
  listaED_imprime(lista);

  (void)printf("\nTentativa de remocao do item da posicao 1\n");
  erro = listaED_removePosicao(lista, 1);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
  }
  (void)printf("\n* Lista apos remover o elemento da posicao 1\n");
  listaED_imprime(lista);

  (void)printf("\nTentativa de remocao do item da posicao 1 novamente com a lista de 1 elemento\n");
  erro = listaED_removePosicao(lista, 1);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
  }
  (void)printf("\n* Lista apos falhar em remover o elemento 1 em uma lista com 1 elemento\n");
  listaED_imprime(lista);

  (void)printf("\nTentativa de encontrar o elemento de valor 0\n");
  erro = listaED_busca(lista, 0, &posicao);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
  }
  else {
    (void)printf("Foi encontrado o elemento 1 na posicao %u\n", posicao);
  }

  (void)printf("\nTentativa de encontrar o elemento de valor 5\n");
  erro = listaED_busca(lista, 5, &posicao);
  if (erro != SUCESSO) {
    (void)fprintf(stderr, "Erro %u\n", erro);
  }
  else {
    (void)printf("Foi encontrado o elemento 0 na posicao %u\n", posicao);
  }

  (void)printf("\nEstado da lista\n");
  (void)printf("A lista esta vazia? %s\n", (listaED_estaVazia(lista) ? "SIM" : "NAO"));


  // Label que irá agir como um Finally, ou seja, independente de erro ou não,
  // ele é executado
fim:

  // Destroi a lista
  (void)printf("\nDestruicao da lista\n");
  listaED_destroi(lista);
}


/**
 * Ponto de entrada do programa.
 * @param argc Número de argumentos.
 * @param argv Valores dos argumentos.
 * @return SUCESSO caso o programa termine corretamente, ou caso contrário,
 * o código do erro ocorrido.
 */
int main(int argc, char ** argv) {

  testeListaEncadeadaDupla();

  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}