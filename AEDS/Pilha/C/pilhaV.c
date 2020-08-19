/**
 * @file   pilhaV.c
 * @brief  Arquivo com a implementação do TAD Pilha utilizando Vetor.
 * @author Leandro Maia Silva
 * @date   2020-08-18
 */

/* Inclusões */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "tipos.h"
#include "erros.h"
#include "pilha.h"
#include "pilhaV.h"

/* Tipos */


/* Funções auxiliares */

/**
 * Função que inicializa a pilha com os valores adequados.
 * @param pilha Apontador para a pilha a ser utilizada.
 */
static void pilhaV_inicializa(pilhaV_t * pilha, uint32_t capacidade) {
  pilha->nItens = 0;
  pilha->capacidade = capacidade;
  pilha->itens = malloc(capacidade * sizeof(dadosItem));
}

/* Funções exportadas */

/**
 * Função que cria e inicializa uma pilha.
 * @param capacidade Capacidade máxima que a pilha terá.
 * @return Apontador para o local onde a pilha criada foi armazenada.
 */
pilhaV_t * pilhaV_cria(uint32_t capacidade) {

  // Reserva espaço na memória para a pilha
  pilhaV_t * pilha = (pilhaV_t *)malloc(sizeof(pilhaV_t));

  // Inicializa a mesma
  pilhaV_inicializa(pilha, capacidade);

  // Retorna o endereço da pilha criada e inicializada
  return pilha;
}

/**
 * Função que destroi a pilha liberando o espaço utilizado por seus itens e 
 * por ela mesma.
 * @param pilha Apontador para a pilha a ser destruida.
 */
void pilhaV_destroi(pilhaV_t * pilha) {

  // Destroi o espaço dos itens
  free(pilha->itens);

  // Libera o espaço da pilha
  free(pilha);
}

/**
 * Função que insere um item no topo na pilha.
 * @param pilha Apontador para a pilha a ser utilizada.
 * @param info Informação a ser inserida na pilha.
 * @return SUCESSO caso o item seja inserido corretamente na pilha, ou caso
 * contrário, o código do erro.
 */
erro_t pilhaV_empilha(pilhaV_t * pilha, dadosItem info) {

  dadosItem * itensPilha = (dadosItem *)pilha->itens;

  // Verifica se há espaço na pilha para armazenar o item
  if (pilha->nItens >= pilha->capacidade) return ERRO_PILHA_CHEIA;

  // Insere o novo item na pilha
  itensPilha[pilha->nItens++] = info;

  // Se chegou até aqui é porque o novo item foi inserido com sucesso na pilha
  return SUCESSO;
}

/**
 * Função que remove o item no topo da pilha.
 * @param pilha Apontador para a pilha a ser utilizada.
 * @param info Apontador para o local que receberá o valor do item removido.
 * @return SUCESSO caso o item seja inserido removido na pilha, ou caso
 * contrário, o código do erro.
 */
erro_t pilhaV_desempilha(pilhaV_t * pilha, dadosItem * info) {

  dadosItem * itensPilha = (dadosItem *)pilha->itens;

  // Verifica se a pilha não está vazia
  if (pilha->nItens == 0) return ERRO_PILHA_VAZIA;

  // Copia os dados e remove o item da pilha
  (void)memcpy(info, &itensPilha[--pilha->nItens], sizeof(dadosItem));

  // Se chegou até aqui é porque o item foi removido corretamente da pilha
  return SUCESSO;
}

/**
 * Função que obtem o valor no topo da pilha.
 * @param pilha Apontador para a pilha a ser utilizada.
 * @param info Apontador para o local que receberá o valor buscado.
 * @return SUCESSO caso o item seja obtido da pilha, ou caso
 * contrário, o código do erro.
 */
erro_t pilhaV_topo(pilhaV_t * pilha, dadosItem * topo) {

  dadosItem * itensPilha = (dadosItem *)pilha->itens;

  // Se a pilha está vazia, não há topo
  if (pilha->nItens == 0) return ERRO_PILHA_VAZIA;

  // Copia o valor que está no topo da pilha para o local especificado
  (void)memcpy(topo, &itensPilha[pilha->nItens - 1], sizeof(dadosItem));

  // Se chegou até aqui é porque deu tudo certo
  return SUCESSO;
}

/**
 * Função que busca por um item na pilha.
 * Observação: O primeiro item encontrado com a informação desejada é retornado.
 * @param pilha Apontador para a pilha a ser utilizada.
 * @param info Informação a ser procurada na pilha.
 * @param posicao Endereço do local que receberá a posição do item encontrado.
 * @return SUCESSO caso o item desejado seja encontrado, ou caso contrário,
 * o código do erro ocorrido.
 */
bool_t pilhaV_busca(pilhaV_t * pilha, dadosItem info, uint32_t * posicao) {

  uint32_t pos;
  dadosItem * itensPilha = (dadosItem *)pilha->itens;

  // Percore os elementos da pilha procurando aquele cuja informação é a desejada
  for (pos = pilha->nItens -1; pos < pilha->nItens; pos--) {
    if (itensPilha[pos] == info) break;
  }

  // Se a posição é maior que o número de itens, então não encontrou
  if (pos >= pilha->nItens) return ERRO_PILHA_ITEM_NAO_ENCONTRADO;

  // Se chegou até aqui é porque o item foi encontrado e sua posição está em pos
  *posicao = pilha->nItens - pos - 1;
  return SUCESSO;
}

/**
 * Função que verifica se a pilha está vazia.
 * @param pilha Apontador para a pilha a ser utilizada.
 * @return VERDADEIRO caso a pilha esteja vazia, ou FALSO caso contrário.
 */
bool_t pilhaV_estaVazia(pilhaV_t * pilha) {
  return pilha->nItens == 0;
}

/**
 * Função que imprime todos os itens da pilha.
 * @param pilha Apontador para a pilha a ser utilizada.
 */
void pilhaV_imprime(pilhaV_t * pilha) {

  uint32_t pos;
  dadosItem * itensPilha = (dadosItem *)pilha->itens;

  printf("pilha com %u item(s)\n", pilha->nItens);
  printf("Impressao da pilha\n"\
         "------------------\n");

  // Imprime posição e o valor de cada item da pilha
  for (pos = pilha->nItens - 1; pos < pilha->nItens; pos--) {
    printf("Pos: %u / Valor: %i\n", pilha->nItens - pos - 1, itensPilha[pos]);
  }

  printf("------------------\n");
}