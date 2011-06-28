all:	main

Lista.o:	Lista.c
	gcc -c Lista.c

main.o:	main.c
	gcc -c main.c

main:	Lista.o main.o
	gcc -o main Lista.o main.o

clean: 
	rm *.o main