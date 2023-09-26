#ifndef ASSENTO_H
#define ASSENTO_H

#include "passageiro.h"
#include "reserva.h"
#include <string>

class Assento {
  public:
    Assento(int fileira, int coluna, int idVoo);

    void setReserva(Reserva *reserva);

    bool isOcupado();

    virtual bool podeReservar(Passageiro *passageiro) = 0;

  protected:
    int idVoo;

    int fileira;
    int coluna;

    bool ocupado;

    int reservaId;
};

#endif // ASSENTO_H
