/**
 * @file   filaLE.c
 * @brief  Arquivo com a implementa��o do TAD Fila utilizando Lista Encadeada.
 * @author Leandro Maia Silva
 * @date   2020-08-25
 */

/* Inclus�es */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "tipos.h"
#include "erros.h"
#include "fila.h"
#include "filaLE.h"

/* Tipos */

/// Estrutura com os membros de um item da fila
struct itemFilaLE_s {
  dadosItem info;
  struct itemFilaLE_s * proximo;
};

/// Tipo "Item de Fila"
typedef struct itemFilaLE_s itemFilaLE_t;

/* Fun��es auxiliares */

/**
 * Fun��o que inicializa a fila com os valores adequados.
 * @param fila Apontador para a fila a ser utilizada.
 */
static void filaLE_inicializa(filaLE_t * fila) {
  fila->nItens = 0;
  fila->primeiro = NULL;
  fila->ultimo = NULL;
}

/* Fun��es exportadas */

/**
 * Fun��o que cria e inicializa uma fila.
 * @return Apontador para o local onde a fila criada foi armazenada.
 */
filaLE_t * filaLE_cria(void) {

  // Reserva espa�o na mem�ria para a fila
  filaLE_t * fila = (filaLE_t *)malloc(sizeof(filaLE_t));

  // Inicializa a mesma
  filaLE_inicializa(fila);

  // Retorna o endere�o da fila criada e inicializada
  return fila;
}

/**
 * Fun��o que destroi a fila liberando o espa�o utilizado por seus itens e 
 * por ela mesma.
 * @param fila Apontador para a fila a ser destruida.
 */
void filaLE_destroi(filaLE_t * fila) {

  itemFilaLE_t * atual, *proximo;

  // Come�a pelo in�cio da fila
  atual = (itemFilaLE_t *)fila->primeiro;

  // Percorre todos os elementos da fila dando free em cada um deles
  while (atual != NULL) {
    proximo = atual->proximo;
    free(atual);
    atual = proximo;
  }

  // Libera o espa�o da fila
  free(fila);
}

/**
 * Fun��o que insere um item no final da fila.
 * @param fila Apontador para a fila a ser utilizada.
 * @param info Informa��o a ser inserida na fila.
 * @return SUCESSO caso o item seja inserido corretamente na fila, ou caso
 * contr�rio, o c�digo do erro.
 */
erro_t filaLE_insere(filaLE_t * fila, dadosItem info) {

  itemFilaLE_t * novoItem;

  // Cria um novo elemento e inicializa o item
  novoItem = (itemFilaLE_t *)malloc(sizeof(itemFilaLE_t));
  novoItem->info = info;
  novoItem->proximo = NULL;

  // Se tem item na fila, ent�o o novo entra depois dele
  if (fila->ultimo != NULL) {
    ((itemFilaLE_t *)fila->ultimo)->proximo = novoItem;
  }
  // sen�o, ent�o ele � o primeiro tamb�m
  else {
    fila->primeiro = novoItem;
  }

  // O novo item � sempre o �ltimo
  fila->ultimo = novoItem;
  fila->nItens++;

  // Se chegou at� aqui � porque o novo item foi inserido com sucesso na fila
  return SUCESSO;
}

/**
 * Fun��o que remove o item do in�cio da fila.
 * @param fila Apontador para a fila a ser utilizada.
 * @param info Apontador para o local que receber� o valor do item removido.
 * @return SUCESSO caso o item seja inserido removido na fila, ou caso
 * contr�rio, o c�digo do erro.
 */
erro_t filaLE_remove(filaLE_t * fila, dadosItem * info) {

  itemFilaLE_t * elementoARemover = (itemFilaLE_t *)fila->primeiro;

  // Verifica se a fila n�o est� vazia
  if (fila->nItens == 0) return ERRO_FILA_VAZIA;

  // Copia os dados, remove o item da fila
  (void)memcpy(info, &elementoARemover->info, sizeof(dadosItem));
  fila->primeiro = elementoARemover->proximo;

  // Se a fila ficou vazia, ent�o o �ltimo n�o � v�lido mais
  if (fila->primeiro == NULL) {
    fila->ultimo = NULL;
  }

  // Se chegou at� aqui � porque o item foi removido corretamente da fila
  free(elementoARemover);
  fila->nItens--;
  return SUCESSO;
}

/**
 * Fun��o que obtem o valor no in�cio da fila.
 * @param fila Apontador para a fila a ser utilizada.
 * @param info Apontador para o local que receber� o valor buscado.
 * @return SUCESSO caso o item seja obtido da fila, ou caso
 * contr�rio, o c�digo do erro.
 */
erro_t filaLE_primeiro(filaLE_t * fila, dadosItem * primeiro) {

  // Se a fila est� vazia, n�o h� primeiro
  if (fila->nItens == 0) return ERRO_FILA_VAZIA;

  // Copia o valor que est� no in�cio da fila para o local especificado
  (void)memcpy(primeiro, fila->primeiro, sizeof(dadosItem));

  // Se chegou at� aqui � porque deu tudo certo
  return SUCESSO;
}

/**
 * Fun��o que busca por um item na fila.
 * Observa��o: O primeiro item encontrado com a informa��o desejada � retornado.
 * @param fila Apontador para a fila a ser utilizada.
 * @param info Informa��o a ser procurada na fila.
 * @param posicao Endere�o do local que receber� a posi��o do item encontrado.
 * @return SUCESSO caso o item desejado seja encontrado, ou caso contr�rio,
 * o c�digo do erro ocorrido.
 */
bool_t filaLE_busca(filaLE_t * fila, dadosItem info, uint32_t * posicao) {

  uint32_t pos = 0;
  itemFilaLE_t * proximo = (itemFilaLE_t *)fila->primeiro;

  // Percore os elementos da fila procurando aquele cuja informa��o � a desejada
  while (proximo != NULL) {
    if (proximo->info == info) break;
    proximo = proximo->proximo;
    pos++;
  }

  // O elemento que est� no pr�ximo � o item encontrado.
  // Caso a fila tenha chegado no final e nenhum item foi encontrado, ent�o
  // o pr�ximo � NULL
  // Caso a fila esteja vazia, ent�o o pr�ximo � NULL desde o in�cio.
  if (proximo == NULL) return ERRO_FILA_ITEM_NAO_ENCONTRADO;

  // Se chegou at� aqui � porque o item foi encontrado e sua posi��o est� em pos
  *posicao = pos;
  return SUCESSO;
}

/**
 * Fun��o que verifica se a fila est� vazia.
 * @param fila Apontador para a fila a ser utilizada.
 * @return VERDADEIRO caso a fila esteja vazia, ou FALSO caso contr�rio.
 */
bool_t filaLE_estaVazia(filaLE_t * fila) {
  return fila->nItens == 0;
}

/**
 * Fun��o que imprime todos os itens da fila.
 * @param fila Apontador para a fila a ser utilizada.
 */
void filaLE_imprime(filaLE_t * fila) {

  uint32_t i;
  itemFilaLE_t * atual;
  itemFilaLE_t * proximo = (itemFilaLE_t *)fila->primeiro;

  printf("Fila com %u item(s)\n", fila->nItens);
  printf("Impressao da fila\n"\
    "------------------\n");

  // Imprime posi��o e o valor de cada item da fila
  for (i = 0; i < fila->nItens; i++) {

    // Controla os links da fila
    atual = proximo;
    proximo = atual->proximo;

    printf("Pos: %u / Valor: %i\n", i, atual->info);
  }

  printf("------------------\n");

}