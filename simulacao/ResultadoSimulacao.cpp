#include "ResultadoSimulacao.h"

namespace simulacao {

    ResultadoSimulacao::ResultadoSimulacao() {}

    ResultadoSimulacao::ResultadoSimulacao(double btu) {
        this->btu = btu;
    }

    int ResultadoSimulacao::getId() const {
        return id;
    }

    double ResultadoSimulacao::getBTU() const {
        return btu;
    }

}
