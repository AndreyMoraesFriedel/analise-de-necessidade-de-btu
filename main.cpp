#include "simulacao/Simulador.h"

int main() {
    simulacao::Simulador s;
    s.executar(
        "entrada.csv",
        "saida.csv"
    );
    return 0;
}