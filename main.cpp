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

// FUNCIONES AUXIALIARES
void existesocio(string ci)
{
    bool existesocio = false;
    int i = 0;
    while (!existesocio && i < coleccionSocios.topeU)
    {
        if (coleccionSocios.socio[i]->getCi() == ci)
        {
            existesocio = true;
        }
        i++;
    }
    if (!existesocio)
    {
        throw invalid_argument("\nERROR: NO EXISTE UN SOCIO CON ESA CI EN EL SISTEMA\n");
    }
}

void noExisteUsuario(string ci)
{
    bool existesocio = false;
    int i = 0;
    while (!existesocio && i < coleccionSocios.topeU)
    {
        if (coleccionSocios.socio[i]->getCi() == ci)
        {
            existesocio = true;
        }
        i++;
    }
    if (existesocio)
    {
        throw invalid_argument("\nERROR: YA EXISTE UN SOCIO CON ESA CI EN EL SISTEMA\n");
    }
}

void consultaslibre(string ci)
{
    bool consultalibre = false;
    int i = 0;
    while (i < coleccionSocios.topeU)
    {
        if (coleccionSocios.socio[i]->getCi() == ci && coleccionSocios.socio[i]->getTopeConsultas() <= CANT_CONSULTAS)
        {
            consultalibre = true;
        }
        i++;
    }
    if (!consultalibre)
    {
        throw invalid_argument("\nERROR: SOCIO SIN CONSULTAS LIBRES \n");
    }
}
void mascotaslibre(string ci)
{
    bool consultalibre = false;
    int i = 0;
    while (i < coleccionSocios.topeU)
    {
        if (coleccionSocios.socio[i]->getCi() == ci && coleccionSocios.socio[i]->getTopeMascotas() <= CANT_CONSULTAS)
        {
            consultalibre = true;
        }

        i++;
    }
    if (!consultalibre)
    {
        throw invalid_argument("\nERROR: EL SOCIO LLEGO AL MAXIMO DE MASCOTAS PERMITIDAS");
        sleep(3);
    }
}

// OPERACIONES: OPERACION A
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
    try
    {
        cout << "entro al try" << endl;
        DtPerro &dtperro = dynamic_cast<DtPerro &>(mascota);
        Perro *perro = new Perro(dtperro.getNombre(), dtperro.getGenero(), dtperro.getPeso(), dtperro.getRacionDiaria(), dtperro.getRaza(), dtperro.getVacunaCachorro());
        Socio *socio = new Socio(ci, nombre, fechaIngreso, perro);
        coleccionSocios.socio[coleccionSocios.topeU] = socio;
        coleccionSocios.socio[coleccionSocios.topeU]->setTopeConsultas(0);
        coleccionSocios.socio[coleccionSocios.topeU]->setTopeMascotas(1);
        cout << "Mascota (perro) añadida: " << perro->getNombre() << " al socio " << nombre << endl;
        sleep(3);
    }
    catch (bad_cast)
    {
        try
        {
            DtGato &dtgato = dynamic_cast<DtGato &>(mascota);
            Gato *gato = new Gato(dtgato.getNombre(), dtgato.getGenero(), dtgato.getPeso(), dtgato.getRacionDiaria(), dtgato.getTipoPelo());
            Socio *socio = new Socio(ci, nombre, fechaIngreso, gato);
            coleccionSocios.socio[coleccionSocios.topeU] = socio;
            coleccionSocios.socio[coleccionSocios.topeU]->setTopeConsultas(0);
            coleccionSocios.socio[coleccionSocios.topeU]->setTopeMascotas(1);
            cout << "Mascota (gato) añadida: " << gato->getNombre() << " al socio " << nombre << endl;
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
    try
    {
        noExisteUsuario(ci);
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
                cout << "Raza Invalida" << endl;
                break;
            }
            cout << "¿Tiene vacuna? " << endl;
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
    catch (invalid_argument &e)
    {
        cout << e.what() << endl;
        sleep(3);
    }
}

// OPERACIONES OPERACION B
void agregarMascota(string ci, DtMascota &dtMascota)
{
    int f, i;

    for (int i = 0; i < coleccionSocios.topeU; i++)
        while (i < coleccionSocios.topeU)
        {
            if (coleccionSocios.socio[i]->getCi() == ci)
            {
                f = i;
                i++;
            }
        }
    if (CANT_MASCOTAS > coleccionSocios.socio[f]->getTopeMascotas())
    {
        try
        {
            ;
            DtPerro &dtperro = dynamic_cast<DtPerro &>(dtMascota);
            Perro *perro = new Perro(dtperro.getNombre(), dtperro.getGenero(), dtperro.getPeso(), dtperro.getRacionDiaria(), dtperro.getRaza(), dtperro.getVacunaCachorro());
            coleccionSocios.socio[f]->setMascota(perro);
        }
        catch (bad_cast)
        {
            try
            {
                DtGato &dtgato = dynamic_cast<DtGato &>(dtMascota);
                Gato *gato = new Gato(dtgato.getNombre(), dtgato.getGenero(), dtgato.getPeso(), dtgato.getRacionDiaria(), dtgato.getTipoPelo());
                coleccionSocios.socio[f]->setMascota(gato);
            }
            catch (bad_cast)
            {
            }
        }
    }
    else
        cout << "SE INGRESO EL NUMERO MAXIMO DE MASCOTAS" << endl;
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
    try
    {
        existesocio(ci);
        sleep(3);
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
                cout << "Raza Invalida" << endl;
                break;
            }
            cout << "¿Tiene vacuna? " << endl;
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
    catch (invalid_argument &e)
    {
        cout << e.what() << endl;
        sleep(3);
    }
}

// OPERACIONES OPERACION C
void ingresarConsulta(string motivo, string ci)
{
    // CREAR DTFECHA
    int dia, mes, anio;
    cout << "Digite la fecha de la consulta" << endl;
    cout << "Dia: " << endl;
    cin >> dia;
    cout << "Mes: " << endl;
    cin >> mes;
    cout << "Año: " << endl;
    cin >> anio;
    DtFecha fechaIngreso = DtFecha(dia, mes, anio);

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
    cout << "       INGRESAR CONSULTA " << endl;
    cout << "Ingresar Socio" << endl;
    cout << "       Digitar Ci: " << endl;
    cin >> ci;
    try
    {
        try
        {
            consultaslibre(ci);
            cout << "Ingresar  Motivo: " << endl;
            cin >> motivo;
            ingresarConsulta(motivo, ci);
        }
        catch (invalid_argument &e)
        {
            cout << e.what() << endl;
            sleep(3);
        }
    }
    catch (invalid_argument &e)
    {
        cout << e.what() << endl;
        sleep(3);
    }
}

// OPERACIONES OPERACION D
DtConsulta **verConsultasAntesDeFecha(DtFecha &fecha, string ciSocio, int &cantConsultas)
{
    Socio *socio;
    DtConsulta **consultas = new DtConsulta *[cantConsultas];
    int f = 0;
    for (int i = 0; i < coleccionSocios.topeU; i++)
    {
        if (coleccionSocios.socio[i]->getCi() == ciSocio)
        {
            socio = coleccionSocios.socio[i];
        }
    }

    for (int i = 0; i < socio->getTopeConsultas(); i++)
    {
        if (fecha.getAnio() > socio->getConsulta(i)->getFechaConsulta().getAnio())
        {
            consultas[f] = new DtConsulta(socio->getConsulta(i)->getFechaConsulta(), socio->getConsulta(i)->getMotivo());

            f++;
        }
        else if (fecha.getAnio() == socio->getConsulta(i)->getFechaConsulta().getAnio())
        {
            if (fecha.getMes() > socio->getConsulta(i)->getFechaConsulta().getMes())
            {
                consultas[f] = new DtConsulta(socio->getConsulta(i)->getFechaConsulta(), socio->getConsulta(i)->getMotivo());
                f++;
            }
            else if (fecha.getMes() == socio->getConsulta(i)->getFechaConsulta().getMes())
            {
                if (fecha.getDia() > socio->getConsulta(i)->getFechaConsulta().getDia())
                {
                    consultas[f] = new DtConsulta(socio->getConsulta(i)->getFechaConsulta(), socio->getConsulta(i)->getMotivo());
                    f++;
                }
            }
        }
    }

    return consultas;
}
void verConsultasAntesDeFecha()
{
    string ci;
    cout << "_________________________________" << endl;
    cout << "Ingresar Socio" << endl;
    cout << "       Digitar Ci: " << endl;
    cin >> ci;

    try
    {
        existesocio(ci);
        sleep(3);
        // CREAR DTFECHA
        int dia, mes, anio, cantConsultas, cantConsultasMenores;
        cout << "Digite la fecha de ingreso" << endl;
        cout << "Dia: " << endl;
        cin >> dia;
        cout << "Mes: " << endl;
        cin >> mes;
        cout << "Año: " << endl;
        cin >> anio;
        DtFecha fechaIngreso = DtFecha(dia, mes, anio);
        for (int i = 0; i < coleccionSocios.topeU; i++)
        {
            if (coleccionSocios.socio[i]->getCi() == ci)
            {
                cantConsultas = coleccionSocios.socio[i]->getTopeConsultas();
                cantConsultasMenores = coleccionSocios.socio[i]->cantidadConsultasAntesDeFecha(fechaIngreso);
            }
        }
        if (cantConsultasMenores > 0)
        {
            DtConsulta **consultas = new DtConsulta *[cantConsultasMenores];
            consultas = verConsultasAntesDeFecha(fechaIngreso, ci, cantConsultas);

            for (int i = 0; i < cantConsultasMenores; i++)
            {
                cout << "Fecha: " << consultas[i]->getFechaConsulta().getDia() << "/" << consultas[i]->getFechaConsulta().getMes() << "/" << consultas[i]->getFechaConsulta().getAnio() << endl;
                cout << "Motivo: " << consultas[i]->getMotivo() << endl;
            }
            sleep(3);
            for (int i = 0; i < cantConsultasMenores; i++)
            {
                delete consultas[i];
            }
            delete[] consultas;
            sleep(3);
        }
        else
        {
            cout << "NO HAY CONSULTAS VALIDAS" << endl;
            sleep(5);
        }
    }
    catch (invalid_argument &e)
    {
        cout << e.what() << endl;
        sleep(3);
    }
}
// OPERACIONES OPERACION E

DtMascota **obtenerMascotas(string ci, int &cantMascotas)
{
    DtMascota **mascotas = new DtMascota *[cantMascotas];
    for (int i = 0; i < coleccionSocios.topeU; i++)
    {
        if (coleccionSocios.socio[i]->getCi() == ci)
        {
            sleep(3);
            for (int j = 0; j < coleccionSocios.socio[i]->getTopeMascotas(); j++)
            {
                Mascota *mascota = coleccionSocios.socio[i]->getMascota(j);
                Gato *gato = dynamic_cast<Gato *>(mascota);
                if (gato != nullptr)
                {
                    mascotas[j] = new DtGato(gato->getNombre(), gato->getGenero(), gato->getPeso(), gato->obtenerRacionDiaria(), gato->getTipoPelo());
                }
                else
                {
                    Perro *perro = dynamic_cast<Perro *>(mascota);
                    mascotas[j] = new DtPerro(perro->getNombre(), perro->getGenero(), perro->getPeso(), perro->obtenerRacionDiaria(), perro->getRaza(), perro->getVacunaCachorro());
                }
            }
        }
        else
        {
        }
    }
    return mascotas;
}

void obtenerMascotas()
{
    string ci;
    cout << "_________________________________" << endl;
    cout << "Ingresar Socio" << endl;
    cout << "       Digitar Ci: " << endl;
    cin >> ci;
    try
    {
        existesocio(ci);
        int f;
        for (int i = 0; i < coleccionSocios.topeU; i++)
        {
            if (coleccionSocios.socio[i]->getCi() == ci)
            {
                f = i;
            }
        }
        int cantMascotas = coleccionSocios.socio[f]->getTopeMascotas();
        DtMascota **mascotas = obtenerMascotas(ci, cantMascotas);
        for (int i = 0; i < cantMascotas; i++)
        {
            cout << "Nombre: " << mascotas[i]->getNombre() << endl;
            cout << "Genero: " << mascotas[i]->getGenero() << endl;
            cout << "Peso: " << mascotas[i]->getPeso() << endl;
            cout << "Racion Diaria: " << mascotas[i]->getRacionDiaria() << endl;
            try
            {
                DtPerro &dtperro = dynamic_cast<DtPerro &>(*mascotas[i]);
                cout << "Raza: " << dtperro.getRaza() << endl;
                cout << "Vacuna Cachorro: " << dtperro.getVacunaCachorro() << endl;
            }
            catch (bad_cast)
            {
                try
                {
                    DtGato &dtgato = dynamic_cast<DtGato &>(*mascotas[i]);
                    cout << "Tipo Pelo: " << dtgato.getTipoPelo() << endl;
                }
                catch (bad_cast)
                {
                }
            }
        }
        sleep(3);
    }
    catch (invalid_argument &e)
    {
        cout << e.what() << endl;
        sleep(3);
    }
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
    cout << "   4)Mostrar Consultas" << endl;
    cout << "   5)Mostrar Macotas de un socio" << endl;
    cout << "   9)Mostrar Socios" << endl;
    cout << "   10)Mostrar Socios y Mascotas" << endl;
    cout << "   0)Salir" << endl;
}

void eliminarSocio(string ci)
{
    int i = 0;
    bool existe = false;
    while (i < coleccionSocios.topeU && (!existe))
    {
        if (coleccionSocios.socio[i]->getCi() == ci)
        {
            existe = true;
            delete coleccionSocios.socio[i];
        }
        i++;
    }
    cout << "Socio con CI " << ci << " eliminado correctamente." << endl;
    sleep(3);
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
            verConsultasAntesDeFecha();
            break;
        case 5:
            obtenerMascotas();
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
