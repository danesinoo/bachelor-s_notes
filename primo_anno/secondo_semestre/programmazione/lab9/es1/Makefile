CC = gcc

%.o: %.c
	${CC} -c $< -o $@

test_studente: studente.o test_studente.c
	${CC} studente.o test_studente.c -o $@

test_corso: corso.o studente.o test_corso.c
	${CC} corso.o studente.o test_corso.c -o $@

test_parser: corso.o studente.o parser.o test_parser.c
	${CC} corso.o studente.o parser.o test_parser.c -o $@

clear:
	rm *.o