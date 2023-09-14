c:-['joestar_family.pro'].

% facts

male('George').
male('Jonathan').
male('George II').
male('Joseph').
male('Josuke').
male('Sadao').
male('Jotaro').

female('Mary').
female('Erina').
female('Lisa Lisa').
female('Suzi Q').
female('Tomoko').
female('Holy').
female('Shizuka').
female('Jolyne').

parent_of('Jonathan', 'George').
parent_of('Jonathan', 'Mary').
parent_of('George II', 'Jonathan').
parent_of('George II', 'Erina').
parent_of('Joseph', 'George II').
parent_of('Joseph', 'Lisa Lisa').
parent_of('Holy', 'Joseph').
parent_of('Holy', 'Suzi Q').
parent_of('Shizuka', 'Joseph').
parent_of('Josuke', 'Joseph').
parent_of('Josuke', 'Tomoko').
parent_of('Jotaro', 'Holy').
parent_of('Jotaro', 'Sadao').
parent_of('Jolyne', 'Jotaro').

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

ancestor_of(A, B) :- parent_of(A, B).
ancestor_of(A, B) :- parent_of(A, X), ancestor_of(X, B). 