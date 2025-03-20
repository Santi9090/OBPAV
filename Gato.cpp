#include "Gato.h"

Gato::Gato(){}

Gato::Gato(string& nombre, Genero genero, float peso, float racionDiaria, TipoPelo tipoPelo): Mascota(nombre, genero, peso, racionDiaria){
    this->tipoPelo = tipoPelo;
}

float Gato::obtenerRacionDiaria(){
    return this->racionDiaria;
}

void Gato::setTipoPelo(TipoPelo tipoPelo){
    this->tipoPelo = tipoPelo;
}

TipoPelo Gato::getTipoPelo() const{
    return this->tipoPelo;
}

Gato::~Gato(){}

float Gato::obtenerRacionDiaria(){
    return this->peso*0.015;
}