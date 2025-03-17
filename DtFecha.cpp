#include <DtFecha.h>
#include <iostream>
#include <string>

using namespace std;

DtFecha::DtFecha(){}
DtFecha::DtFecha( int dia, int mes , int anio){
     this->fecha=fecha;
     this->dia=dia;
     this->anio=anio;
}

int DtFecha::getDia() const {
     return dia; 
    }
int DtFecha::getMes() const {
     return mes; 
    }
int DtFecha::getAnio() const {
     return anio; 
    }
    