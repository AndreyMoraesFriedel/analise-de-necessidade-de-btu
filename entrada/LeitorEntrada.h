#ifndef LEITOR_ENTRADA_H
#define LEITOR_ENTRADA_H

namespace entrada {

    class LeitorEntrada {
        public:
            virtual double lerLargura() = 0;
            virtual double lerComprimento() = 0;
            virtual double lerAltura() = 0;

            virtual int lerPessoas() = 0;
            virtual int lerEletronicos() = 0;

            virtual bool lerSolDireto() = 0;

            virtual double lerTemperaturaAtual() = 0;
            virtual double lerTemperaturaExterna() = 0;
            virtual int lerQuantidade(const char* mensagem) = 0;
            
            virtual ~LeitorEntrada() {}
    };

}

#endif