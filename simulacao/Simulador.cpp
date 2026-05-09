#include <iostream>
#include <string>
#include "Simulador.h"

#include "../calculos/CalculadoraBTU.h"
#include "../calculos/CalculadoraBTUAvancado.h"

#include "../entrada/EntradaConsole.h"
#include "../entrada/EntradaArquivo.h"

#include "../ambiente/Ambiente.h"
#include "../ambiente/Pessoa.h"
#include "../ambiente/Janela.h"

#include "../equipamentos/Televisao.h"
#include "../equipamentos/Computador.h"
#include "../equipamentos/Luz.h"

using namespace entrada;
using namespace simulacao;
using namespace ambiente;
using namespace equipamentos;
using namespace std;

Simulador::Simulador() {
    entrada = nullptr;
}

void Simulador::executar() {
    escolherTipoEntrada();
    int opcao;
    do {
        mostrarMenu();
        cin >> opcao;
        executarOpcao(opcao);
    } while (opcao != 0);
    delete entrada;
}

void Simulador::mostrarMenu() {
    cout << "\n===== SIMULADOR AR CONDICIONADO =====" << endl;
    cout << "1 - Calcular BTU (Simples)" << endl;
    cout << "2 - Calcular BTU (Avancado - POO)" << endl;
    cout << "0 - Sair" << endl;
    cout << "Escolha uma opcao: ";
}

void Simulador::executarOpcao(int opcao) {
    EntradaArquivo* ea = dynamic_cast<EntradaArquivo*>(entrada);
    if (ea != nullptr) {
        ea->reiniciar();
    }
    switch (opcao) {
        case 1:
            executarBTUSimples();
            break;
        case 2:
            executarBTUAvancado();
            break;
        case 0:
            cout << "Encerrando..." << endl;
            break;
        default:
            cout << "Opcao invalida!" << endl;
    }
}

void Simulador::escolherTipoEntrada() {
    int opcao;
    cout << "===== TIPO DE ENTRADA =====" << endl;
    cout << "1 - Console" << endl;
    cout << "2 - Arquivo" << endl;
    cout << "Escolha: ";
    cin >> opcao;
    if (opcao == 1) {
        entrada = new EntradaConsole();
    } else {
        string nomeArquivo;
        cout << "Nome do arquivo: ";
        cin >> nomeArquivo;
        entrada = new EntradaArquivo(
            nomeArquivo.c_str()
        );
    }
}

void Simulador::executarBTUSimples() {
    double largura = entrada->lerLargura();
    double comprimento = entrada->lerComprimento();
    double area = largura * comprimento;
    int pessoas = entrada->lerPessoas();
    int eletronicos = entrada->lerEletronicos();
    bool sol = entrada->lerSolDireto();
    double resultado = calculos::CalculadoraBTU::calcular(
        area,
        pessoas - 1,
        eletronicos,
        sol
    );
    cout << "\nBTU (Simples): " << resultado << endl;
}

void Simulador::executarBTUAvancado() {
    double tempAtual = entrada->lerTemperaturaAtual();
    double tempExterna = entrada->lerTemperaturaExterna();
    double largura = entrada->lerLargura();
    double comprimento = entrada->lerComprimento();
    double altura = entrada->lerAltura();
    Ambiente amb(
        tempAtual,
        tempExterna,
        largura,
        comprimento,
        altura
    );
    // Pessoas
    int numPessoas = entrada->lerPessoas();
    for (int i = 0; i < numPessoas; i++) {
        amb.adicionarPessoa(Pessoa());
    }
    // TVs
    int numTV = entrada->lerQuantidade(
        "Quantidade de TVs: "
    );
    for (int i = 0; i < numTV; i++) {
        auto* tv = new Televisao();
        tv->ligar();
        amb.adicionarAparelho(tv);
    }
    // Computadores
    int numPC = entrada->lerQuantidade(
        "Quantidade de computadores: "
    );
    for (int i = 0; i < numPC; i++) {
        auto* pc = new Computador();
        pc->ligar();
        amb.adicionarAparelho(pc);
    }
    // Luz padrão
    Luz luz(100);
    luz.ligar();
    amb.adicionarLuz(luz);
    // Sol direto
    bool sol = entrada->lerSolDireto();
    amb.adicionarJanela(
        Janela(false, sol)
    );
    double resultado = calculos::CalculadoraBTUAvancado::calcular(amb);
    cout << "\nBTU (Avancado): " << resultado << endl;
}