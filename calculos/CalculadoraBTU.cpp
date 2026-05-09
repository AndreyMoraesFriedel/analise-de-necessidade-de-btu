#include "CalculadoraBTU.h"

namespace calculos {

    double CalculadoraBTU::calcular(
        double area,
        int pessoasExtras,
        int eletronicos,
        bool solDireto
    ) {
        double btus = 0;
        btus += area * 600;
        btus += pessoasExtras * 600;
        btus += eletronicos * 600;
        if (solDireto)
            btus += 1000;
        return btus;
    }

}