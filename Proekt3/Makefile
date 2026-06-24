 all: main.out 

 main.out: main.c swimming.o linkedlist.o
	gcc main.c swimming.o linkedlist.o -o main.out
	./main.out

swimming.o: swimming.c swimming.h
	gcc -c swimming.c -o swimming.o

linkedlist.o: linkedlist.c linkedlist.h
	gcc -c linkedlist.c -o linkedlist.o

clean:
	rm -f *.o *.out