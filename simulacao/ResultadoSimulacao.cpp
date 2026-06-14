#include "ResultadoSimulacao.h"

namespace simulacao {

    ResultadoSimulacao::ResultadoSimulacao() {}

    ResultadoSimulacao::ResultadoSimulacao(
        double largura,
        double comprimento,
        int pessoas,
        int televisoes,
        int computadores,
        int celulares,
        bool solDireto,
        double btu
    ) {
        this->largura = largura;
        this->comprimento = comprimento;

        this->pessoas = pessoas;
        this->televisoes = televisoes;
        this->computadores = computadores;
        this->celulares = celulares;

        this->solDireto = solDireto;

        this->btu = btu;
    }

    int ResultadoSimulacao::getId() const {
        return id;
    }

    double ResultadoSimulacao::getLargura() const {
        return largura;
    }

    double ResultadoSimulacao::getComprimento() const {
        return comprimento;
    }

    int ResultadoSimulacao::getPessoas() const {
        return pessoas;
    }

    int ResultadoSimulacao::getTelevisoes() const {
        return televisoes;
    }

    int ResultadoSimulacao::getComputadores() const {
        return computadores;
    }

    int ResultadoSimulacao::getCelulares() const {
        return celulares;
    }

    bool ResultadoSimulacao::getSolDireto() const {
        return solDireto;
    }

    double ResultadoSimulacao::getBTU() const {
        return btu;
    }

}
