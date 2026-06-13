#include "Miembro.h"
#include "Suscripcion.h"
#include <iostream>
using namespace std;

Miembro::Miembro(string nombre, int edad, Suscripcion* suscripcion): Persona(nombre, edad)
{
    if(suscripcion == nullptr)
    {
        throw invalid_argument("La suscripción no puede ser nula.");
    }
    
    this->suscripcion = suscripcion;
}

Miembro::Miembro(string nombre, int edad, int id, Suscripcion* suscripcion): Persona(nombre, edad, id)
{
    if(suscripcion == nullptr)
    {
        throw invalid_argument("La suscripción no puede ser nula.");
    }
    
    this->suscripcion = suscripcion;
}

Suscripcion* Miembro::getSuscripcion() const {return suscripcion;}

void Miembro::setSuscripcion(Suscripcion* suscripcion)
{
    if(suscripcion==nullptr)
    {
        throw invalid_argument("La suscripción no puede ser nula.");
    }

    this->suscripcion = suscripcion;
}

void Miembro::mostrarInfo() const
{
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Edad: "<<edad<<endl;
    cout<<"Suscripcion: "<<endl;
    cout<<"ID: "<<id<<endl;
    cout<<"Suscripción: "<<endl;
    suscripcion->mostrarInfo();
    cout<<endl;
}

Miembro::~Miembro()
{
    delete suscripcion;
}