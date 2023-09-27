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
    
    std::string getNome();
    int getIdade();

    void setPremium(bool premium);
    void setNome(std::string nome);
    void setIdade(int idade);

  private:
    int id;
    std::string nome;
    int idade;
    bool premium;
};

#endif // PASSAGEIRO_H
