/**
 * @file   listaES.c
 * @brief  Arquivo com a implementa��o do TAD Lista Encadeada Simples.
 * @author Leandro Maia Silva
 * @date   2020-08-13
 */

/* Inclus�es */
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

/* Fun��es auxiliares */

/**
 * Fun��o que inicializa a lista com os valores adequados.
 * @param lista Apontador para a lista a ser utilizada.
 */
static void listaES_inicializa(listaES_t * lista) {
  lista->nItens = 0;
  lista->primeiro = NULL;
}

/**
 * Fun��o que obtem o elemento da lista que est� na N-�sima posi��o.
 * @param lista Apontador para a lista a ser percorrida.
 * @param posicao Posi��o do item desejado.
 * @param item Apontador para o local onde o endere�o do item desejado
 * ser� armazenado.
 * @return SUCESSO caso o item desejado seja encontrado, ou caso contr�rio,
 * o c�digo do erro ocorrido.
 */
static erro_t listaES_obtemElementoPosicao(listaES_t * lista, uint32_t posicao, itemListaES_t ** item) {

  itemListaES_t * atual;

  // Verifica se a lista possui elementos suficientes
  if (posicao > lista->nItens) return ERRO_LISTA_POSICAO_INVALIDA;

  // Come�a a percorrer a lista a partir do primeiro elemento
  atual = (itemListaES_t *)lista->primeiro;


  while (posicao-- != 0) {
    atual = atual->proximo;
  }

  // Se chegou at� aqui � porque correu tudo bem
  *item = atual;
  return SUCESSO;
}

/* Fun��es exportadas */

/**
 * Fun��o que cria e inicializa uma lista encadeada.
 * @return Apontador para o local onde a lista criada foi armazenada.
 */
listaES_t * listaES_cria(void) {

  // Reserva espa�o na mem�ria para a lista
  listaES_t * lista = (listaES_t *)malloc(sizeof(listaES_t));

  // Inicializa a mesma
  listaES_inicializa(lista);

  // Retorna o endere�o da lista criada e inicializada
  return lista;
}

/**
 * Fun��o que destroi a lista liberando o espa�o utilizado por seus itens e 
 * por ela mesma.
 * @param lista Apontador para a lista a ser destruida.
 */
void listaES_destroi(listaES_t * lista) {

  itemListaES_t * atual, * proximo;

  // Come�a pelo primeiro elemento da lista
  atual = (itemListaES_t *)lista->primeiro;

  // Percorre todos os elementos da lista dando free em cada um deles
  while (atual != NULL) {
    proximo = atual->proximo;
    free(atual);
    atual = proximo;
  }

  // Libera o espa�o da lista
  free(lista);
}

/**
 * Fun��o que insere um item no in�cio da lista.
 * @param lista Apontador para a lista a ser utilizada.
 * @param info Informa��o a ser inserida na lista.
 * @return SUCESSO caso o item seja inserido corretamente na lista, ou caso
 * contr�rio, o c�digo do erro.
 */
erro_t listaES_insereInicio(listaES_t * lista, dadosItem info) {
  return listaES_insereNesimaPosicao(lista, info, 0);
}

/**
 * Fun��o que insere um item no fim da lista.
 * @param lista Apontador para a lista a ser utilizada.
 * @param info Informa��o a ser inserida na lista.
 * @return SUCESSO caso o item seja inserido corretamente na lista, ou caso
 * contr�rio, o c�digo do erro.
 */
erro_t listaES_insereFinal(listaES_t * lista, dadosItem info) {
  return listaES_insereNesimaPosicao(lista, info, lista->nItens);
}

/**
 * Fun��o que insere um item na posi��o especificada na lista.
 * @param lista Apontador para a lista a ser utilizada.
 * @param info Informa��o a ser inserida na lista.
 * @param posicao Posi��o onde a informa��o ser� inserida. O valor deve estar 
 * entre [0..lista->nItens].
 * @return SUCESSO caso o item seja inserido corretamente na lista, ou caso
 * contr�rio, o c�digo do erro.
 */
erro_t listaES_insereNesimaPosicao(listaES_t * lista, dadosItem info, uint32_t posicao) {

  erro_t erro;
  itemListaES_t * novoItem, * anterior;

  // Verifico se a posi��o faz sentido com o n�mero atual de itens na lista
  if (posicao > lista->nItens) return ERRO_LISTA_POSICAO_INVALIDA;

  // Cria um novo elemento e inicializa o item
  novoItem = (itemListaES_t *)malloc(sizeof(itemListaES_t));
  novoItem->info = info;
  novoItem->proximo = NULL;

  // Se for a posi��o ZERO, ent�o o novo item ser� o novo primeiro item
  if (posicao == 0) {
    novoItem->proximo = (itemListaES_t *)lista->primeiro;
    lista->primeiro = novoItem;
  }
  // .. sen�o, ent�o eu busco o item da posi��o N-1 para ligar o novo item.
  else {

    // Busco o item anterior para fazer a liga��o
    erro = listaES_obtemElementoPosicao(lista, posicao - 1, &anterior);
    if (erro != SUCESSO) return erro;

    // Fa�o a liga��o
    novoItem->proximo = anterior->proximo;
    anterior->proximo = novoItem;
  }

  // Se chegou at� aqui � porque o novo item foi inserido com sucesso na lista
  lista->nItens++;
  return SUCESSO;
}

/**
 * Fun��o que remove um item da lista.
 * @param lista Apontador para a lista a ser utilizada.
 * @param info Informa��o do item a ser removido.
 * @return SUCESSO caso o item seja inserido removido na lista, ou caso
 * contr�rio, o c�digo do erro.
 */
erro_t listaES_removeElemento(listaES_t * lista, dadosItem info) {

  itemListaES_t * anterior = NULL;
  itemListaES_t * elementoARemover = (itemListaES_t *)lista->primeiro;

  // Percore os elementos da lista procurando aquele cuja informa��o � a desejada
  while (elementoARemover != NULL) {
    if (elementoARemover->info == info) break;
    anterior = elementoARemover;
    elementoARemover = elementoARemover->proximo;
  }

  // Verifica se o item foi encontrado, ou seja, se o elementoARemover n�o � nulo
  if (elementoARemover == NULL) { return ERRO_LISTA_ITEM_NAO_ENCONTRADO; }

  // Se chegou aqui � porque encontrou o item desejado e ele est� no elementoARemover
  // Se o anterior � nulo, ent�o � porque o item encontrado � o primeiro da lista ...
  if (anterior == NULL) {
    lista->primeiro = elementoARemover->proximo;
  }
  // ... sen�o, ent�o ele pode estar em qualquer lugar, mas garantidamente n�o � o primeiro
  else {
    anterior->proximo = elementoARemover->proximo;
  }

  // Se chegou at� aqui � porque o item foi removido corretamente da lista
  free(elementoARemover);
  lista->nItens--;
  return SUCESSO;
}

/**
 * Fun��o que remove um item da lista na posi��o especificada.
 * @param lista Apontador para a lista a ser utilizada.
 * @param posicao Posi��o do item a ser removido.
 * @return SUCESSO caso o item seja inserido removido na lista, ou caso
 * contr�rio, o c�digo do erro.
 */
erro_t listaES_removePosicao(listaES_t * lista, uint32_t posicao) {

  erro_t erro;
  itemListaES_t * elementoARemover, * anterior;

  // Verifico se a posi��o faz sentido com o n�mero atual de itens na lista
  if (posicao >= lista->nItens) return ERRO_LISTA_POSICAO_INVALIDA;

  // Aqui, garantidamente, eu tenho pelo menos um elemento na lista

  // Se for o primeiro da lista, ent�o basta pul�-lo
  if (posicao == 0) {
    elementoARemover = (itemListaES_t *)lista->primeiro;
    lista->primeiro = elementoARemover->proximo;
  }
  // .. sen�o, eu busco o anterior e pulo o elemento a ser removido
  else {

    // Busco o item anterior para fazer a liga��o
    erro = listaES_obtemElementoPosicao(lista, posicao - 1, &anterior);
    if (erro != SUCESSO) return erro;

    // Pulo o elemento a ser removido
    elementoARemover = anterior->proximo;
    anterior->proximo = elementoARemover->proximo;
  }

  // Se chegou at� aqui � porque o item foi pulado e removido com sucesso na lista
  free(elementoARemover);
  lista->nItens--;
  return SUCESSO;
}

/**
 * Fun��o que busca por um item na lista.
 * Observa��o: O primeiro item encontrado com a informa��o desejada � retornado.
 * @param lista Apontador para a lista a ser utilizada.
 * @param info Informa��o a ser procurada na lista.
 * @param posicao Endere�o do local que receber� a posi��o do item encontrado.
 * @return SUCESSO caso o item desejado seja encontrado, ou caso contr�rio,
 * o c�digo do erro ocorrido.
 */
bool_t listaES_busca(listaES_t * lista, dadosItem info, uint32_t * posicao) {

  uint32_t pos = 0;
  itemListaES_t * proximo = (itemListaES_t *)lista->primeiro;

  // Percore os elementos da lista procurando aquele cuja informa��o � a desejada
  while (proximo != NULL) {
    if (proximo->info == info) break;
    proximo = proximo->proximo;
    pos++;
  }

  // O elemento que est� no pr�ximo � o item encontrado.
  // Caso a lista tenha chegado no final e nenhum item foi encontrado, ent�o
  // o pr�ximo � NULL
  // Caso a lista esteja vazia, ent�o o pr�ximo � NULL desde o in�cio.
  if (proximo == NULL) return FALSO;
  
  // Se chegou at� aqui � porque o item foi encontrado e sua posi��o est� em pos
  *posicao = pos;
  return VERDADEIRO;
}

/**
 * Fun��o que verifica se a lista est� vazia.
 * @param lista Apontador para a lista a ser utilizada.
 * @return VERDADEIRO caso a lista esteja vazia, ou FALSO caso contr�rio.
 */
bool_t listaES_estaVazia(listaES_t * lista) {
  return lista->nItens == 0;
}

/**
 * Fun��o que imprime todos os itens da lista.
 * @param lista Apontador para a lista a ser utilizada.
 */
void listaES_imprime(listaES_t * lista) {

  uint32_t i;
  itemListaES_t * atual;
  itemListaES_t * proximo = lista->primeiro;

  printf("Lista com %u item(s)\n", lista->nItens);
  printf("Impressao da lista\n"\
         "------------------\n");

  // Imprime posi��o e o valor de cada item da lista
  for (i = 0; i < lista->nItens; i++) {

    // Controla os links da lista
    atual = proximo;
    proximo = atual->proximo;

    printf("Pos: %u / Valor: %i\n", i, atual->info);
  }

  printf("------------------\n");
}