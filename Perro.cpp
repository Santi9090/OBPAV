#include <Perro.h>

using namespace std;

Perro::Perro(): Mascota(){}

Perro::Perro(string& nombre, Genero genero, float peso, float racionDiaria, RazaPerro raza, bool vacunaCachorro): Mascota(nombre, genero, peso, racionDiaria){
    this->raza = raza;
    this->vacunaCachorro = vacunaCachorro;
}

void Perro::setRaza(RazaPerro raza){
    this->raza = raza;
}

RazaPerro Perro::getRaza(){
    return this->raza;
}

bool Perro::getVacunaCachorro(){
    return this->vacunaCachorro;
}

void Perro::setVacunaCachorro(bool vacunaCachorro){
    this->vacunaCachorro = vacunaCachorro;
}

Perro::~Perro(){}

float Perro::obtenerRacionDiaria(){
    return this->peso*0.025;
}