#include "assentoComum.h"

AssentoComum::AssentoComum(int fileira, int coluna, int idVoo) : Assento(fileira, coluna, idVoo) {}

bool AssentoComum::podeReservar(Passageiro *passageiro) {
    return !this->ocupado;
}