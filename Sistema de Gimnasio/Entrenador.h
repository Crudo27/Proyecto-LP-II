#pragma once
#include "Persona.h"
#include <string>
using namespace std;

class Entrenador: public Persona
{
    private:
        string especialidad;
        double tarifaHora;
        int horasTrabajadas = 0;
    public:
        Entrenador(string nombre, int edad, string especialidad, double tarifaHora);
        Entrenador(string nombre, int edad, int id, string especialidad, double tarifaHora);
        
        string getEspecialidad() const;
        double getTarifaHora() const;
        int getHorasTrabajadas() const;

        void setEspecialidad(string especialidad);
        void setTarifaHora(double tarifaHora);

        void registrarHora();

        double calcularSueldo() const;

        void mostrarInfo() const override;
};