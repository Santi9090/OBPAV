main: DtConsulta.o DtFecha.o DtGato.o DtPerro.o DtMascota.o Gato.o Perro.o Mascota.o Consulta.o Socio.o main.o 
	g++ DtConsulta.o DtFecha.o DtGato.o DtPerro.o DtMascota.o  Gato.o Perro.o Mascota.o Consulta.o Socio.o main.o -o exec
main.o: main.cpp

DtConsulta.o: DtConsulta.cpp

DtFecha.o: DtFecha.cpp

DtGato.o: DtGato.cpp

DtPerro.o: DtPerro.cpp

DtMascota.o: DtMascota.cpp

Gato.o: Gato.cpp

Perro.o: Perro.cpp

Mascota.o: Mascota.cpp

Consulta.o: Consulta.cpp

Socio.o: Socio.cpp


clean:
	rm -rf *.o exec
	clear