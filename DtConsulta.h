#ifndef DT_CONSULTA_H
#define DT_CONSULTA_H

#include "DtFecha.h"
#include <string>
using namespace std;

class DtConsulta {
private:
    DtFecha* fechaConsulta;
    string motivo;

public:
    DtConsulta(const DtFecha& fechaConsulta, const string& motivo);

    DtFecha getFechaConsulta() const;
    string getMotivo() const;

    void setFechaConsulta(const DtFecha& fechaConsulta);
    void setMotivo(const string& motivo);
    ~DtConsulta();
};

#endif
