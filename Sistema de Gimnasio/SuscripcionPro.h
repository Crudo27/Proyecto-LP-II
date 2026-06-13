#pragma once
#include "Suscripcion.h"
#include <string>

class SuscripcionPro: public Suscripcion
{
    public:
        SuscripcionPro();

        double calcularDescuento() const override;

        void mostrarInfo() const override;
};