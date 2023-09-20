#include <fstream>
#include <iostream>

using namespace std;

void exibeMenuVoo() {
    cout << "------------------------" << endl;
    cout << "1 - Cadastrar Voo" << endl;
    cout << "2 - Listar Voos" << endl;
    cout << "3 - Alterar Voo" << endl;
    cout << "4 - Cancelar Voo" << endl;
    cout << "5 - Voltar" << endl;
    cout << "------------------------" << endl;
};
void menuVoo() {
    while (true) {
        exibeMenuVoo();

        int opcao;
        cin >> opcao;

        if (opcao == 1) {
            cout << "Cadastrando Voo..." << endl;
        } else if (opcao == 2) {
            cout << "Listando Voos..." << endl;
        } else if (opcao == 3) {
            cout << "Alterando Voo..." << endl;
        } else if (opcao == 4) {
            cout << "Cancelando Voo..." << endl;
        } else if (opcao == 5) {
            break;
        }
    }
}
void exibeMenuPassagem() {
    cout << "------------------------" << endl;
    cout << "1 - Comprar Passagem" << endl;
    cout << "2 - Listar Assentos Disponiveis" << endl;
    cout << "3 - Alterar Assento" << endl;
    cout << "4 - Cancelar Pasasgem" << endl;
    cout << "5 - Voltar" << endl;
    cout << "------------------------" << endl;
};
void menuPassagem() {
    while (true) {
        exibeMenuPassagem();

        int opcao;
        cin >> opcao;

        if (opcao == 1) {
            cout << "Comprando Passagem..." << endl;
        } else if (opcao == 2) {
            cout << "Listando Assentos Disponiveis..." << endl;
        } else if (opcao == 3) {
            cout << "Alterando Assento..." << endl;
        } else if (opcao == 4) {
            cout << "Cancelando Passagem..." << endl;
        } else if (opcao == 5) {
            break;
        }
    }
}
void exibeMenuGeral() {
    cout << "------------------------" << endl;
    cout << "1 - Voos" << endl;
    cout << "2 - Passagem" << endl;
    cout << "3 - Sair" << endl;
    cout << "------------------------" << endl;
};
void menuGeral() {
    while (true) {
        exibeMenuGeral();
        int opcao;
        cin >> opcao;

        string senhaMestre = "123";
        string senha;

        if (opcao == 1) {
            cout << "Insira a senha: ";
            cin >> senha;

            if (senha == senhaMestre) {
                exibeMenuVoo();
            } else {
                cout << "Senha Invalida" << endl;
                continue;
            }
        } else if (opcao == 2) {
            menuPassagem();
        } else if (opcao == 3) {
            break;
        } else {
            cout << "Opcao Invalida" << endl;
        }
    }
}
void carregaArquivos() {
    cout << "Carregando Aquivos..." << endl;
    string linha;
    int numLinha = 0;
    ifstream fp;

    fp.open("endereco.json");

    if (!fp.is_open()) {
        cout << "Erro ao abrir arquivo" << endl;
        return;
    }

    while (numLinha) {
        if (numLinha == 1) {
            getline(fp, linha);
        }
        getline(fp, linha);

        if (numLinha == 2) {
            break;
        }
        numLinha++;
    }
}
void salvaArquivos() {
    cout << "Salvando Aquivos..." << endl;
}
void encerraPrograma() {
    salvaArquivos();
    cout << "Saindo..." << endl;
}
int main() {
    cout << "Iniciando Programa..." << endl;

    menuGeral();

    encerraPrograma();

    return 0;
}