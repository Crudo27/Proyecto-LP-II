#pragma once
#include "Suscripcion.h"
#include <string>

class SuscripcionBasica: public Suscripcion
{
    public:
        SuscripcionBasica();

        double calcularDescuento() const override;

        void mostrarInfo() const;
};