#include "GeradorEntrada.h"

#include <fstream>

namespace entrada {

void GeradorEntrada::gerar(
    const std::string& arquivo,
    int maxPessoas,
    int maxComputadores
) {

    std::ofstream out(
        arquivo
    );

    out
        << "largura;comprimento;"
        << "pessoas;"
        << "tvs;"
        << "computadores;"
        << "celulares;"
        << "solDireto\n";

    for (
        int pessoas = 1;
        pessoas <= maxPessoas;
        pessoas++
    ) {

        for (
            int pcs = 1;
            pcs <= maxComputadores;
            pcs++
        ) {

            out
                << "5;5;"
                << pessoas << ";"
                << "0;"
                << pcs << ";"
                << "0;"
                << "0\n";
        }
    }
}

}
