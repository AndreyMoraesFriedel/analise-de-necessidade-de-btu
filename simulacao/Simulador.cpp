#include "Simulador.h"

#include "../entrada/LeitorCSV.h"

#include "../simulacao/ResultadoSimulacao.h"

#include "../calculos/CalculadoraBTU.h"

#include "../ambiente/Ambiente.h"
#include "../ambiente/Pessoa.h"

#include "../equipamentos/Televisao.h"
#include "../equipamentos/Computador.h"
#include "../equipamentos/Celular.h"

#include "ResultadoSimulacao-odb.hxx"

#include <odb/database.hxx>
#include <odb/transaction.hxx>
#include <odb/sqlite/database.hxx>

#include <vector>

using namespace ambiente;
using namespace equipamentos;

namespace simulacao {

    void Simulador::executar(const std::string& entradaCSV) {

        auto cenarios = entrada::LeitorCSV::ler(
            entradaCSV
        );

        odb::sqlite::database db(
            "simulador.db",
            SQLITE_OPEN_READWRITE |
            SQLITE_OPEN_CREATE
        );

        for (const auto& cenario : cenarios) {
            Ambiente amb(
                cenario.getLargura(),
                cenario.getComprimento(),
                cenario.getSolDireto()
            );
            //Pessoas
            for (int i = 0;
                 i < cenario.getPessoas();
                 i++) {

                amb.adicionarPessoa(
                    new Pessoa()
                );
            }
            //TVs
            for (int i = 0;
                 i < cenario.getTelevisoes();
                 i++) {
                auto* tv = new Televisao();

                tv->ligar();

                amb.adicionarAparelho(tv);
            }

            //PCs
            for (int i = 0;
                 i < cenario.getComputadores();
                 i++) {

                auto* pc = new Computador();

                pc->ligar();

                amb.adicionarAparelho(pc);
            }

            //Celulares
            for (int i = 0;
                 i < cenario.getCelulares();
                 i++) {

                auto* cl = new Celular();

                cl->ligar();

                amb.adicionarAparelho(cl);
            }

            double resultado =
                calculos::CalculadoraBTU
                    ::calcular(amb);

            ResultadoSimulacao r(resultado);

            odb::transaction t(
                db.begin()
            );

            db.persist(r);

            t.commit();
        }

    }

}
