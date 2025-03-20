#ifndef SOCIO_H
#define SOCIO_H
#define CANT_CONSULTAS 20
#include <iostream>
#include <string>
#include "DtFecha.h"
#include "Consulta.h"
#define CANT_MASCOTAS

using namespace std; // Uso del espacio de nombres std

class Socio
{
    private: 
        string ci; 
        string Nombre;
        DtFecha fechaIngreso;
        Consulta* Consultas[CANT_CONSULTAS];
        int topeConsultas;
        Mascota* Mascotas[CANT_MASCOTAS];
        int topeMascotas;
    public:
        Socio();
        Socio(string ci, string Nombre, DtFecha fechaIngreso);
        void setCi(string ci);
        string getCi();
        void setNombre(string Nombre);
        string getNombre();
        void setFechaIngreso(DtFecha fechaIngreso);
        DtFecha getFechaIngreso();
        void agregarConsulta(Consulta*)
        ~Socio();
        Consulta** obtenerConslta(int&)
        void eliminarConsulta(consulta&)
};

#endif // SOCIO_H