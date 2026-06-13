#include "Entrenador.h"
#include <iostream>
using namespace std;

Entrenador::Entrenador(string nombre, int edad, string especialidad, double tarifaHora): Persona(nombre, edad) 
{
    if(especialidad.empty() || especialidad.length() < 2)
    {
        throw invalid_argument("Especialidad inválida.");
    }

    if(tarifaHora<=0)
    {
        throw invalid_argument("Tarifa inválida.");
    }

    this->especialidad = especialidad;

    this->tarifaHora = tarifaHora;
}

Entrenador::Entrenador(string nombre, int edad, int id, string especialidad, double tarifaHora, int horasTrabajadas): Persona(nombre, edad, id) 
{
    if(especialidad.empty() || especialidad.length() < 2)
    {
        throw invalid_argument("Especialidad inválida.");
    }

    if(tarifaHora<=0)
    {
        throw invalid_argument("Tarifa inválida.");
    }

    if(horasTrabajadas < 0)
    {
        throw invalid_argument("Horas trabajadas inválidas.");
    }

    this->especialidad = especialidad;

    this->tarifaHora = tarifaHora;

    this->horasTrabajadas = horasTrabajadas;
}

string Entrenador::getEspecialidad() const { return especialidad; };

double Entrenador::getTarifaHora() const { return tarifaHora; };

int Entrenador::getHorasTrabajadas() const { return horasTrabajadas; };

void Entrenador::setEspecialidad(string especialidad)
{
    if(especialidad.empty() || especialidad.length() < 2)
    {
        throw invalid_argument("Especialidad inválida.");
    }
    this->especialidad = especialidad;
};

void Entrenador::setTarifaHora(double tarifaHora)
{
    if(tarifaHora <= 0)
    {
        throw invalid_argument("La tarifa no puede ser menor o igual que 0.");
    }
    this->tarifaHora = tarifaHora;
}

void Entrenador::registrarHora()
{
    horasTrabajadas++;
}

double Entrenador::calcularSueldo() const
{
    return tarifaHora * horasTrabajadas;   
}

void Entrenador::mostrarInfo() const
{
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Edad: "<<edad<<endl;
    cout<<"Especialidad: "<<especialidad<<endl;
    cout<<"ID: "<<id<<endl;
    cout<<"Tarifa por hora: "<<tarifaHora<<endl;
    cout<<"Horas registradas: "<<horasTrabajadas<<endl;
    cout<<"Sueldo: "<<calcularSueldo()<<endl;
}