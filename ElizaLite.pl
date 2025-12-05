lookup(you,i).
lookup(i,'why do you').
lookup(do,'no,').
lookup(are,'am not').
lookup(portuguese,russian).


eliza([], []).
eliza([Word|Rest], [NewWord|NewRest]) :-
    lookup(Word, NewWord), !,
    eliza(Rest, NewRest).
eliza([Word|Rest], [Word|NewRest]) :-
    eliza(Rest, NewRest).

printC([]).
printC([Word]):-
    write(Word).
printC([Word|Rest]):-
    write(Word),
    write(' '),
    printC(Rest).

interact:-
    nl,
    write('Ready> ' ),
    read(Call),
    response(Call),
    interact.

response(Call):-
    eliza(Call,Response),
    write('Eliza: '),
    printC(Response),
    nl.

