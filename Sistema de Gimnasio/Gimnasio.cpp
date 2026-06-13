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

    registrarSuscripciones();
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

void Gimnasio::registrarSuscripciones() //Registra todas las suscripciones en el map
{
    factorySuscripcion["Básica"] = [](){return new SuscripcionBasica();};
    factorySuscripcion["Pro"] = [](){return new SuscripcionPro();};
    factorySuscripcion["VIP"] = [](){return new SuscripcionVIP();};
}

Suscripcion* Gimnasio::cargarSuscripciones(const string& tipo)
{
    auto it = factorySuscripcion.find(tipo);

    if(it != factorySuscripcion.end())
    {
        return it->second();
    }

    throw invalid_argument("Tipo de suscripción desconocido: " + tipo);
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
        if(linea.empty()) continue;
        
        stringstream ss(linea);

        string id;
        string nombre;
        string edad;
        string suscripcion;
        
        getline(ss,id,',');
        getline(ss,nombre,',');
        getline(ss,edad,',');
        getline(ss,suscripcion,',');

        try
        {
            Suscripcion* s = cargarSuscripciones(suscripcion);
            miembros.push_back(new Miembro(nombre,stoi(edad),stoi(id),s));
        }catch(const exception& e)
        {
            cerr<<"Error al cargar línea: "<<linea<<" -> "<<e.what()<<endl;
        }
    }

    arch.close();
}

void Gimnasio::guardarMiembros(const string& amiembros)
{
    ofstream archivo(amiembros);
    
    if(!archivo)
    {
        throw runtime_error("No se pudo abrir el archivo.");
    }
    
    for(Miembro* m: miembros)
    {
        archivo<<m->getID()<<","<<m->getNombre()<<","<<m->getEdad()<<","<<m->getSuscripcion()->getTipo()<<"\n";
    }

    archivo.close();
}

void Gimnasio::agregarEntrenador(Entrenador* e)
{
    entrenadores.push_back(e);
}

void Gimnasio::eliminarEntrenador(int id)
{
    Entrenador* e = buscarEntrenador(id);

    if(e != nullptr)
    {
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

void Gimnasio::cargarEntrenadores(const string& aentrenadores)
{
    ifstream arch(aentrenadores);

    if(!arch)
    {
        throw runtime_error("El archivo no pudo cargarse.");
    }
    
    string linea;

    while(getline(arch,linea))
    {
        if(linea.empty()) continue;
        
        stringstream ss(linea);

        string id;
        string nombre;
        string edad;
        string especialidad;
        string tarifaHora;
        string horasTrabajadas;
        
        getline(ss,id,',');
        getline(ss,nombre,',');
        getline(ss,edad,',');
        getline(ss,especialidad,',');
        getline(ss,tarifaHora,',');
        getline(ss,horasTrabajadas,',');

        try
        {
            entrenadores.push_back(new Entrenador(nombre,stoi(edad),stoi(id),especialidad,stod(tarifaHora),stoi(horasTrabajadas)));
        }catch(const exception& e)
        {
            cerr<<"Error al cargar línea: "<<linea<<" -> "<<e.what()<<endl;
        }
    }

    arch.close();
}

void Gimnasio::guardarEntrenadores(const string& aentrenadores)
{
    ofstream archivo(aentrenadores);

    if(!archivo)
    {
        throw runtime_error("No se pudo abrir el archivo");
    }

    for(Entrenador* e: entrenadores)
    {
        archivo<<e->getID()<<','<<e->getNombre()<<','<<e->getEdad()<<','<<e->getEspecialidad()<<','<<e->getTarifaHora()<<','<<e->getHorasTrabajadas()<<"\n";
    }

    archivo.close();
}

void Gimnasio::cargarCSV()
{
    cargarMiembros("Miembros.csv");
    cargarEntrenadores("Entrenadores.csv");
}

void Gimnasio::guardarCSV()
{
    guardarMiembros("Miembros.csv");
    guardarEntrenadores("Entrenadores.csv");
}

Gimnasio::~Gimnasio()
{
    for(Miembro* m: miembros)
    {
        delete m;
    }

    for(Entrenador* e: entrenadores)
    {
        delete e;
    }

    miembros.clear();
    entrenadores.clear();
}