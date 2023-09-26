#ifndef AVIAO_H
#define AVIAO_H

#include "assento.h"
#include "passageiro.h"
#include <string>
#include <vector>

class Aviao {
  public:
    Aviao(int nFileiras, int nColunas);

    std::string getDados();

    int getId();

    int getFileiras();
    int getColunas();

    int getNumAssentos();

    Assento *getAseento(int fileira, int coluna);

  private:
    int id;

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
