CC = gcc

%.o: %.c
	${CC} -c $< -o $@

test_pila: pila.o main_pila.c
	${CC} pila.o main_pila.c -o $@

test_vector: vector.o main_vector.c
	${CC} vector.o main_vector.c -o $@

test_lista: lista.o main_lista.c
	${CC} lista.o main_lista.c -o $@

clear:
	rm *.o test_*
