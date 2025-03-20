#include "Gato.h"

Gato::Gato(){}

Gato::Gato(string nombre, Genero genero, float peso, float racionDiaria, TipoPelo tipoPelo): Mascota(nombre, genero, peso){
    this->tipoPelo = tipoPelo;
}
void Gato::setTipoPelo(TipoPelo tipoPelo){
    this->tipoPelo = tipoPelo;
}

TipoPelo Gato::getTipoPelo(){
    return this->tipoPelo;
}

Gato::~Gato(){}

float Gato::obtenerRacionDiaria(){
    return this->getPeso()*0.015;
}