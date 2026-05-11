#ifndef RESULTADO_SIMULACAO_H
#define RESULTADO_SIMULACAO_H

#include <string>

namespace simulacao {

class ResultadoSimulacao {

private:

    int id;

    std::string tipo;

    double btu;

public:

    ResultadoSimulacao(
        int id,
        std::string tipo,
        double btu
    );

    int getId() const;

    std::string getTipo() const;

    double getBTU() const;
};

}

#endif