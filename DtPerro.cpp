#include "DtPerro.h"
#include <iostream>
#include <string>
using namespace std;

DtPerro::DtPerro():DtMascota(){}
DtPerro::DtPerro(string nombre, Genero genero, float peso, float racionDiaria, RazaPerro raza, bool vacunaCachorro)
    : DtMascota(nombre, genero, peso, racionDiaria){}

RazaPerro DtPerro::getRaza(){
    return raza;
}

bool DtPerro::getVacunaCachorro(){
    return vacunaCachorro;
}

void DtPerro::setRaza(RazaPerro raza) {
    this->raza = raza;
}

void DtPerro::setVacunaCachorro(bool vacunaCachorro) {
    this->vacunaCachorro = vacunaCachorro;
}
DtPerro::~DtPerro() {}