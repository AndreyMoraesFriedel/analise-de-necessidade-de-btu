#ifndef SIMULADOR_H
#define SIMULADOR_H

#include <string>

namespace simulacao {

    class Simulador {

    public:
        void executar(
            const std::string& entradaCSV,
            const std::string& saidaCSV
        );
    };

}

#endif