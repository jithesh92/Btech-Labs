fib(A,B,C):-
	C>2,
	D is A+B,
	write(' '),
	write(D),
	F is C-1,
	fib(B,D,F).

main(A):-
	B is 1,
	write(B),
	write(' '),	
	write(B),
	fib(B,B,A).
