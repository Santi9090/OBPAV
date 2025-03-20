#ifndef MASCOTA_H
#define MASCOTA_H
#include <Genero.h>
#include <string>

using namespace std;

class Mascota{
    private:
        string nombre;
        Genero genero;
        peso float;
    public:
        Mascota();
        Mascota(string nombre, Genero genero, float peso);
        string getNombre();
        void setNombre(string nombre);
        Genero getGenero();
        void setGenero(Genero genero);
        float getPeso();
        void setPeso(float peso);
        ~Mascota();
        virtual float obtenerRacionDiaria() = 0;
}
#endif