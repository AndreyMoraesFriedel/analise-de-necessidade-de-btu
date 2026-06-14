#ifndef COMPUTADOR_H
#define COMPUTADOR_H

#include "AparelhoEletronico.h"

namespace equipamentos {

    class Computador : public AparelhoEletronico {
        public:
       		 double getCargaTermica() const override;
    
    };
}

#endif
