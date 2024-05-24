import subprocess  # Para executar o programa externo
import sys         # Para acessar os argumentos da linha de comando
import time        # Para medir o tempo de execução
import json        # Para trabalhar com dados JSON
import requests    # Para fazer requisições HTTP
import argparse    # Para processamento de argumentos

versao = "1.3"

'''
Função principal
'''
def main():

    # Configuração do argparse
    parser = argparse.ArgumentParser(description=f"Testador {versao}")
    parser.add_argument("programa", help="Nome do programa a ser testado")
    parser.add_argument("-f", "--arquivo", help="Caminho para o arquivo JSON local (opcional)")
    parser.add_argument("ano", nargs='?', help="Ano (opcional se usar -f)")
    parser.add_argument("lista", nargs='?', help="Número da lista (opcional se usar -f)")
    parser.add_argument("exercicio", nargs='?', help="Número do exercício (opcional se usar -f)")
    args = parser.parse_args()
    
    # Mostra nome do programa e versão
    print(f"Testador.py\nVersão {versao}\n")
    
    # Obtem o nome do programa a ser testado
    programa = args.programa

    # Se o usuário forneceu um arquivo local
    if args.arquivo: 
        try:
            with open(args.arquivo, 'r') as f:
                print("Utilizando arquivo de testes local")
                dados = json.load(f)
        except (FileNotFoundError, json.JSONDecodeError) as e:
            print(f"Erro ao ler o arquivo JSON: {e}")
            return
    else:  # Se não, baixa do GitHub (como antes)

        # Verifica se foram fornecidos os argumentos necessários
        if len(sys.argv) != 5:
            # Encerra o script se os argumentos estiverem incorretos
            print("Uso: python testador.py <programa> <ano> <lista> <exercicio>")
            return

        # Extrai os argumentos da linha de comando
        ano, lista, exercicio = args.ano, args.lista, args.exercicio

        # Constrói o nome do arquivo JSON e a URL para baixá-lo do GitHub
        nome_arquivo = f"LE{lista}_ex{exercicio}.json"
        url = f"https://raw.githubusercontent.com/elmaia/coltec/master/IP/Listas%20de%20Exercicicios/{ano}/LE%20{lista}/{nome_arquivo}"

        try:
            # Faz a requisição HTTP para baixar o arquivo JSON
            print("Baixando arquivo de testes da Internet")
            response = requests.get(url)
            response.raise_for_status()  # Lança uma exceção se houve erro na requisição
            # Carrega o conteúdo do arquivo JSON em um dicionário Python
            dados = json.loads(response.text)
        except requests.exceptions.RequestException as e:
            # Caso ocorra algum erro na requisição, imprime uma mensagem e encerra
            print(f"Erro ao baixar o arquivo: {e}")
            return
            
    # Neste pontos todos os testes estão carregados em dados

    # Itera sobre cada conjunto de entrada/saída no array JSON
    corretos, total = 0, 0
    for i, caso_teste in enumerate(dados):
    
        # Incrementa o número de testes
        total += 1

        # Extrai a entrada e a saída esperada do dicionário
        entrada = caso_teste["entrada"]
        saida_esperada = caso_teste["saida"]

        try:
            # Executa o programa com a entrada obtida do JSON
            print(">> Execucao " + str(i + 1))

            # Marca o início da execução
            inicio = time.time()  
            resultado = subprocess.run(
                [programa],
                input=entrada,
                capture_output=True,
                text=True,
                timeout=1  # Tempo limite de execução em segundos
            )
            fim = time.time()  # Marca o fim da execução
        except subprocess.TimeoutExpired:
            # Se o programa exceder o tempo limite, imprime uma mensagem e encerra
            print("Tempo limite excedido!")
            continue

        # Calcula e imprime o tempo de execução
        tempo_execucao = fim - inicio
        print(f"Tempo: {tempo_execucao:.2f}s")

        # Compara a saída do programa com a saída esperada
        if resultado.stderr == saida_esperada:
            corretos += 1
            print("Saídas idênticas!\n")
        else:
            # Em caso de saídas diferentes, imprime as duas para comparação
            print("Saídas diferentes!")
            print("-" * 20)
            print("Saída obtida:")
            print(resultado.stderr)
            print("-" * 20)
            print("Saída esperada:")
            print(saida_esperada)
    
    # Imprime o resultado final
    print("-" * 40)
    print("Resultado: " + str(corretos) + "/" + str(total))

# Executa a função principal se o script for executado diretamente
if __name__ == "__main__":
    main()
