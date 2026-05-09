#include "Ambiente.h"

namespace ambiente {

    Ambiente::Ambiente(
        double temperaturaAtual,
        double temperaturaExterna,
        double largura,
        double comprimento,
        double altura
    ) {
        this->temperaturaAtual = temperaturaAtual;
        this->temperaturaExterna = temperaturaExterna;
        this->largura = largura;
        this->comprimento = comprimento;
        this->altura = altura;
    }
    double Ambiente::getTemperatura() const {
        return temperaturaAtual;
    }

    void Ambiente::setTemperatura(double t) {
        temperaturaAtual = t;
    }

    void Ambiente::adicionarPessoa(const Pessoa& p) {
        pessoas.push_back(p);
    }

    void Ambiente::adicionarAparelho(equipamentos::AparelhoEletronico* a) {
        aparelhos.push_back(a);
    }

    void Ambiente::adicionarLuz(const equipamentos::Luz& l) {
        luzes.push_back(l);
    }

    void Ambiente::adicionarPorta(const Porta& p) {
        portas.push_back(p);
    }

    void Ambiente::adicionarJanela(const Janela& j) {
        janelas.push_back(j);
    }

    double Ambiente::calcularCalorInterno() const {
        double total = 0;
        for (const auto& p : pessoas)
            total += p.gerarCalor();

        for (auto* a : aparelhos)
            total += a->gerarCalor();

        for (const auto& l : luzes)
            total += l.gerarCalor();
        return total;
    }

    double Ambiente::calcularArea() const {
        return largura * comprimento;
    }

    double Ambiente::getTemperaturaExterna() const {
        return temperaturaExterna;
    }

    const std::vector<Janela>& Ambiente::getJanelas() const {
        return janelas;
    }

    double Ambiente::calcularVolume() const {
        return largura * comprimento * altura;
    }

}