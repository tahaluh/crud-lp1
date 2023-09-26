#include "assentoComum.h"

AssentoComum::AssentoComum(int fileira, int coluna, int idVoo) : Assento(fileira, coluna, idVoo) {}

void AssentoComum::Reservar(Passageiro *passageiro) {
    this->ocupado = true;
    this->reserva = new Reserva(passageiro->getId(), this->idVoo, this->fileira, this->coluna);

    passageiro->adicionaReserva(this->reserva);
}