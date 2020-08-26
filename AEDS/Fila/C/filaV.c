/**
 * @file   filaV.c
 * @brief  Arquivo com a implementa��o do TAD Fila utilizando Vetor.
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
#include "filaV.h"

/* Tipos */


/* Fun��es auxiliares */

/**
 * Fun��o que inicializa a fila com os valores adequados.
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
 * Fun��o que retorna a pr�xima posi��o.
 * @param fila Apontador para a fila a ser utilizada.
 * @param posicao �ndice da posi��o atual.
 * @return �ndice da pr�xima posi��o.
 */
static inline uint32_t filaV_proximo(filaV_t * fila, uint32_t posicao) {
  return (posicao + 1) % fila->capacidade;
}


/**
 * Fun��o que retorna a posi��o anterior.
 * @param fila Apontador para a fila a ser utilizada.
 * @param posicao �ndice da posi��o atual.
 * @return �ndice da posi��o anterior.
 */
static inline uint32_t filaV_anterior(filaV_t * fila, uint32_t posicao) {
  return (posicao == 0 ? fila->capacidade - 1 : posicao - 1);
}

/**
 * Fun��o que retorna o �ndice da posi��o absoluta com rela��o a posi��o relativa
 * e o in�cio da fila.
 * @param fila Apontador para a fila a ser utilizada.
 * @param indice Valor do �ndice a ter a posi��o absoluta calculada.
 * @return Posi��o absoluta.
 */
static inline uint32_t filaV_posicaoAbsoluta(filaV_t * fila, uint32_t indice) {
  return (fila->primeiro + indice) % fila->capacidade;
}

/* Fun��es exportadas */

/**
 * Fun��o que cria e inicializa uma fila.
 * @param capacidade Capacidade m�xima que a fila ter�.
 * @return Apontador para o local onde a fila criada foi armazenada.
 */
filaV_t * filaV_cria(uint32_t capacidade) {

  // Reserva espa�o na mem�ria para a fila
  filaV_t * fila = (filaV_t *)malloc(sizeof(filaV_t));

  // Inicializa a mesma
  filaV_inicializa(fila, capacidade);

  // Retorna o endere�o da fila criada e inicializada
  return fila;
}

/**
 * Fun��o que destroi a fila liberando o espa�o utilizado por seus itens e 
 * por ela mesma.
 * @param fila Apontador para a fila a ser destruida.
 */
void filaV_destroi(filaV_t * fila) {

  // Destroi o espa�o dos itens
  free(fila->itens);

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
erro_t filaV_insere(filaV_t * fila, dadosItem info) {

  dadosItem * itensfila = (dadosItem *)fila->itens;

  // Verifica se h� espa�o na fila para armazenar o item
  if (fila->nItens >= fila->capacidade) return ERRO_FILA_CHEIA;

  // Insere o novo item na fila
  itensfila[fila->ultimo] = info;

  // Incrementa a posi��o do �ltimo e o n�mero de itens
  fila->ultimo = filaV_proximo(fila, fila->ultimo);
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
erro_t filaV_remove(filaV_t * fila, dadosItem * info) {

  dadosItem * itensfila = (dadosItem *)fila->itens;

  // Verifica se a fila n�o est� vazia
  if (fila->nItens == 0) return ERRO_FILA_VAZIA;

  // Copia os dados, remove o item da fila e decrementa o n�mero de itens
  (void)memcpy(info, &itensfila[fila->primeiro], sizeof(dadosItem));
  fila->primeiro = filaV_proximo(fila, fila->primeiro);
  fila->nItens--;

  // Se chegou at� aqui � porque o item foi removido corretamente da fila
  return SUCESSO;
}

/**
 * Fun��o que obtem o valor no in�cio da fila.
 * @param fila Apontador para a fila a ser utilizada.
 * @param info Apontador para o local que receber� o valor buscado.
 * @return SUCESSO caso o item seja obtido da fila, ou caso
 * contr�rio, o c�digo do erro.
 */
erro_t filaV_primeiro(filaV_t * fila, dadosItem * primeiro) {

  dadosItem * itensfila = (dadosItem *)fila->itens;

  // Se a fila est� vazia, n�o h� primeiro
  if (fila->nItens == 0) return ERRO_FILA_VAZIA;

  // Copia o valor que est� no in�cio da fila para o local especificado
  (void)memcpy(primeiro, &itensfila[fila->primeiro], sizeof(dadosItem));

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
bool_t filaV_busca(filaV_t * fila, dadosItem info, uint32_t * posicao) {

  uint32_t pos;
  dadosItem * itensfila = (dadosItem *)fila->itens;

  // Percore os elementos da fila procurando aquele cuja informa��o � a desejada
  for (pos = 0; pos < fila->nItens; pos++) {
    if (itensfila[filaV_posicaoAbsoluta(fila, pos)] == info) break;
  }

  // Se a posi��o � maior que o n�mero de itens, ent�o n�o encontrou
  if (pos >= fila->nItens) return ERRO_FILA_ITEM_NAO_ENCONTRADO;

  // Se chegou at� aqui � porque o item foi encontrado e sua posi��o est� em pos
  *posicao = filaV_posicaoAbsoluta(fila, pos);
  return SUCESSO;
}

/**
 * Fun��o que verifica se a fila est� vazia.
 * @param fila Apontador para a fila a ser utilizada.
 * @return VERDADEIRO caso a fila esteja vazia, ou FALSO caso contr�rio.
 */
bool_t filaV_estaVazia(filaV_t * fila) {
  return fila->nItens == 0;
}

/**
 * Fun��o que imprime todos os itens da fila.
 * @param fila Apontador para a fila a ser utilizada.
 */
void filaV_imprime(filaV_t * fila) {

  uint32_t pos;
  dadosItem * itensfila = (dadosItem *)fila->itens;

  printf("fila com %u item(s)\n", fila->nItens);
  printf("Impressao da fila\n"\
         "------------------\n");

  // Imprime posi��o e o valor de cada item da fila
  for (pos = 0; pos < fila->nItens; pos++) {
    printf("Pos: %u / Valor: %i\n", pos, itensfila[filaV_posicaoAbsoluta(fila, pos)]);
  }

  printf("------------------\n");
}