#include "SuscripcionPro.h"
#include <iostream>

SuscripcionPro::SuscripcionPro(): Suscripcion("Pro",100.0,"Acceso a sala de pesas + clases grupales + vestuario privado") {};

double SuscripcionPro::calcularDescuento() const
{
    return 0.10;
}

void SuscripcionPro::mostrarInfo() const
{
    Suscripcion::mostrarInfo();
    cout<<"Descuento en productos: "<<calcularDescuento()<<endl;
}