 all: main.out 

 main.out: main.c swimming.o dynArr.o
	gcc main.c swimming.o dynArr.o -o main.out
	./main.out

swimming.o: swimming.c swimming.h
	gcc -c swimming.c -o swimming.o

dynArr.o: dynArr.c dynArr.h
	gcc -c dynArr.c -o dynArr.o

clean:
	rm -f *.o *.out