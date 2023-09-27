#ifndef AVIAO_H
#define AVIAO_H

#include "assento.h"
#include <string>
#include <vector>

class Aviao {
  public:
    Aviao(std::string origem, std::string destino, float tempoVoo, std::string data, std::string horario, int nFileiras, int nColunas, int id);

    std::string getDados();

    int getId();

    int getFileiras();
    int getColunas();

    int getNumAssentos();

    void listarAssentosDisponiveis();

    Assento *getAssento(int fileira, int coluna);

  private:
    int id;

    std::string origem;
    std::string destino;

    float tempoVoo;

    std::string data;
    std::string horario;

    int nFileiras;
    int nColunas;

    std::vector<std::vector<Assento *>> matrixAssentos;
};

#endif // AVIAO_H
