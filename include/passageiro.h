#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H

#include "assento.h"
#include "passageiro.h"
#include "reserva.h"
#include <string>
#include <vector>

class Passageiro {
  public:
    Passageiro(std::string nome, std::string numPassagem, int idade, bool premium);

  private:
    std::string nome;
    int idade;
    bool premium;

    std::vector<Reserva> reservas;
};

#endif // PASSAGEIRO_H
