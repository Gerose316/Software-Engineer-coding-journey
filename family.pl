lookup(Var,[bind(Var,Value)| _ ],Value).
lookup(Var,[ _ |Rest],Value) :- lookup(Var,Rest,Value).

val2(plus(X,Y),B,Value) :-
    val2(X,B,XValue),
    val2(Y,B,YValue),
    Value is XValue + YValue.
val2(sub(X,Y),B,Value) :-
    val2(X,B,XValue),
    val2(Y,B,YValue),
    Value is XValue - YValue.
val2(times(X,Y),B,Value) :-
    val2(X,B,XValue),
    val2(Y,B,YValue),
    Value is XValue * YValue.
val2(div(X,Y),B,Value) :-
    val2(X,B,XValue),
    val2(Y,B,YValue),
    Value is XValue / YValue.
val2(const(X),_,Value):-Value is X.
val2(var(X),B,Value) :-
    lookup(X,B,Value).
val2(let(X,Exp1,Exp2),B,Value) :-
    val2(Exp1,B,XValue),
    val2(Exp2,[bind(X,XValue)|B],Value).
