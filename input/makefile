CC=gcc

all: input tests build

.PHONY: input tests build

input:
	$(CC) -c src/input.c -o ../build/input.o

tests:
	$(MAKE) -C tests all

build:
	$(MAKE) -C build all
