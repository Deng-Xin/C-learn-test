all:server client

server:server.c socket.c
	gcc -o server server.c socket.c -lpthread

client:client.c socket.c
	gcc -o client client.c socket.c -lpthread

.PHONY: clean
clean:
	rm *.o server client
