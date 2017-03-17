#1 - Escreva uma função que receba uma lista de nomes e retorne uma lista com a string "Sr. " adicionada ao início de cada nome.
def add_sr(l1): 
	return list(map(lambda x: "Sr." + x , l1))


#2 - Escreva uma função que, dada uma lista de números, calcule 3n*2 + 2/n + 1 para cada número n da lista.
def funcao_equacao(l1): 
	return list(map(lambda x: 3*x*2 + 2/x + 1, l1))


#3 - Crie uma função que receba uma lista de nomes e retorne outra lista com somente aqueles nomes que terminarem com a letra 'a'.
def procura_letra(l1):
	return list(filter(lambda x: x[-1] == 'a', l1))


#4 - Escreva uma função que, dada uma lista de idades de pessoas no ano atual, retorne uma lista somente com as idades de quem nasceu depois de 1970. Para testar a condição, sua função deverá subtrair a idade do ano atual. Exemplo de uso:
 def apos_70(l1):
 	return list(filter(lambda x: x < 2017 - 1970, l1));


 #5 - O código abaixo é escrito em Python imperativo. Escreva um código equivalente usando programação funcional.
 	def dobra_valor(l1):
 		return list(map(lambda x: x*2, l1))

