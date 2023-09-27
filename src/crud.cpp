#include "crud.h"

#include <cstring>
#include <fstream>
#include <iostream>

Crud::Crud() {
}

// Arquivos
void Crud::salvaArquivos() {
    int i, size;

    std::fstream fp;

    // aviao

    size = this->avioes.size();
    fp.open("./db/avioes.txt", std::ios::out | std::ios::trunc);

    if (!fp.is_open()) {
        std::cerr << "Erro ao salvar o arquivo avioes: " << std::strerror(errno) << std::endl;
        return;
    }

    for (i = 0; i < size; i++) {
        fp << this->avioes[i]->getId() << std::endl;
        fp << this->avioes[i]->getFileiras() << std::endl;
        fp << this->avioes[i]->getColunas() << std::endl;
        fp << this->avioes[i]->getOrigem() << std::endl;
        fp << this->avioes[i]->getDestino() << std::endl;
        fp << this->avioes[i]->getTempoVoo() << std::endl;
        fp << this->avioes[i]->getData() << std::endl;
        fp << this->avioes[i]->getHorario() << std::endl;
    }

    fp.close();

    // passageiro

    size = this->passageiros.size();
    fp.open("./db/passageiros.txt", std::ios::out | std::ios::trunc);

    if (!fp.is_open()) {
        std::cerr << "Erro ao salvar o arquivo passageiros";
        return;
    }

    for (i = 0; i < size; i++) {
        fp << this->passageiros[i]->getId() << std::endl;
        fp << this->passageiros[i]->getNome() << std::endl;
        fp << this->passageiros[i]->getIdade() << std::endl;
        fp << this->passageiros[i]->isPremium() << std::endl;
    }

    fp.close();

    // reserva

    size = this->reservas.size();
    fp.open("./db/reservas.txt", std::ios::out | std::ios::trunc);

    if (!fp.is_open()) {
        std::cerr << "Erro ao salvar o arquivo reservas";
        return;
    }

    for (i = 0; i < size; i++) {
        fp << this->reservas[i]->getId() << std::endl;
        fp << this->reservas[i]->getIdPassageiro() << std::endl;
        fp << this->reservas[i]->getIdVoo() << std::endl;
        fp << this->reservas[i]->getFileira() << std::endl;
        fp << this->reservas[i]->getColuna() << std::endl;
    }

    fp.close();

    std::cout << "Arquivos salvos" << std::endl;
}
void Crud::carregaArquivos() {
    std::ifstream fp;

    // aviao
    int id, nFileiras, nColunas;
    float tempoVoo;
    std::string origem, destino, data, horario;

    fp.open("./db/avioes.txt");

    if (!fp.is_open()) {
        std::cerr << "Erro ao carregar o arquivo avioes";
        return;
    }

    std::streambuf *originalCin = std::cin.rdbuf(fp.rdbuf()); // alguem por favor me ajuda

    while (std::cin >> id >> nFileiras >> nColunas >> origem >> destino >> tempoVoo >> data >> horario) {
        this->criarVoo(nFileiras, nColunas, origem, destino, tempoVoo, data, horario, id);

        if (fp.eof()) {
            break;
        }
    }

    fp.close();

    // passageiro

    std::string nome;
    int idade;
    bool premium;

    fp.open("./db/passageiros.txt");

    if (!fp.is_open()) {
        std::cerr << "Erro ao carregar o arquivo avioes";
        return;
    }

    std::cin.rdbuf(fp.rdbuf()); // alguem por favor me ajuda

    while (std::cin >> id >> nome >> idade >> premium) {

        this->criarPassageiro(nome, idade, premium, id);

        if (fp.eof()) {
            break;
        }
    }

    fp.close();

    // reserva

    int passageiroId, aviaoId, fileira, coluna;

    fp.open("./db/reservas.txt");

    if (!fp.is_open()) {
        std::cerr << "Erro ao carregar o arquivo avioes";
        return;
    }

    std::cin.rdbuf(fp.rdbuf()); // alguem por favor me ajuda

    while (std::cin >> id >> passageiroId >> aviaoId >> fileira >> coluna) {

        this->criarReserva(passageiroId, aviaoId, fileira, coluna, id);

        if (fp.eof()) {
            break;
        }
    }

    // Restaure a entrada padrão original
    std::cin.rdbuf(originalCin);

    fp.close();
}
void Crud::exibirRelatorio() {
    std::cout << "------------------------" << std::endl;
    std::cout << "Relatorio" << std::endl;
    std::cout << "------------------------" << std::endl;
    std::cout << "Total de voos: " << this->avioes.size() << std::endl;
    std::cout << "Total de passageiros: " << this->passageiros.size() << std::endl;
    std::cout << "Total de reservas: " << this->reservas.size() << std::endl;
    std::cout << "------------------------" << std::endl;
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
    Aviao *aviao;

    std::cout << "Informe o ID do Aviao: ";
    std::cin >> aviaoId;

    aviao = this->getAviao(aviaoId);

    if (aviao != nullptr) {
        aviao->listarAssentosDisponiveis();
    } else {
        std::cout << "Aviao nao encontrado" << std::endl;
    }
}
void Crud::lerDadosCriarVoo(bool usuario) {
    int nFileiras, nColunas, id = 0;
    std::string origem, destino, data, horario;
    float tempoVoo;

    if (!usuario) {
        std::cin >> id;
    }

    if (usuario) {
        std::cout << "Informe os dados do Voo: " << std::endl;
        std::cout << "Quantidade de Fileiras: ";
    }
    std::cin >> nFileiras;

    if (usuario) {
        std::cout << "Quantidade de Colunas: ";
    }
    std::cin >> nColunas;

    if (usuario) {
        std::cout << "Origem: ";
    }
    std::cin >> origem;

    if (usuario) {
        std::cout << "Destino: ";
    }
    std::cin >> destino;

    if (usuario) {
        std::cout << "Tempo de Voo: ";
    }
    std::cin >> tempoVoo;

    if (usuario) {
        std::cout << "Data: ";
    }
    std::cin >> data;

    if (usuario) {
        std::cout << "Horario: ";
    }
    std::cin >> horario;

    criarVoo(nFileiras, nColunas, origem, destino, tempoVoo, data, horario, id);
}
void Crud::lerDadosCriarReserva(bool usuario) {
    int id = 0;
    int idPassageiro;
    int idVoo;
    int fileiraAssento;
    int colunaAssento;

    if (!usuario) {
        std::cin >> id;
    }

    if (usuario) {
        std::cout << "Informe os dados da Reserva: " << std::endl;
        std::cout << "ID Passageiro: ";
    }
    std::cin >> idPassageiro;

    if (usuario) {
        std::cout << "ID Voo: ";
    }
    std::cin >> idVoo;

    if (usuario) {
        std::cout << "Fileira: ";
    }
    std::cin >> fileiraAssento;

    if (usuario) {
        std::cout << "Coluna: ";
    }
    std::cin >> colunaAssento;

    criarReserva(idPassageiro, idVoo, fileiraAssento, colunaAssento, id);
}
void Crud::lerDadosCriarPassageiro(bool usuario) {
    std::string nome;
    int idade, id = 0;
    int premium;

    if (!usuario) {
        std::cin >> id;
    }

    if (usuario) {
        std::cout << "Informe os dados do Passageiro: " << std::endl;
        std::cout << "Nome: ";
    }
    std::cin >> nome;

    if (usuario) {
        std::cout << "Idade: ";
    }
    std::cin >> idade;

    if (usuario) {
        std::cout << "Premium: ";
    }
    std::cin >> premium;

    criarPassageiro(nome, idade, premium == 1, id);
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

// Editar

void Crud::lerEditarOrigemVoo() {
    int id, i, aviaoSize = this->avioes.size();
    bool existe = false;
    std::string newOrigem;

    std::cout << "Informe o ID do Voo: ";
    std::cin >> id;

    std::cout << "Informe a nova Origem: ";
    std::cin >> newOrigem;

    for (i = 0; i < aviaoSize; i++) {
        if (avioes[i]->getId() == id) {
            avioes[i]->setOrigem(newOrigem);
            existe = true;
            break;
        }
    }

    if (!existe) {
        std::cout << "Voo inexistente" << std::endl;
    }
}
void Crud::lerEditarDestinoVoo() {
    int id, i, aviaoSize = this->avioes.size();
    bool existe = false;
    std::string newDestino;

    std::cout << "Informe o ID do Voo: ";
    std::cin >> id;

    std::cout << "Informe o novo Destino: ";
    std::cin >> newDestino;

    for (i = 0; i < aviaoSize; i++) {
        if (avioes[i]->getId() == id) {
            avioes[i]->setDestino(newDestino);
            existe = true;
            break;
        }
    }

    if (!existe) {
        std::cout << "Voo inexistente" << std::endl;
    }
}
void Crud::lerEditarDataVoo() {
    int id, i, aviaoSize = this->avioes.size();
    bool existe = false;
    std::string newData;

    std::cout << "Informe o ID do Voo: ";
    std::cin >> id;

    std::cout << "Informe a nova Data: ";
    std::cin >> newData;

    for (i = 0; i < aviaoSize; i++) {
        if (avioes[i]->getId() == id) {
            avioes[i]->setData(newData);
            existe = true;
            break;
        }
    }

    if (!existe) {
        std::cout << "Voo inexistente" << std::endl;
    }
}
void Crud::lerEditarHorarioVoo() {
    int id, i, aviaoSize = this->avioes.size();
    bool existe = false;
    std::string newHorario;

    std::cout << "Informe o ID do Voo: ";
    std::cin >> id;

    std::cout << "Informe o novo Horario: ";
    std::cin >> newHorario;

    for (i = 0; i < aviaoSize; i++) {
        if (avioes[i]->getId() == id) {
            avioes[i]->setHorario(newHorario);
            existe = true;
            break;
        }
    }

    if (!existe) {
        std::cout << "Voo inexistente" << std::endl;
    }
}

void Crud::lerEditarNomePassageiro() {
    int id, i, passageiroSize = this->passageiros.size();
    bool existe = false;
    std::string newNome;

    std::cout << "Informe o ID do Passageiro: ";
    std::cin >> id;

    std::cout << "Informe o novo Nome: ";
    std::cin >> newNome;

    for (i = 0; i < passageiroSize; i++) {
        if (passageiros[i]->getId() == id) {
            passageiros[i]->setNome(newNome);
            existe = true;
            break;
        }
    }

    if (!existe) {
        std::cout << "Passageiro inexistente" << std::endl;
    }
}
void Crud::lerEditarIdadePassageiro() {
    int id, i, passageiroSize = this->passageiros.size();
    bool existe = false;
    int newIdade;

    std::cout << "Informe o ID do Passageiro: ";
    std::cin >> id;

    std::cout << "Informe a nova idade: ";
    std::cin >> newIdade;

    for (i = 0; i < passageiroSize; i++) {
        if (passageiros[i]->getId() == id) {
            passageiros[i]->setIdade(newIdade);
            existe = true;
            break;
        }
    }

    if (!existe) {
        std::cout << "Passageiro inexistente" << std::endl;
    }
}
void Crud::lerEditarPremiumPassageiro() {
    int id, i, passageiroSize = this->passageiros.size();
    bool existe = false;
    bool newPremium;

    std::cout << "Informe o ID do Passageiro: ";
    std::cin >> id;

    std::cout << "Informe o novo Status Premium: ";
    std::cin >> newPremium;

    for (i = 0; i < passageiroSize; i++) {
        if (passageiros[i]->getId() == id) {
            passageiros[i]->setPremium(newPremium);
            existe = true;
            break;
        }
    }

    if (!existe) {
        std::cout << "Passageiro inexistente" << std::endl;
    }
}

void Crud::lerEditarPosicaoAssento() {
    int id, i, j, reservasSize = this->reservas.size();
    bool existe = false, disponivel = false;
    int newColuna, newFileira;

    std::cout << "Informe o ID da Reserva: ";
    std::cin >> id;

    std::cout << "Informe a nova Fileira: ";
    std::cin >> newFileira;

    std::cout << "Informe a nova Coluna: ";
    std::cin >> newColuna;

    for (i = 0; i < reservasSize; i++) {
        if (reservas[i]->getId() == id) {
            existe = true;
            if (this->criarReserva(reservas[i]->getIdPassageiro(), reservas[i]->getIdVoo(), newFileira, newColuna, id) != nullptr) {
                disponivel = true;
                this->cancelaReserva(reservas[i]->getIdPassageiro(), reservas[i]->getIdVoo(), reservas[i]->getFileira(), reservas[i]->getColuna());
            }
            break;
        }
    }

    if (!existe) {
        std::cout << "Reserva inexistente" << std::endl;
    }

    if (!disponivel) {
        std::cout << "Assento indisponivel" << std::endl;
    }
}

// Criar
Passageiro *Crud::criarPassageiro(std::string nome, int idade, bool premium, int id) {
    int newId = id ? id : this->getNewPassageirosId();
    Passageiro *passageiro = new Passageiro(nome, idade, premium, newId);
    passageiros.push_back(passageiro);
    return passageiro;
}
Aviao *Crud::criarVoo(int nFileiras, int nColunas, std::string origem, std::string destino, float tempoVoo, std::string data, std::string horario, int id) {
    int newId = id ? id : this->getNewAvioesId();

    Aviao *aviao = new Aviao(origem, destino, tempoVoo, data, horario, nFileiras, nColunas, this->getNewAvioesId());

    avioes.push_back(aviao);
    return aviao;
}
Reserva *Crud::criarReserva(int passageiroId, int aviaoId, int fileira, int coluna, int id) {
    int newId = id ? id : this->getNewReservasId();
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

    Reserva *reserva = new Reserva(passageiroId, aviaoId, fileira, coluna, newId);
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
    int i, size = reservas.size(), avioesSize = avioes.size();
    int indexPassageiro, indexVoo;
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

            existe = true;

            for (i = 0; i < avioesSize; i++) { // cancela a reserva no assento
                if (avioes[i]->getId() == idVoo) {
                    avioes[i]->getAssento(fileiraAssento, colunaAssento)->cancelaReserva();
                    break;
                }
            }

            break;
        }
    }

    if (existe) {
        std::cout << "Reserva cancelada com sucesso" << std::endl;
    } else {
        std::cout << "Reserva não encontrada" << std::endl;
    }
}
void Crud::cancelaReservasVoo(int idVoo) {
    int i, j, k;
    int vooIndex, indexPassageiro;
    int avioesSize = avioes.size(), reservasSize = reservas.size();
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
        for (j = 0; j < fileirasAviao; j++) {    // para cada fileira
            for (k = 0; k < colunasAviao; k++) { // para cada coluna (assento)
                for (i = 0; i < reservasSize; i++) {
                    if (reservas[i]->getIdVoo() == idVoo && reservas[i]->getFileira() == j && reservas[i]->getColuna() == k) {
                        this->cancelaReserva(reserva->getIdPassageiro(), idVoo, j, k);
                    }
                }
            }
        }
    } else {
        std::cout << "Voo não encontrado" << std::endl;
    }
}
void Crud::deletarPassageiro(int idPassageiro) {
    int i, passageirosSize = passageiros.size(), reservasSize = reservas.size();
    int indexPassageiro;
    bool existe = false, hasReservas = false;

    for (i = 0; i < passageirosSize; i++) {
        if (passageiros[i]->getId() == idPassageiro) {
            indexPassageiro = i;
            existe = true;
            break;
        }
    }

    if (!existe) {
        std::cout << "Passageiro não encontrado" << std::endl;
        return;
    }

    for (i = 0; i < reservasSize; i++) {
        if (reservas[i]->getIdPassageiro() == idPassageiro) {
            hasReservas = true;
            break;
        }
    }

    if (hasReservas) {
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
        cancelaReservasVoo(idVoo);
        avioes.erase(avioes.begin() + vooIndex);
        std::cout << "Voo cancelado com sucesso" << std::endl;
    } else {
        std::cout << "Voo não encontrado" << std::endl;
    }
}