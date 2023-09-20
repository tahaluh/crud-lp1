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
