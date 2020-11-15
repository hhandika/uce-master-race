CFLAGS=	-Wall -Werror
OBJS= main.o cli.o utils.o bead_cleanup_protocols.o
DEPS= utils.h cli.h
TARGET= bin/ucemr

%.O: %.c $(DEPS)
	$(CC) -c $< $(CFLAGS) -o $(TARGET)

ucemr: $(OBJS)
	$(CC) $^ $(CFLAGS) -o $(TARGET)

clean:
	rm *.o