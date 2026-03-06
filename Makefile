CC=gcc
CFLAGS=-Wall -Wextra -Iinclude
SRC=src/main.c src/server.c src/request.c src/response.c src/logger.c src/router.c
OUT=build/server

all:
	mkdir -p build
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

run: all
	./$(OUT)

clean:
	rm -rf build
