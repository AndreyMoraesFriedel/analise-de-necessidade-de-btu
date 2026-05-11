#ifndef CALCULADORA_BTU_H
#define CALCULADORA_BTU_H
#include "../ambiente/Ambiente.h"
namespace calculos {

    class CalculadoraBTU {
        public:
            static double calcular(const ambiente::Ambiente& amb);
    };

}

#endif