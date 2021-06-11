main: main.o hardware.o funciones.o teclado.o user.o
	gcc main.o hardware.o funciones.o teclado.o user.o -o main -Wall -g

main.o: main.c hardware.h funciones.h teclado.h user.h
	gcc main.c -c -Wall

hardware.o: hardware.c hardware.h
	gcc hardware.c -c -Wall

funciones.o: funciones.c funciones.h
	gcc funciones.c -c -Wall

teclado.o: teclado.c teclado.h user.h funciones.h hardware.h
	gcc teclado.c -c -Wall

user.o: user.c user.h funciones.h
	gcc user.c -c -Wall

clean:
	rm *.o