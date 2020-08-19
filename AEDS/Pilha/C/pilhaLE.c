/**
 * @file   pilhaLE.c
 * @brief  Arquivo com a implementa��o do TAD Pilha utilizando pilha Encadeada.
 * @author Leandro Maia Silva
 * @date   2020-08-18
 */

/* Inclus�es */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "tipos.h"
#include "erros.h"
#include "pilha.h"
#include "pilhaLE.h"

/* Tipos */

/// Estrutura com os membros de um item da pilha
struct itemPilhaLE_s {
  dadosItem info;
  struct itemPilhaLE_s * proximo;
};

/// Tipo "Item de pilha"
typedef struct itemPilhaLE_s itemPilhaLE_t;

/* Fun��es auxiliares */

/**
 * Fun��o que inicializa a pilha com os valores adequados.
 * @param pilha Apontador para a pilha a ser utilizada.
 */
static void pilhaLE_inicializa(pilhaLE_t * pilha) {
  pilha->nItens = 0;
  pilha->topo = NULL;
}

/* Fun��es exportadas */

/**
 * Fun��o que cria e inicializa uma pilha.
 * @return Apontador para o local onde a pilha criada foi armazenada.
 */
pilhaLE_t * pilhaLE_cria(void) {

  // Reserva espa�o na mem�ria para a pilha
  pilhaLE_t * pilha = (pilhaLE_t *)malloc(sizeof(pilhaLE_t));

  // Inicializa a mesma
  pilhaLE_inicializa(pilha);

  // Retorna o endere�o da pilha criada e inicializada
  return pilha;
}

/**
 * Fun��o que destroi a pilha liberando o espa�o utilizado por seus itens e 
 * por ela mesma.
 * @param pilha Apontador para a pilha a ser destruida.
 */
void pilhaLE_destroi(pilhaLE_t * pilha) {

  itemPilhaLE_t * atual, * proximo;

  // Come�a pelo topo da pilha
  atual = (itemPilhaLE_t *)pilha->topo;

  // Percorre todos os elementos da pilha dando free em cada um deles
  while (atual != NULL) {
    proximo = atual->proximo;
    free(atual);
    atual = proximo;
  }

  // Libera o espa�o da pilha
  free(pilha);
}

/**
 * Fun��o que insere um item no topo na pilha.
 * @param pilha Apontador para a pilha a ser utilizada.
 * @param info Informa��o a ser inserida na pilha.
 * @return SUCESSO caso o item seja inserido corretamente na pilha, ou caso
 * contr�rio, o c�digo do erro.
 */
erro_t pilhaLE_empilha(pilhaLE_t * pilha, dadosItem info) {

  itemPilhaLE_t * novoItem;

  // Cria um novo elemento e inicializa o item
  novoItem = (itemPilhaLE_t *)malloc(sizeof(itemPilhaLE_t));
  novoItem->info = info;
  novoItem->proximo = (itemPilhaLE_t *)pilha->topo;

  // Fa�o a liga��o
  pilha->topo = novoItem;

  // Se chegou at� aqui � porque o novo item foi inserido com sucesso na pilha
  pilha->nItens++;
  return SUCESSO;
}

/**
 * Fun��o que remove o item no topo da pilha.
 * @param pilha Apontador para a pilha a ser utilizada.
 * @param info Apontador para o local que receber� o valor do item removido.
 * @return SUCESSO caso o item seja inserido removido na pilha, ou caso
 * contr�rio, o c�digo do erro.
 */
erro_t pilhaLE_desempilha(pilhaLE_t * pilha, dadosItem * info) {

  itemPilhaLE_t * anterior = NULL;
  itemPilhaLE_t * elementoARemover = (itemPilhaLE_t *)pilha->topo;

  // Verifica se a pilha est� vazia
  if (elementoARemover == NULL) return ERRO_PILHA_VAZIA;

  // Copia os dados do item antes de remov�-lo
  (void)memcpy(info, &elementoARemover->info, sizeof(dadosItem));

  // Faz o pr�ximo item ser o novo top
  pilha->topo = elementoARemover->proximo;

  // Se chegou at� aqui � porque o item foi removido corretamente da pilha
  free(elementoARemover);
  pilha->nItens--;
  return SUCESSO;
}

/**
 * Fun��o que obtem o valor no topo da pilha.
 * @param pilha Apontador para a pilha a ser utilizada.
 * @param info Apontador para o local que receber� o valor buscado.
 * @return SUCESSO caso o item seja obtido da pilha, ou caso
 * contr�rio, o c�digo do erro.
 */
erro_t pilhaLE_topo(pilhaLE_t * pilha, dadosItem * topo) {

  // Se a pilha est� vazia, n�o h� topo
  if (pilha->topo == NULL) return ERRO_PILHA_VAZIA;

  // Copia o valor que est� no topo da pilha para o local especificado
  (void)memcpy(topo, pilha->topo, sizeof(dadosItem));

  // Se chegou at� aqui � porque deu tudo certo
  return SUCESSO;
}

/**
 * Fun��o que busca por um item na pilha.
 * Observa��o: O primeiro item encontrado com a informa��o desejada � retornado.
 * @param pilha Apontador para a pilha a ser utilizada.
 * @param info Informa��o a ser procurada na pilha.
 * @param posicao Endere�o do local que receber� a posi��o do item encontrado.
 * @return SUCESSO caso o item desejado seja encontrado, ou caso contr�rio,
 * o c�digo do erro ocorrido.
 */
bool_t pilhaLE_busca(pilhaLE_t * pilha, dadosItem info, uint32_t * posicao) {

  uint32_t pos = 0;
  itemPilhaLE_t * proximo = (itemPilhaLE_t *)pilha->topo;

  // Percore os elementos da pilha procurando aquele cuja informa��o � a desejada
  while (proximo != NULL) {
    if (proximo->info == info) break;
    proximo = proximo->proximo;
    pos++;
  }

  // O elemento que est� no pr�ximo � o item encontrado.
  // Caso a pilha tenha chegado no final e nenhum item foi encontrado, ent�o
  // o pr�ximo � NULL
  // Caso a pilha esteja vazia, ent�o o pr�ximo � NULL desde o in�cio.
  if (proximo == NULL) return ERRO_PILHA_ITEM_NAO_ENCONTRADO;
  
  // Se chegou at� aqui � porque o item foi encontrado e sua posi��o est� em pos
  *posicao = pos;
  return SUCESSO;
}

/**
 * Fun��o que verifica se a pilha est� vazia.
 * @param pilha Apontador para a pilha a ser utilizada.
 * @return VERDADEIRO caso a pilha esteja vazia, ou FALSO caso contr�rio.
 */
bool_t pilhaLE_estaVazia(pilhaLE_t * pilha) {
  return pilha->nItens == 0;
}

/**
 * Fun��o que imprime todos os itens da pilha.
 * @param pilha Apontador para a pilha a ser utilizada.
 */
void pilhaLE_imprime(pilhaLE_t * pilha) {

  uint32_t i;
  itemPilhaLE_t * atual;
  itemPilhaLE_t * proximo = pilha->topo;

  printf("pilha com %u item(s)\n", pilha->nItens);
  printf("Impressao da pilha\n"\
         "------------------\n");

  // Imprime posi��o e o valor de cada item da pilha
  for (i = 0; i < pilha->nItens; i++) {

    // Controla os links da pilha
    atual = proximo;
    proximo = atual->proximo;

    printf("Pos: %u / Valor: %i\n", i, atual->info);
  }

  printf("------------------\n");
}