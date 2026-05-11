#include "Simulador.h"

#include "../entrada/LeitorCSV.h"

#include "../simulacao/ResultadoSimulacao.h"
#include "../simulacao/EscritorResultado.h"

#include "../calculos/CalculadoraBTU.h"

#include "../ambiente/Ambiente.h"
#include "../ambiente/Pessoa.h"

#include "../equipamentos/Televisao.h"
#include "../equipamentos/Computador.h"

#include <vector>

using namespace ambiente;
using namespace equipamentos;

namespace simulacao {

    void Simulador::executar(const std::string& entradaCSV, const std::string& saidaCSV) {
        auto cenarios = entrada::LeitorCSV::ler(entradaCSV);
        std::vector<ResultadoSimulacao> resultados;
        int id = 1;
        for (const auto& cenario : cenarios) {
            Ambiente amb(
                cenario.getLargura(),
                cenario.getComprimento(),
                cenario.getSolDireto()
            );
            //Pessoas
            for (int i = 0; i < cenario.getPessoas(); i++) {
                amb.adicionarPessoa(new Pessoa());
            }
            //TVs
            for (int i = 0;i < cenario.getTelevisoes();i++) {
                auto* tv = new Televisao();
                tv->ligar();
                amb.adicionarAparelho(tv);
            }
            //PCs
            for (int i = 0;i < cenario.getComputadores();i++) {
                auto* pc = new Computador();
                pc->ligar();
                amb.adicionarAparelho(pc);
            }
            double resultado = calculos::CalculadoraBTU::calcular(amb);
            resultados.push_back(ResultadoSimulacao(id,resultado));
            id++;
        }
        EscritorResultado::escrever(saidaCSV,resultados);
    }

}