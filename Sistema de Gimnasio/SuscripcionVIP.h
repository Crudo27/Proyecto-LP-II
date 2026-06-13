#pragma once
#include "Suscripcion.h"
#include <string>

class SuscripcionVIP: public Suscripcion
{
    public:    
        SuscripcionVIP();

        double calcularDescuento() const override;

        void mostrarInfo() const override;
};