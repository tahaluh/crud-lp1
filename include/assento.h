#ifndef ASSENTO_H
#define ASSENTO_H

#include "reserva.h"
#include <string>

class Assento {
  public:
    Assento(int fileira, int coluna);

    virtual void reservar(Passageiro *passageiro) = 0;

  protected:
    int idVoo;
   
    int fileira;
    int coluna;

    bool ocupado;

    Reserva *reserva;
};

#endif // ASSENTO_H
