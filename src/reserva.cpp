#include "reserva.h"

Reserva::Reserva(int idPassageiro, int idVoo, int fileiraAssento, int colunaAssento, int id) : idPassageiro(idPassageiro), idVoo(idVoo), fileiraAssento(fileiraAssento), colunaAssento(colunaAssento), id(id) {
}

std::string Reserva::getDados() {
    return "Id: " + std::to_string(id) + "ID Passageiro: " + std::to_string(idPassageiro) + " ID Voo: " + std::to_string(idVoo) + " Fileira: " + std::to_string(fileiraAssento) + " Coluna: " + std::to_string(colunaAssento);
}

int Reserva::getId() {
    return id;
}

int Reserva::getIdPassageiro() {
    return idPassageiro;
}

int Reserva::getIdVoo() {
    return idVoo;
}

int Reserva::getFileira() {
    return fileiraAssento;
}

int Reserva::getColuna() {
    return colunaAssento;
}
