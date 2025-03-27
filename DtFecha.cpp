#include "DtFecha.h"
#include <iostream>
#include <string>

using namespace std;

DtFecha::DtFecha() {}
DtFecha::DtFecha(int dia, int mes, int anio)
{
     this->mes = mes;
     this->dia = dia;
     this->anio = anio;
}

int DtFecha::getDia()
{
     return this->dia;
}
int DtFecha::getMes()
{
     return this->mes;
}

int DtFecha::getAnio()
{
     return this->anio;
}

DtFecha::~DtFecha() {}
