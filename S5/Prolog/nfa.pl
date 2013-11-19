final(q3).
tran(q0,_,q0).
tran(q0,1,q1).
tran(q1,1,q3).
tran(q1,0,q2).
tran(q2,_,q3).
accepts(State,[]):-
	final(State),
	nl,
	write('string accepted').

accepts(State,[X|Rest]):-
	tran(State,X,State1),
	accepts(State1,Rest).

main(A):-
accepts(q0,A).
