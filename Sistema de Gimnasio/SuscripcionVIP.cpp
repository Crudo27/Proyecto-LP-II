#include "SuscripcionVIP.h"
#include <iostream>

SuscripcionVIP::SuscripcionVIP(): Suscripcion("VIP", 150.0, "Acceso ilimitado + entrenador personal + spa + estacionamiento") {};

double SuscripcionVIP::calcularDescuento() const
{
    return 0.20;
}

void SuscripcionVIP::mostrarInfo() const
{
    Suscripcion::mostrarInfo();
    cout<<"Descuento en productos: "<<calcularDescuento()<<endl;
}