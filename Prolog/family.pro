c:-['family.pro'].

% facts

male('Joseph Patrick Kennedy').
male('John Vernou Bouvier III').
male('John Fitzgerald Kennedy').
male('Joseph Patrick Kennedy Jr.').
male('Aristotle Onassis').
male('Patrick Bouvier Kennedy').
male('John Fitzgerald Kennedy II').

female('Rose Elizabeth Fitzgerald').
female('Rosemary Kennedy').
female('Eunice Marie Kennedy').
female('Kathleen Kennedy').
female('Janet Norton Lee').
female('Jaqueline Lee Bouvier').
female('Caroline Bouvier Kennedy').

parent_of('John Fitzgerald Kennedy','Joseph Patrick Kennedy').
parent_of('John Fitzgerald Kennedy','Rose Elizabeth Fitzgerald').
parent_of('Rosemary Kennedy','Joseph Patrick Kennedy').
parent_of('Rosemary Kennedy','Rose Elizabeth Fitzgerald').
parent_of('Joseph Patrick Kennedy Jr.','Joseph Patrick Kennedy').
parent_of('Joseph Patrick Kennedy Jr.','Rose Elizabeth Fitzgerald').
parent_of('Eunice Marie Kennedy','Joseph Patrick Kennedy').
parent_of('Eunice Marie Kennedy','Rose Elizabeth Fitzgerald').
parent_of('Kathleen Kennedy','Joseph Patrick Kennedy').
parent_of('Kathleen Kennedy','Rose Elizabeth Fitzgerald').

% rules
sibling_of(X,S):-parent_of(X,P),parent_of(S,P),X\==S.

brother_of(X,B):-sibling_of(X,B),male(B).

sister_of(X,S):-sibling_of(X,S),female(S).

mother_of(X,M):-parent_of(X,M),female(M).

father_of(X,M):-parent_of(X,M),male(M).

gp_of(X,GP):-parent_of(X,P),parent_of(P,GP).

cousin_of(X,C):-
  gp_of(X,GP),
  gp_of(C,GP),
  X\==C,
  not(sibling_of(X,C)).
  
uncle_or_aunt_of(X,Who):-
  parent_of(X,P),
  sibling_of(P,Who).
  
uncle_of(X,Who):-uncle_or_aunt_of(X,Who),male(Who).

aunt_of(X,Who):-uncle_or_aunt_of(X,Who),female(Who).
