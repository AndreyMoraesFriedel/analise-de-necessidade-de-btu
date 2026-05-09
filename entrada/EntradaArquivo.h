#ifndef ENTRADA_ARQUIVO_H
#define ENTRADA_ARQUIVO_H

#include "LeitorEntrada.h"
#include <fstream>

namespace entrada {

    class EntradaArquivo : public LeitorEntrada {

        private:
            std::ifstream arquivo;
        public:
            EntradaArquivo(const char* nomeArquivo);
            void reiniciar();
            double lerLargura() override;
            double lerComprimento() override;
            double lerAltura() override;
            int lerPessoas() override;
            int lerEletronicos() override;
            bool lerSolDireto() override;
            double lerTemperaturaAtual() override;
            double lerTemperaturaExterna() override;
            int lerQuantidade(const char* mensagem) override;
            ~EntradaArquivo();
    };

}

#endif