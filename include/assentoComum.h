#ifndef ASSENTO_COMUM_H
#define ASSENTO_COMUM_H

#include "assento.h"
#include "passageiro.h"
#include <string>

class AssentoComum : public Assento {
  public:
    AssentoComum(int fileira, int coluna);
    
    void reservar(Passageiro *passageiro);
};

#endif // ASSENTO_COMUM_H
