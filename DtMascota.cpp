#include "DtMascota.h"
#include <iostream>
#include <string>

using namespace std;

DtMascota::DtMascota() {}
DtMascota::DtMascota(const string& nombre, Genero genero, float peso, float racionDiaria) {
    this->nombre = nombre;
    this->genero = genero;
    this->peso = peso;
    this->racionDiaria = racionDiaria;
}
string DtMascota::getNombre() const {
    return nombre;
}

Genero DtMascota::getGenero() const {
    return genero;
}

float DtMascota::getPeso() const {
    return peso;
}

float DtMascota::getRacionDiaria() const {
    return racionDiaria;
}

void DtMascota::setNombre(const string& nombre) {
    this->nombre = nombre;
}

void DtMascota::setGenero(Genero genero) {
    this->genero = genero;
}

void DtMascota::setPeso(float peso) {
    this->peso = peso;
}

void DtMascota::setRacionDiaria(float racionDiaria) {
    this->racionDiaria = racionDiaria;
}
DtMascota::~DtMascota() {}
