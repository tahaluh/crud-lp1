#include "crud.h"

#include <iostream>

Crud::Crud() {
}

// Arquivos
void Crud::salvaArquivos() {
}
void Crud::carregaArquivos() {
}

// Ler
void Crud::lerCancelarVoo() {
    int idVoo;

    std::cout << "Informe o ID do Voo: ";
    std::cin >> idVoo;

    this->cancelaVoo(idVoo);
}
void Crud::lerListarAssentosDisponiveis() {
    int aviaoId;

    std::cout << "Informe o ID do Aviao: ";
    std::cin >> aviaoId;

    this->getAviao(aviaoId)->listarAssentosDisponiveis();
}
void Crud::lerDadosCriarVoo() {
    int nFileiras, nColunas;
    std::string origem, destino, data, horario;
    float tempoVoo;

    std::cout << "Informe os dados do Voo: " << std::endl;
    std::cout << "Quantidade de Fileiras: ";
    std::cin >> nFileiras;

    std::cout << "Quantidade de Colunas: ";
    std::cin >> nColunas;

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

    criarVoo(nFileiras, nColunas, origem, destino, tempoVoo, data, horario);
}
void Crud::lerDadosCriarPassageiro() {
    std::string nome;
    int idade;
    int premium;

    std::cout << "Informe os dados do Passageiro: " << std::endl;

    std::cout << "Nome: ";
    std::cin >> nome;

    std::cout << "Idade: ";
    std::cin >> idade;

    std::cout << "Premium: ";
    std::cin >> premium;

    criarPassageiro(nome, idade, premium == 1);
}
void Crud::lerDeletarPassageiro() {
    int idPassageiro;

    std::cout << "Informe o ID do Passageiro: ";
    std::cin >> idPassageiro;

    this->deletarPassageiro(idPassageiro);
}
void Crud::lerCancelarReserva() {
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

    this->cancelaReserva(idPassageiro, idVoo, fileiraAssento, colunaAssento);
}
void Crud::lerDadosCriarReserva() {
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

    criarReserva(idPassageiro, idVoo, fileiraAssento, colunaAssento);
}

// Criar
Passageiro *Crud::criarPassageiro(std::string nome, int idade, bool premium) {
    Passageiro *passageiro = new Passageiro(nome, idade, premium, this->getNewPassageirosId());
    passageiros.push_back(passageiro);
    return passageiro;
}
Aviao *Crud::criarVoo(int nFileiras, int nColunas, std::string origem, std::string destino, float tempoVoo, std::string data, std::string horario) {
    int newId = this->getNewAvioesId();

    Aviao *aviao = new Aviao(origem, destino, tempoVoo, data, horario, nFileiras, nColunas, this->getNewAvioesId());

    avioes.push_back(aviao);
    return aviao;
}
Reserva *Crud::criarReserva(int passageiroId, int aviaoId, int fileira, int coluna) {
    int aviaoIndex, passageiroIndex;
    bool existe = false;

    for (int i = 0; i < avioes.size(); i++) {
        if (avioes[i]->getId() == aviaoId) {
            aviaoIndex = i;
            existe = true;
            break;
        }
    }

    if (!existe) {
        std::cout << "Aviao nao encontrado" << std::endl;
        return nullptr;
    }

    existe = false;

    for (int i = 0; i < passageiros.size(); i++) {
        if (passageiros[i]->getId() == passageiroId) {
            passageiroIndex = i;
            existe = true;
            break;
        }
    }

    if (!existe) {
        std::cout << "Passageiro nao encontrado" << std::endl;
        return nullptr;
    }

    Assento *assento = avioes[aviaoIndex]->getAssento(fileira, coluna);

    if (assento->isOcupado()) {
        std::cout << "Assento ocupado" << std::endl;
        return nullptr;
    }

    if (!assento->podeReservar(this->passageiros[passageiroIndex])) {
        std::cout << "Assento indisponivel para esse passageiro" << std::endl;
        return nullptr;
    };

    Reserva *reserva = new Reserva(passageiroId, aviaoId, fileira, coluna, this->getNewReservasId());
    reservas.push_back(reserva);

    assento->setReserva(reserva);
    return reserva;
}

// Listar
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

// Get
Passageiro *Crud::getPassageiro(int id) {
    int i, size = passageiros.size();

    for (i = 0; i < size; i++) {
        if (passageiros[i]->getId() == id) {
            return passageiros[i];
        }
    }

    return nullptr;
}
Aviao *Crud::getAviao(int id) {
    int i, size = avioes.size();

    for (i = 0; i < size; i++) {
        if (avioes[i]->getId() == id) {
            return avioes[i];
        }
    }

    return nullptr;
}
Reserva *Crud::getReserva(int id) {
    int i, size = reservas.size();

    for (i = 0; i < size; i++) {
        if (reservas[i]->getId() == id) {
            return reservas[i];
        }
    }

    return nullptr;
}

// NewId
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

// Deletar
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
void Crud::deletarPassageiro(int idPassageiro) {
    int i, size = passageiros.size();
    int indexPassageiro;

    for (i = 0; i < size; i++) {
        if (passageiros[i]->getId() == idPassageiro) {
            indexPassageiro = i;
            break;
        }
    }

    if (passageiros[indexPassageiro]->getNumReservas() > 0) {
        std::cout << "Passageiro não pode ser deletado, pois possui reservas" << std::endl;
    } else {
        passageiros.erase(passageiros.begin() + indexPassageiro);
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