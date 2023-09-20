#ifndef ASSENTO_H
#define ASSENTO_H

#include "passageiro.h"
#include <string>

class Assento {
  public:
    Assento(int fileira, int coluna);

    void definirPassageiro(Passageiro *passageiro);

  private:
    int fileira;
    int coluna;

    bool ocupado;
    bool premium;

    Passageiro *passageiro;
};

#endif // ASSENTO_H
