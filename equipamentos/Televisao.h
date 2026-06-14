#ifndef TELEVISAO_H
#define TELEVISAO_H

#include "AparelhoEletronico.h"

namespace equipamentos {

    class Televisao : public AparelhoEletronico {

    public:
        double getCargaTermica() const override;
    };

}

#endif
