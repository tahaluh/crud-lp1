#include "assento.h"

Assento::Assento(int fileira, int coluna, int idVoo) : fileira(fileira), coluna(coluna), idVoo(idVoo), ocupado(false), reservaId(0) {
}

void Assento::setReserva(Reserva *reserva) {
    reservaId = reserva->getId();
    ocupado = true;
}

bool Assento::isOcupado() {
    return ocupado;
}

