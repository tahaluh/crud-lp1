#ifndef AVIAO_H
#define AVIAO_H

#include "assento.h"
#include "passageiro.h"
#include <string>
#include <vector>

class Aviao {
  public:
    Aviao(int nFileiras, int nColunas);

  private:
    std::string origem;
    std::string destino;

    float tempoVoo;

    std::string data;
    std::string horario;

    int nFileiras;
    int nColunas;

    int id;

    std::vector<std::vector<Assento>> matrixAssentos;
};

#endif // AVIAO_H