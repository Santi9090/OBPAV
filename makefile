main: DtConsulta.o DtFecha.o Socio.o Gato.o Perro.o Mascota.o Consulta.o  main.o 
	g++ DtConsulta.o DtFecha.o  Socio.o  Gato.o Perro.o Mascota.o Consulta.o main.o -o exec
main.o: main.cpp

DtConsulta.o: DtConsulta.cpp

DtFecha.o: DtFecha.cpp

DtGato.o: DtGato.cpp

DtMascota.o: DtMascota.cpp

DtPerro.o: DtPerro.cpp

Gato.o: Gato.cpp

Mascota.o: Mascota.cpp

Perro.o: Perro.cpp

Consulta.o: Consulta.cpp

Socio.o: Socio.cpp


clean:
	rm -rf *.o exec
	clear