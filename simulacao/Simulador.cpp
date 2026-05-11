#include "Simulador.h"

#include "../entrada/LeitorCSV.h"

#include "../calculos/CalculadoraBTU.h"
#include "../calculos/CalculadoraBTUAvancado.h"

#include "ResultadoSimulacao.h"
#include "EscritorResultado.h"

#include "../ambiente/Ambiente.h"
#include "../ambiente/Pessoa.h"
#include "../ambiente/Janela.h"

#include "../equipamentos/Televisao.h"
#include "../equipamentos/Computador.h"
#include "../equipamentos/Luz.h"

#include <vector>

using namespace simulacao;
using namespace ambiente;
using namespace equipamentos;
using namespace std;

namespace simulacao {

void Simulador::executar(
    const string& entradaCSV,
    const string& saidaCSV
) {
    auto cenarios = entrada::LeitorCSV::ler(entradaCSV);
    vector<ResultadoSimulacao> resultados;
    int id = 1;
    for (const auto& cenario : cenarios) {
        double resultado = 0;
        //Simples
        if (cenario.getTipo() == "simples") {
            double area = cenario.getLargura() * cenario.getComprimento();
            resultado = calculos::CalculadoraBTU::calcular(
                area,
                cenario.getPessoas() - 1,
                cenario.getTelevisoes(),
                cenario.getSolDireto()
            );
        }
        //Avancado
        else if (cenario.getTipo() =="avancado") {
            Ambiente amb(
                cenario.getTemperaturaAtual(),
                cenario.getTemperaturaExterna(),
                cenario.getLargura(),
                cenario.getComprimento(),
                cenario.getAltura()
            );
            // Pessoas
            for (int i = 0;i < cenario.getPessoas();i++) {
                amb.adicionarPessoa(
                    Pessoa()
                );
            }
            // TVs
            for (int i = 0;i < cenario.getTelevisoes();i++) {
                auto* tv = new Televisao();
                tv->ligar();
                amb.adicionarAparelho(tv);
            }
            // PCs
            for(int i = 0;i < cenario.getComputadores();i++) {
                auto* pc = new Computador();
                pc->ligar();
                amb.adicionarAparelho(pc);
            }
            // Luz
            Luz luz(100);
            luz.ligar();
            amb.adicionarLuz(luz);
            // Sol
            amb.adicionarJanela(
                Janela(
                    false,
                    cenario.getSolDireto()
                )
            );
            resultado =calculos::CalculadoraBTUAvancado::calcular(amb);
        }
        resultados.push_back(ResultadoSimulacao(id,cenario.getTipo(),resultado));
        id++;
    }
    EscritorResultado::escrever(saidaCSV,resultados);
}

}