CFLAGS=	-Wall -Werror
OBJS= main.o utils.o bead_cleanup_protocols.o
DEPS= utils.h
TARGET= bin/ucemr

%.O: %.c $(DEPS)
	$(CC) -c $< $(CFLAGS) -o $(TARGET)

ucemr: $(OBJS)
	$(CC) $^ $(CFLAGS) -o $(TARGET)

clean:
	rm *.o