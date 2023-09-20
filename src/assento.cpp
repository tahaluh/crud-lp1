#include "assento.h"

Assento::Assento(int fileira, int coluna) : fileira(fileira), coluna(coluna), ocupado(false) {
    if (fileira <= 2) { // as 3 primeiras fileiras são premium
        premium = true;
    }
}

void Assento::definirPassageiro(Passageiro *passageiro) {
    this->passageiro = passageiro;
}