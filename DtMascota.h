#ifndef DT_MASCOTA_H
#define DT_MASCOTA_H
#include <string>

class DtMascota {
private:
    string nombre;
    Genero genero;
    float peso;
    float racionDiaria;

public:

    DtMascota(const string& nombre, Genero genero, float peso, float racionDiaria);
    string getNombre() const;
    Genero getGenero() const;
    float getPeso() const;
    float getRacionDiaria() const;
    void setNombre(const string& nombre);
    void setGenero(Genero genero);
    void setPeso(float peso);
    void setRacionDiaria(float racionDiaria);
    ~DtMascota();
};

#endif