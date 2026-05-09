#ifndef SIMULADOR_H
#define SIMULADOR_H

#include "../entrada/LeitorEntrada.h"

namespace simulacao {

    class Simulador {
        private:
            entrada::LeitorEntrada* entrada;
        public:
            Simulador();
            void executar();
        private:
            void mostrarMenu();
            void executarOpcao(int opcao);
            void escolherTipoEntrada();
            void executarBTUSimples();
            void executarBTUAvancado();
    };

}

#endif