#Questão 8 da OBI de 2016 - Iniciação Nível 1 - Fase 1


#A partir de nº de postes > 1, a cada poste soma-se 3 travas
#Se 3 travas, 2 conjuntos de 3 travas
#nº total de travas = (nº total de postes -1) * 3


#Usuário coloca número de postes e travas
#No caso da questão 8, o primeiro valor vai se manter = 6 nas consultas
#O valor T vai ser testado para ver se a resposta bate

calcula_traves(6, 15).
calcula_traves(P, T) :- P1 is P - 1, T is 3*P1. 