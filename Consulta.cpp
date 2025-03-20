#include "Consulta.h"
#include <iostream>
#include <string>

using namespace std;

Consulta::Consulta(){}
Consulta::Consulta( DtFecha fechaConsulta, string motivo){
    this->fechaConsulta = DtFecha();
    this->motivo = "";
}

void Consulta::setFechaConsulta(DtFecha fechaConsulta){ // Cambio de DtFecha a DtFecha creo que esta mal 
    this->fechaConsulta = fechaConsulta;
}

DtFecha Consulta::getFechaConsulta(){   
    return this->fechaConsulta;
}

string Consulta::getMotivo(){
    return this->motivo;
}
void Consulta::setMotivo(string motivo){
    this->motivo= motivo;
}

Consulta::~Consulta(){}