#include "DtConsulta.h"
#include <iostream>
#include <string>
using namespace std;

DtConsulta::DtConsulta(const DtFecha& fechaConsulta, const string& motivo)
    : fechaConsulta(fechaConsulta), motivo(motivo) {}

DtFecha DtConsulta::getFechaConsulta() const {
    return fechaConsulta;
}

string DtConsulta::getMotivo() const {
    return motivo;
}

void DtConsulta::setFechaConsulta(const DtFecha& fechaConsulta) {
    this->fechaConsulta = fechaConsulta;
}

void DtConsulta::setMotivo(const string& motivo) {
    this->motivo = motivo;
}
DtConsulta::~DtConsulta() {}
