#include "aviao.h"
#include "assentoComum.h"
#include "assentoPremium.h"
#include <iostream>

Aviao::Aviao(std::string origem, std::string destino, float tempoVoo, std::string data, std::string horario, int nFileiras, int nColunas, int id) : nFileiras(nFileiras), nColunas(nColunas), origem(origem), destino(destino), tempoVoo(tempoVoo), data(data), horario(horario), id(id) {
    std::vector<Assento *> tempAssentos; // inicia todos os assentos como vazios
    for (int i = 0; i < nFileiras; i++) {
        for (int j = 0; j < nColunas; j++) {
            if (j <= 3) {
                tempAssentos.push_back(new AssentoPremium(i, j, this->id));
            } else {
                tempAssentos.push_back(new AssentoComum(i, j, this->id));
            }
        }
        this->matrixAssentos.push_back(tempAssentos);
        tempAssentos.clear();
    }
}

std::string Aviao::getDados() {
    return "Id: " + std::to_string(this->id) + " - Origem: " + this->origem + " - Destino: " + this->destino + " - Fileiras: " + std::to_string(this->nFileiras) + " - Colunas: " + std::to_string(this->nColunas) + " - Tempo de Voo: " + std::to_string(this->tempoVoo) + "horas - Data: " + this->data + " - Horario: " + this->horario;
}

int Aviao::getId() {
    return this->id;
}

int Aviao::getFileiras() {
    return this->nFileiras;
}

int Aviao::getColunas() {
    return this->nColunas;
}

int Aviao::getNumAssentos() {
    return this->nColunas * this->nFileiras;
}

Assento *Aviao::getAssento(int fileira, int coluna) {
    return this->matrixAssentos[fileira][coluna];
}

void Aviao::listarAssentosDisponiveis() {
    for (int i = 0; i < this->nFileiras; i++) {
        for (int j = 0; j < this->nColunas; j++) {
            if (this->matrixAssentos[i][j]->isOcupado()) {
                std::cout << " X ";
            } else {
                std::cout << " O ";
            }
        }

        std::cout << std::endl;
    }
}

std::string Aviao::getOrigem() {
    return this->origem;
}

std::string Aviao::getDestino() {
    return this->destino;
}

float Aviao::getTempoVoo() {
    return this->tempoVoo;
}

std::string Aviao::getData() {
    return this->data;
}

std::string Aviao::getHorario() {
    return this->horario;
}