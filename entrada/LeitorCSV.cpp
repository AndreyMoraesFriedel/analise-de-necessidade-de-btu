#include "LeitorCSV.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
using namespace simulacao;

bool linhaVazia(const string& s) {

    for (char c : s) {
        if (!isspace(c)) {
            return false;
        }
    }
    return true;
}

namespace entrada {

    vector<CenarioSimulacao>
    LeitorCSV::ler(const string& caminho) {
        vector<CenarioSimulacao> cenarios;
        ifstream arquivo(caminho);
        if (!arquivo.is_open()) {
            cout << "Erro ao abrir CSV!" << endl;
            return cenarios;
        }
        string linha;
        //Ignora cabeçalho
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
            if (campos.size() != 10) {
                cout << "Linha invalida: " << linha << endl;
                continue;
            }
            CenarioSimulacao c(
                campos[0],
                stod(campos[1]),
                stod(campos[2]),
                stod(campos[3]),
                stod(campos[4]),
                stod(campos[5]),
                stoi(campos[6]),
                stoi(campos[7]),
                stoi(campos[8]),
                stoi(campos[9])
            );
            cenarios.push_back(c);
        }
        return cenarios;
    }

}