#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H

#include "reserva.h"
#include <string>
#include <vector>

class Passageiro {
  public:
    Passageiro(std::string nome, int idade, bool premium, int id);

    std::string getDados();
    int getId();

    bool isPremium();

  private:
    int id;
    std::string nome;
    int idade;
    bool premium;
};

#endif // PASSAGEIRO_H
