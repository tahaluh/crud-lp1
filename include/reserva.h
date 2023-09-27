#ifndef RESERVA_H
#define RESERVA_H

#include <string>
#include <vector>

class Reserva {
  public:
    Reserva(int idPassageiro, int idVoo, int fileiraAssento, int colunaAssento, int id);

    std::string getDados();

    int getId();

    int getIdPassageiro();
    int getIdVoo();
    int getFileira();
    int getColuna();

  private:
    int id;

    int idPassageiro;
    int idVoo;

    int fileiraAssento;
    int colunaAssento;
};

#endif // RESERVA_H
