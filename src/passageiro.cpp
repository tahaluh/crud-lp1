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

std::string Passageiro::getNome() {
    return this->nome;
}

int Passageiro::getIdade() {
    return this->idade;
}

void Passageiro::setPremium(bool premium) {
    this->premium = premium;
}
void Passageiro::setNome(std::string nome) {
    this->nome = nome;
}
void Passageiro::setIdade(int idade) {
    this->idade = idade;
}