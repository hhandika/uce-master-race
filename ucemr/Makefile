output: main.o utils.o bead_cleanup_protocols.o
	gcc main.o utils.o bead_cleanup_protocols.o -o bin/ucemr

main.o: main.c
	gcc -c main.c

utils.o: utils.c utils.h
	gcc -c utils.c

bead_cleanup_protocols.o: bead_cleanup_protocols.c
	gcc -c bead_cleanup_protocols.c

clean:
	rm *.o