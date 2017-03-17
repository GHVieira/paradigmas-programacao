#1 - Defina uma função somaQuad(x,y) que calcule a soma dos quadrados de dois números x e y.
def somaQuad(x,y):
	x = pow(x,2)
	y = pow(y,2)

	return x+y


#2 - Crie uma função hasEqHeads(l1,l2) que verifique se as listas l1 e l2 possuem o mesmo primeiro elemento.
def hasEqHeads(l1,l2):

	return l1[0] == l2[0]


#3 - Escreva uma função que receba uma lista de nomes e retorne uma lista com a string "Sr. " adicionada ao início de cada nome. Defina uma função auxiliar para ajudar neste exercício.
def add_sr2(l1): 
	return "Sr." + l1

def add_sr(l1): 
	return list(map(add_sr2, l1))


#4 - Crie uma função que receba uma string e retorne o número de espaços nela contidos. Defina uma função auxiliar para ajudar neste exercício.
def localiza_espaco_aux(string)
	return string == ' '

def localiza_espaco(string)
	return len(list(filter(localiza_espaco_aux, string)))


#5 - Escreva uma função que, dada uma lista de números, calcule 3n*2 + 2/n + 1 para cada número n da lista. Defina uma função auxiliar para ajudar neste exercício.
def funcao_equacao(l1): 
	return 3*l1*2 + 2/l1 + 1

def funcao_add(l1): 
	return list(map(funcao_equacao, l1))


#6 - Escreva uma função que, dada uma lista de números, retorne uma lista com apenas os que forem negativos. Defina uma função auxiliar para ajudar neste exercício.
def negativos_aux(l1): 
	return l1<0

def negativos(l1): 
	return list(filter(negativos_aux, l1)) 


#7 - Escreva uma função que receba uma lista de números e retorne somente os que estiverem entre 1 e 100, inclusive. Defina uma função auxiliar para ajudar neste exercício.
def intervalo_aux(l1):
	return (l1>=1 and l1<=100)

def intervalo(l1):
	return list(filter(intervalo_aux, l1))


#8 - Escreva uma função que receba uma lista de números e retorne somente aqueles que forem pares. Defina uma função auxiliar para ajudar neste exercício.
def par_aux(l1):
	return ((l1%2)==0)

def par(l1):
	return list(filter(par_aux, l1))


#9 - Crie uma função charFound(c,s) que verifique se o caracter c está contido na string. O resultado deve ser True ou False. Você não deve usar o operador in. Defina uma função auxiliar para ajudar neste exercício.	
def charFound(c, s):
	def charFound_aux(x):
		return c == x

	return filter(charFound_aux, s)


#10 - Escreva uma função que receba uma lista de strings e retorne uma nova lista com adição de marcações HTML (p.ex.: <B> e </B>) antes e depois de cada string
def add_marcadores_aux(string):
	return "<B>" + l1 + "</B>"

def add_marcadores_aux(lista_string):
	return list(map(add_marcadores_aux, lista_string)) 
