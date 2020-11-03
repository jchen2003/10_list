all : main.o construction.o
	gcc -o construction main.o construction.o

main.o: main.c construction.h
	gcc -c main.c

construction.o: construction.c
	gcc -c construction.c

run:
	./construction

clean:
	rm *.o