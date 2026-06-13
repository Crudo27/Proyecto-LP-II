#include "Suscripcion.h"
#include <iostream>
#include <stdexcept>
using namespace std;

Suscripcion::Suscripcion(string tipo, double precio, string beneficio)
{
    if(tipo.empty())
    {
        throw invalid_argument("Tipo inválido. Debe ser: Básico, Pro o VIP.");
    }

    if(precio<0)
    {
        throw invalid_argument("El precio no puede ser menor que 0.");
    }

    if(beneficio.empty())
    {
        throw invalid_argument("Los beneficios están vacíos");
    }
    
    this->tipo = tipo;
    this->precio = precio;
    this->beneficio = beneficio;
}

string Suscripcion::getTipo() const {return tipo;}

double Suscripcion::getPrecio() const {return precio;}

string Suscripcion::getBeneficio() const {return beneficio;}

void Suscripcion::mostrarInfo() const
{
    cout<<"Tipo: "<<tipo<<endl;
    cout<<"Precio: "<<precio<<endl;
    cout<<"Beneficio: "<<beneficio<<endl;
}