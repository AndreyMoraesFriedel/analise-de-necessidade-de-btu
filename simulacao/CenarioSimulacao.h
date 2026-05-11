#ifndef CENARIO_SIMULACAO_H
#define CENARIO_SIMULACAO_H

#include <string>

namespace simulacao {

    class CenarioSimulacao {

    private:
        double largura;
        double comprimento;
        int pessoas;
        int televisoes;
        int computadores;
        int celulares;
        bool solDireto;
    public:
        CenarioSimulacao(
            double largura,
            double comprimento,
            int pessoas,
            int televisoes,
            int computadores,
            int celulares,
            bool solDireto
        );
        double getLargura() const;
        double getComprimento() const;
        int getPessoas() const;
        int getTelevisoes() const;
        int getComputadores() const;
        int getCelulares() const;
        bool getSolDireto() const;
    };

}

#endif