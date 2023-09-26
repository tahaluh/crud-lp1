#include "assentoPremium.h"

#include <iostream>

AssentoPremium::AssentoPremium(int fileira, int coluna, int idVoo) : Assento(fileira, coluna, idVoo) {}

void AssentoPremium::Reservar(Passageiro *passageiro) {
    if (passageiro->isPremium()) {
        this->ocupado = true;
        this->reserva = new Reserva(passageiro->getId(), this->idVoo, this->fileira, this->coluna);

        passageiro->AdicionaReserva(this->reserva);
    } else {
        std::cout << "O Passageiro não é Premium" << std::endl;
    }
}