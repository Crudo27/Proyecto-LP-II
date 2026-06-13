#pragma once
#include <string>
using namespace std;

class Persona //Header de Persona
{
    protected:
        string nombre;
        int edad;
        int id;
        static int contadorID;
    public:
        Persona(string nombre, int edad);
        Persona(string nombre, int edad, int id);

        string getNombre() const;
        int getEdad() const;
        int getID() const;

        void setNombre(string nombre);
        void setEdad(int edad);

        virtual void mostrarInfo() const = 0;

        virtual ~Persona() = default;
};