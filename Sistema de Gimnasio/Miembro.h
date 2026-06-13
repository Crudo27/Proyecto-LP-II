#pragma once
#include "Persona.h"
#include "Suscripcion.h"
using namespace std;

class Miembro: public Persona //Header de Miembro
{
    private:
        Suscripcion* suscripcion;
    public:
        Miembro(string nombre, int edad, Suscripcion* suscripcion);
        Miembro(string nombre, int edad, int id, Suscripcion* suscripcion);

        Suscripcion* getSuscripcion() const;

        void setSuscripcion(Suscripcion* s);

        void mostrarInfo() const override;

        ~Miembro();
};