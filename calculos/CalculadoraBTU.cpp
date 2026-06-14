#include "CalculadoraBTU.h"

namespace calculos {

    double CalculadoraBTU::calcular(const ambiente::Ambiente& amb){
        double btus = 0;
        btus += amb.calcularArea() * 600;
        if(amb.getPessoas().size()>1){
            btus += (amb.getPessoas().size()-1) * 600;
        }
	for (auto aparelho : amb.getAparelhos()) {
    	    btus += aparelho->getCargaTermica();
	}
        if (amb.isSolDireto())
            btus += 1000;
        return btus;
    }

}
