//
// Created by Moises Fernandez on 4/10/18.
//

#ifndef PROYECTO3_RESERVA_H
#define PROYECTO3_RESERVA_H

#include "Material.h"
#include "Fecha.h"
#include "Libro.h"
#include "Disco.h"
#include "Software.h"

class Reserva
{
public:
    Reserva();
    Reserva(int, int, Fecha);

    int getIdMaterial() { return idMaterial; }
    int getIdCliente() { return idCliente; }
    Fecha getFechaReservacion() { return fechaReservacion; }

    void setIdMaterial(int idMaterial) { this->idMaterial = idMaterial; }
    void setIdCliente(int idCliente) { this->idCliente = idCliente; }
    void setFechaReservacion(Fecha fechaReservacion) { this->fechaReservacion = fechaReservacion; }

    Fecha calculaFechaFinReserva(int cantDias);

private:
    int idMaterial, idCliente;
    Fecha fechaReservacion;
};

Reserva::Reserva()
{
    idMaterial = 0;
    idCliente = 0;
    Fecha f(0, 0, 0);
    fechaReservacion = f;
}

Reserva::Reserva(int idM, int idC, Fecha f)
{
    idMaterial = idM;
    idCliente = idC;
    fechaReservacion = f;
}

Fecha Reserva::calculaFechaFinReserva(int cantDias)
{
    return fechaReservacion + cantDias;
}

#endif //PROYECTO3_RESERVA_H
