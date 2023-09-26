#include "assentoPremium.h"

#include <iostream>

AssentoPremium::AssentoPremium(int fileira, int coluna, int idVoo) : Assento(fileira, coluna, idVoo) {}

bool AssentoPremium::podeReservar(Passageiro *passageiro) {
    if (!this->ocupado) {
        if (passageiro->isPremium()) {
            return true;
        } else {
            std::cout << "Apenas passageiros premium podem reservar este assento." << std::endl;
            return false;
        }
    };
}