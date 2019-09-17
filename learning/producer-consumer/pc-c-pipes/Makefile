# Muito simples, apenas para nao precisar rodar o comando inteiro do gcc
# everytime

CC := gcc
CFLAGS := -pthread -Wall -O0 -pg

all: main

main: main.c
	${CC} main.c pipe.c ${CFLAGS} -o main
