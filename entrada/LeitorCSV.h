#ifndef LEITORCSV_H
#define LEITORCSV_H

#include <vector>
#include <string>

#include "../simulacao/CenarioSimulacao.h"

namespace entrada {

    class LeitorCSV {

    public:
        static std::vector<simulacao::CenarioSimulacao>
        ler(const std::string& caminho);
    };

}

#endif