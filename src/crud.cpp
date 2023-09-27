#include "crud.h"

#include <iostream>

Crud::Crud() {
}

void Crud::salvaArquivos() {
}

void Crud::carregaArquivos() {
}

int Crud::getNewAvioesId() {
    int newId = 0, i;
    bool existe = true;

    while (existe) {
        newId++;
        existe = false;

        for (int i = 0; i < avioes.size(); i++) {
            if (avioes[i]->getId() == newId) {
                existe = true;
                break;
            }
        }
    }

    return newId;
}

Aviao *Crud::lerDadosCriarVoo() {
    int nFileiras, nColunas;
    std::string origem, destino, data, horario;
    float tempoVoo;

    std::cout << "Informe os dados do Voo: " << std::endl;
    std::cout << "Origem: ";
    std::cin >> origem;

    std::cout << "Destino: ";
    std::cin >> destino;

    std::cout << "Tempo de Voo: ";
    std::cin >> tempoVoo;

    std::cout << "Data: ";
    std::cin >> data;

    std::cout << "Horario: ";
    std::cin >> horario;

    return criarVoo(nFileiras, nColunas, origem, destino, tempoVoo, data, horario);
}

Aviao *Crud::criarVoo(int nFileiras, int nColunas, std::string origem, std::string destino, float tempoVoo, std::string data, std::string horario) {
    int newId = this->getNewAvioesId();

    Aviao *aviao = new Aviao(origem, destino, tempoVoo, data, horario, nFileiras, nColunas, this->getNewAvioesId());
    avioes.push_back(aviao);
    return aviao;
}

int Crud::getNewPassageirosId() {
    int newId = 0, i;
    bool existe = true;

    while (existe) {
        newId++;
        existe = false;

        for (int i = 0; i < passageiros.size(); i++) {
            if (passageiros[i]->getId() == newId) {
                existe = true;
                break;
            }
        }
    }

    return newId;
}
Passageiro *Crud::lerDadosCriarPassageiro() {
    std::string nome;
    int idade;
    bool premium;

    std::cout << "Informe os dados do Passageiro: " << std::endl;

    std::cout << "Nome: ";
    std::cin >> nome;

    std::cout << "Idade: ";
    std::cin >> idade;

    std::cout << "Premium: ";
    std::cin >> premium;

    return criarPassageiro(nome, idade, premium);
}
Passageiro *Crud::criarPassageiro(std::string nome, int idade, bool premium) {
    Passageiro *passageiro = new Passageiro(nome, idade, premium, this->getNewPassageirosId());
    passageiros.push_back(passageiro);
    return passageiro;
}

int Crud::getNewReservasId() {
    int newId = 0, i;
    bool existe = true;

    while (existe) {
        newId++;
        existe = false;

        for (int i = 0; i < reservas.size(); i++) {
            if (reservas[i]->getId() == newId) {
                existe = true;
                break;
            }
        }
    }

    return newId;
}
Reserva *Crud::lerDadosCriarReserva() {
    int idPassageiro;
    int idVoo;
    int fileiraAssento;
    int colunaAssento;

    std::cout << "Informe os dados da Reserva: " << std::endl;

    std::cout << "ID Passageiro: ";
    std::cin >> idPassageiro;

    std::cout << "ID Voo: ";
    std::cin >> idVoo;

    std::cout << "Fileira: ";
    std::cin >> fileiraAssento;

    std::cout << "Coluna: ";
    std::cin >> colunaAssento;

    return criarReserva(passageiros[idPassageiro], avioes[idVoo], fileiraAssento, colunaAssento);
}
Reserva *Crud::criarReserva(Passageiro *passageiro, Aviao *aviao, int fileira, int coluna) {
    Reserva *reserva = new Reserva(passageiro->getId(), aviao->getId(), fileira, coluna, this->getNewReservasId());
    reservas.push_back(reserva);
    return reserva;
}

void Crud::listarVoos() {
    int i, size = avioes.size();

    for (i = 0; i < size; i++) {
        std::cout << avioes[i]->getDados() << std::endl;
    }
}

void Crud::listarReservas() {
    int i, size = reservas.size();

    for (i = 0; i < size; i++) {
        std::cout << reservas[i]->getDados() << std::endl;
    }
}

void Crud::listarPassageiros() {
    int i, size = passageiros.size();

    for (i = 0; i < size; i++) {
        std::cout << passageiros[i]->getDados() << std::endl;
    }
}

void Crud::cancelaReserva(int idPassageiro, int idVoo, int fileiraAssento, int colunaAssento) {
    int i, size = reservas.size();
    int indexPassageiro;
    bool existe = false;

    for (i = 0; i < size; i++) {
        if (passageiros[i]->getId() == idPassageiro) {
            indexPassageiro = i;
            break;
        }
    }

    for (i = 0; i < size; i++) {
        if (reservas[i]->getIdPassageiro() == idPassageiro && reservas[i]->getIdVoo() == idVoo && reservas[i]->getFileira() == fileiraAssento && reservas[i]->getColuna() == colunaAssento) {

            reservas.erase(reservas.begin() + i);
            passageiros[indexPassageiro]->removeReserva(idVoo, fileiraAssento, colunaAssento);

            existe = true;

            break;
        }
    }

    if (existe) {
        std::cout << "Reserva cancelada com sucesso" << std::endl;
    } else {
        std::cout << "Reserva não encontrada" << std::endl;
    }
}

void Crud::cancelaReservas(int idVoo) {
    int i, j, k;
    int vooIndex, indexPassageiro;
    int avioesSize = avioes.size(), passageirosSize = passageiros.size();
    int fileirasAviao, colunasAviao;

    Reserva *reserva;
    bool aviaoExiste = false;

    for (i = 0; i < avioesSize; i++) {
        if (avioes[i]->getId() == idVoo) {
            vooIndex = i;

            fileirasAviao = avioes[vooIndex]->getFileiras();
            colunasAviao = avioes[vooIndex]->getColunas();

            aviaoExiste = true;
            break;
        }
    }

    if (aviaoExiste) {
        for (j = 0; j < fileirasAviao; j++) {           // para cada fileira
            for (k = 0; k < colunasAviao; k++) {        // para cada coluna (assento)
                for (i = 0; i < passageirosSize; i++) { // para cada passageiro
                    if (passageiros[i]->removeReserva(idVoo, j, k))
                        break;
                }
            }
        }
    }
}

void Crud::cancelaVoo(int idVoo) {
    int i, size = avioes.size();
    int vooIndex;
    bool existe = false;

    for (i = 0; i < size; i++) {
        if (avioes[i]->getId() == idVoo) {
            vooIndex = i;
            existe = true;
            break;
        }
    }

    if (existe) {
        cancelaReservas(idVoo);
        avioes.erase(avioes.begin() + vooIndex);
        std::cout << "Voo cancelado com sucesso" << std::endl;
    } else {
        std::cout << "Voo não encontrado" << std::endl;
    }
}