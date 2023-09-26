#ifndef RESERVA_H
#define RESERVA_H

#include "assento.h"
#include <string>
#include <vector>

class Reserva {
  public:
    Reserva(int idPassageiro, int idVoo, int fileiraAssento, int colunaAssento);

    std::string getDados();

    int getIdPassageiro();
    int getIdVoo();
    int getFileira();
    int getColuna();

  private:
    int idPassageiro;
    int idVoo;

    int fileiraAssento;
    int colunaAssento;
};

#endif // RESERVA_H
