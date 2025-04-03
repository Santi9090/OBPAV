#include "DtPerro.h"
#include <iostream>
#include <string>
using namespace std;

DtPerro::DtPerro():DtMascota(){}
DtPerro::DtPerro(string nombre, Genero genero, float peso, float racionDiaria, RazaPerro raza, bool vacunaCachorro)
    : DtMascota(nombre, genero, peso, racionDiaria),raza(raza),vacunaCachorro(vacunaCachorro) {}

RazaPerro DtPerro::getRaza() const{
    return raza;
}

bool DtPerro::getVacunaCachorro()const{
    return vacunaCachorro;
}

DtPerro::~DtPerro() {}