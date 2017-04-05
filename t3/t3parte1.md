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