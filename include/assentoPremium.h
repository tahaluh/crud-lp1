#ifndef ASSENTO_PREMIUM_H
#define ASSENTO_PREMIUM_H

#include "assento.h"
#include <string>

class AssentoPremium : public Assento {
  public:
    AssentoPremium(int fileira, int coluna, int idVoo);

    bool podeReservar(Passageiro *passageiro);
};

#endif // ASSENTO_PREMIUM_H
