# 1 - Defina um predicado somaQuad(X,Y,Q) que seja verdadeiro se Q for a soma dos quadrados de X e Y.
quad(A,B,C) :- C is (A*A) + (B*B).

somaQuad(X, Y, Z) :- quad(X, Y, Z).


# 2 - Defina um predicado zeroInit(L) que é verdadeiro se L for uma lista que inicia com o número 0 (zero).
zeroInit([H|T]) :- H =:= 0.


# 3 - Defina um predicado hasEqHeads(L1,L2) que seja verdadeiro se as listas L1 e L2 possuírem o mesmo primeiro elemento. 
hasEqHeads([H|T],[C|R]) :- H=:=C.


# 4 - Defina um predicado has5(L) que seja verdadeiro se L for uma lista de 5 elementos. Lembre de como funciona a unificação em Prolog e resolva este exercício sem usar o predicado pré-definido length.
tam([], 0).
tam([H|T], S) :- tam(T, S1), S is 1 + S1.

has5(L) :- tam(L, S), S =:= 5.


# 5 - Defina um predicado hasN(L,N) que seja verdadeiro se L for uma lista de N elementos. Agora você pode usar um predicado pré-definido.
hasN(L,N) :- tam(L, S), S=:= N.


# 6 - Defina um predicado isBin(L) que seja verdadeiro se L for uma lista contendo somente elementos 0 e 1. Use recursão.
isBin([]).
isBin(L) :- L = [H|T], isBin(T), member(H, [0,1]).


# 7 - Defina um predicado mesmaPosicao(A,L1,L2) para verificar se um elemento A está na mesma posição nas listas L1 e L2. Assuma que L1 e L2 sejam permutações de uma lista de elementos distintos, sem repetições. Dica: procure auxílio em predicados pré-definidos.
encontraind(A,[A|_],0).
encontraind(A,[_|T],I) :- encontraind(A,T,X), I is X + 1.

mesmaPosicao(A,L1,L2) :- encontraind(A,L1,R), encontraind(A,L2,R1), R=:=R1.


# 8 - Defina um predicado repete5(E,L) que seja verdadeiro se a lista L for composta por exatamente 5 repetições do elemento E. Não use recursão.
repete5(E, L) :- L = [E,E,E,E,E].


# 9 - Defina um predicado recursivo sumQuads(L,S) que seja verdadeiro se S for o somatório dos quadrados dos elementos da lista L.
sumQuads([],0).
sumQuads([H|T], S) :- sumQuads(T, S1), S is H*H + S1.


# 10 - Defina um predicado recursivo repete(N,E,L) que seja verdadeiro se a lista L for composta por exatamente N repetições do elemento E. 
confere1([], E, 0).
confere1([H|T], E, S) :- confere1(T, E, S1), H =:= E, S is 1 + S1.

repete(N, E, L) :- confere1(L, E, X), X=:=N. 


# 11 - Defina um predicado recursivo mapop(L1,L2) que seja verdadeiro se a lista L2 for formada aplicando-se a operação 2*x+1 a cada elemento x da lista L1.
confere([], [], 0).
confere([H|T], [C|R], S) :- confere(T, R, S1), C =:= 2*H+1, S is 1 + S1.

mapop(L1,L2) :- confere(L1, L2, X), tam(L1, X1), X=:=X1.


# 12 - Defina um predicado positivos(L1,L2), de forma que L2 seja uma lista só com os elementos positivos de L1.
positivos([], []).
positivos([H|T], L) :- H<0, positivos(T,L).
positivos([H|T], L) :- H=0, positivos(T,L).

positivos([H|T], [H|R]) :- positivos(T,R).
