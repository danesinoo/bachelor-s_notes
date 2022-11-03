CC = gcc
OBJ = board.o giocatore.o partita.o main.c
TEST_OBJ = board.o giocatore.o tests.c

%.o: %.c
	${CC} -c $< -o $@

main: ${OBJ}
	${CC} ${OBJ} -o $@

test: ${TEST_OBJ}
	${CC} ${TEST_OBJ} -o $@

clear:
	rm *.o main