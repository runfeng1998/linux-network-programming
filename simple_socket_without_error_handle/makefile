all:server client

server:server.o
	gcc $< -o $@

client:client.o
	gcc $< -o $@

%.o:%.c
	gcc -c $< 

clean:
	rm *.o client server 
