/**
 * @file   listaED.c
 * @brief  Arquivo com a implementa��o do TAD Lista Duplamente Encadeada.
 * @author Leandro Maia Silva
 * @date   2020-08-17
 */

/* Inclus�es */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "tipos.h"
#include "erros.h"
#include "lista.h"
#include "listaED.h"

/* Tipos */

/// Estrutura com os membros de um item da lista
struct itemListaED_s {
  struct itemListaED_s * anterior;
  dadosItem info;
  struct itemListaED_s * proximo;
};

/// Tipo "Item de Lista"
typedef struct itemListaED_s itemListaED_t;

/* Fun��es auxiliares */

/**
 * Fun��o que inicializa a lista com os valores adequados.
 * @param lista Apontador para a lista a ser utilizada.
 */
static void listaED_inicializa(listaED_t * lista) {
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
static erro_t listaED_obtemElementoPosicao(listaED_t * lista, uint32_t posicao, itemListaED_t ** item) {

  itemListaED_t * atual;

  // Verifica se a lista possui elementos suficientes
  if (posicao > lista->nItens) return ERRO_LISTA_POSICAO_INVALIDA;

  // Come�a a percorrer a lista a partir do primeiro elemento
  atual = (itemListaED_t *)lista->primeiro;


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
listaED_t * listaED_cria(void) {

  // Reserva espa�o na mem�ria para a lista
  listaED_t * lista = (listaED_t *)malloc(sizeof(listaED_t));

  // Inicializa a mesma
  listaED_inicializa(lista);

  // Retorna o endere�o da lista criada e inicializada
  return lista;
}

/**
 * Fun��o que destroi a lista liberando o espa�o utilizado por seus itens e 
 * por ela mesma.
 * @param lista Apontador para a lista a ser destruida.
 */
void listaED_destroi(listaED_t * lista) {

  itemListaED_t * atual, * proximo;

  // Come�a pelo primeiro elemento da lista
  atual = (itemListaED_t *)lista->primeiro;

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
erro_t listaED_insereInicio(listaED_t * lista, dadosItem info) {
  return listaED_insereNesimaPosicao(lista, info, 0);
}

/**
 * Fun��o que insere um item no fim da lista.
 * @param lista Apontador para a lista a ser utilizada.
 * @param info Informa��o a ser inserida na lista.
 * @return SUCESSO caso o item seja inserido corretamente na lista, ou caso
 * contr�rio, o c�digo do erro.
 */
erro_t listaED_insereFinal(listaED_t * lista, dadosItem info) {
  return listaED_insereNesimaPosicao(lista, info, lista->nItens);
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
erro_t listaED_insereNesimaPosicao(listaED_t * lista, dadosItem info, uint32_t posicao) {

  erro_t erro;
  itemListaED_t * novoItem, * anterior;

  // Verifico se a posi��o faz sentido com o n�mero atual de itens na lista
  if (posicao > lista->nItens) return ERRO_LISTA_POSICAO_INVALIDA;

  // Cria um novo elemento e inicializa o item
  novoItem = (itemListaED_t *)malloc(sizeof(itemListaED_t));
  novoItem->info = info;
  novoItem->proximo = NULL;
  novoItem->anterior = NULL;

  // Se for a posi��o ZERO, ent�o o novo item ser� o novo primeiro item
  if (posicao == 0) {
    novoItem->proximo = (itemListaED_t *)lista->primeiro;

    // Se o antigo primeiro n�o era nulo, ent�o ele precisa apontar para o novo item
    if (novoItem->proximo != NULL) {
      novoItem->proximo->anterior = novoItem;
    }

    // Torna o novo item o primeiro da lista
    lista->primeiro = novoItem;
  }
  // .. sen�o, ent�o eu busco o item da posi��o N-1 para ligar o novo item.
  else {

    // Busco o item anterior para fazer a liga��o
    erro = listaED_obtemElementoPosicao(lista, posicao - 1, &anterior);
    if (erro != SUCESSO) return erro;

    // Fa�o a liga��o
    novoItem->proximo = anterior->proximo;
    anterior->proximo = novoItem;
    novoItem->anterior = anterior;

    // Se existia um item depois da posi��o onde estou colocando o novoItem, ent�o
    // preciso faz�-lo apontar para o novoItem.
    if (novoItem->proximo != NULL) {
      novoItem->proximo->anterior = novoItem;
    }
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
erro_t listaED_removeElemento(listaED_t * lista, dadosItem info) {

  itemListaED_t * elementoARemover = (itemListaED_t *)lista->primeiro;

  // Percore os elementos da lista procurando aquele cuja informa��o � a desejada
  while (elementoARemover != NULL) {
    if (elementoARemover->info == info) break;
    elementoARemover = elementoARemover->proximo;
  }

  // Verifica se o item foi encontrado, ou seja, se o elementoARemover n�o � nulo
  if (elementoARemover == NULL) { return ERRO_LISTA_ITEM_NAO_ENCONTRADO; }

  // Se o pr�ximo existe, ent�o ele aponta para o anterior
  if (elementoARemover->proximo != NULL) {
    elementoARemover->proximo->anterior = elementoARemover->anterior;
  }

  // Se o anterior existe, ent�o ele aponta para o pr�ximo
  if (elementoARemover->anterior != NULL) {
    elementoARemover->anterior->proximo = elementoARemover->proximo;
  }
  // ... se n�o existe, ent�o estou removendo o primeiro da listatenho, ent�o sou o primeiro da lista
  else {

    // O novo in�cio � pr�ximo do item a ser removido removido
    lista->primeiro = elementoARemover->proximo;
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
erro_t listaED_removePosicao(listaED_t * lista, uint32_t posicao) {

  erro_t erro;
  itemListaED_t * elementoARemover;

  // Verifico se a posi��o faz sentido com o n�mero atual de itens na lista
  if (posicao >= lista->nItens) return ERRO_LISTA_POSICAO_INVALIDA;

  // Aqui, garantidamente, eu tenho pelo menos um elemento na lista

  // Busco o item a ser removido
  erro = listaED_obtemElementoPosicao(lista, posicao, &elementoARemover);
  if (erro != SUCESSO) return erro;

  // Se eu tenho um anterior, ent�o fa�o ele apontar para o pr�ximo
  if (elementoARemover->anterior != NULL) {
    elementoARemover->anterior->proximo = elementoARemover->proximo;
  }

  // Se eu tenho um pr�ximo, ent�o fa�o ele apontar para o anterior
  if (elementoARemover->proximo != NULL) {
    elementoARemover->proximo->anterior = elementoARemover->anterior;
  }

  // Se eu removi o primeiro item da lista, ent�o o pr�ximo � o novo primeiro
  if (posicao == 0) {
    lista->primeiro = elementoARemover->proximo;
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
bool_t listaED_busca(listaED_t * lista, dadosItem info, uint32_t * posicao) {

  uint32_t pos = 0;
  itemListaED_t * proximo = (itemListaED_t *)lista->primeiro;

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
  if (proximo == NULL) return ERRO_LISTA_ITEM_NAO_ENCONTRADO;
  
  // Se chegou at� aqui � porque o item foi encontrado e sua posi��o est� em pos
  *posicao = pos;
  return SUCESSO;
}

/**
 * Fun��o que verifica se a lista est� vazia.
 * @param lista Apontador para a lista a ser utilizada.
 * @return VERDADEIRO caso a lista esteja vazia, ou FALSO caso contr�rio.
 */
bool_t listaED_estaVazia(listaED_t * lista) {
  return lista->nItens == 0;
}

/**
 * Fun��o que imprime todos os itens da lista.
 * @param lista Apontador para a lista a ser utilizada.
 */
void listaED_imprime(listaED_t * lista) {

  uint32_t i;
  itemListaED_t * atual;
  itemListaED_t * proximo = lista->primeiro;

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