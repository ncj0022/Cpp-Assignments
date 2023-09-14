go:-
  puzzle(Show,[0,1,2,3,4,5,6,7,8,9],_),
  Show,
  fail
; nl.

/*

  S E N D +
  M O R E
---------
M O N E Y  

*/

% problem specific code

puzzle(show(S,E,N,D,M,O,R,Y))-->

  add_digits(D,E,Y,  0,C1),
  add_digits(N,R,E, C1,C2),
  add_digits(E,O,N, C2,C3),
  add_digits(S,M,O, C3,
                 M),
                 
  {S>0,M>0}.

show(S,E,N,D,M,O,R,Y):-
( write('  '),
  write([S,E,N,D]),
  write('+'),nl,
  write('  '),
  write([M,O,R,E]),
  write('='),nl,
  write([M,O,N,E,Y]),nl,
  fail
; nl
).

% reusable code

digit(X)-->{integer(X)},!.
digit(X)-->sel(X).

add_digits(D1,D2,Res,C1,C2)-->
   digit(D1),
   digit(D2),
   digit(Res),
   {add_with_carry(D1,D2,C1, Res,C2)}.

add_with_carry(D1,D2,C1, Res,C2):-
    S is (D1+D2)+C1,
    Res is S mod 10,
    C2 is S // 10.

sel(X,[X|Xs],Xs).
sel(X,[Y|Xs],[Y|Ys]):-sel(X,Xs,Ys).