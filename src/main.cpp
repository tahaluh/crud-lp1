#include "controleDePagamentos.h"
#include "pagamento.h"
#include <iostream>
#include <string>

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