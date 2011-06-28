all:	test calc

BigN.o:	BigN.c
	gcc -c BigN.c

test.o:	test.c
	gcc -c test.c

test:	BigN.o test.o
	gcc -o test BigN.o test.o

calc.o:	calc.c
	gcc -c calc.c

calc: BigN.o calc.o
	gcc -o calc BigN.o calc.o

clean: 
	rm *.o test