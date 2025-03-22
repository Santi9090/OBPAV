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
#define MAX_SOCIOS 999

using namespace std;

//TODOS LOS SOCIOS DEL SISTEMA
struct{
    Socio* socio[MAX_SOCIOS];
    int topeU;
} coleccionSocios;


//OPERACION A
//void registarSocio(string ci, string nombre, DtMascota& dtMascota){}
//OPERACION B
//void agregarMascota(string ci, DtMascota& dtMascota){}
//OPERACION C 
//void ingresarConsulta(string motivo, string ci){}
//OPERACION D 
//DtConsulta  verConsultasAntesDeFecha(DtFecha& fecha, string ciSocio, int& cantConsultas){}
//OPERACION E
//void eliminarSocio(string ci){}
//OPERACION F
//DtMascota  obtenerMascotas(string ci, int& cantMascotas){}


void registrarSocio(string ci, string nombre, DtMascota& dtMascota){
    int dia,mes,anio;
    cout << "Ingresar Fecha de Ingreso" << endl;
    cout << "Dia: " << endl;
    cin >> dia;
    cout << "Mes: " << endl;
    cin >> mes;
    cout << "Anio: " << endl;
    cin >> anio;
    DtFecha fechaIngreso = DtFecha(dia,mes,anio);
    fechaIngreso.setAnio(anio);
    fechaIngreso.setMes(mes);
    fechaIngreso.setDia(dia);
    dtMascota.setRacionDiaria(0);
    Socio* socio= new Socio(ci,nombre,fechaIngreso);
    coleccionSocios.socio[coleccionSocios.topeU]=socio;
    coleccionSocios.topeU++;
}
void registrarSocio(){

    //DECLARACION DE LAS VARIABLES UTILIZADAS 
    string ci,nombre,mnombre,genero,raza;
    float peso;
    bool vacunaCachorro;
    int menutipo,menugenero;
    DtGato dtgato = DtGato();
    DtPerro dtperro = DtPerro();
    
    // MENU DE LOS DATOS DEL SOCIO CI Y NOMBRE
    cout << "_________________________________" << endl;
    cout << "Ingresar Socio" << endl;
    cout << "       Digitar Ci: " << endl;
    cin >> ci; 
    cout << "       Digitar Nombre: " << endl;
    cin >> nombre;
    // noExisteSocio(ci); //Funcion a implementar que chequee si existe un socio
  
    // MENU PARA INGRESAR UNA MASCOTA
    cout << "INGRESAR MASCOTA" << endl;
    cout << "Tipo:" << endl;
    cout << "1) Perro" << endl;
    cout << "2) Gato" << endl;
    cin >> menutipo;
    cout << "Nombre" << endl;
    cout << "Seleccionar genero:" << endl;
    cout << "1  ) Hembra " << endl;
    cout << "2) Macho "  << endl;
    cin >> menugenero ;
    switch(menugenero){
        case 1:
            Genero genero=Macho;
        break;
        case 2:
            Genero genero1=Hembra;
        break;
        default: cout << "Genero Invalido " << endl;
    }

    cout >> "Peso de la mascota? : " << endl;
    cin >> peso;
    switch(menutipo){
        case 1: // En caso de que sea perro
                int menurazaperro;
                cout << "1)Raza del perro;" << endl;
                cout << "2)labrador" << endl;
                cout << "3)ovejero" << endl;
                cout << "4)bulldog" << endl;
                cout << "5)pitbull" << endl;
                cout << "6)collie" << endl;
                cout << "7)pekines" << endl;
                cout << "8)otro" << endl;
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
    cout << "Elija la Opcion:" << endl;
    cout << "   1) Registrar Socio" << endl;
    cout << "   2)Ingresar Consulta" << endl;
    cout << "   0)Salir" << endl;

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

void eliminarSocio(string ci) {
    int indice = -1;
    for (int i = 0; i < coleccionSocios.topeU; i++) {
        if (coleccionSocios.socio[i]->getCi() == ci) {
            indice = i;
            break;
        }
    }
    if (indice == -1) {
        throw invalid_argument("No existe un socio registrado con la cédula: " + ci);
    }
    Socio* socio = coleccionSocios.socio[indice];
    int cantConsultas;
    Consulta** consultas = socio->obtenerConslta(cantConsultas);
    for (int i = 0; i < cantConsultas; i++) {
        delete consultas[i];
    }
    for (int i = 0; i < CANT_MASCOTAS; i++) {
        if (socio->Mascotas[i] != nullptr) {
            delete socio->Mascotas[i];
        }
    }
    delete socio;
    for (int i = indice; i < coleccionSocios.topeU - 1; i++) {
        coleccionSocios.socio[i] = coleccionSocios.socio[i + 1];
    }
    coleccionSocios.topeU--;
    cout << "Socio con CI " << ci << " eliminado correctamente." << endl;
}