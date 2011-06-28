all:	main

Chamadas.o:	Chamadas.c
	gcc -c Chamadas.c

main.o:	main.c
	gcc -c main.c

main:	Chamadas.o main.o
	gcc -o main Chamadas.o main.o

clean: 
	rm *.o main main.exe