CC = gcc

CFLAGS = -c -O0  -I/home/$(USER)/local/include/ -I/usr/include/

CFLAGSDEBUG = -g -Wall -c -I/home/$(USER)/local/include/ -I/usr/include/

LFLAGS = -lm  


functions:	
	$(CC) $(CFLAGS) $@.c -o $@.o
senx:  
	echo  compilando $@.c
	$(CC) $(CFLAGS) $@.c -o $@.o
	$(CC) functions.o $@.o $	(LFLAGS)  -lm -o  $@.x		
cosx:
	echo  compilando $@.c
	$(CC) $(CFLAGS) $@.c -o $@.o
	$(CC) functions.o $@.o $(LFLAGS)  -lm -o  $@.x

calculadora:
	echo  compilando $@.c
	$(CC) $(CFLAGS) $@.c -o $@.o
	$(CC) functions.o $@.o $(LFLAGS)  -lm -o  $@.x

escribir_archivos:
	echo  compilando $@.c
	$(CC) $(CFLAGS) $@.c -o $@.o
	$(CC) $@.o $(LFLAGS)  -lm -o  $@.x

precedencia_operadores:
	echo  compilando $@.c
	$(CC) $(CFLAGS) $@.c -o $@.o
	$(CC) $@.o $(LFLAGS)  -lm -o  $@.x

primos:
	echo  compilando $@.c
	$(CC) $(CFLAGS) $@.c -o $@.o
	$(CC) $@.o $(LFLAGS)  -lm -o  $@.x

masa_relativista:
	echo  compilando $@.c
	$(CC) $(CFLAGS) $@.c -o $@.o
	$(CC) functions.o $@.o $(LFLAGS)  -lm -o  $@.x

aprox_pi:
	echo 	 compilando $@.c
	$(CC) $(CFLAGS) $@.c -o $@.o
	$(CC) $@.o $(LFLAGS)  -lm -o  $@.x

localidad_temporal:
		echo  compilando $@.c
		$(CC) $(CFLAGS) $@.c -o $@.o
		$(CC) $@.o $(LFLAGS)  -lm -o  $@.x

cputime_operacion_vectores:
		echo  compilando $@.c
		$(CC) $(CFLAGS) $@.c -o $@.o
		$(CC) $@.o $(LFLAGS)  -lm -o  $@.x

localidad_espacial:
		echo  compilando $@.c
		$(CC) $(CFLAGS) $@.c -o $@.o
		$(CC) $@.o $(LFLAGS)  -lm -o  $@.x

multiplicacion_matrices:
		echo  compilando $@.c
		$(CC) $(CFLAGS) $@.c -o $@.o
		$(CC) $@.o $(LFLAGS)  -lm -o  $@.x

pippeling:		
	echo  compilando $@.c
	$(CC) $(CFLAGS) $@.c -o $@.o	
	$(CC) $@.o $(LFLAGS)  -lm -o  $@.x
debug: 
	echo Estoy compilando para debugear $@.c
	$(CC) $(CFLAGSDEBUG) $@.c -o $@.o
	$(CC) $@.o $(LFLAGS)  -o $@.x


clean:
	rm -rf *.~
	rm -rf *.out
	rm -rf *#
	rm -rf *.o
	rm -rf *.a
	rm -rf *.so
	rm *.x
