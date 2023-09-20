#ifndef CONTROLE_DE_PAGAMENTO_H
#define CONTROLE_DE_PAGAMENTO_H

#include "pagamento.h"
#include <string>
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
