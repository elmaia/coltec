/**
 * @file   listaORD.c
 * @brief  Arquivo com a implementa��o do TAD Lista Encadeada Simples Ordenada.
 * @author Leandro Maia Silva
 * @date   2020-08-18
 */

/* Inclus�es */
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

/* Fun��es auxiliares */

/**
 * Fun��o que inicializa a lista com os valores adequados.
 * @param lista Apontador para a lista a ser utilizada.
 */
static void listaORD_inicializa(listaORD_t * lista, ComparaDadosItem_f funcComparar) {
  lista->nItens = 0;
  lista->primeiro = NULL;
  lista->comparador = funcComparar;
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
static erro_t listaORD_obtemElementoPosicao(listaORD_t * lista, uint32_t posicao, itemListaORD_t ** item) {

  itemListaORD_t * atual;

  // Verifica se a lista possui elementos suficientes
  if (posicao > lista->nItens) return ERRO_LISTA_POSICAO_INVALIDA;

  // Come�a a percorrer a lista a partir do primeiro elemento
  atual = (itemListaORD_t *)lista->primeiro;


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
 * @funcComparar Fun��o que compara os dados dos itens da lista.
 * @return Apontador para o local onde a lista criada foi armazenada.
 */
listaORD_t * listaORD_cria(ComparaDadosItem_f funcComparar) {

  // Reserva espa�o na mem�ria para a lista
  listaORD_t * lista = (listaORD_t *)malloc(sizeof(listaORD_t));

  // Inicializa a mesma
  listaORD_inicializa(lista, funcComparar);

  // Retorna o endere�o da lista criada e inicializada
  return lista;
}

/**
 * Fun��o que destroi a lista liberando o espa�o utilizado por seus itens e 
 * por ela mesma.
 * @param lista Apontador para a lista a ser destruida.
 */
void listaORD_destroi(listaORD_t * lista) {

  itemListaORD_t * atual, * proximo;

  // Come�a pelo primeiro elemento da lista
  atual = (itemListaORD_t *)lista->primeiro;

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
 * Fun��o que insere um item na posi��o adequada na lista.
 * @param lista Apontador para a lista a ser utilizada.
 * @param info Informa��o a ser inserida na lista.
 * @return SUCESSO caso o item seja inserido corretamente na lista, ou caso
 * contr�rio, o c�digo do erro.
 */
erro_t listaORD_insere(listaORD_t * lista, dadosItem info) {

  itemListaORD_t * novoItem, *atual, * anterior;

  // Cria um novo elemento e inicializa o item
  novoItem = (itemListaORD_t *)malloc(sizeof(itemListaORD_t));
  novoItem->info = info;
  novoItem->proximo = NULL;

  // Percorre os itens enquanto n�o achar a posi��o certa para inserior o item
  anterior = NULL;
  atual = (itemListaORD_t *)lista->primeiro;
  while ((atual != NULL) && (lista->comparador(atual->info, info) < 0)) {
    anterior = atual;
    atual = atual->proximo;
  }

  // Se o anterior � NULL, ent�o est� inserindo no in�cio da lista
  if (anterior == NULL) {
    novoItem->proximo = (itemListaORD_t *)lista->primeiro;
    lista->primeiro = novoItem;
  }
  // Sen�o, ent�o o anterior aponta para o novo e o novo para quem o anterior apontava
  else {
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
erro_t listaORD_removeElemento(listaORD_t * lista, dadosItem info) {

  itemListaORD_t * anterior = NULL;
  itemListaORD_t * elementoARemover = (itemListaORD_t *)lista->primeiro;

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
erro_t listaORD_removePosicao(listaORD_t * lista, uint32_t posicao) {

  erro_t erro;
  itemListaORD_t * elementoARemover, * anterior;

  // Verifico se a posi��o faz sentido com o n�mero atual de itens na lista
  if (posicao >= lista->nItens) return ERRO_LISTA_POSICAO_INVALIDA;

  // Aqui, garantidamente, eu tenho pelo menos um elemento na lista

  // Se for o primeiro da lista, ent�o basta pul�-lo
  if (posicao == 0) {
    elementoARemover = (itemListaORD_t *)lista->primeiro;
    lista->primeiro = elementoARemover->proximo;
  }
  // .. sen�o, eu busco o anterior e pulo o elemento a ser removido
  else {

    // Busco o item anterior para fazer a liga��o
    erro = listaORD_obtemElementoPosicao(lista, posicao - 1, &anterior);
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
bool_t listaORD_busca(listaORD_t * lista, dadosItem info, uint32_t * posicao) {

  uint32_t pos = 0;
  itemListaORD_t * proximo = (itemListaORD_t *)lista->primeiro;

  // Percore os elementos da lista procurando aquele cuja informa��o � a desejada
  while (proximo != NULL) {

    // Se � igual, ent�o encontrou
    if (proximo->info == info) break;

    // Se o valor do item da lista � maior que o valor procurado, ent�o certamente
    // n�o est� na lista, pois a mesma � ordenada
    if (lista->comparador(proximo->info, info) > 0) {
      proximo = NULL;
      break;
    }

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
bool_t listaORD_estaVazia(listaORD_t * lista) {
  return lista->nItens == 0;
}

/**
 * Fun��o que imprime todos os itens da lista.
 * @param lista Apontador para a lista a ser utilizada.
 */
void listaORD_imprime(listaORD_t * lista) {

  uint32_t i;
  itemListaORD_t * atual;
  itemListaORD_t * proximo = lista->primeiro;

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