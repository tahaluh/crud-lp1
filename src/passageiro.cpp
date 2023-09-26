#include "passageiro.h"

Passageiro::Passageiro(std::string nome, int idade, bool premium) : nome(nome), idade(idade), premium(premium) {}

void Passageiro::adicionaReserva(Reserva *reserva) {
    reservas.push_back(reserva);
}

int Passageiro::removeReserva(int idVoo, int fileiraAssento, int colunaAssento) {
    int i, size = reservas.size();
    int indexPassageiro;
    bool existe = false;

    for (i = 0; i < size; i++) {
        if (reservas[i]->getIdPassageiro() == this->getId() && reservas[i]->getIdVoo() == idVoo && reservas[i]->getFileira() == fileiraAssento && reservas[i]->getColuna() == colunaAssento) {
            reservas.erase(reservas.begin() + i);
            return 1;
        }
    }

    return 0;
}

std::string Passageiro::getDados() {
    return "Id: " + std::to_string(this->getId()) + "Nome: " + this->nome + "Idade: " + std::to_string(this->idade) + "Premium: " + std::to_string(this->premium);
}

int Passageiro::getId() {
    return this->id;
}

bool Passageiro::isPremium() {
    return this->premium;
}