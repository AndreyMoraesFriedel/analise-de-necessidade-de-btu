#ifndef CELULAR_H
#define CELULAR_H

#include "AparelhoEletronico.h"

namespace equipamentos {

    class Celular : public AparelhoEletronico {
        public:
       		 double getCargaTermica() const override;
   
    };

}

#endif
