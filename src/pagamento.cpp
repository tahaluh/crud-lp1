#include "pagamento.h"

Pagamento::Pagamento() {}
Pagamento::Pagamento(double valorPagamento, std::string nomeDoFuncionario) : valorPagamento(valorPagamento), nomeDoFuncionario(nomeDoFuncionario) {}

double Pagamento::getValorPagamento() {
    return this->valorPagamento;
}

std::string Pagamento::getNomeDoFuncionario() {
    return this->nomeDoFuncionario;
}

void Pagamento::setValorPagamento(double valor) {
    this->valorPagamento = valor;
}

void Pagamento::setNomeDoFuncionario(std::string nome) {
    this->nomeDoFuncionario = nome;
}