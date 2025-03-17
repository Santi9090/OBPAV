#include "DtPerro.h"
#include <iostream>
#include <string>
using namespace std;

DtPerro::DtPerro(const string& nombre, Genero genero, float peso, float racionDiaria, razaPerro raza, bool vacunaCachorro)
    : DtMascota(nombre, genero, peso, racionDiaria), raza(raza), vacunaCachorro(vacunaCachorro) {}

razaPerro DtPerro::getRaza() const {
    return raza;
}

bool DtPerro::getVacunaCachorro() const {
    return vacunaCachorro;
}

void DtPerro::setRaza(razaPerro raza) {
    this->raza = raza;
}

void DtPerro::setVacunaCachorro(bool vacunaCachorro) {
    this->vacunaCachorro = vacunaCachorro;
}
DtPerro::~DtPerro() {}