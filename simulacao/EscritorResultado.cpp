#include "EscritorResultado.h"

#include <fstream>

using namespace std;

namespace simulacao {

    void EscritorResultado::escrever( const string& caminho, const vector<ResultadoSimulacao>& resultados) {
        ofstream arquivo(caminho);
        arquivo << "id;btu\n";
        for (const auto& r : resultados) {
            arquivo << r.getId() << ";" << r.getBTU() << endl;
        }
        arquivo.close();
    }

}