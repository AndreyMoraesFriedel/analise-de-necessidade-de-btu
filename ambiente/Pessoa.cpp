#include "Pessoa.h"

namespace ambiente {

Pessoa::Pessoa(
    int percepcaoCalor
) {
    this->percepcaoCalor =
        percepcaoCalor;
}

int Pessoa::getPercepcaoCalor() const {
    return percepcaoCalor;
}

}
