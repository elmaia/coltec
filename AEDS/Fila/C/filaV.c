/**
 * @file   filaV.c
 * @brief  Arquivo com a implementação do TAD Fila utilizando Vetor.
 * @author Leandro Maia Silva
 * @date   2020-08-25
 */

/* Inclusões */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "tipos.h"
#include "erros.h"
#include "fila.h"
#include "filaV.h"

/* Tipos */


/* Funções auxiliares */

/**
 * Função que inicializa a fila com os valores adequados.
 * @param fila Apontador para a fila a ser utilizada.
 */
static void filaV_inicializa(filaV_t * fila, uint32_t capacidade) {
  fila->nItens = 0;
  fila->primeiro = 0;
  fila->ultimo = 0;
  fila->capacidade = capacidade;
  fila->itens = malloc(capacidade * sizeof(dadosItem));
}

/**
 * Função que retorna a próxima posição.
 * @param fila Apontador para a fila a ser utilizada.
 * @param posicao Índice da posição atual.
 * @return Índice da próxima posição.
 */
static inline uint32_t filaV_proximo(filaV_t * fila, uint32_t posicao) {
  return (posicao + 1) % fila->capacidade;
}


/**
 * Função que retorna a posição anterior.
 * @param fila Apontador para a fila a ser utilizada.
 * @param posicao Índice da posição atual.
 * @return Índice da posição anterior.
 */
static inline uint32_t filaV_anterior(filaV_t * fila, uint32_t posicao) {
  return (posicao == 0 ? fila->capacidade - 1 : posicao - 1);
}

/**
 * Função que retorna o índice da posição absoluta com relação a posição relativa
 * e o início da fila.
 * @param fila Apontador para a fila a ser utilizada.
 * @param indice Valor do Índice a ter a posição absoluta calculada.
 * @return Posição absoluta.
 */
static inline uint32_t filaV_posicaoAbsoluta(filaV_t * fila, uint32_t indice) {
  return (fila->primeiro + indice) % fila->capacidade;
}

/* Funções exportadas */

/**
 * Função que cria e inicializa uma fila.
 * @param capacidade Capacidade máxima que a fila terá.
 * @return Apontador para o local onde a fila criada foi armazenada.
 */
filaV_t * filaV_cria(uint32_t capacidade) {

  // Reserva espaço na memória para a fila
  filaV_t * fila = (filaV_t *)malloc(sizeof(filaV_t));

  // Inicializa a mesma
  filaV_inicializa(fila, capacidade);

  // Retorna o endereço da fila criada e inicializada
  return fila;
}

/**
 * Função que destroi a fila liberando o espaço utilizado por seus itens e 
 * por ela mesma.
 * @param fila Apontador para a fila a ser destruida.
 */
void filaV_destroi(filaV_t * fila) {

  // Destroi o espaço dos itens
  free(fila->itens);

  // Libera o espaço da fila
  free(fila);
}

/**
 * Função que insere um item no final da fila.
 * @param fila Apontador para a fila a ser utilizada.
 * @param info Informação a ser inserida na fila.
 * @return SUCESSO caso o item seja inserido corretamente na fila, ou caso
 * contrário, o código do erro.
 */
erro_t filaV_insere(filaV_t * fila, dadosItem info) {

  dadosItem * itensfila = (dadosItem *)fila->itens;

  // Verifica se há espaço na fila para armazenar o item
  if (fila->nItens >= fila->capacidade) return ERRO_FILA_CHEIA;

  // Insere o novo item na fila
  itensfila[fila->ultimo] = info;

  // Incrementa a posição do último e o número de itens
  fila->ultimo = filaV_proximo(fila, fila->ultimo);
  fila->nItens++;

  // Se chegou até aqui é porque o novo item foi inserido com sucesso na fila
  return SUCESSO;
}

/**
 * Função que remove o item do início da fila.
 * @param fila Apontador para a fila a ser utilizada.
 * @param info Apontador para o local que receberá o valor do item removido.
 * @return SUCESSO caso o item seja inserido removido na fila, ou caso
 * contrário, o código do erro.
 */
erro_t filaV_remove(filaV_t * fila, dadosItem * info) {

  dadosItem * itensfila = (dadosItem *)fila->itens;

  // Verifica se a fila não está vazia
  if (fila->nItens == 0) return ERRO_FILA_VAZIA;

  // Copia os dados, remove o item da fila e decrementa o número de itens
  (void)memcpy(info, &itensfila[fila->primeiro], sizeof(dadosItem));
  fila->primeiro = filaV_proximo(fila, fila->primeiro);
  fila->nItens--;

  // Se chegou até aqui é porque o item foi removido corretamente da fila
  return SUCESSO;
}

/**
 * Função que obtem o valor no início da fila.
 * @param fila Apontador para a fila a ser utilizada.
 * @param info Apontador para o local que receberá o valor buscado.
 * @return SUCESSO caso o item seja obtido da fila, ou caso
 * contrário, o código do erro.
 */
erro_t filaV_primeiro(filaV_t * fila, dadosItem * primeiro) {

  dadosItem * itensfila = (dadosItem *)fila->itens;

  // Se a fila está vazia, não há primeiro
  if (fila->nItens == 0) return ERRO_FILA_VAZIA;

  // Copia o valor que está no início da fila para o local especificado
  (void)memcpy(primeiro, &itensfila[fila->primeiro], sizeof(dadosItem));

  // Se chegou até aqui é porque deu tudo certo
  return SUCESSO;
}

/**
 * Função que busca por um item na fila.
 * Observação: O primeiro item encontrado com a informação desejada é retornado.
 * @param fila Apontador para a fila a ser utilizada.
 * @param info Informação a ser procurada na fila.
 * @param posicao Endereço do local que receberá a posição do item encontrado.
 * @return SUCESSO caso o item desejado seja encontrado, ou caso contrário,
 * o código do erro ocorrido.
 */
bool_t filaV_busca(filaV_t * fila, dadosItem info, uint32_t * posicao) {

  uint32_t pos;
  dadosItem * itensfila = (dadosItem *)fila->itens;

  // Percore os elementos da fila procurando aquele cuja informação é a desejada
  for (pos = 0; pos < fila->nItens; pos++) {
    if (itensfila[filaV_posicaoAbsoluta(fila, pos)] == info) break;
  }

  // Se a posição é maior que o número de itens, então não encontrou
  if (pos >= fila->nItens) return ERRO_FILA_ITEM_NAO_ENCONTRADO;

  // Se chegou até aqui é porque o item foi encontrado e sua posição está em pos
  *posicao = filaV_posicaoAbsoluta(fila, pos);
  return SUCESSO;
}

/**
 * Função que verifica se a fila está vazia.
 * @param fila Apontador para a fila a ser utilizada.
 * @return VERDADEIRO caso a fila esteja vazia, ou FALSO caso contrário.
 */
bool_t filaV_estaVazia(filaV_t * fila) {
  return fila->nItens == 0;
}

/**
 * Função que imprime todos os itens da fila.
 * @param fila Apontador para a fila a ser utilizada.
 */
void filaV_imprime(filaV_t * fila) {

  uint32_t pos;
  dadosItem * itensfila = (dadosItem *)fila->itens;

  printf("fila com %u item(s)\n", fila->nItens);
  printf("Impressao da fila\n"\
         "------------------\n");

  // Imprime posição e o valor de cada item da fila
  for (pos = 0; pos < fila->nItens; pos++) {
    printf("Pos: %u / Valor: %i\n", pos, itensfila[filaV_posicaoAbsoluta(fila, pos)]);
  }

  printf("------------------\n");
}