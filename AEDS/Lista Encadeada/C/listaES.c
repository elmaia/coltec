/**
 * @file   listaES.c
 * @brief  Arquivo com a implementação do TAD Lista Encadeada Simples.
 * @author Leandro Maia Silva
 * @date   2020-08-13
 */

/* Inclusões */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "tipos.h"
#include "erros.h"
#include "lista.h"
#include "listaES.h"

/* Tipos */

/// Estrutura com os membros de um item da lista
struct itemListaES_s {
  dadosItem info;
  struct itemListaES_s * proximo;
};

/// Tipo "Item de Lista"
typedef struct itemListaES_s itemListaES_t;

/* Funções auxiliares */

/**
 * Função que inicializa a lista com os valores adequados.
 * @param lista Apontador para a lista a ser utilizada.
 */
static void listaES_inicializa(listaES_t * lista) {
  lista->nItens = 0;
  lista->primeiro = NULL;
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
static erro_t listaES_obtemElementoPosicao(listaES_t * lista, uint32_t posicao, itemListaES_t ** item) {

  itemListaES_t * atual;

  // Verifica se a lista possui elementos suficientes
  if (posicao > lista->nItens) return ERRO_LISTA_POSICAO_INVALIDA;

  // Começa a percorrer a lista a partir do primeiro elemento
  atual = (itemListaES_t *)lista->primeiro;


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
 * @return Apontador para o local onde a lista criada foi armazenada.
 */
listaES_t * listaES_cria(void) {

  // Reserva espaço na memória para a lista
  listaES_t * lista = (listaES_t *)malloc(sizeof(listaES_t));

  // Inicializa a mesma
  listaES_inicializa(lista);

  // Retorna o endereço da lista criada e inicializada
  return lista;
}

/**
 * Função que destroi a lista liberando o espaço utilizado por seus itens e 
 * por ela mesma.
 * @param lista Apontador para a lista a ser destruida.
 */
void listaES_destroi(listaES_t * lista) {

  itemListaES_t * atual, * proximo;

  // Começa pelo primeiro elemento da lista
  atual = (itemListaES_t *)lista->primeiro;

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
 * Função que insere um item no início da lista.
 * @param lista Apontador para a lista a ser utilizada.
 * @param info Informação a ser inserida na lista.
 * @return SUCESSO caso o item seja inserido corretamente na lista, ou caso
 * contrário, o código do erro.
 */
erro_t listaES_insereInicio(listaES_t * lista, dadosItem info) {
  return listaES_insereNesimaPosicao(lista, info, 0);
}

/**
 * Função que insere um item no fim da lista.
 * @param lista Apontador para a lista a ser utilizada.
 * @param info Informação a ser inserida na lista.
 * @return SUCESSO caso o item seja inserido corretamente na lista, ou caso
 * contrário, o código do erro.
 */
erro_t listaES_insereFinal(listaES_t * lista, dadosItem info) {
  return listaES_insereNesimaPosicao(lista, info, lista->nItens);
}

/**
 * Função que insere um item na posição especificada na lista.
 * @param lista Apontador para a lista a ser utilizada.
 * @param info Informação a ser inserida na lista.
 * @param posicao Posição onde a informação será inserida. O valor deve estar 
 * entre [0..lista->nItens].
 * @return SUCESSO caso o item seja inserido corretamente na lista, ou caso
 * contrário, o código do erro.
 */
erro_t listaES_insereNesimaPosicao(listaES_t * lista, dadosItem info, uint32_t posicao) {

  erro_t erro;
  itemListaES_t * novoItem, * anterior;

  // Verifico se a posição faz sentido com o número atual de itens na lista
  if (posicao > lista->nItens) return ERRO_LISTA_POSICAO_INVALIDA;

  // Cria um novo elemento e inicializa o item
  novoItem = (itemListaES_t *)malloc(sizeof(itemListaES_t));
  novoItem->info = info;
  novoItem->proximo = NULL;

  // Se for a posição ZERO, então o novo item será o novo primeiro item
  if (posicao == 0) {
    novoItem->proximo = (itemListaES_t *)lista->primeiro;
    lista->primeiro = novoItem;
  }
  // .. senão, então eu busco o item da posição N-1 para ligar o novo item.
  else {

    // Busco o item anterior para fazer a ligação
    erro = listaES_obtemElementoPosicao(lista, posicao - 1, &anterior);
    if (erro != SUCESSO) return erro;

    // Faço a ligação
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
erro_t listaES_removeElemento(listaES_t * lista, dadosItem info) {

  itemListaES_t * anterior = NULL;
  itemListaES_t * elementoARemover = (itemListaES_t *)lista->primeiro;

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
erro_t listaES_removePosicao(listaES_t * lista, uint32_t posicao) {

  erro_t erro;
  itemListaES_t * elementoARemover, * anterior;

  // Verifico se a posição faz sentido com o número atual de itens na lista
  if (posicao >= lista->nItens) return ERRO_LISTA_POSICAO_INVALIDA;

  // Aqui, garantidamente, eu tenho pelo menos um elemento na lista

  // Se for o primeiro da lista, então basta pulá-lo
  if (posicao == 0) {
    elementoARemover = (itemListaES_t *)lista->primeiro;
    lista->primeiro = elementoARemover->proximo;
  }
  // .. senão, eu busco o anterior e pulo o elemento a ser removido
  else {

    // Busco o item anterior para fazer a ligação
    erro = listaES_obtemElementoPosicao(lista, posicao - 1, &anterior);
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
bool_t listaES_busca(listaES_t * lista, dadosItem info, uint32_t * posicao) {

  uint32_t pos = 0;
  itemListaES_t * proximo = (itemListaES_t *)lista->primeiro;

  // Percore os elementos da lista procurando aquele cuja informação é a desejada
  while (proximo != NULL) {
    if (proximo->info == info) break;
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
bool_t listaES_estaVazia(listaES_t * lista) {
  return lista->nItens == 0;
}

/**
 * Função que imprime todos os itens da lista.
 * @param lista Apontador para a lista a ser utilizada.
 */
void listaES_imprime(listaES_t * lista) {

  uint32_t i;
  itemListaES_t * atual;
  itemListaES_t * proximo = lista->primeiro;

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