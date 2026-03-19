inventory: main.o inventory.o
	gcc main.o inventory.o -o inventory.exe

main.o: main.c inventory.h
	gcc -c main.c

inventory.o: inventory.c inventory.h
	gcc -c inventory.c

clean:
	del *.o inventory.exe