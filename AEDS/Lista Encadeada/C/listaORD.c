/**
 * @file   listaORD.c
 * @brief  Arquivo com a implementação do TAD Lista Encadeada Simples Ordenada.
 * @author Leandro Maia Silva
 * @date   2020-08-18
 */

/* Inclusões */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "tipos.h"
#include "erros.h"
#include "lista.h"
#include "listaORD.h"

/* Tipos */

/// Estrutura com os membros de um item da lista
struct itemListaORD_s {
  dadosItem info;
  struct itemListaORD_s * proximo;
};

/// Tipo "Item de Lista"
typedef struct itemListaORD_s itemListaORD_t;

/* Funções auxiliares */

/**
 * Função que inicializa a lista com os valores adequados.
 * @param lista Apontador para a lista a ser utilizada.
 */
static void listaORD_inicializa(listaORD_t * lista, ComparaDadosItem_f funcComparar) {
  lista->nItens = 0;
  lista->primeiro = NULL;
  lista->comparador = funcComparar;
}

/**
 * Função que obtem o elemento da lista que está na N-ésima posição.
 * @param lista Apontador para a lista a ser percorrida.
 * @param posicao Posição do item desejado.
 * @param item Apontador para o local onde o endereço do item desejado
 * será armazenado.
 * @return SUCESSO caso o item desejado seja encontrado, ou caso contrário,
 * o código do erro ocorrido.
 */
static erro_t listaORD_obtemElementoPosicao(listaORD_t * lista, uint32_t posicao, itemListaORD_t ** item) {

  itemListaORD_t * atual;

  // Verifica se a lista possui elementos suficientes
  if (posicao > lista->nItens) return ERRO_LISTA_POSICAO_INVALIDA;

  // Começa a percorrer a lista a partir do primeiro elemento
  atual = (itemListaORD_t *)lista->primeiro;


  while (posicao-- != 0) {
    atual = atual->proximo;
  }

  // Se chegou até aqui é porque correu tudo bem
  *item = atual;
  return SUCESSO;
}

/* Funções exportadas */

/**
 * Função que cria e inicializa uma lista encadeada.
 * @funcComparar Função que compara os dados dos itens da lista.
 * @return Apontador para o local onde a lista criada foi armazenada.
 */
listaORD_t * listaORD_cria(ComparaDadosItem_f funcComparar) {

  // Reserva espaço na memória para a lista
  listaORD_t * lista = (listaORD_t *)malloc(sizeof(listaORD_t));

  // Inicializa a mesma
  listaORD_inicializa(lista, funcComparar);

  // Retorna o endereço da lista criada e inicializada
  return lista;
}

/**
 * Função que destroi a lista liberando o espaço utilizado por seus itens e 
 * por ela mesma.
 * @param lista Apontador para a lista a ser destruida.
 */
void listaORD_destroi(listaORD_t * lista) {

  itemListaORD_t * atual, * proximo;

  // Começa pelo primeiro elemento da lista
  atual = (itemListaORD_t *)lista->primeiro;

  // Percorre todos os elementos da lista dando free em cada um deles
  while (atual != NULL) {
    proximo = atual->proximo;
    free(atual);
    atual = proximo;
  }

  // Libera o espaço da lista
  free(lista);
}

/**
 * Função que insere um item na posição adequada na lista.
 * @param lista Apontador para a lista a ser utilizada.
 * @param info Informação a ser inserida na lista.
 * @return SUCESSO caso o item seja inserido corretamente na lista, ou caso
 * contrário, o código do erro.
 */
erro_t listaORD_insere(listaORD_t * lista, dadosItem info) {

  itemListaORD_t * novoItem, *atual, * anterior;

  // Cria um novo elemento e inicializa o item
  novoItem = (itemListaORD_t *)malloc(sizeof(itemListaORD_t));
  novoItem->info = info;
  novoItem->proximo = NULL;

  // Percorre os itens enquanto não achar a posição certa para inserior o item
  anterior = NULL;
  atual = (itemListaORD_t *)lista->primeiro;
  while ((atual != NULL) && (lista->comparador(atual->info, info) < 0)) {
    anterior = atual;
    atual = atual->proximo;
  }

  // Se o anterior é NULL, então está inserindo no início da lista
  if (anterior == NULL) {
    novoItem->proximo = (itemListaORD_t *)lista->primeiro;
    lista->primeiro = novoItem;
  }
  // Senão, então o anterior aponta para o novo e o novo para quem o anterior apontava
  else {
    novoItem->proximo = anterior->proximo;
    anterior->proximo = novoItem;
  }

  // Se chegou até aqui é porque o novo item foi inserido com sucesso na lista
  lista->nItens++;
  return SUCESSO;
}

/**
 * Função que remove um item da lista.
 * @param lista Apontador para a lista a ser utilizada.
 * @param info Informação do item a ser removido.
 * @return SUCESSO caso o item seja inserido removido na lista, ou caso
 * contrário, o código do erro.
 */
erro_t listaORD_removeElemento(listaORD_t * lista, dadosItem info) {

  itemListaORD_t * anterior = NULL;
  itemListaORD_t * elementoARemover = (itemListaORD_t *)lista->primeiro;

  // Percore os elementos da lista procurando aquele cuja informação é a desejada
  while (elementoARemover != NULL) {
    if (elementoARemover->info == info) break;
    anterior = elementoARemover;
    elementoARemover = elementoARemover->proximo;
  }

  // Verifica se o item foi encontrado, ou seja, se o elementoARemover não é nulo
  if (elementoARemover == NULL) { return ERRO_LISTA_ITEM_NAO_ENCONTRADO; }

  // Se chegou aqui é porque encontrou o item desejado e ele está no elementoARemover
  // Se o anterior é nulo, então é porque o item encontrado é o primeiro da lista ...
  if (anterior == NULL) {
    lista->primeiro = elementoARemover->proximo;
  }
  // ... senão, então ele pode estar em qualquer lugar, mas garantidamente não é o primeiro
  else {
    anterior->proximo = elementoARemover->proximo;
  }

  // Se chegou até aqui é porque o item foi removido corretamente da lista
  free(elementoARemover);
  lista->nItens--;
  return SUCESSO;
}

/**
 * Função que remove um item da lista na posição especificada.
 * @param lista Apontador para a lista a ser utilizada.
 * @param posicao Posição do item a ser removido.
 * @return SUCESSO caso o item seja inserido removido na lista, ou caso
 * contrário, o código do erro.
 */
erro_t listaORD_removePosicao(listaORD_t * lista, uint32_t posicao) {

  erro_t erro;
  itemListaORD_t * elementoARemover, * anterior;

  // Verifico se a posição faz sentido com o número atual de itens na lista
  if (posicao >= lista->nItens) return ERRO_LISTA_POSICAO_INVALIDA;

  // Aqui, garantidamente, eu tenho pelo menos um elemento na lista

  // Se for o primeiro da lista, então basta pulá-lo
  if (posicao == 0) {
    elementoARemover = (itemListaORD_t *)lista->primeiro;
    lista->primeiro = elementoARemover->proximo;
  }
  // .. senão, eu busco o anterior e pulo o elemento a ser removido
  else {

    // Busco o item anterior para fazer a ligação
    erro = listaORD_obtemElementoPosicao(lista, posicao - 1, &anterior);
    if (erro != SUCESSO) return erro;

    // Pulo o elemento a ser removido
    elementoARemover = anterior->proximo;
    anterior->proximo = elementoARemover->proximo;
  }

  // Se chegou até aqui é porque o item foi pulado e removido com sucesso na lista
  free(elementoARemover);
  lista->nItens--;
  return SUCESSO;
}

/**
 * Função que busca por um item na lista.
 * Observação: O primeiro item encontrado com a informação desejada é retornado.
 * @param lista Apontador para a lista a ser utilizada.
 * @param info Informação a ser procurada na lista.
 * @param posicao Endereço do local que receberá a posição do item encontrado.
 * @return SUCESSO caso o item desejado seja encontrado, ou caso contrário,
 * o código do erro ocorrido.
 */
bool_t listaORD_busca(listaORD_t * lista, dadosItem info, uint32_t * posicao) {

  uint32_t pos = 0;
  itemListaORD_t * proximo = (itemListaORD_t *)lista->primeiro;

  // Percore os elementos da lista procurando aquele cuja informação é a desejada
  while (proximo != NULL) {

    // Se é igual, então encontrou
    if (proximo->info == info) break;

    // Se o valor do item da lista é maior que o valor procurado, então certamente
    // não está na lista, pois a mesma é ordenada
    if (lista->comparador(proximo->info, info) > 0) {
      proximo = NULL;
      break;
    }

    proximo = proximo->proximo;
    pos++;
  }

  // O elemento que está no próximo é o item encontrado.
  // Caso a lista tenha chegado no final e nenhum item foi encontrado, então
  // o próximo é NULL
  // Caso a lista esteja vazia, então o próximo é NULL desde o início.
  if (proximo == NULL) return FALSO;
  
  // Se chegou até aqui é porque o item foi encontrado e sua posição está em pos
  *posicao = pos;
  return VERDADEIRO;
}

/**
 * Função que verifica se a lista está vazia.
 * @param lista Apontador para a lista a ser utilizada.
 * @return VERDADEIRO caso a lista esteja vazia, ou FALSO caso contrário.
 */
bool_t listaORD_estaVazia(listaORD_t * lista) {
  return lista->nItens == 0;
}

/**
 * Função que imprime todos os itens da lista.
 * @param lista Apontador para a lista a ser utilizada.
 */
void listaORD_imprime(listaORD_t * lista) {

  uint32_t i;
  itemListaORD_t * atual;
  itemListaORD_t * proximo = lista->primeiro;

  printf("Lista com %u item(s)\n", lista->nItens);
  printf("Impressao da lista\n"\
         "------------------\n");

  // Imprime posição e o valor de cada item da lista
  for (i = 0; i < lista->nItens; i++) {

    // Controla os links da lista
    atual = proximo;
    proximo = atual->proximo;

    printf("Pos: %u / Valor: %i\n", i, atual->info);
  }

  printf("------------------\n");
}