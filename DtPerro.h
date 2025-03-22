#ifndef DT_PERRO_H
#define DT_PERRO_H

#include "DtMascota.h"
#include "RazaPerro.h"

class DtPerro : public DtMascota {
private:
    RazaPerro raza;
    bool vacunaCachorro;

public:
    DtPerro();
    DtPerro(string nombre,Genero genero, float peso, float racionDiaria, RazaPerro raza, bool vacunaCachorro);
    RazaPerro getRaza();
    bool getVacunaCachorro();
    void setRaza(RazaPerro raza);
    void setVacunaCachorro(bool vacunaCachorro);
    ~DtPerro();
};

#endif
