#ifndef AMBIENTE_H
#define AMBIENTE_H

#include <vector>
#include "Pessoa.h"
#include "../equipamentos/AparelhoEletronico.h"

namespace ambiente {

    class Ambiente {
        private:
            double largura;
            double comprimento;
            bool solDireto;
            std::vector<Pessoa*> pessoas;
            std::vector<equipamentos::AparelhoEletronico*> aparelhos;
        public:
            Ambiente(double largura,double comprimento, bool solDireto);
            void adicionarAparelho(equipamentos::AparelhoEletronico* a);
            void adicionarPessoa(Pessoa* p);
            std::vector<equipamentos::AparelhoEletronico*> getAparelhos() const;
            std::vector<Pessoa*> getPessoas() const;
            bool isSolDireto() const;
            double calcularArea() const;
    };

}

#endif