#ifndef PESSOA_H
#define PESSOA_H

//Atraves da p. diretiva include consigo passar
//caminho de arquivo e libs
#include "../energia/GeradorCalor.h"

namespace ambiente {

    //Pessoa esta herdando/implementando a interface GeradorCalor
    class Pessoa : public energia::GeradorCalor {
        //este private é opcional neste caso
        private:
            double calorGerado;
        public:
            //definindo o construtor da classe
            //uma pessoa emite aproximadamente 120 Watts de calor para o ambiente
            Pessoa(double calor = 120.0);
            //informando que esta subclasse ira sobreescrever
            //o metodo da classe mae
            double gerarCalor() const override;
    };

}

#endif