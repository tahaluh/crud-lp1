#ifndef PAGAMENTO_H
#define PAGAMENTO_H

#include <string>

class Pagamento {
  public:
    Pagamento();
    Pagamento(double valorPagamento, std::string nomeDoFuncionario);

    double getValorPagamento();
    std::string getNomeDoFuncionario();

    void setValorPagamento(double valor);
    void setNomeDoFuncionario(std::string nome);

  protected:
    double valorPagamento;
    std::string nomeDoFuncionario;
};

#endif // PAGAMENTO_H

#ifndef CONTROLE_DE_PAGAMENTO_H
#define CONTROLE_DE_PAGAMENTO_H

#include <vector>

class ControleDePagamentos {
  public:
    ControleDePagamentos(int nPagamentos);

    void setPagamento(Pagamento pagamento, int indicePagamento);

    Pagamento getPagamento(int indicePagamento);

    float calculaTotalDePagamentos();

    int getIndexFuncionario(std::string nome);

  private:
    std::vector<Pagamento> pagamentos;
};

#endif // CONTROLE_DE_PAGAMENTO_H

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

#include <iostream>

using namespace std;

int main() {
    int nPagamentos, i;
    string nomeFuncionario, nomePesquisa;
    double valorPagamento;
    Pagamento pagamento;

    cin >> nPagamentos;

    ControleDePagamentos controle = ControleDePagamentos(nPagamentos);

    for (i = 0; i < nPagamentos; i++) {
        cin >> valorPagamento;
        cin.ignore();
        getline(cin, nomeFuncionario);
        pagamento = Pagamento(valorPagamento, nomeFuncionario);
        controle.setPagamento(pagamento, i);
    }

    getline(cin, nomePesquisa);

    i = controle.getIndexFuncionario(nomePesquisa);

    if (i == -1) {
        cout << nomePesquisa << " não encontrado(a)." << endl;
    } else {
        cout << controle.getPagamento(i).getNomeDoFuncionario() << ": R$ " << controle.getPagamento(i).getValorPagamento() << endl;
    }

    cout << "Total: R$ " << controle.calculaTotalDePagamentos() << endl;

    cin >> nomeFuncionario;

    return 0;
}