#include "EntradaArquivo.h"
#include <iostream>
using namespace std;

namespace entrada {

    EntradaArquivo::EntradaArquivo(const char* nomeArquivo) {
        arquivo.open(nomeArquivo);
        if (!arquivo.is_open()) {
            cout << "Erro ao abrir arquivo!" << endl;
        }
    }

    void EntradaArquivo::reiniciar() {
        arquivo.clear();
        arquivo.seekg(0);
    }

    double EntradaArquivo::lerLargura() {
        double l;
        arquivo >> l;
        return l;
    }

    double EntradaArquivo::lerComprimento() {
        double c;
        arquivo >> c;
        return c;
    }

    double EntradaArquivo::lerAltura() {
        double a;
        arquivo >> a;
        return a;
    }

    int EntradaArquivo::lerPessoas() {
        int p;
        arquivo >> p;
        return p;
    }

    int EntradaArquivo::lerEletronicos() {
        int e;
        arquivo >> e;
        return e;
    }

    bool EntradaArquivo::lerSolDireto() {
        int valor;
        arquivo >> valor;
        return valor == 1;
    }

    double EntradaArquivo::lerTemperaturaAtual() {
        double t;
        arquivo >> t;
        return t;
    }

    double EntradaArquivo::lerTemperaturaExterna() {
        double t;
        arquivo >> t;
        return t;
    }

    int EntradaArquivo::lerQuantidade(const char* mensagem) {
        int q;
        arquivo >> q;
        return q;
    }

    EntradaArquivo::~EntradaArquivo() {
        if (arquivo.is_open())
            arquivo.close();
    }

}