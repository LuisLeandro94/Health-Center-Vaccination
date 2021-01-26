all: listaCentros.o listaUtentes.o listaVacinas.o utente.o centroVacinacao.o vacina.o main.c
	gcc -g -o main.o utente.o  listaCentros.o centroVacinacao.o listaUtentes.o listaVacinas.o vacina.o main.c

listaCentros.o: centroVacinacao.o listaCentros.c
	gcc -g -o listaCentros.o centroVacinacao.o listaCentros.c -c 

listaVacinas.o: vacina.o listaVacinas.c
	gcc -g -o listaVacinas.o vacina.o listaVacinas.c -c

centroVacinacao.o: centroVacinacao.c
	gcc -g -o centroVacinacao.o centroVacinacao.c -c

listaUtentes.o: utente.o vacina.o listaUtentes.c
	gcc -g -o listaUtentes.o utente.o vacina.o listaUtentes.c -c

utente.o: utente.o vacina.o utente.c
	gcc -g -o utente.o vacina.o utente.c -c
vacina.o: vacina.c
	gcc -g -o vacina.o vacina.c -c

clean: 
	del vacina.o utente.o centroVacinacao.o listaVacinas.o listaCentros.o listaUtentes.o main.o

run:
	mingw32-make all
	./main.o