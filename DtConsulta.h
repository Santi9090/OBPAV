#ifndef DT_CONSULTA_H
#define DT_CONSULTA_H

#include "DtFecha.h"
#include <string>
using namespace std;

class DtConsulta {
private:
    DtFecha fechaConsulta;
    string motivo;

public:
    DtConsulta();
    DtConsulta(DtFecha fechaConsulta, string motivo);
    DtFecha getFechaConsulta();
    string getMotivo();
    void setFechaConsulta(DtFecha fechaConsulta);
    void setMotivo(string motivo);
    ~DtConsulta();
};

#endif
