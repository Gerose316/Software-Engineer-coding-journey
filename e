% the dictionary
lookup(logic,logik).
lookup(is,macht).
lookup(fun,spass).
lookup(A,A).
% the translation procedure
translate([],[]).
translate(ES,GS):-
[W|R]=ES,
lookup(W,GW),
translate(R,GR),
GS=[GW|GR].
