#include "passageiro.h"

Passageiro::Passageiro(std::string nome, int idade, bool premium, int id) : nome(nome), idade(idade), premium(premium), id(id) {}
std::string Passageiro::getDados() {
    return "Id: " + std::to_string(this->getId()) + " - Nome: " + this->nome + " - Idade: " + std::to_string(this->idade) + " - Premium: " + std::to_string(this->premium);
}

int Passageiro::getId() {
    return this->id;
}

bool Passageiro::isPremium() {
    return this->premium;
}