main: main.o rpn_calculator.o stack.o
	cc -o main main.c rpn_calculator.o stack.o
rpn_calculator.o: rpn_calculator.c rpn_calculator.h stack.o stack.h
	cc -c rpn_calculator.c
stack.o: stack.c stack.h
	cc -c stack.c
