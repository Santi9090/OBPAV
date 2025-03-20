#ifndef CONSULTA_H
#define CONSULTA_H
#include <iostream>
#include <string>
#include "DtFecha.h"

using namespace std;

class Consulta{
    private:
        DtFecha fechaConsulta;
        string  motivo;
    public:
        Consulta();
        Consulta(DtFecha fechaConsulta, string motivo);
        DtFecha getFechaConsulta();
        void setFechaConsulta(DtFecha fechaConsulta);
        string getMotivo;
        void setMotivo(string motivo);
        ~Consulta();


};
#endif // CONSULTA_H