#include <iostream>
#include <string>
#include "socio.h"
using namespace std;

int menu=9; // Variable que almacena la opción del menú

Socio* psocio = new Socio("1234567" , "Juan", DtFecha(1,1,2020)); // Creación de un objeto de la clase Socio


do
{
    cout << "Bienvenido!" << endl
    cout << "Elija La Opcion:" << endl
    cout << "    1)Registrar Socio" << endl
    cout << "    2)Agregar Mascota" << endl
    cout << "    3)Ingresar consulta" endl
    cout << "    0)Salir" << endl
switch (menu) // Estructura de control switch del menu
{
case menu == 1:
    break;
case menu == 2:
    break;
case menu == 3:
break;
case menu == 4:
    break;
default:
    cout << "Opción no válida" << endl;
    break;
}


} while (meun != 0); // Bucle que se ejecuta mientras la opción del menú sea diferente de 0