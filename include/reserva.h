#ifndef RESERVA_H
#define RESERVA_H

#include "assento.h"
#include <string>
#include <vector>

class Reserva {
  public:
    Reserva(int idPassageiro, int idVoo, int fileiraAssento, int colunaAssento);

  private:
    int idPassageiro;
    int idVoo;

    int fileiraAssento;
    int colunaAssento;
};

#endif // RESERVA_H
