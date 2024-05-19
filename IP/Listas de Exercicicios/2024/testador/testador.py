import subprocess  # Para executar o programa externo
import sys         # Para acessar os argumentos da linha de comando
import time        # Para medir o tempo de execução
import json        # Para trabalhar com dados JSON
import requests    # Para fazer requisições HTTP

'''
Função principal
'''
def main():
    # Verifica se foram fornecidos os 4 argumentos necessários
    if len(sys.argv) != 4:
        # Encerra o script se os argumentos estiverem incorretos
        print("Uso: python testador.py <programa> <ano> <lista> <exercicio>")
        return  

    # Extrai os argumentos da linha de comando
    programa, ano, lista, exercicio = sys.argv[1:]

    # Constrói o nome do arquivo JSON e a URL para baixá-lo do GitHub
    nome_arquivo = f"LE{lista}_ex{exercicio}.json"
    url = f"https://raw.githubusercontent.com/elmaia/coltec/master/IP/Listas%20de%20Exercicicios/{ano}/LE%20{lista}/{nome_arquivo}"

    try:
        # Faz a requisição HTTP para baixar o arquivo JSON
        response = requests.get(url)
        response.raise_for_status()  # Lança uma exceção se houve erro na requisição
        # Carrega o conteúdo do arquivo JSON em um dicionário Python
        dados = json.loads(response.text)
    except requests.exceptions.RequestException as e:
        # Caso ocorra algum erro na requisição, imprime uma mensagem e encerra
        print(f"Erro ao baixar o arquivo: {e}")
        return

    # Itera sobre cada conjunto de entrada/saída no array JSON
    for i, caso_teste in enumerate(dados):

        # Extrai a entrada e a saída esperada do dicionário
        entrada = caso_teste["entrada"]
        saida_esperada = caso_teste["saida"]

        try:
            # Executa o programa com a entrada obtida do JSON

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
            return

        # Calcula e imprime o tempo de execução
        tempo_execucao = fim - inicio
        print(f"Tempo de execução: {tempo_execucao:.2f} segundos")

        # Compara a saída do programa com a saída esperada
        if resultado.stdout == saida_esperada:
            print("Saídas idênticas!")
        else:
            # Em caso de saídas diferentes, imprime as duas para comparação
            print("Saídas diferentes!")
            print("-" * 20)
            print("Saída obtida:")
            print(resultado.stdout)
            print("-" * 20)
            print("Saída esperada:")
            print(saida_esperada)

# Executa a função principal se o script for executado diretamente
if __name__ == "__main__":
    main()
