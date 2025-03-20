#include "Socio.h"
#include <iostream>
#include <string>
using namespace std;

// Constructor sin parámetros
Socio::Socio() {}

// Constructor con parámetros
Socio::Socio(string ci, string Nombre, DtFecha fechaIngreso) {
    this->ci = ci;
    this->Nombre = Nombre;
    this->fechaIngreso = fechaIngreso;
}

// Setter para `ci`
void Socio::setCi(string ci) {
    this->ci = ci;
}

// Getter para `ci`
string Socio::getCi() {
    return this->ci;
}

// Setter para `Nombre`
void Socio::setNombre(string nombre) {
    this->Nombre = nombre; // Asegúrate de que `Nombre` sea el nombre correcto de la variable miembro
}

// Getter para `Nombre`
string Socio::getNombre() {
    return this->Nombre; // Usar `Nombre` en lugar de `nombre` (para que coincida con el miembro de la clase)
}

// Destructor (si lo necesitas, pero si no lo tienes, puedes eliminarlo)
Socio::~Socio() {
    // Aquí podrías liberar recursos si fuera necesario, pero no es obligatorio en este caso
}

Consulta** Socio::obtenerConslta(int& cantSocios){
    cantConsultas=this->topeConsultas,
    retrun this->consulta;
}

void Socio::eliminarConsultas(){}