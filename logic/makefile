CC=gcc

all: logic tests build

.PHONY: logic tests build

logic:
	$(CC) -c src/logic.c -o ../build/logic.o

tests:
	$(MAKE) -C tests all

build:
	$(MAKE) -C build all
