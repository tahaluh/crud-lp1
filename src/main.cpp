#include <fstream>
#include <iostream>

#include <crud.h>

using namespace std;

void exibeMenuVoo() {
    cout << endl
         << "------------------------" << endl;
    cout << "1 - Cadastrar Voo" << endl;
    cout << "2 - Listar Voos" << endl;
    cout << "3 - Alterar Voo" << endl;
    cout << "4 - Cancelar Voo" << endl;
    cout << "5 - Voltar" << endl;
    cout << "------------------------" << endl;
};
void menuVoo(Crud *crud) {
    while (true) {
        exibeMenuVoo();

        int opcao;
        cin >> opcao;

        if (opcao == 1) {
            crud->lerDadosCriarVoo();
            cout << "Cadastrando Voo..." << endl;
        } else if (opcao == 2) {
            cout << "Listando Voos..." << endl;
            crud->listarVoos();
        } else if (opcao == 3) {
            cout << "Alterando Voo..." << endl;
        } else if (opcao == 4) {
            crud->lerCancelarVoo();
            cout << "Cancelando Voo..." << endl;
        } else if (opcao == 5) {
            break;
        }
    }
}
void exibeMenuPassageiro() {
    cout << endl
         << "------------------------" << endl;
    cout << "1 - Cadastrar Passageiro" << endl;
    cout << "2 - Listar Passageiros" << endl;
    cout << "3 - Alterar Passageiro" << endl;
    cout << "4 - Deletar Passageiro" << endl;
    cout << "5 - Voltar" << endl;
    cout << "------------------------" << endl;
};
void menuPassageiro(Crud *crud) {
    while (true) {
        exibeMenuPassageiro();

        int opcao;
        cin >> opcao;

        if (opcao == 1) {
            crud->lerDadosCriarPassageiro();
            cout << "Cadastrando Passageiro..." << endl;
        } else if (opcao == 2) {
            cout << "Listando Passageiros..." << endl;
            crud->listarPassageiros();
        } else if (opcao == 3) {
            cout << "Alterando Passageiro..." << endl;
        } else if (opcao == 4) {
            crud->lerDeletarPassageiro();
            cout << "Deletando Passageiro..." << endl;
        } else if (opcao == 5) {
            break;
        }
    }
}
void exibeMenuPassagem() {
    cout << endl
         << "------------------------" << endl;
    cout << "1 - Comprar Passagem" << endl;
    cout << "2 - Listar Reservas" << endl;
    cout << "3 - Listar Assentos Disponiveis" << endl;
    cout << "4 - Alterar Assento" << endl;
    cout << "5 - Cancelar Pasasgem" << endl;
    cout << "6 - Voltar" << endl;
    cout << "------------------------" << endl;
};
void menuPassagem(Crud *crud) {
    while (true) {
        exibeMenuPassagem();

        int opcao;
        cin >> opcao;

        if (opcao == 1) {
            crud->lerDadosCriarReserva();
            cout << "Comprando Passagem..." << endl;
        } else if (opcao == 2) {
            cout << "Listando Reservas..." << endl;
            crud->listarReservas();
        } else if (opcao == 3) {
            cout << "Listando Assentos Disponiveis..." << endl;
            crud->lerListarAssentosDisponiveis();
        } else if (opcao == 4) {
            cout << "Alterando Assento..." << endl;
        } else if (opcao == 5) {
            crud->lerCancelarReserva();
            cout << "Cancelando Passagem..." << endl;
        } else if (opcao == 6) {
            break;
        }
    }
}
void exibeMenuGeral() {
    cout << endl
         << "------------------------" << endl;
    cout << "1 - Voos" << endl;
    cout << "2 - Passageiros" << endl;
    cout << "3 - Passagens" << endl;
    cout << "4 - Sair" << endl;
    cout << "------------------------" << endl;
};
void menuGeral(Crud *crud) {
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
                menuVoo(crud);
            } else {
                cout << "Senha Invalida" << endl;
                continue;
            }
        } else if (opcao == 2) {
            menuPassageiro(crud);
        } else if (opcao == 3) {
            menuPassagem(crud);
        } else if (opcao == 4) {
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
void iniciaPrograma(Crud *crud) {
    cout << "Iniciando Programa..." << endl;
    crud->carregaArquivos();
}
void encerraPrograma(Crud *crud) {
    crud->salvaArquivos();
    cout << "Saindo..." << endl;
}
int main() {
    Crud *crud = new Crud();

    iniciaPrograma(crud);

    menuGeral(crud);

    encerraPrograma(crud);

    return 0;
}