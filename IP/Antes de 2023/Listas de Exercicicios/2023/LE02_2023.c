/**
 * @file   LE02_2023.c
 * @brief  Arquivo com a implementação de sugestão de solução da LE02.
 * @author Leandro Maia Silva
 * @date   2023-03-25
 */

/* Inclusões */
#include <stdio.h>   // printf e scanf
#include <stdbool.h> // bool
#include <math.h>    // pow

/* Constantes */

// Constante que associa o código de erro 0 ao significado de sucesso
#define SUCESSO  0

/**
 * Faça o fluxograma e um programa que leia dois números
 * inteiros e determine qual deles é o maior (não o maior valor) ou se são
 * iguais
 */
void exercicio01(void) {

  int numero1, numero2;

  // Obtenho os números
  printf("Digite dois numeros separados par espaco para compara-los (Ex: 8 15) : ");
  scanf("%d %d", &numero1, &numero2);

  // Realizo as comparações e imprimo a informação conforme resultado
  if (numero1 == numero2) {
    printf("Os numeros %d e %d sao IGUAIS.\n", numero1, numero2);
  } else {
    if (numero1 < numero2) {
      printf("Entre os numeros %d e %d, o segundo eh maior com valor %d.\n", numero1, numero2, numero2);
    } else {
      printf("Entre os numeros %d e %d, o primeiro eh maior com valor %d.\n", numero1, numero2, numero1);
    }
  }
}

/**
 * Faça o fluxograma e um programa que leia três
 * comprimentos (x, y e z) e responda se eles formam um triângulo, ou seja,
 * se x < y + z e y < x + z e z < x + y.
 */
void exercicio02(void) {

  float x, y, z;
  bool ehTriangulo;

  // Obtem os lados
  printf("Digite os comprimentos dos segmentos para verificar se forma um triangulo (Ex: 1.0 1.0. 2.0): ");
  scanf("%f %f %f", &x, &y, &z);

  // Verifica se é um triangulo
  ehTriangulo = (x < y + z) && (y < x + z) && (z < x + y);

  // Mostra o resultado
  if (ehTriangulo) {
    printf("Os comprimentos %f, %f e %f FORMAM um triangulo.\n", x, y, z);
  } else {
    printf("Os comprimentos %f, %f e %f NAO FORMAM um triangulo.\n", x, y, z);
  }
}

/**
 * Faça um programa para ler o número do dia da semana e
 * imprimir seu respectivo nome por extenso. Considere o número 1 como
 * domingo, 2 como segunda e etc. Caso o dia da semana seja inválido, exibir
 * a mensagem “Dia da Semana invalido”.
 */
void exercicio03(void) {

  int diaSemana;

  // Obtem o dia da semana
  printf("Digite o numero referente ao dia da semana para obter seu nome [1:7]: ");
  scanf("%d", &diaSemana);

  // Imprime o dia da semana conforme o numero
  switch (diaSemana) {
    case 1:
      printf("Domingo\n");
      break;
    case 2:
      printf("Segunda-feira\n");
      break;
    case 3:
      printf("Terca-feira\n");
      break;
    case 4:
      printf("Quarta-feira\n");
      break;
    case 5:
      printf("Quinta-feira\n");
      break;
    case 6:
      printf("Sexta-feira\n");
      break;
    case 7:
      printf("Sabado\n");
      break;

    default:
      printf("Dia da semana invalido\n");
      break;
  }
}

/**
 * Faça o fluxograma e um programa que leia dois números
 * inteiros e uma das operações (soma, subtração, multiplicação, divisão,
 * potência e radiciação) e imprima a operação com o resultado.
 */
void exercicio04(void) {

  int numero1, numero2;
  char operador;

  // Obtem a expressao
  printf("Digite a expressao simples a ser calculada (Ex: 2 * 2): ");
  printf("+ : adicao\n");
  printf("* : substracao\n");
  printf("* : multiplicacao\n");
  printf("/ : divisao\n");
  printf("^ : potenciacao\n");
  printf("# : radiciacao\n");
  scanf("%d %c %d", &numero1, &operador, &numero2);

  switch (operador) {
  case '+':
    printf("%d %c %d = %d", numero1, operador, numero2, numero1 + numero2);
    break;
  case '-':
    printf("%d %c %d = %d", numero1, operador, numero2, numero1 - numero2);
    break;
  case '*':
    printf("%d %c %d = %d", numero1, operador, numero2, numero1 * numero2);
    break;
  case '/':
    printf("%d %c %d = %f", numero1, operador, numero2, 1.0 * numero1 / numero2);
    break;
  case '^':
    printf("%d %c %d = %lf", numero1, operador, numero2,  pow(numero1, numero2));
    break;
  case '#':
    printf("%d %c %d = %lf", numero1, operador, numero2,  pow(numero1, 1.0 / numero2));
    break;
  default:
    printf("Operacao invalida.\n");
    break;
  }    
}

/**
 * Faça um programa que leia as notas de três provas de
 * três alunos e imprime em forma de tabela (um aluno por linha, uma nota
 * por coluna) os valores lidos além do conceito dele.
 * Todas as notas devem ter duas casas decimais e elas devem ser separadas
 * por uma tabulação.
 * Conceitos: A[90:100] ; B[80:90[ ; C[70:80[ ; D[60:70[ ; R[0:60[
 */
 
// Número de notas.
// Por enquanto a constante não aplica real melhoria no código, mas é bom
// praticar o não uso de constantes literais.
#define NUMERO_DE_NOTAS 3
 
void exercicio05(void) {
  
  float aluno1_nota1, aluno1_nota2, aluno1_nota3, aluno1_media;
  float aluno2_nota1, aluno2_nota2, aluno2_nota3, aluno2_media;
  float aluno3_nota1, aluno3_nota2, aluno3_nota3, aluno3_media;
  char aluno1_conceito, aluno2_conceito, aluno3_conceito;
  
  // Obtem as notas dos alunos
  printf("Vamos ler as notas de tres alunos.\n");
  printf("Aluno 1 - Nota 1: ");
  scanf("%f", &aluno1_nota1);
  printf("Aluno 1 - Nota 2: ");
  scanf("%f", &aluno1_nota2);
  printf("Aluno 1 - Nota 3: ");
  scanf("%f", &aluno1_nota3);
  printf("Aluno 2 - Nota 1: ");
  scanf("%f", &aluno2_nota1);
  printf("Aluno 2 - Nota 2: ");
  scanf("%f", &aluno2_nota2);
  printf("Aluno 2 - Nota 3: ");
  scanf("%f", &aluno2_nota3);
  printf("Aluno 3 - Nota 1: ");
  scanf("%f", &aluno3_nota1);
  printf("Aluno 3 - Nota 2: ");
  scanf("%f", &aluno3_nota2);
  printf("Aluno 3 - Nota 3: ");
  scanf("%f", &aluno3_nota3);
  
  // Calcula as médias
  aluno1_media = (aluno1_nota1 + aluno1_nota2 + aluno1_nota3) / NUMERO_DE_NOTAS;
  aluno2_media = (aluno2_nota1 + aluno2_nota2 + aluno2_nota3) / NUMERO_DE_NOTAS;
  aluno3_media = (aluno3_nota1 + aluno3_nota2 + aluno3_nota3) / NUMERO_DE_NOTAS;
  
  // Calcula os conceitos
  
  // Aluno 1
  if      (aluno1_media >= 90) { aluno1_conceito = 'A'; }
  else if (aluno1_media >= 80) { aluno1_conceito = 'B'; }
  else if (aluno1_media >= 70) { aluno1_conceito = 'C'; }
  else if (aluno1_media >= 60) { aluno1_conceito = 'D'; }
  else                         { aluno1_conceito = 'R'; }
  // Aluno 2
  if      (aluno2_media >= 90) { aluno2_conceito = 'A'; }
  else if (aluno2_media >= 80) { aluno2_conceito = 'B'; }
  else if (aluno2_media >= 70) { aluno2_conceito = 'C'; }
  else if (aluno2_media >= 60) { aluno2_conceito = 'D'; }
  else                         { aluno2_conceito = 'R'; }
  // Aluno 3
  if      (aluno3_media >= 90) { aluno3_conceito = 'A'; }
  else if (aluno3_media >= 80) { aluno3_conceito = 'B'; }
  else if (aluno3_media >= 70) { aluno3_conceito = 'C'; }
  else if (aluno3_media >= 60) { aluno3_conceito = 'D'; }
  else                         { aluno3_conceito = 'R'; }
  
  // Imprime as notas em forma de tabela
  printf("Notas:\n");
  printf("Aluno %d\t%.2f\t%.2f\t%.2f\t%c\n",1, aluno1_nota1, aluno1_nota2, aluno1_nota3, aluno1_conceito);
  printf("Aluno %d\t%.2f\t%.2f\t%.2f\t%c\n",2, aluno2_nota1, aluno2_nota2, aluno2_nota3, aluno2_conceito);
  printf("Aluno %d\t%.2f\t%.2f\t%.2f\t%c\n",3, aluno3_nota1, aluno3_nota2, aluno3_nota3, aluno3_conceito);  
  
}

/**
 * Faça um programa que leia, nesta ordem, a altura (em
 * metros) e o sexo (caractere) e em seguida imprima o peso ideal dela.
 * Homens: (72,7 x altura) - 58
 * Mulheres: (62,1 x altura) – 44,7
 */
void exercicio06(void) {

  float altura, pesoIdeal;
  char sexo;

  // Obtem os dados
  printf("Digite sua altura em metros: ");
  scanf("%f", &altura);
  printf("Digite seu sexo (M/m ou F/f): ");
  scanf(" %c", &sexo);

  // Calcula o peso ideal
  if ((sexo == 'M') || (sexo == 'm')) {
    pesoIdeal = (72.7f * altura) - 58;
  } else {
    pesoIdeal = (62.1f * altura) - 44.7f;
  }

  // Informa o peso ideal
  printf("Seu peso ideal eh %.2f. ", pesoIdeal);
}


/**
* Função principal do programa onde o mesmo será iniciado.
* @param argc Número de parâmetros.
* @param argv Valores dos parâmetros.
* @return SUCESSO caso o programa seja executado corretamente, ou caso contrário,
* o código do erro ocorrido.
*/
int main(int argc, char ** argv) {

  int nExercicio;

  do {
    printf("Digite o numero do exercicio que quer executar [1:6]. 0 para sair: ");
    scanf("%d", &nExercicio);

    switch (nExercicio) {
      case 0: break;
      case 1: {
        exercicio01();
        break;
      }
      case 2: {
        exercicio02();
        break;
      }
      case 3: {
        exercicio03();
        break;
      }
      case 4: {
        exercicio04();
        break;
      }
      case 5: {
        exercicio05();
        break;
      }
      case 6: {
        exercicio06();
        break;
      }
      default: {
        printf("Voce escolheu um exercicio invalido.\n");
      }
    }

    // Adiciono uma quebra de linha para separar cada execução de exercício
    printf("\n");

  } while (nExercicio != 0);

  // Se chegou até aqui é porque correu tudo bem
  return SUCESSO;
}