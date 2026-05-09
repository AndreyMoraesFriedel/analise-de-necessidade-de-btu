#ifndef CALCULADORA_BTU_AVANCADO_H
#define CALCULADORA_BTU_AVANCADO_H

#include "../ambiente/Ambiente.h"

namespace calculos {

    class CalculadoraBTUAvancado {
        public:
            static double calcular(const ambiente::Ambiente& amb);
    };

}

#endif