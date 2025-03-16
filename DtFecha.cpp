#include <DtFecha.h>
#include <iostream>
#include <string>

using namespace std;

DtFecha::DtFecha() : dia(1), mes(1), anio(2000) {}
DtFecha::DtFecha(int dia, int mes, int anio) : dia(dia), mes(mes), anio(anio) {}
int DtFecha::getDia() const {
     return dia; 
    }
int DtFecha::getMes() const {
     return mes; 
    }
int DtFecha::getAnio() const {
     return anio; 
    }