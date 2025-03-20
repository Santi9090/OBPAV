#ifndef PERRO_H
#define PERRO_H

#include "Mascota.h"
#include "RazaPerro.h"
#include <string>

using namespace std;

class Perro : public Mascota {
    private:
        RazaPerro raza;
        bool vacunaCachorro;
    public:
        Perro();
        Perro(string nombre, Genero genero, float peso, float racionDiaria, RazaPerro raza, bool vacunaCachorro);
        void setRaza(RazaPerro raza);
        RazaPerro getRaza();
        bool getVacunaCachorro();
        void setVacunaCachorro(bool vacunaCachorro);
        ~Perro();
        float obtenerRacionDiaria();
};

#endif