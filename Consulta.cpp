#include "Consulta.h"
#include <iostream>
#include <string>

using namespace std;

Consulta::Consulta(){}
Consulta::Consulta( DtFecha fechaConsulta, string motivo){
    this->fechaConsulta = DtFecha();
    this->motivo = "";
}

Consulta::setFechaConsulta(DtFecha fechaConsulta){ // Cambio de DtFecha a DtFecha creo que esta mal 
    this->fechaConsulta = fechaConsulta;
}

Consulta::getFechaConsulta(){
    return this->fechaConsulta;
}

Consulta::getMotivo(){
    return this->motivo;
}
Consulta::setMotivo(string motivo){
    this->motivo= motivo;
}

Consulta::~Consulta(){}