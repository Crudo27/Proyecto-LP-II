#include "SuscripcionBasica.h"
#include <iostream>

SuscripcionBasica::SuscripcionBasica(): Suscripcion("Básica",50.0,"Acceso a sala de pesas"){};

double SuscripcionBasica::calcularDescuento() const
{
    return 0.0;
}