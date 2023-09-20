#include "controleDePagamentos.h"

ControleDePagamentos::ControleDePagamentos(int nPagamentos) {
    this->pagamentos = std::vector<Pagamento>(nPagamentos);
}

void ControleDePagamentos::setPagamento(Pagamento pagamento, int indicePagamento) {
    this->pagamentos[indicePagamento] = pagamento;
};

Pagamento ControleDePagamentos::getPagamento(int indicePagamento) {
    return this->pagamentos[indicePagamento];
}

float ControleDePagamentos::calculaTotalDePagamentos() {
    float total = 0;
    for (int i = 0; i < pagamentos.size(); i++) {
        total += pagamentos[i].getValorPagamento();
    }
    return total;
}

int ControleDePagamentos::getIndexFuncionario(std::string nome) {
    for (int i = 0; i < this->pagamentos.size(); i++) {
        std::string nomeFuncionarioAtual = this->pagamentos[i].getNomeDoFuncionario();

        if (nomeFuncionarioAtual.find(nome) != std::string::npos) {
            return i;
        }
    }
    return -1;
}
