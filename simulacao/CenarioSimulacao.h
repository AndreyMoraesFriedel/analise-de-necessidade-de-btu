#ifndef CENARIO_SIMULACAO_H
#define CENARIO_SIMULACAO_H

#include <string>

namespace simulacao {

    class CenarioSimulacao {

    private:
        std::string tipo;
        double temperaturaAtual;
        double temperaturaExterna;
        double largura;
        double comprimento;
        double altura;
        int pessoas;
        int televisoes;
        int computadores;
        bool solDireto;
    public:
        CenarioSimulacao(
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
        );
        std::string getTipo() const;
        double getTemperaturaAtual() const;
        double getTemperaturaExterna() const;
        double getLargura() const;
        double getComprimento() const;
        double getAltura() const;
        int getPessoas() const;
        int getTelevisoes() const;
        int getComputadores() const;
        bool getSolDireto() const;
    };

}

#endif