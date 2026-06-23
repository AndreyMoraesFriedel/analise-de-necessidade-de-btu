#include "CalculadoraBTU.h"

namespace calculos {

    double CalculadoraBTU::calcular(const ambiente::Ambiente& amb){
        double btus = 0;
        btus += amb.calcularArea() * 600;
	for (auto pessoa:amb.getPessoas()) {
		btus += 600;
		btus += (pessoa->getPercepcaoCalor() - 3) * 200;
	}
	for (auto aparelho : amb.getAparelhos()) {
    	    btus += aparelho->getCargaTermica();
	}
        if (amb.isSolDireto())
            btus += 1000;
        return btus;
    }

}
