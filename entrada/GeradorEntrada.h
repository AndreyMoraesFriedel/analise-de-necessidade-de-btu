#ifndef GERADORENTRADA_H
#define GERADORENTRADA_H

#include <string>

namespace entrada {

class GeradorEntrada {

public:

    static void gerar(
        const std::string& arquivo,
        int maxPessoas,
        int maxComputadores
    );
};

}

#endif
