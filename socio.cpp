#include "socio.h"
#include <iostream>
#include <string>
using namespace std;   

Socio::Socio(){}
Socio::Socio( string ci, string Nombre, DtFecha fechaIngreso){ {
    this->ci = "";
    this->Nombre = "";
    this->fechaIngreso = DtFecha();
}

void Socio::setCi(string ci) {
    this->ci = ci;
}

string Socio::getCi(){
    return this->ci;
}

void Socio::setNombre(string nombre){
    this->nombre = nombre;
}

string Socio:getNombre(){
    return this->nombre;
}

