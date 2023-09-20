#include "aviao.h"

Aviao::Aviao(int nFileiras, int nColunas) : nFileiras(nFileiras), nColunas(nColunas) {
    std::vector<Assento> tempAssentos; // inicia todos os assentos como vazios
    for (int i = 0; i < nFileiras; i++) {
        for (int j = 0; j < nColunas; j++) {
            tempAssentos.push_back(Assento(i, j));
        }
        this->matrixAssentos.push_back(tempAssentos);
        tempAssentos.clear();
    }
}