main: DtConsulta.o DtFecha.o Socio.o main.o 
	g++ DtConsulta.o DtFecha.o  Socio.o main.o -o exec
main.o: main.cpp

DtConsulta.o: DtConsulta.cpp

DtFecha.o: DtFecha.cpp

DtGato.o: DtGato.cpp

DtMascota.o: DtMascota.cpp

DtPerro.o: DtPerro.cpp

#genero.o: Genero.cpp

#RazaPerro.o: RazaPerro.cpp

Socio.o: Socio.cpp

TipoPelo.o: TipoPelo.cpp

clean:
	rm -rf *.o exec
	clear