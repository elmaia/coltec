/**
 * @file   pilhaV.c
 * @brief  Arquivo com a implementa��o do TAD Pilha utilizando Vetor.
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
#include "pilhaV.h"

/* Tipos */


/* Fun��es auxiliares */

/**
 * Fun��o que inicializa a pilha com os valores adequados.
 * @param pilha Apontador para a pilha a ser utilizada.
 */
static void pilhaV_inicializa(pilhaV_t * pilha, uint32_t capacidade) {
  pilha->nItens = 0;
  pilha->capacidade = capacidade;
  pilha->itens = malloc(capacidade * sizeof(dadosItem));
}

/* Fun��es exportadas */

/**
 * Fun��o que cria e inicializa uma pilha.
 * @param capacidade Capacidade m�xima que a pilha ter�.
 * @return Apontador para o local onde a pilha criada foi armazenada.
 */
pilhaV_t * pilhaV_cria(uint32_t capacidade) {

  // Reserva espa�o na mem�ria para a pilha
  pilhaV_t * pilha = (pilhaV_t *)malloc(sizeof(pilhaV_t));

  // Inicializa a mesma
  pilhaV_inicializa(pilha, capacidade);

  // Retorna o endere�o da pilha criada e inicializada
  return pilha;
}

/**
 * Fun��o que destroi a pilha liberando o espa�o utilizado por seus itens e 
 * por ela mesma.
 * @param pilha Apontador para a pilha a ser destruida.
 */
void pilhaV_destroi(pilhaV_t * pilha) {

  // Destroi o espa�o dos itens
  free(pilha->itens);

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
erro_t pilhaV_empilha(pilhaV_t * pilha, dadosItem info) {

  dadosItem * itensPilha = (dadosItem *)pilha->itens;

  // Verifica se h� espa�o na pilha para armazenar o item
  if (pilha->nItens >= pilha->capacidade) return ERRO_PILHA_CHEIA;

  // Insere o novo item na pilha
  itensPilha[pilha->nItens++] = info;

  // Se chegou at� aqui � porque o novo item foi inserido com sucesso na pilha
  return SUCESSO;
}

/**
 * Fun��o que remove o item no topo da pilha.
 * @param pilha Apontador para a pilha a ser utilizada.
 * @param info Apontador para o local que receber� o valor do item removido.
 * @return SUCESSO caso o item seja inserido removido na pilha, ou caso
 * contr�rio, o c�digo do erro.
 */
erro_t pilhaV_desempilha(pilhaV_t * pilha, dadosItem * info) {

  dadosItem * itensPilha = (dadosItem *)pilha->itens;

  // Verifica se a pilha n�o est� vazia
  if (pilha->nItens == 0) return ERRO_PILHA_VAZIA;

  // Copia os dados e remove o item da pilha
  (void)memcpy(info, &itensPilha[--pilha->nItens], sizeof(dadosItem));

  // Se chegou at� aqui � porque o item foi removido corretamente da pilha
  return SUCESSO;
}

/**
 * Fun��o que obtem o valor no topo da pilha.
 * @param pilha Apontador para a pilha a ser utilizada.
 * @param info Apontador para o local que receber� o valor buscado.
 * @return SUCESSO caso o item seja obtido da pilha, ou caso
 * contr�rio, o c�digo do erro.
 */
erro_t pilhaV_topo(pilhaV_t * pilha, dadosItem * topo) {

  dadosItem * itensPilha = (dadosItem *)pilha->itens;

  // Se a pilha est� vazia, n�o h� topo
  if (pilha->nItens == 0) return ERRO_PILHA_VAZIA;

  // Copia o valor que est� no topo da pilha para o local especificado
  (void)memcpy(topo, &itensPilha[pilha->nItens - 1], sizeof(dadosItem));

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
bool_t pilhaV_busca(pilhaV_t * pilha, dadosItem info, uint32_t * posicao) {

  uint32_t pos;
  dadosItem * itensPilha = (dadosItem *)pilha->itens;

  // Percore os elementos da pilha procurando aquele cuja informa��o � a desejada
  for (pos = pilha->nItens -1; pos < pilha->nItens; pos--) {
    if (itensPilha[pos] == info) break;
  }

  // Se a posi��o � maior que o n�mero de itens, ent�o n�o encontrou
  if (pos >= pilha->nItens) return ERRO_PILHA_ITEM_NAO_ENCONTRADO;

  // Se chegou at� aqui � porque o item foi encontrado e sua posi��o est� em pos
  *posicao = pilha->nItens - pos - 1;
  return SUCESSO;
}

/**
 * Fun��o que verifica se a pilha est� vazia.
 * @param pilha Apontador para a pilha a ser utilizada.
 * @return VERDADEIRO caso a pilha esteja vazia, ou FALSO caso contr�rio.
 */
bool_t pilhaV_estaVazia(pilhaV_t * pilha) {
  return pilha->nItens == 0;
}

/**
 * Fun��o que imprime todos os itens da pilha.
 * @param pilha Apontador para a pilha a ser utilizada.
 */
void pilhaV_imprime(pilhaV_t * pilha) {

  uint32_t pos;
  dadosItem * itensPilha = (dadosItem *)pilha->itens;

  printf("pilha com %u item(s)\n", pilha->nItens);
  printf("Impressao da pilha\n"\
         "------------------\n");

  // Imprime posi��o e o valor de cada item da pilha
  for (pos = pilha->nItens - 1; pos < pilha->nItens; pos--) {
    printf("Pos: %u / Valor: %i\n", pilha->nItens - pos - 1, itensPilha[pos]);
  }

  printf("------------------\n");
}