#ifndef DT_PERRO_H
#define DT_PERRO_H

#include "DtMascota.h"
#include "razaPerro.h"

class DtPerro : public DtMascota {
private:
    razaPerro raza;
    bool vacunaCachorro;

public:
    DtPerro(const string& nombre, Genero genero, float peso, float racionDiaria, razaPerro raza, bool vacunaCachorro);
    razaPerro getRaza() const;
    bool getVacunaCachorro() const;
    void setRaza(razaPerro raza);
    void setVacunaCachorro(bool vacunaCachorro);
    ~DtPerro();
};

#endif
