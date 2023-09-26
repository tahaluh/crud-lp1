#include "aviao.h"
#include "assentoComum.h"
#include "assentoPremium.h"

Aviao::Aviao(int nFileiras, int nColunas) : nFileiras(nFileiras), nColunas(nColunas) {
    std::vector<Assento> tempAssentos; // inicia todos os assentos como vazios
    for (int i = 0; i < nFileiras; i++) {
        for (int j = 0; j < nColunas; j++) {
            if (j <= 3) {
                tempAssentos.push_back(AssentoPremium(i, j, this->id));
            } else {
                tempAssentos.push_back(AssentoComum(i, j, this->id));
            }
        }
        this->matrixAssentos.push_back(tempAssentos);
        tempAssentos.clear();
    }
}