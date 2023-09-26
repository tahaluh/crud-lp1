#ifndef ASSENTO_COMUM_H
#define ASSENTO_COMUM_H

#include "assento.h"
#include <string>

class AssentoComum : public Assento {
  public:
    AssentoComum(int fileira, int coluna, int idVoo);

    bool podeReservar(Passageiro *passageiro);
};

#endif // ASSENTO_COMUM_H
