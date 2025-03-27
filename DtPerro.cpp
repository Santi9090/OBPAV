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

DtPerro::~DtPerro() {}