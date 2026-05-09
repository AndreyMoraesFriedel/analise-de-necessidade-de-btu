#ifndef ENTRADA_CONSOLE_H
#define ENTRADA_CONSOLE_H

#include "LeitorEntrada.h"

namespace entrada {

        class EntradaConsole : public LeitorEntrada {

        public:

            double lerLargura() override;
            double lerComprimento() override;
            double lerAltura() override;

            int lerPessoas() override;
            int lerEletronicos() override;

            bool lerSolDireto() override;

            double lerTemperaturaAtual() override;
            double lerTemperaturaExterna() override;
            int lerQuantidade(const char* mensagem) override;
        };

    }

#endif