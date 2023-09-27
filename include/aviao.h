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

    float getTempoVoo();
    std::string getData();
    std::string getHorario();
    std::string getOrigem();
    std::string getDestino();

    void setHorario(std::string horario);
    void setTempoVoo(float tempoVoo);
    void setData(std::string data);
    void setOrigem(std::string origem);
    void setDestino(std::string destino);

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
