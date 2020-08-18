/**
 * @file   listaED.c
 * @brief  Arquivo com a implementação do TAD Lista Duplamente Encadeada.
 * @author Leandro Maia Silva
 * @date   2020-08-17
 */

/* Inclusões */
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

/* Funções auxiliares */

/**
 * Função que inicializa a lista com os valores adequados.
 * @param lista Apontador para a lista a ser utilizada.
 */
static void listaED_inicializa(listaED_t * lista) {
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
static erro_t listaED_obtemElementoPosicao(listaED_t * lista, uint32_t posicao, itemListaED_t ** item) {

  itemListaED_t * atual;

  // Verifica se a lista possui elementos suficientes
  if (posicao > lista->nItens) return ERRO_LISTA_POSICAO_INVALIDA;

  // Começa a percorrer a lista a partir do primeiro elemento
  atual = (itemListaED_t *)lista->primeiro;


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
listaED_t * listaED_cria(void) {

  // Reserva espaço na memória para a lista
  listaED_t * lista = (listaED_t *)malloc(sizeof(listaED_t));

  // Inicializa a mesma
  listaED_inicializa(lista);

  // Retorna o endereço da lista criada e inicializada
  return lista;
}

/**
 * Função que destroi a lista liberando o espaço utilizado por seus itens e 
 * por ela mesma.
 * @param lista Apontador para a lista a ser destruida.
 */
void listaED_destroi(listaED_t * lista) {

  itemListaED_t * atual, * proximo;

  // Começa pelo primeiro elemento da lista
  atual = (itemListaED_t *)lista->primeiro;

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
erro_t listaED_insereInicio(listaED_t * lista, dadosItem info) {
  return listaED_insereNesimaPosicao(lista, info, 0);
}

/**
 * Função que insere um item no fim da lista.
 * @param lista Apontador para a lista a ser utilizada.
 * @param info Informação a ser inserida na lista.
 * @return SUCESSO caso o item seja inserido corretamente na lista, ou caso
 * contrário, o código do erro.
 */
erro_t listaED_insereFinal(listaED_t * lista, dadosItem info) {
  return listaED_insereNesimaPosicao(lista, info, lista->nItens);
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
erro_t listaED_insereNesimaPosicao(listaED_t * lista, dadosItem info, uint32_t posicao) {

  erro_t erro;
  itemListaED_t * novoItem, * anterior;

  // Verifico se a posição faz sentido com o número atual de itens na lista
  if (posicao > lista->nItens) return ERRO_LISTA_POSICAO_INVALIDA;

  // Cria um novo elemento e inicializa o item
  novoItem = (itemListaED_t *)malloc(sizeof(itemListaED_t));
  novoItem->info = info;
  novoItem->proximo = NULL;
  novoItem->anterior = NULL;

  // Se for a posição ZERO, então o novo item será o novo primeiro item
  if (posicao == 0) {
    novoItem->proximo = (itemListaED_t *)lista->primeiro;

    // Se o antigo primeiro não era nulo, então ele precisa apontar para o novo item
    if (novoItem->proximo != NULL) {
      novoItem->proximo->anterior = novoItem;
    }

    // Torna o novo item o primeiro da lista
    lista->primeiro = novoItem;
  }
  // .. senão, então eu busco o item da posição N-1 para ligar o novo item.
  else {

    // Busco o item anterior para fazer a ligação
    erro = listaED_obtemElementoPosicao(lista, posicao - 1, &anterior);
    if (erro != SUCESSO) return erro;

    // Faço a ligação
    novoItem->proximo = anterior->proximo;
    anterior->proximo = novoItem;
    novoItem->anterior = anterior;

    // Se existia um item depois da posição onde estou colocando o novoItem, então
    // preciso fazê-lo apontar para o novoItem.
    if (novoItem->proximo != NULL) {
      novoItem->proximo->anterior = novoItem;
    }
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
erro_t listaED_removeElemento(listaED_t * lista, dadosItem info) {

  itemListaED_t * elementoARemover = (itemListaED_t *)lista->primeiro;

  // Percore os elementos da lista procurando aquele cuja informação é a desejada
  while (elementoARemover != NULL) {
    if (elementoARemover->info == info) break;
    elementoARemover = elementoARemover->proximo;
  }

  // Verifica se o item foi encontrado, ou seja, se o elementoARemover não é nulo
  if (elementoARemover == NULL) { return ERRO_LISTA_ITEM_NAO_ENCONTRADO; }

  // Se o próximo existe, então ele aponta para o anterior
  if (elementoARemover->proximo != NULL) {
    elementoARemover->proximo->anterior = elementoARemover->anterior;
  }

  // Se o anterior existe, então ele aponta para o próximo
  if (elementoARemover->anterior != NULL) {
    elementoARemover->anterior->proximo = elementoARemover->proximo;
  }
  // ... se não existe, então estou removendo o primeiro da listatenho, então sou o primeiro da lista
  else {

    // O novo início é próximo do item a ser removido removido
    lista->primeiro = elementoARemover->proximo;
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
erro_t listaED_removePosicao(listaED_t * lista, uint32_t posicao) {

  erro_t erro;
  itemListaED_t * elementoARemover;

  // Verifico se a posição faz sentido com o número atual de itens na lista
  if (posicao >= lista->nItens) return ERRO_LISTA_POSICAO_INVALIDA;

  // Aqui, garantidamente, eu tenho pelo menos um elemento na lista

  // Busco o item a ser removido
  erro = listaED_obtemElementoPosicao(lista, posicao, &elementoARemover);
  if (erro != SUCESSO) return erro;

  // Se eu tenho um anterior, então faço ele apontar para o próximo
  if (elementoARemover->anterior != NULL) {
    elementoARemover->anterior->proximo = elementoARemover->proximo;
  }

  // Se eu tenho um próximo, então faço ele apontar para o anterior
  if (elementoARemover->proximo != NULL) {
    elementoARemover->proximo->anterior = elementoARemover->anterior;
  }

  // Se eu removi o primeiro item da lista, então o próximo é o novo primeiro
  if (posicao == 0) {
    lista->primeiro = elementoARemover->proximo;
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
bool_t listaED_busca(listaED_t * lista, dadosItem info, uint32_t * posicao) {

  uint32_t pos = 0;
  itemListaED_t * proximo = (itemListaED_t *)lista->primeiro;

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
  if (proximo == NULL) return ERRO_LISTA_ITEM_NAO_ENCONTRADO;
  
  // Se chegou até aqui é porque o item foi encontrado e sua posição está em pos
  *posicao = pos;
  return SUCESSO;
}

/**
 * Função que verifica se a lista está vazia.
 * @param lista Apontador para a lista a ser utilizada.
 * @return VERDADEIRO caso a lista esteja vazia, ou FALSO caso contrário.
 */
bool_t listaED_estaVazia(listaED_t * lista) {
  return lista->nItens == 0;
}

/**
 * Função que imprime todos os itens da lista.
 * @param lista Apontador para a lista a ser utilizada.
 */
void listaED_imprime(listaED_t * lista) {

  uint32_t i;
  itemListaED_t * atual;
  itemListaED_t * proximo = lista->primeiro;

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