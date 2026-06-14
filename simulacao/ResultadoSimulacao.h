#ifndef RESULTADO_SIMULACAO_H
#define RESULTADO_SIMULACAO_H

#include <odb/core.hxx>

namespace simulacao {

    #pragma db object
    class ResultadoSimulacao {

        friend class odb::access;

    private:

        #pragma db id auto
        int id;

        double largura;
        double comprimento;

        int pessoas;
        int televisoes;
        int computadores;
        int celulares;

        bool solDireto;

        double btu;

    public:

        ResultadoSimulacao();

        ResultadoSimulacao(
            double largura,
            double comprimento,
            int pessoas,
            int televisoes,
            int computadores,
            int celulares,
            bool solDireto,
            double btu
        );

        int getId() const;

        double getLargura() const;
        double getComprimento() const;

        int getPessoas() const;
        int getTelevisoes() const;
        int getComputadores() const;
        int getCelulares() const;

        bool getSolDireto() const;

        double getBTU() const;
    };

}

#endif
