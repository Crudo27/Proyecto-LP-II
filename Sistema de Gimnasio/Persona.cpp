#include "Persona.h"
#include <iostream>
#include <stdexcept>
using namespace std;

int Persona::contadorID = 1; //Contador que asigna una id nueva automáticamente

Persona::Persona(string nombre, int edad)
{
    if(nombre.empty())
    {
        throw invalid_argument("El nombre no puede estar vacío.");
    }

    if(nombre.length()<2)
    {
        throw invalid_argument("Nombre inválido.");
    }

    if(edad<0)
    {
        throw invalid_argument("La edad no puede ser menor que 0.");
    }

    if(edad>120)
    {
        throw invalid_argument("Edad inválida.");
    }

    this->nombre = nombre;
    this->edad = edad;
    this->id = contadorID++;
}

Persona::Persona(string nombre, int edad, int id)
{
    if(nombre.empty())
    {
        throw invalid_argument("El nombre no puede estar vacío.");
    }

    if(nombre.length()<2)
    {
        throw invalid_argument("Nombre inválido.");
    }

    if(edad<0)
    {
        throw invalid_argument("La edad no puede ser menor que 0.");
    }

    if(edad>120)
    {
        throw invalid_argument("Edad inválida.");
    }

    if(id <= 0)
    {
        throw invalid_argument("El id no puede ser menor o igual que 0.");
    }

    this->nombre = nombre;
    this->edad = edad;
    this->id = id;
    if(id >= contadorID)
    {
        contadorID = id + 1;
    }
}

string Persona::getNombre() const {return nombre;}

int Persona::getEdad() const {return edad;};

int Persona::getID() const {return id;}

void Persona::setNombre(string nombre)
{
    if(nombre.empty() || nombre.length() < 2)
    {
        throw invalid_argument("Nombre inválido.");
    }
    this->nombre = nombre;
}

void Persona::setEdad(int edad)
{
    if(edad <= 0)
    {
        throw invalid_argument("La edad no puede ser menor o igual que 0;");
    }

    this->edad = edad;
}