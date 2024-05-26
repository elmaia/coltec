# Lista de Exerc�cios 2024

O objetivo desta p�gina � armazenar as listas de exerc�cios 
disponibilizadas em 2024 e sugest�es de solu��es.

A partir da *Lista de Exerc�cios 05*, tentaremos fazer um testador 
autom�tico que ser� utilizado durante as provas.
O objetivo � fazer com que, durante o desenvolvimento, voc� tenha
ideia se est� no caminho correto.

## Testador em C (Windows e Linux)

A vers�o atual do testador funciona com a seguinte sintaxe:

> ./testador <seu_executavel> <arquivo_entrada> <arquivo_saida_referencia>

O que ele faz?

- Abre o seu execut�vel e redireciona a sa�da;
- Joga o arquivo de entrada como se fosse o usu�rio digitando;
- Tudo que o programa imprimir utilizando o PRINTF � redirecionado;
- No final, a sa�da do programa � comparada com a sa�da de refer�ncia.

## Testador em Python (Windows e Linux)

A vers�o atual do testador funciona com a seguinte sintaxe:

> python testador.py <seu_executavel> <ano> <lista_exercicio> <num_exercicio>

O que ele faz?

- Abre o seu execut�vel e redireciona a sa�da;
- Obtem os testes aqui no Github conforme o ano, lista de exerc�cio e n�mero do exerc�cio informado
- Joga cada entrada do arquivo de testes como se fosse o usu�rio digitando;
- Tudo que o programa imprimir utilizando o PRINTF � redirecionado;
- No final, a sa�da do programa � comparada com a sa�da de refer�ncia.
- Depois de todos os casos de testes � exibido o n�mero de acertos e de casos testados.


## Preparo do programa para testes autom�ticos

Apesar de n�o ser a utiliza��o adequada, como o objetivo � fazer os testes
autom�ticos, a sa�da de erro � utilizada como sa�da "Oficial".
Para isso, foi criada uma macro chamada PRINTF que, caso o programa seja
compilado com a defini��o de TESTADOR ativada, usa a sa�da de erros
como sa�da oficial, caso contr�rio, funciona como um printf tradicional.

### Macro

Cole o seguinte trecho de c�digo no seu programa para habilit�-lo a ser utilizado
com os testador

```c
/**
 * Macro para utiliza��o do canal de sa�da de erro como
 * sa�da de texto para testes autom�ticos.
 */
#ifdef TESTADOR
  #define PRINTF(format, ...) fprintf(stderr, format, __VA_ARGS__)
#else
  #define PRINTF(format, ...) printf(format, __VA_ARGS__)
#endif
```

### Compilando e habilitando o testador

Para habilitar o PRINTF como sa�da oficial, compile seu programa com a 
defini��o TESTADOR ativa.

Para isso basta adicionar **-DTESTADOR** no gcc.

> gcc -DTESTADOR seuarquivo.c -o seuexecutavel.exe

### Exemplo

Suponha que voc� queira testar o seu exerc�cio 01 da lista de exerc�cios 05.

1. Adicione o c�digo da macro no seu arquivo.
  - Ctrl+C e Ctrl+V
2. Compile utilizando a defini��o TESTADOR
  - gcc -DTESTADOR le05_ex01.c -o le05_ex01.exe
3. Execute o testador
  - ./testador le05_ex01.exe le05_ex01_entrada01.txt le05_ex01_saida01.txt
  ou
  - python testador.py le05_ex01.exe 2024 05 01
4. - Verifique o resultado