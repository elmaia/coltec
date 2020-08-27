/**
 * @file   main.c
 * @brief  Arquivo com a implementação das funções de inicialização do programa.
 * @author Leandro Maia Silva
 * @date   2020-08-24
 */
 
/* Inclusões */
#include <stdio.h>
#include "erros.h"
 
/**
 * Função onde o programa é inicializado.
 * @param argc Número de argumentos passados para o programa pela linha
 * de comando.
 * @param argv Valores dos argumentos.
 * @return SUCESSO caso o programa termine conforme esperado, ou caso
 * contrário, o código do erro ocorrido.
 */
 int main(int argc, char ** argv) {
   
   (void)printf("Tudo OK.\n");
   
   // Se chegou até aqui é porque correu tudo bem
   return SUCESSO;
 }