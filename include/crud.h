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
    void exibirRelatorio();

    Passageiro *getPassageiro(int id);
    Aviao *getAviao(int id);
    Reserva *getReserva(int id);

    void lerDadosCriarVoo(bool usuario = true);
    void lerDadosCriarPassageiro(bool usuario = true);
    void lerDadosCriarReserva(bool usuario = true);

    void lerListarAssentosDisponiveis();

    void lerCancelarVoo();
    void lerDeletarPassageiro();
    void lerCancelarReserva();

    // edita voo
    void lerEditarOrigemVoo();
    void lerEditarDestinoVoo();
    void lerEditarDataVoo();
    void lerEditarHorarioVoo();

    // edita passageiro
    void lerEditarNomePassageiro();
    void lerEditarIdadePassageiro();
    void lerEditarPremiumPassageiro();

    // edita reserva
    void lerEditarPosicaoAssento();

    Aviao *criarVoo(int nFileiras, int nColunas, std::string origem, std::string destino, float tempoVoo, std::string data, std::string horario, int id);
    Passageiro *criarPassageiro(std::string nome, int idade, bool premium, int id);
    Reserva *criarReserva(int passageiroId, int aviaoId, int fileira, int coluna, int id);

    void listarVoos();
    void listarReservas();
    void listarPassageiros();

    void cancelaReserva(int idPassageiro, int idVoo, int fileiraAssento, int colunaAssento);
    void cancelaReservasVoo(int idVoo);
    void deletarPassageiro(int idPassageiro);
    void cancelaVoo(int idVoo);

    int getNewAvioesId();
    int getNewPassageirosId();
    int getNewReservasId();

  private:
    std::vector<Aviao *> avioes;
    std::vector<Passageiro *> passageiros;
    std::vector<Reserva *> reservas;
};

#endif // CRUD_H
