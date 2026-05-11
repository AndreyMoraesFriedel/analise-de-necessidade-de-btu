#ifndef ESCRITOR_RESULTADO_H
#define ESCRITOR_RESULTADO_H

#include <vector>
#include <string>

#include "ResultadoSimulacao.h"

namespace simulacao {

class EscritorResultado {
    public:
        static void escrever(
            const std::string& caminho,
            const std::vector<ResultadoSimulacao>& resultados
        );
};

}

#endif