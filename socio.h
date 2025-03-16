#ifndef SOCIO_H
#define SOCIO_H
#include <iostream>
#include <string>

use namespace std; // Uso del espacio de nombres std

class Socio
{
    private: 
        string ci; 
        string Nombre;
        DtFecha fechaIngreso;
    public:
        Socio();
        void setCi(string ci);
        string getCi();
        void setNombre(string Nombre);
        string getNombre();
        void setFechaIngreso(DtFecha fechaIngreso);
        DtFecha getFechaIngreso();
        ~Socio();

        
}


#endif // SOCIO_H
