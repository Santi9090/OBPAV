#ifndef DT_FECHA_H
#define DT_FECHA_H
#include <iostream>
#include <string>

using namespace std; // Uso del espacio de nombres std
class DtFecha
{
private:
    int dia;
    int mes;
    int anio;
public:
    DtFecha();
    DtFecha(int dia, int mes, int anio);
    int getDia();
    void setDia(int dia);
    int getMes();
    void setMes(int mes);
    int getAnio();
    void setAnio(int anio);
    ~DtFecha();
};

#endif // DT_FECHA_H