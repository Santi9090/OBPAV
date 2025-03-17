#ifndef DT_GATO_H
#define DT_GATO_H

#include "DtMascota.h"
#include "TipoPelo.h"
#include "Genero.h"
using namespace std;

class DtGato : public DtMascota {
private:
    TipoPelo tipoPelo;
public:
    DtGato(const string& nombre, Genero genero, float peso, float racionDiaria, TipoPelo tipoPelo);
    TipoPelo getTipoPelo() const;
    void setTipoPelo(TipoPelo tipoPelo);
    ~DtGato();
};

#endif
