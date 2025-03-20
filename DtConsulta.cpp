#include "DtConsulta.h"
#include <iostream>
#include <string>
using namespace std;

DtConsulta::DtConsulta() {}
DtConsulta::DtConsulta(DtFecha fechaConsulta, string motivo){
    this->fechaConsulta = fechaConsulta;
    this->motivo = motivo;
}
DtFecha DtConsulta::getFechaConsulta()  {
    return fechaConsulta;
}

string DtConsulta::getMotivo() {
    return motivo;
}

void DtConsulta::setFechaConsulta(DtFecha fechaConsulta) {
    this->fechaConsulta = fechaConsulta;
}

void DtConsulta::setMotivo( string motivo) {
    this->motivo = motivo;
}
DtConsulta::~DtConsulta() {}