CC = gcc
OBJ = studenti_laureati.o main.c

%.o: %.c
	${CC} -c $< -o $@

main: ${OBJ}
	${CC} ${OBJ} -o $@

clear:
	rm *.o main