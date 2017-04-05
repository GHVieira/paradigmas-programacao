#Questão 1

pai(roberto,joao).
pai(joao, jose).
pai(roberto,julio).
pai(julio,marcos).
pai(julio,mario).
avo(X,Z) :- pai(X,Y), pai(Y,Z).


[trace]  ?- avo(joao, Y).
   Call: (8) avo(joao, _4852) ? creep  #Chama avô procurando um neto para João
   Call: (9) pai(joao, _5070) ? creep  #Procurando se João é pai de alguem
   Exit: (9) pai(joao, jose) ? creep   #Encontrou José como filho para João
   Call: (9) pai(jose, _4852) ? creep  #Procurando um filho para José
   Fail: (9) pai(jose, _4852) ? creep  #Fail pois José não tem filho
   Fail: (8) avo(joao, _4852) ? creep  #Fail pois o filho de João não possui filho
false.


#Questão 2

azulejos(0,0).
azulejos(Na,Nq) :-
   Na > 0,
   Q is floor(sqrt(Na)),
   R is Na - Q*Q,
   azulejos(R,C),
   Nq is 1 + C.

[trace]  ?- azulejos(120,A).
   Call: (8) azulejos(120, _4852) ? creep         #Procura quantos quadrados se formam com Na(120) azulejos
   Call: (9) 120>0 ? creep                        #Verifica se Na é maior que 0 (para fazer a raiz) 
   Exit: (9) 120>0 ? creep                        #Retorna verdadeiro
   Call: (9) _5078 is floor(sqrt(120)) ? creep    #Q(5078) vai receber o valor arredondado pra baixo da raiz quadrada de Na
   Exit: (9) 10 is floor(sqrt(120)) ? creep       #O maior quadrado se forma com 10 azulejos de lateral (10*10=100 Azulejos)
   Call: (9) _5090 is 120-10*10 ? creep           #R(5090) vai recer o numero Na-Q^2 de Azulejos(Desconta do numero total)
   Exit: (9) 20 is 120-10*10 ? creep              #Sobraram 20 azulejos dos 120 iniciais
   Call: (9) azulejos(20, _5092) ? creep          #Procura quantos quadrados se formam com R(20) azulejos
   Call: (10) 20>0 ? creep                        #Verifica se Na é maior que 0 (para fazer a raiz)
   Exit: (10) 20>0 ? creep                        #Retorna verdadeiro
   Call: (10) _5098 is floor(sqrt(20)) ? creep    #Q(5098) vai receber o valor arredondado para baixo da raiz quadrada de Na
   Exit: (10) 4 is floor(sqrt(20)) ? creep        #O maior quadrado se forma com 4 azulejos na lateral(4*4=16 Azulejos)
   Call: (10) _5110 is 20-4*4 ? creep             #R(5110) vai receber o numero Na-Q^2 de Azulejos(Deconta do numero total)
   Exit: (10) 4 is 20-4*4 ? creep                 #Sobraram 4 azulejos dos 20 que foram mandados
   Call: (10) azulejos(4, _5112) ? creep          #Procura quantos quadrados se formam com Na(4) azulejos
   Call: (11) 4>0 ? creep                         #Verifica se Na é maior que 0 (para fazer a raiz)
   Exit: (11) 4>0 ? creep                         #Retorna verdadeiro
   Call: (11) _5118 is floor(sqrt(4)) ? creep     #Q(5118) vai receber o valor arredondado para baixo da raiz quadrada de Na
   Exit: (11) 2 is floor(sqrt(4)) ? creep         #O maior quadrado se forma com 2 azulejos na lateral(2*2=4 Azulejps)
   Call: (11) _5130 is 4-2*2 ? creep              #R(5130) vai receber o numero Na-Q^2 de Azulejos(Deconta do numero total)
   Exit: (11) 0 is 4-2*2 ? creep                  #Sobraram 0 azulejos dos 4 que foram mandados
   Call: (11) azulejos(0, _5132) ? creep          #Procura quantos quadrados se formam com Na(0) azulejos
   Exit: (11) azulejos(0, 0) ? creep              #Aplica-se a regra de parada caso o Na seja 0
   Call: (11) _5136 is 1+0 ? creep                #Nq(5136) soma-se 1 à medida que se "volta" na recursão
   Exit: (11) 1 is 1+0 ? creep                    #Nq ++
   Exit: (10) azulejos(4, 1) ? creep              #"Volta" para quando Na era 4
   Call: (10) _5142 is 1+1 ? creep                #Nq(5142) soma-se com 1
   Exit: (10) 2 is 1+1 ? creep                    #Nq ++
   Exit: (9) azulejos(20, 2) ? creep              #"Volta" para quando Na era 20
   Call: (9) _4852 is 1+2 ? creep                 #Nq(4852) soma-se com 1
   Exit: (9) 3 is 1+2 ? creep                     #Nq ++
   Exit: (8) azulejos(120, 3) ? creep             #"Volta" para quando Na era 120
A = 3                                             #Número de quadrados formados termina em 3.

