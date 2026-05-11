#include "ResultadoSimulacao.h"

namespace simulacao {

    ResultadoSimulacao::ResultadoSimulacao(int id, std::string tipo, double btu) {
        this->id = id;
        this->tipo = tipo;
        this->btu = btu;
    }

    int ResultadoSimulacao::getId() const {
        return id;
    }

    std::string ResultadoSimulacao::getTipo() const {
        return tipo;
    }

    double ResultadoSimulacao::getBTU() const {
        return btu;
    }

}