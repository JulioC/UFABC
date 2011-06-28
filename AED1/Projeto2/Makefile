all:	test

Tree.o:	Tree.c
	gcc -c Tree.c

test.o:	test.c
	gcc -c test.c

test:	Tree.o test.o
	gcc -o test Tree.o test.o

clean: 
	rm *.o test test.exe