#include "CalculadoraBTU.h"

namespace calculos {

    double CalculadoraBTU::calcular(const ambiente::Ambiente& amb){
        double btus = 0;
        btus += amb.calcularArea() * 600;
        if(amb.getPessoas().size()>1){
            btus += amb.getPessoas().size() * 600;
        }
        btus += amb.getAparelhos().size() * 600;
        if (amb.isSolDireto())
            btus += 1000;
        return btus;
    }

}