#include "DtGato.h"
#include <iostream>
#include <string>
using namespace std;

DtGato::DtGato() {}
DtGato::DtGato(string nombre, Genero genero, float peso, float racionDiaria, TipoPelo tipoPelo)
    : DtMascota(nombre, genero, peso, racionDiaria), tipoPelo(tipoPelo) {}

TipoPelo DtGato::getTipoPelo() const {
    return tipoPelo;
}

void DtGato::setTipoPelo(TipoPelo tipoPelo) {
    this->tipoPelo = tipoPelo;
}
DtGato::~DtGato() {}
