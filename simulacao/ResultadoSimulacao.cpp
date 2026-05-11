#include "ResultadoSimulacao.h"

namespace simulacao {

    ResultadoSimulacao::ResultadoSimulacao(int id,double btu) {
        this->id = id;
        this->btu = btu;
    }

    int ResultadoSimulacao::getId() const {
        return id;
    }

    double ResultadoSimulacao::getBTU() const {
        return btu;
    }

}