#include "CenarioSimulacao.h"

namespace simulacao {

    CenarioSimulacao::CenarioSimulacao(
        double largura,
        double comprimento,
        int pessoas,
        int televisoes,
        int computadores,
        bool solDireto
    ) {
        this->largura = largura;
        this->comprimento = comprimento;
        this->pessoas = pessoas;
        this->televisoes = televisoes;
        this->computadores = computadores;
        this->solDireto = solDireto;
    }


    double CenarioSimulacao::getLargura() const {
        return largura;
    }

    double CenarioSimulacao::getComprimento() const {
        return comprimento;
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