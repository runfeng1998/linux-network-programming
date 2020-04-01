src = $(wildcard *.c)
obj = $(patsubst %.c, %.o, $(src))

all: server client

server:server.o wrap.o
	gcc $^ -o $@

client:client.o wrap.o
	gcc $^ -o $@

%.o:%.c
	gcc -c $< 

.PHONY: clean all
clean:
	rm *.o client server 
