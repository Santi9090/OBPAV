#include "Socio.h"
#include <iostream>
#include <string>
using namespace std;

// Constructor sin parámetros
Socio::Socio() {}

// Constructor con parámetros
Socio::Socio(string ci, string Nombre, DtFecha fechaIngreso,Mascota * mascota)
{
    this->ci = ci;
    this->Nombre = Nombre;
    this->fechaIngreso = fechaIngreso;
    this->Mascotas[topeMascotas]=mascota;
    this->topeMascotas++;
}

// Setter para `ci`
void Socio::setCi(string ci)
{
    this->ci = ci;
}

// Getter para `ci`
string Socio::getCi()
{
    return this->ci;
}

// Setter para `Nombre`
void Socio::setNombre(string nombre)
{
    this->Nombre = nombre; // Asegúrate de que `Nombre` sea el nombre correcto de la variable miembro
}

// Getter para `Nombre`
string Socio::getNombre()
{
    return this->Nombre; // Usar `Nombre` en lugar de `nombre` (para que coincida con el miembro de la clase)
}

// Destructor (si lo necesitas, pero si no lo tienes, puedes eliminarlo)
Socio::~Socio()
{
    // Aquí podrías liberar recursos si fuera necesario, pero no es obligatorio en este caso
}

void Socio::setMascota(Mascota *mascota)
{
    this->Mascotas[this->topeMascotas] = mascota;
    this->topeMascotas++;
}
Mascota **Socio::getMascotas()
{
    return this->Mascotas;
}

Consulta **Socio::obtenerConsulta(int &cantSocios)
{
    int consultas = CANT_CONSULTAS;
    consultas = this->topeConsultas;
    return this->Consultas;
}
Consulta **Socio::eliminarConsulta(Consulta consulta) {}

void Socio::setTopeConsultas(int tope)
{

    this->topeConsultas = tope;
}
int Socio::getTopeConsultas()
{
    return this->topeConsultas;
}

void Socio::setTopeMascotas(int tope)
{
    this->topeMascotas = tope;
}
int Socio::getTopeMascotas()
{
    return this->topeMascotas;
}

void Socio::setConsulta(Consulta *consulta)
{
    this->Consultas[this->topeConsultas] = consulta;
    this->topeConsultas++;
}
Consulta **Socio::getConsultas()
{
    return this->Consultas;
}

Mascota *Socio::getMascota(int posicion)
{
    return this->Mascotas[posicion];
}

Consulta *Socio::getConsulta(int posicion)
{
    return this->Consultas[posicion];
}

// Metodo que retorna la cantidad de consultas antes de una fecha dada
int Socio::cantidadConsultasAntesDeFecha(DtFecha fecha)
{
    int f = 0;
    for (int i = 0; i < this->topeConsultas; i++)
    {
        if (fecha.getAnio() > this->getConsulta(i)->getFechaConsulta().getAnio())
            f++;
        else if (fecha.getAnio() == this->getConsulta(i)->getFechaConsulta().getAnio())
            if (fecha.getMes() > this->getConsulta(i)->getFechaConsulta().getMes())
                f++;
            else if (fecha.getMes() == this->getConsulta(i)->getFechaConsulta().getMes())
            {
                if (fecha.getDia() > this->getConsulta(i)->getFechaConsulta().getDia())
                    f++;
            }
        else
        {
        }
    }
    return f;
}
