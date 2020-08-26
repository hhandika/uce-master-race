CFLAGS=	-Wall -Werror
OBJS= main.o utils.o bead_cleanup_protocols.o
TARGET= bin/ucemr


output: 
	$(CC) $(OBJS) $(CFLAGS) -o $(TARGET)

main.o: main.c
	$(CC) -c $< $(CFLAGS)

utils.o: utils.c utils.h
	$(CC) -c $< $(CFLAGS)

bead_cleanup_protocols.o: bead_cleanup_protocols.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm *.o