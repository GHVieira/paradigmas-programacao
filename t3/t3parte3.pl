#Questão 8 da OBI de 2016 - Iniciação Nível 1 - Fase 1


#Para ter traves, precisa-se no mínimo 2 postes, então a regra caso tenha apenas 1 poste
adiciona_traves(1, 0).
#Recursiva que vai ser chamada X vezes sendo X o número de postes-1
#Cada vez, que for chamada, o número de traves R aumenta em 3 e vai acumulando
adiciona_traves(P, R) :- P>1, P1 is P-1, adiciona_traves(P1,R1), R is R1+3.


#Função principal que recebe número de postes(P) e travas(T) e retorna TRUE caso os números batam
calcula_traves(P, T) :- adiciona_traves(P, R), T=:=R. 