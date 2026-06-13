#pragma once
#include <string>
using namespace std;

class Suscripcion //Header de Suscripcion
{
    protected:
        string tipo;
        double precio;
        string beneficio;
    public:
        Suscripcion(string tipo, double precio, string beneficio);

        string getTipo() const;
        double getPrecio() const;
        string getBeneficio() const;
        virtual double calcularDescuento() const = 0;

        virtual void mostrarInfo() const;

        virtual ~Suscripcion() = default;
};