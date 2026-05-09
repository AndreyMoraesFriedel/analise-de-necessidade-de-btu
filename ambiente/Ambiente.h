#ifndef AMBIENTE_H
#define AMBIENTE_H

#include <vector>
#include "Pessoa.h"
#include "../equipamentos/AparelhoEletronico.h"
#include "../equipamentos/Luz.h"
#include "Porta.h"
#include "Janela.h"

namespace ambiente {

    class Ambiente {
        private:
            double temperaturaAtual;
            double temperaturaExterna;
            double largura;
            double comprimento;
            double altura;
            std::vector<Pessoa> pessoas;
            std::vector<equipamentos::AparelhoEletronico*> aparelhos;
            std::vector<equipamentos::Luz> luzes;
            std::vector<Porta> portas;
            std::vector<Janela> janelas;
        public:
            Ambiente(
                double temperaturaAtual,
                double temperaturaExterna,
                double largura,
                double comprimento,
                double altura
            );

            double getTemperatura() const;
            void setTemperatura(double t);
            void adicionarPessoa(const Pessoa& p);
            void adicionarAparelho(equipamentos::AparelhoEletronico* a);
            void adicionarLuz(const equipamentos::Luz& l);
            void adicionarPorta(const Porta& p);
            void adicionarJanela(const Janela& j);
            double calcularCalorInterno() const;
            double calcularArea() const;
            double getTemperaturaExterna() const;
            double calcularVolume() const;
            const std::vector<Janela>& getJanelas() const;
    };

}

#endif