CFLAGS=	-Wall -Werror -Wextra -pedantic -o3 -std=c11
OBJS= main.o cli.o utils.o protocols.o pre_library.o lib_amp.o
DEPS= utils.h cli.h pre_library.h lib_amp.h
TARGET= bin/ucemr


%.O: %.c $(DEPS)
	$(CC) -c $< $(CFLAGS) -o $@

ucemr: $(OBJS)
	$(CC) $^ $(CFLAGS) -o $(TARGET)

clean:
	rm *.o

cleanall:
	rm *.o bin/ucemr