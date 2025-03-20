#include <iostream>
#include <string>
#include "Socio.h"
#include "DtFecha.h"
#include "DtMascota.h"
#include "DtConsulta.h"
#include "Consulta.h"
#include "Genero.h"
#include "DtPerro.h"
#include "DtGato.h"

using namespace std;

//TODOS LOS SOCIOS DEL SISTEMA
struct{
    Socio* Socio[MAX_SOCIOS];
    int topeU;
} coleccionSocios;


//OPERACION A
void registarSocio(string ci, string nombre, DtMascota& dtMascota){

}
//OPERACION B
void agregarMascota(string ci, DtMascota& dtMascota){}
//OPERACION C 
void ingresarConsulta(string motivo, string ci){}
//OPERACION D 
DtConsulta  verConsultasAntesDeFecha(DtFecha& fecha, string ciSocio, int& cantConsultas){}
//OPERACION E
void eliminarSocio(string ci){}
//OPERACION F
DtMascota  obtenerMascotas(string ci, int& cantMascotas){}


void registrarSocio(string ci, string nombre, DtMascota& dtMascota){

    dtMascota->setRacionDiaria(0);
    Socio* socio= new Socio(ci,nombre,dtMascota);
    coleccionSocios.socio[coleccionSocios.topeU]=socio;
    coleccionSocios.topeU++;
}
void registrarSocio(){

    //DECLARACION DE LAS VARIABLES UTILIZADAS 
    string ci,nombre,mnombre,genero,raza;
    float peso;
    bool vacunaCachorro;
    int menutipo,menugenero;
    Genero genero:
    DtGato dtgato;
    DtPerro dtperro;
    
    // MENU DE LOS DATOS DEL SOCIO CI Y NOMBRE
    cout << "_________________________________" << endl
    cout << "Ingresar Socio" << endl
    cout << "       Digitar Ci: " << endl
    cin >> ci; 
    cout << "       Digitar Nombre: " << endl
    cin >> nombre;
    // noExisteSocio(ci); //Funcion a implementar que chequee si existe un socio
  
    // MENU PARA INGRESAR UNA MASCOTA
    cout << "INGRESAR MASCOTA" << endl
    cout << "Tipo:" << endl
    cout << "1) Perro" << endl
    cout << "2) Gato" << endl
    cin >> menutipo;
    cout << "Nombre" << endl
    cin >> mnombre;
    cout >> "Seleccionar genero:" << endl
    cout >> "1) Hembra " >> endl
    cout >> "2) Macho "  >> endl
    cin >> menugenero
    switch(menugenero){
        case 1:
            genero=Macho;
        break;
        case 2:
            genero=Hembra;
        break;
        default: cout << "Genero Invalido " << endl
    }

    cout >> "Peso de la mascota? : " << endls
    cin >> peso;
    switch(menutipo){
        case 1: // En caso de que sea perro
                RazaPerro razzaperro;
                int menurazaperro;
                cout << "1)Raza del perro;"
                cout << "2)labrador"
                cout << "3)ovejero"
                cout << "4)bulldog"
                cout << "5)pitbull"
                cout << "6)collieo"
                cout << "7)pekines"
                cout << "8)otro"
                cin >> menurazaperro;
                switch(menurazaperro){
                    case 1
                }


                break;
        case 2: // En caso de que sea gato 
                break;
        default:
    }

}
void menu(){}

void menu(){
    system("clear");
    cout << "_____________________________________" << endl;
    cout << "Elija la Opcion:"
    cout << "   1) Registrar Socio"
    cout << "   2)Ingresar Consulta"
    cout << "   0)Salir"

}


int main(){
    coleccionUsuarios.topeU=0
    int menu;
    menu();
    cin >> menu;
    while (menu!=0){
        switch(menu){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 0:
                cout << "SALIENDO..." << endl;
                break;
            default:
                cout << "OPCION INVALIDA" << endl;
        }
        menu();
        cin >> menu;
        
    }
    
    return 0;
};