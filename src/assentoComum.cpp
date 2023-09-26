#include "assentoComum.h"

AssentoComum::AssentoComum(int fileira, int coluna) : Assento(fileira, coluna) {}

void AssentoComum::reservar(Passageiro *passageiro) {
    this->ocupado = true;
    this->reserva = new Reserva(passageiro->getId(), this->idVoo, this->fileira, this->coluna);

    passageiro->AdicionaReserva(this->reserva);
}