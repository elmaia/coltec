/**
 * @file   main.c
 * @brief  Arquivo com a implementa��o das fun��es de inicializa��o do programa.
 * @author Leandro Maia Silva
 * @date   2020-08-24
 */
 
/* Inclus�es */
#include <stdio.h>
#include "erros.h"
 
/**
 * Fun��o onde o programa � inicializado.
 * @param argc N�mero de argumentos passados para o programa pela linha
 * de comando.
 * @param argv Valores dos argumentos.
 * @return SUCESSO caso o programa termine conforme esperado, ou caso
 * contr�rio, o c�digo do erro ocorrido.
 */
 int main(int argc, char ** argv) {
   
   (void)printf("Tudo OK.\n");
   
   // Se chegou at� aqui � porque correu tudo bem
   return SUCESSO;
 }