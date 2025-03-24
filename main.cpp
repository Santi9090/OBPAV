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
#include "Mascota.h"
#include "Perro.h"
#include "Gato.h"
#define MAX_SOCIOS 10
#include <unistd.h>
using namespace std;

// TODOS LOS SOCIOS DEL SISTEMA
struct
{
    Socio *socio[MAX_SOCIOS];
    int topeU;
} coleccionSocios;

// OPERACION A
// void registarSocio(string ci, string nombre, DtMascota& dtMascota){}
// OPERACION B
// void agregarMascota(string ci, DtMascota& dtMascota){}
// OPERACION C
// void ingresarConsulta(string motivo, string ci){}
// OPERACION D
// DtConsulta  verConsultasAntesDeFecha(DtFecha& fecha, string ciSocio, int& cantConsultas){}
// OPERACION E
// void eliminarSocio(string ci){}
// OPERACION F
// DtMascota  obtenerMascotas(string ci, int& cantMascotas){}

bool existesocio(string ci)
{
    for (int i = 0; i < coleccionSocios.topeU; i++)
    {
        if (coleccionSocios.socio[i]->getCi() == ci)
        {
            return true;
        }
    }
    return false;
}

void registrarSocio(string ci, string nombre, DtMascota &mascota)
{
    int dia, mes, anio;
    cout << "Ingresar Fecha de Ingreso" << endl;
    cout << "Dia: " << endl;
    cin >> dia;
    cout << "Mes: " << endl;
    cin >> mes;
    cout << "Año: " << endl;
    cin >> anio;
    DtFecha fechaIngreso = DtFecha(dia, mes, anio);
    fechaIngreso.setAnio(anio);
    fechaIngreso.setMes(mes);
    fechaIngreso.setDia(dia);
    Socio *socio = new Socio(ci, nombre, fechaIngreso);
    coleccionSocios.socio[coleccionSocios.topeU] = socio;
    coleccionSocios.socio[coleccionSocios.topeU]->setTopeConsultas(0);
    coleccionSocios.socio[coleccionSocios.topeU]->setTopeMascotas(0);
    try
    {
        cout << "entro al try" << endl;
        DtPerro &dtperro = dynamic_cast<DtPerro &>(mascota);
        Perro *perro = new Perro(dtperro.getNombre(), dtperro.getGenero(), dtperro.getPeso(), dtperro.getRacionDiaria(), dtperro.getRaza(), dtperro.getVacunaCachorro());
        coleccionSocios.socio[coleccionSocios.topeU]->setMascota(perro);
        cout << "Mascota añadida: " << perro->getNombre() << " al socio " << nombre << endl;
        sleep(3);
    }
    catch (bad_cast)
    {
        try
        {
            DtGato &dtgato = dynamic_cast<DtGato &>(mascota);
            Gato *gato = new Gato(dtgato.getNombre(), dtgato.getGenero(), dtgato.getPeso(), dtgato.getRacionDiaria(), dtgato.getTipoPelo());
            cout << "Mascota añadida: " << gato->getNombre() << " al socio " << nombre << endl;
            coleccionSocios.socio[coleccionSocios.topeU]->setMascota(gato);

            sleep(3);
        }
        catch (bad_cast)
        {
        }
    }
    coleccionSocios.topeU++;
}
void registrarSocio()
{

    // DECLARACION DE LAS VARIABLES UTILIZADAS
    string ci, nombre, mnombre, raza;
    float peso;
    bool vacunaCachorro;
    int menutipo, menugenero, menuvacuna;
    DtGato dtgato = DtGato();
    DtPerro dtperro = DtPerro();
    Genero genero;
    RazaPerro razaperro;
    TipoPelo tipopelo;

    // MENU DE LOS DATOS DEL SOCIO CI Y NOMBRE
    cout << "_________________________________" << endl;
    cout << "Ingresar Socio" << endl;
    cout << "       Digitar Ci: " << endl;
    cin >> ci;
    cout << "       Ingresar Nombre: " << endl;
    cin >> nombre;
    // noExisteSocio(ci); //Funcion a implementar que chequee si existe un socio

    // MENU PARA INGRESAR UNA MASCOTA
    cout << "INGRESAR MASCOTA" << endl;
    cout << "Tipo:" << endl;
    cout << "1) Perro" << endl;
    cout << "2) Gato" << endl;
    cin >> menutipo;

    // DIGITAR NOMBRE DE LA MASCOTA
    cout << "Nombre de la Mascota" << endl;
    cin >> mnombre;

    // MENU PARA SELECCIONAR GENERO
    cout << "Seleccionar genero:" << endl;
    cout << "1) Hembra " << endl;
    cout << "2) Macho " << endl;
    cin >> menugenero;
    do
    {
        if (menugenero == 1)
        {
            genero = Macho;
        }
        else if (menugenero == 2)
        {
            genero = Hembra;
        }
        else
        {
            cout << "Invalido " << endl;
        }
    } while (menugenero != 1 && menugenero != 2);

    // MENU PARA SELECCIONAR PESO DE LA MASCOTA
    cout << "Peso de la mascota? : " << endl;
    cin >> peso;

    // SWITCH QUE DEPENDE DE SI ES PERRO O GATO
    switch (menutipo)
    {
    case 1:
    { // En caso de que sea perro
        int menurazaperro;

        cout << "Raza del perro:" << endl;
        cout << "1)labrador" << endl;
        cout << "2)ovejero" << endl;
        cout << "3)bulldog" << endl;
        cout << "4)pitbull" << endl;
        cout << "5)collie" << endl;
        cout << "6)pekines" << endl;
        cout << "7)otro" << endl;
        cin >> menurazaperro;

        switch (menurazaperro)
        {
        case 1:
        {
            razaperro = labrador;
            break;
        }
        case 2:
        {
            razaperro = ovejero;
            break;
        }
        case 3:
        {
            razaperro = bulldog;
            break;
        }
        case 4:
        {
            razaperro = pitbull;
            break;
        }
        case 5:
        {
            razaperro = collie;
            break;
        }
        case 6:
        {
            razaperro = pekines;
            break;
        }
        case 7:
        {
            razaperro = otro;
        }
        default:
            cout << "Raza Invalid" << endl;
            break;
        }
        cout << "Tiene vacuna ? " << endl;
        cout << "1-Si" << endl;
        cout << "2-No" << endl;
        cin >> menuvacuna;
        switch (menuvacuna)
        {
        case 1:
            vacunaCachorro = true;
            break;
        case 2:
            vacunaCachorro = false;
            break;
        default:
            break;
        }
        DtPerro dtperro = DtPerro(mnombre, genero, peso, 0, razaperro, vacunaCachorro);

        registrarSocio(ci, nombre, dtperro);
        break;
    }
    case 2:
    { // En caso de que sea gato
        int menutipopelo;
        do
        {
            cout << "Seleccionar tipo de pelo: " << endl;
            cout << "1-Corto" << endl;
            cout << "2-Mediano" << endl;
            cout << "3-Largo" << endl;
            cin >> menutipopelo;

            if (menutipopelo == 1)
                tipopelo = Corto;
            else if (menutipopelo == 2)
                tipopelo = Mediano;
            else if (menutipopelo == 3)
                tipopelo = Largo;
            else
                cout << "INVALIDO " << endl;

        } while (menutipopelo != 1 && menutipopelo != 2 && menutipopelo != 3);

        DtGato dtgato = DtGato(mnombre, genero, peso, 0, tipopelo);
        registrarSocio(ci, nombre, dtgato);
        break;
    }
    default:
        cout << "INVALIDO" << endl;
        break;
    }
}

void agregarMascota(string ci, DtMascota &dtMascota)
{
    int f;
    if (existesocio(ci))
    {
        for (int i = 0; i < coleccionSocios.topeU; i++)
            if (coleccionSocios.socio[i]->getCi() == ci)
                f = i;
        if (CANT_MASCOTAS > coleccionSocios.socio[f]->getTopeMascotas())
        {
            try
            {
                cout << "entro al try" << endl;
                DtPerro &dtperro = dynamic_cast<DtPerro &>(dtMascota);
                Perro *perro = new Perro(dtperro.getNombre(), dtperro.getGenero(), dtperro.getPeso(), dtperro.getRacionDiaria(), dtperro.getRaza(), dtperro.getVacunaCachorro());
                coleccionSocios.socio[f]->setMascota(perro);
                cout << "Mascota añadida: " << perro->getNombre() << " al socio " << coleccionSocios.socio[f]->getNombre() << endl;
                sleep(3);
            }
            catch (bad_cast)
            {
                try
                {
                    DtGato &dtgato = dynamic_cast<DtGato &>(dtMascota);
                    Gato *gato = new Gato(dtgato.getNombre(), dtgato.getGenero(), dtgato.getPeso(), dtgato.getRacionDiaria(), dtgato.getTipoPelo());
                    cout << "Mascota añadida: " << gato->getNombre() << " al socio " << coleccionSocios.socio[f]->getNombre() << endl;
                    coleccionSocios.socio[f]->setMascota(gato);
                    sleep(3);
                }
                catch (bad_cast)
                {
                }
            }
        }
        else
            cout << "SE INGRESO EL NUMERO MAXIMO DE MASCOTAS" << endl;
    }
    else
    {
        cout << "NO EXISTE EL SOCIO" << endl;
        sleep(3);
    }
}

void agregarMascota()
{

    // DECLARACION DE LAS VARIABLES UTILIZADAS
    string ci, nombre, mnombre, raza;
    float peso;
    bool vacunaCachorro;
    int menutipo, menugenero, menuvacuna;
    DtGato dtgato = DtGato();
    DtPerro dtperro = DtPerro();
    Genero genero;
    RazaPerro razaperro;
    TipoPelo tipopelo;

    // MENU DE LOS DATOS DEL SOCIO CI Y NOMBRE
    cout << "_________________________________" << endl;
    cout << "Socio A ingresar Mascota  " << endl;
    cout << "       Digitar Ci: " << endl;
    cin >> ci;
    if (existesocio(ci))
    {
        // MENU PARA INGRESAR UNA MASCOTA
        cout << "INGRESAR MASCOTA" << endl;
        cout << "Tipo:" << endl;
        cout << "1) Perro" << endl;
        cout << "2) Gato" << endl;
        cin >> menutipo;

        // DIGITAR NOMBRE DE LA MASCOTA
        cout << "Nombre de la Mascota" << endl;
        cin >> mnombre;

        // MENU PARA SELECCIONAR GENERO
        cout << "Seleccionar genero:" << endl;
        cout << "1) Hembra " << endl;
        cout << "2) Macho " << endl;
        cin >> menugenero;
        do
        {
            if (menugenero == 1)
            {
                genero = Macho;
            }
            else if (menugenero == 2)
            {
                genero = Hembra;
            }
            else
            {
                cout << "Invalido " << endl;
            }
        } while (menugenero != 1 && menugenero != 2);

        // MENU PARA SELECCIONAR PESO DE LA MASCOTA
        cout << "Peso de la mascota? : " << endl;
        cin >> peso;

        // SWITCH QUE DEPENDE DE SI ES PERRO O GATO
        switch (menutipo)
        {
        case 1:
        { // En caso de que sea perro
            int menurazaperro;

            cout << "Raza del perro:" << endl;
            cout << "1)labrador" << endl;
            cout << "2)ovejero" << endl;
            cout << "3)bulldog" << endl;
            cout << "4)pitbull" << endl;
            cout << "5)collie" << endl;
            cout << "6)pekines" << endl;
            cout << "7)otro" << endl;
            cin >> menurazaperro;

            switch (menurazaperro)
            {
            case 1:
            {
                razaperro = labrador;
                break;
            }
            case 2:
            {
                razaperro = ovejero;
                break;
            }
            case 3:
            {
                razaperro = bulldog;
                break;
            }
            case 4:
            {
                razaperro = pitbull;
                break;
            }
            case 5:
            {
                razaperro = collie;
                break;
            }
            case 6:
            {
                razaperro = pekines;
                break;
            }
            case 7:
            {
                razaperro = otro;
            }
            default:
                cout << "Raza Invalid" << endl;
                break;
            }
            cout << "Tiene vacuna ? " << endl;
            cout << "1-Si" << endl;
            cout << "2-No" << endl;
            cin >> menuvacuna;
            switch (menuvacuna)
            {
            case 1:
                vacunaCachorro = true;
                break;
            case 2:
                vacunaCachorro = false;
                break;
            default:
                break;
            }
            DtPerro dtperro = DtPerro(mnombre, genero, peso, 0, razaperro, vacunaCachorro);

            agregarMascota(ci, dtperro);
            break;
        }
        case 2:
        { // En caso de que sea gato
            int menutipopelo;
            do
            {
                cout << "Seleccionar tipo de pelo: " << endl;
                cout << "1-Corto" << endl;
                cout << "2-Mediano" << endl;
                cout << "3-Largo" << endl;
                cin >> menutipopelo;

                if (menutipopelo == 1)
                    tipopelo = Corto;
                else if (menutipopelo == 2)
                    tipopelo = Mediano;
                else if (menutipopelo == 3)
                    tipopelo = Largo;
                else
                    cout << "INVALIDO " << endl;

            } while (menutipopelo != 1 && menutipopelo != 2 && menutipopelo != 3);

            DtGato dtgato = DtGato(mnombre, genero, peso, 0, tipopelo);
            agregarMascota(ci, dtgato);
            break;
        }
        default:
            cout << "INVALIDO" << endl;
            break;
        }
    }
    else
    {
        cout << "NO EXISTE EL SOCIO" << endl;
    }
}

void ingresarConsulta(string motivo, string ci)
{
    // CREAR DTFECHA
    int dia, mes, anio;
    cout << "Ingresar Fecha de Ingreso" << endl;
    cout << "Dia: " << endl;
    cin >> dia;
    cout << "Mes: " << endl;
    cin >> mes;
    cout << "Año: " << endl;
    cin >> anio;
    DtFecha fechaIngreso = DtFecha(dia, mes, anio);
    fechaIngreso.setAnio(anio);
    fechaIngreso.setMes(mes);
    fechaIngreso.setDia(dia);

    Consulta *consulta = new Consulta(fechaIngreso, motivo);
    for (int i = 0; i < coleccionSocios.topeU; i++)
    {
        if (coleccionSocios.socio[i]->getCi() == ci)
        {
            coleccionSocios.socio[i]->setConsulta(consulta);
            cout << "Consulta añadida al socio " << coleccionSocios.socio[i]->getNombre() << endl;
            sleep(3);
        }
    }
}

void ingresarConsulta()
{
    string ci, motivo;
    // MENU DE LOS DATOS DEL SOCIO CI Y NOMBRE
    cout << "_________________________________" << endl;
    cout << "Ingresar Socio" << endl;
    cout << "       Digitar Ci: " << endl;
    cin >> ci;
    if (existesocio(ci))
    {
        cout << "Ingresar  Motivo: " << endl;
        cin >> motivo;
        ingresarConsulta(motivo, ci);
    }
    else
    {
        cout << "NO EXISTE EL SOCIO" << endl;
    }
}

void eliminarSocio(string ci)
{
    int indice = -1;
    for (int i = 0; i < coleccionSocios.topeU; i++)
    {
        if (coleccionSocios.socio[i]->getCi() == ci)
        {
            indice = i;
            break;
        }
    }
    if (indice == -1)
    {
        throw invalid_argument("No existe un socio registrado con la cédula: " + ci);
    }
    Socio *socio = coleccionSocios.socio[indice];
    int cantConsultas;
    Consulta **consultas = socio->obtenerConsulta(cantConsultas);
    for (int i = 0; i < cantConsultas; i++)
    {
        delete consultas[i];
    }
    for (int i = 0; i < CANT_MASCOTAS; i++)
    {
        // if (socio.getmascota[i] != nullptr)
        {
            //  delete socio->topeMascotas[i];
        }
    }
    delete socio;
    for (int i = indice; i < coleccionSocios.topeU - 1; i++)
    {
        coleccionSocios.socio[i] = coleccionSocios.socio[i + 1];
    }
    coleccionSocios.topeU--;
    cout << "Socio con CI " << ci << " eliminado correctamente." << endl;
}
// FUNCIONES AUXILIARES

void menu()
{
    system("clear");
    cout << "_____________________________________" << endl;
    cout << "Elija la Opcion:" << endl;
    cout << "   1)Registrar Socio" << endl;
    cout << "   2)Ingresar Mascota" << endl;
    cout << "   3)Ingresar Consulta" << endl;
    cout << "   9)Mostrar Socios" << endl;
    cout << "   10)Mostrar Socios y Mascotas" << endl;
    cout << "   0)Salir" << endl;
}

void mostrarSocios()
{
    // HACER EXCEPCIÓN SI NO HAY SOCIOS
    for (int i = 0; i < coleccionSocios.topeU; i++)
    {
        cout << coleccionSocios.socio[i]->getNombre() << endl;
    }
    sleep(3);
}

void mostrarMascotas()
{
    for (int i = 0; i < coleccionSocios.topeU; i++)
    {
        // Mostrar el nombre del socio
        cout << "Usuario: " << coleccionSocios.socio[i]->getNombre() << endl;

        // Obtener las mascotas del socio
        int topeMascotas = coleccionSocios.socio[i]->getTopeMascotas();
        Mascota **mascotas = coleccionSocios.socio[i]->getMascotas();

        // Verificar si el socio tiene mascotas
        if (topeMascotas == 0)
        {
            cout << "   Este usuario no tiene mascotas." << endl;
        }
        else
        {
            cout << "   Mascotas:" << endl;
            for (int j = 0; j < topeMascotas; j++)
            {
                // Mostrar el nombre de cada mascota
                cout << "     - " << mascotas[j]->getNombre() << endl;
            }
        }
    }
    sleep(3); // Pausa para que el usuario pueda leer la información
}

int main()
{
    menu();
    coleccionSocios.topeU = 0;
    int menu1;
    cin >> menu1;
    while (menu1 != 0)
    {
        switch (menu1)
        {
        case 1:
            registrarSocio();
            break;
        case 2:
            agregarMascota();
            break;
        case 3:
            ingresarConsulta();
            break;
        case 4:
            break;
        case 5:
            break;
        case 9:
            mostrarSocios();
            break;
        case 10:
            mostrarMascotas();
            break;
        case 0:
            cout << "SALIENDO..." << endl;
            break;
        default:
            cout << "OPCION INVALIDA" << endl;
        }
        menu();
        cin >> menu1;
    }

    return 0;
};
