# Lista de Exercícios 2024

O objetivo desta página é armazenar as listas de exercícios 
disponibilizadas em 2024 e sugestões de soluções.

A partir da *Lista de Exercícios 05*, tentaremos fazer um testador 
automático que será utilizado durante as provas.
O objetivo é fazer com que, durante o desenvolvimento, você tenha
ideia se está no caminho correto.

## Testador

A versão atual do testador funciona com a seguinte sintaxe:

> ./testador <seu_executavel> <arquivo_entrada> <arquivo_saida_referencia>

O que ele faz?

- Abre o seu executável e redireciona a saída;
- Joga o arquivo de entrada como se fosse o usuário digitando;
- Tudo que o programa imprimir utilizando o PRINTF é redirecionado;
- No final, a saída do programa é comparada com a saída de referência.

## Preparo do programa para testes automáticos

Apesar de não ser a utilização adequada, como o objetivo é fazer os testes
automáticos, a saída de erro é utilizada como saída "Oficial".
Para isso, foi criada uma macro chamada PRINTF que, caso o programa seja
compilado com a definição de TESTADOR ativada, usa a saída de erros
como saída oficial, caso contrário, funciona como um printf tradicional.

### Macro

Cole o seguinte trecho de código no seu programa para habilitá-lo a ser utilizado
com os testador

```c
/**
 * Macro para utilização do canal de saída de erro como
 * saída de texto para testes automáticos.
 */
#ifdef TESTADOR
  #define PRINTF(format, args...) fprintf(stderr, format, args)
#else
  #define PRINTF(format, args...) printf(format, args)
#endif
```

### Compilando e habilitando o testador

Para habilitar o PRINTF como saída oficial, compile seu programa com a 
definição TESTADOR ativa.

Para isso basta adicionar **-DTESTADOR** no gcc.

> gcc -DTESTADOR seuarquivo.c -o seuexecutavel.exe

### Exemplo

Suponha que você queira testar o seu exercício 01 da lista de exercícios 05.

1. Adicione o código da macro no seu arquivo.
  - Ctrl+C e Ctrl+V
2. Compile utilizando a definição TESTADOR
  - gcc -DTESTADOR le05_ex01.c -o le05_ex01.exe
3. Execute o testador
  - ./testador le05_ex01.exe le05_ex01_entrada01.txt le05_ex01_saida01.txt
4 - Verifique o resultado