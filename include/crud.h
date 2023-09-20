#ifndef CRUD_H
#define CRUD_H

#include "assento.h"
#include "aviao.h"
#include "passageiro.h"
#include <vector>

class Crud {
  public:
    Crud();

    void carregaArquivos();
    void salvaArquivos();

  private:
    std::vector<Aviao> avioes;
    std::vector<Passageiro> passageiros;
    std::vector<Assento> assentos;
};

#endif // CRUD_H
