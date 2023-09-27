#include "aviao.h"
#include "assentoComum.h"
#include "assentoPremium.h"

Aviao::Aviao(std::string origem, std::string destino, float tempoVoo, std::string data, std::string horario, int nFileiras, int nColunas, int id) : nFileiras(nFileiras), nColunas(nColunas), id(id) {
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
    return "Id: " + std::to_string(this->id) + " - Origem: " + this->origem + " - Destino: " + this->destino + " - Tempo de Voo: " + std::to_string(this->tempoVoo) + "horas - Data: " + this->data + " - Horario: " + this->horario;
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

