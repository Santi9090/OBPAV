#ifndef GATO_H
#define GATO_H

#include "Mascota.h"
#include "TipoPelo.h"
#include <string>

using namespace std;

class Gato : public Mascota {
    private:
        TipoPelo tipoPelo;
    public:
        Gato();
        Gato(const string& nombre, Genero genero, float peso, float racionDiaria, TipoPelo tipoPelo);
        void setTipoPelo(TipoPelo tipoPelo);
        TipoPelo getTipoPelo();
        ~Gato();
        float obtenerRacionDiaria();
};


#endi   
