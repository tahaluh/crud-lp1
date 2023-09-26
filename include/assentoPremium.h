#ifndef ASSENTO_PREMIUM_H
#define ASSENTO_PREMIUM_H

#include "assento.h"
#include "passageiro.h"
#include <string>

class AssentoPremium : public Assento {
  public:
    AssentoPremium(int fileira, int coluna);
};

#endif // ASSENTO_PREMIUM_H
