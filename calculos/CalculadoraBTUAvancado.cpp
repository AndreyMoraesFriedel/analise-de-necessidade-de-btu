#include "CalculadoraBTUAvancado.h"
#include "../ambiente/Ambiente.h"
namespace calculos {

    double CalculadoraBTUAvancado::calcular(const ambiente::Ambiente& amb) {
        double btus = 0;
        btus += amb.calcularArea() * 600;
        btus += amb.calcularCalorInterno();
        for (const auto& j : amb.getJanelas()) {
            if (j.temSol())
                btus += 800;
        }
        double diff = amb.getTemperaturaExterna() - amb.getTemperatura();
        if (diff > 0)
            btus += diff * 100;
        return btus;
    }

}