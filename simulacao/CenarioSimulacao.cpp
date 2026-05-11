#include "CenarioSimulacao.h"

namespace simulacao {

    CenarioSimulacao::CenarioSimulacao(
        std::string tipo,
        double temperaturaAtual,
        double temperaturaExterna,
        double largura,
        double comprimento,
        double altura,
        int pessoas,
        int televisoes,
        int computadores,
        bool solDireto
    ) {
        this->tipo = tipo;
        this->temperaturaAtual = temperaturaAtual;
        this->temperaturaExterna = temperaturaExterna;
        this->largura = largura;
        this->comprimento = comprimento;
        this->altura = altura;
        this->pessoas = pessoas;
        this->televisoes = televisoes;
        this->computadores = computadores;
        this->solDireto = solDireto;
    }

    std::string CenarioSimulacao::getTipo() const {
        return tipo;
    }

    double CenarioSimulacao::getTemperaturaAtual() const {
        return temperaturaAtual;
    }

    double CenarioSimulacao::getTemperaturaExterna() const {
        return temperaturaExterna;
    }

    double CenarioSimulacao::getLargura() const {
        return largura;
    }

    double CenarioSimulacao::getComprimento() const {
        return comprimento;
    }

    double CenarioSimulacao::getAltura() const {
        return altura;
    }

    int CenarioSimulacao::getPessoas() const {
        return pessoas;
    }

    int CenarioSimulacao::getTelevisoes() const {
        return televisoes;
    }

    int CenarioSimulacao::getComputadores() const {
        return computadores;
    }

    bool CenarioSimulacao::getSolDireto() const {
        return solDireto;
    }

}