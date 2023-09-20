#ifndef RESERVA_H
#define RESERVA_H

#include "assento.h"
#include <string>
#include <vector>

class Reserva {
  public:
    Reserva();

  private:
    std::string idPassageiro;
    std::string idVoo;

    int fileiraAssento;
    int colunaAssento;
};

#endif // RESERVA_H
