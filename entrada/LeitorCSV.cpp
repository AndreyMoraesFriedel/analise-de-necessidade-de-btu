#include "LeitorCSV.h"

#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;
using namespace simulacao;

namespace entrada {
    bool linhaVazia(const string& s) {
        for (char c : s) {
            if (!isspace(c)) {
                return false;
            }
        }
        return true;
    }

    vector<CenarioSimulacao> LeitorCSV::ler(const string& caminho) {
        vector<CenarioSimulacao> cenarios;
        ifstream arquivo(caminho);
        if (!arquivo.is_open()) {
            cout << "Erro ao abrir CSV!" << endl;
            return cenarios;
        }
        string linha;
        //Ignorar cabeçalho
        getline(arquivo, linha);
        while (getline(arquivo, linha)) {
            if (linhaVazia(linha)) {
                continue;
            }
            stringstream ss(linha);
            vector<string> campos;
            string campo;
            while (getline(ss, campo, ';')) {
                campos.push_back(campo);
            }
            if (campos.size() != 6) {
                cout << "Linha invalida: " << linha << endl;
                continue;
            }
            CenarioSimulacao c(
                stod(campos[0]),
                stod(campos[1]),
                stoi(campos[2]),
                stoi(campos[3]),
                stoi(campos[4]),
                stoi(campos[5])
            );
            cenarios.push_back(c);
        }
        return cenarios;
    }

}