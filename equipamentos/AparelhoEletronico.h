#ifndef APARELHO_ELETRONICO_H
#define APARELHO_ELETRONICO_H

namespace equipamentos {
    class AparelhoEletronico {
    public:
        virtual ~AparelhoEletronico() = default;
        virtual double getCargaTermica() const = 0;
    };

}

#endif
