#include "Pessoa.h"

namespace ambiente {

    Pessoa::Pessoa(double calor) {
        this->calorGerado = calor;
    }

    double Pessoa::gerarCalor() const {
        return calorGerado;
    }

}