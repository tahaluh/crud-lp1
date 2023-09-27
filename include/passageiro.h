#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H

#include "reserva.h"
#include <string>
#include <vector>

class Passageiro {
  public:
    Passageiro(std::string nome, int idade, bool premium, int id);

    void adicionaReserva(Reserva *reserva);

    int removeReserva(int idVoo, int fileiraAssento, int colunaAssento);

    std::string getDados();
    int getId();

    bool isPremium();

    int getNumReservas();

  private:
    int id;
    std::string nome;
    int idade;
    bool premium;

    std::vector<Reserva *> reservas;
};

#endif // PASSAGEIRO_H
