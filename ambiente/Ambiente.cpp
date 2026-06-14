#include "Ambiente.h"

namespace ambiente {

    Ambiente::Ambiente(double largura, double comprimento, bool solDireto) {
        this->largura = largura;
        this->comprimento = comprimento;
        this->solDireto = solDireto;
    }

    void Ambiente::adicionarPessoa(Pessoa* p) {
        pessoas.push_back(p);
    }

    void Ambiente::adicionarAparelho(equipamentos::AparelhoEletronico* a) {
        aparelhos.push_back(a);
    }

    double Ambiente::calcularArea() const {
        return largura * comprimento;
    }

    std::vector<equipamentos::AparelhoEletronico*> Ambiente::getAparelhos() const{
        return this->aparelhos;
    }
    std::vector<Pessoa*> Ambiente::getPessoas() const{
        return this->pessoas;
    }

    bool Ambiente::isSolDireto() const{
        return this->solDireto;
    }

}
