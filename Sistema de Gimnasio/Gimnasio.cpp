#include "Gimnasio.h"
#include "Suscripcion.h"
#include "SuscripcionBasica.h"
#include "SuscripcionPro.h"
#include "SuscripcionVIP.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <functional>
#include <map>
using namespace std;

Gimnasio::Gimnasio(string nombre)
{
    if(nombre.empty() || nombre.length() < 2)
    {
        throw invalid_argument("Nombre inválido.");
    }

    this->nombre = nombre;
}

template <typename T>
T* Gimnasio::buscarPorID(const vector<T*>& vec, int id) const
{
    for(T* e: vec)
    {
        if(e->id == id)
        {
            return e; 
        }
    }

    return nullptr;
}

void Gimnasio::registrarSuscripciones()
{
    factorySuscripcion["Básica"] = [](){return new SuscripcionBasica();};
    factorySuscripcion["Pro"] = [](){return new SuscripcionPro();};
    factorySuscripcion["VIP"] = [](){return new SuscripcionVIP();};
}

Suscripcion* Gimnasio::cargarSuscripciones(const string& tipo)
{
    auto it = factorySuscripcion.find(tipo);

    
}

string Gimnasio::getNombre() const { return nombre; };

void Gimnasio::agregarMiembro(Miembro* miembro)
{
    miembros.push_back(miembro);
}

void Gimnasio::eliminarMiembro(int id)
{
    Miembro* miembro = buscarMiembro(id);

    if(miembro != nullptr)
    {
        for(auto it = miembros.begin(); it != miembros.end(); ++it)
        {
            if(*it == miembro)
            {
                delete *it;
                miembros.erase(it);
                break;
            }
        }
    }
}

Miembro* Gimnasio::buscarMiembro(int id) const
{
    return buscarPorID<Miembro>(miembros, id);
}

void Gimnasio::mostrarMiembros() const
{
    for(Miembro* m: miembros)
    {
        m->mostrarInfo();
        cout<<endl;
    }
}

void Gimnasio::cargarMiembros(const string& amiembros)
{
    ifstream arch(amiembros);

    if(!arch)
    {
        throw runtime_error("El archivo no pudo cargarse.");
    }
    
    string linea;

    while(getline(arch,linea))
    {
        stringstream ss(linea);

        string id;
        string nombre;
        string edad;
        string suscripcion;
        
    }
}

void Gimnasio::agregarEntrenador(Entrenador* e)
{
    entrenadores.push_back(e);
}

void Gimnasio::eliminarEntrenador(int id)
{
    Entrenador* e = buscarEntrenador(id);

    for(auto it = entrenadores.begin(); it != entrenadores.end(); ++it)
    {
        if(*it == e)
        {
            delete *it;
            entrenadores.erase(it);
            break;
        }
    }
}

Entrenador* Gimnasio::buscarEntrenador(int id) const
{
    return buscarPorID(entrenadores, id);
}

void Gimnasio::mostrarEntrenadores() const
{
    for(Entrenador* e: entrenadores)
    {
        e->mostrarInfo();
        cout<<endl;
    }
}

void Gimnasio::cargarCSV()
{
    cargarMiembros("Miembros.csv");
    cargarEntrenadores("Entrenadores.csv");
}

