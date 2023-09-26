#ifndef CRUD_H
#define CRUD_H

#include "assento.h"
#include "aviao.h"
#include "passageiro.h"
#include "reserva.h"

#include <vector>

class Crud {
  public:
    Crud();

    void carregaArquivos();
    void salvaArquivos();

    Aviao *criarVoo(int nFileiras, int nColunas);
    Passageiro *criarPassageiro(std::string nome, std::string numPassagem, int idade, bool premium);
    Reserva *criarReserva(Passageiro *passageiro, Aviao *aviao, int fileira, int coluna);

    void listarVoos();
    void listarReservas();
    void listarPassageiros();

    void cancelaReserva(int idPassageiro, int idVoo, int fileiraAssento, int colunaAssento);
    void cancelaReservas(int idVoo);
    void cancelaVoo(int idVoo);

  private:
    std::vector<Aviao *> avioes;
    std::vector<Passageiro *> passageiros;
    std::vector<Reserva *> reservas;
};

#endif // CRUD_H
