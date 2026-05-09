#ifndef CALCULADORA_BTU_H
#define CALCULADORA_BTU_H

namespace calculos {

    class CalculadoraBTU {
        public:
            static double calcular(
                double area,
                int pessoasExtras,
                int eletronicos,
                bool solDireto
            );
    };

}

#endif