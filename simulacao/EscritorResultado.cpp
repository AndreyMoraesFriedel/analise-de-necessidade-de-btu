#include "EscritorResultado.h"

#include <fstream>

using namespace std;

namespace simulacao {

    void EscritorResultado::escrever(const string& caminho,const vector<ResultadoSimulacao>& resultados) {
        ofstream arquivo(caminho);
        arquivo << "id;tipo;btu" << endl;
        for (const auto& r : resultados) {
            arquivo << r.getId() << ";" << r.getTipo() << ";" << r.getBTU() << endl;
        }
        arquivo.close();
    }

}