OBJS := server.o client.o pipe.o

all: ${OBJS}
	gcc server.o pipe.o -lpthread -o server
	gcc client.o pipe.o -lpthread -o client

%.o: %.c
	gcc -c -Wall -g -o $@ $<

clean:
	rm ${OBJS}
	rm server
	rm client

