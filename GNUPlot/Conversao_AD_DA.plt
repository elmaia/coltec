# Exemplo de conversão A/D e D/A

# Amplitute da onda
A = 5
# Frequência da onda
F = 20
# Número de amostragens
S_Total = 5000
S = 100
# Número de faixas verticais
V = 16

# Função da onda original
# Offset vertical de A/2 para o menor valor ser 0 e o maior ser a amplitude
f_orig(x) = (A/2.0) + (A/2.0)*sin(2*pi*F*x)
f_fast(x) = (A/2.0) + (A/2.0)*sin(2*pi*2*F*x)
g(x) = (x < 0.5 ? f_orig(x) : f_fast(x))
f(x) = (y = g(x),  floor((y/A)*V) * (1.0*A/V))

set macros
set format x ""
desenhar = 'set samples S_Total; set ytics 0,(1.0*A/V), A; set xtics 0, (1.0/(S)), 1; plot [0:1] [-0.5:(A+0.5)] g(x) title "Original" with lines lc rgb "red", f(floor(x*S)*(1.0/S)) title "Tensão Saida" with steps lt 1'

# Ensinando a plotar
print("*********************************************************************************")
print("* Exemplo de conversão A/D e D/A                                                *")
print("* A onda ROXA representa a reconstrução da onda.                                *")
print("* A onda VERMELHO representa a onda original.                                   *")
print("* Exemplo criado por Leandro Maia                                               *")
print("*********************************************************************************")
print("")
print("Para desenhar, digite: @desenhar")
print("Para alterar os parâmetros do desenho, digite: parâmetro = valor")
print("Parâmetros:")
print("--> A: Amplitude. Ex.: A = 5")
print("--> F: Frequencia. Ex.: F = 10")
print("--> S: Número de amostragens por segundo. Ex.: S = 100")
print("--> V: Número de faixas verticais. Ex.: V = 16")
print(sprintf("Os valores padrões são: A = %d, F = %d, S = %d, V = %d",A,F,S,V))
