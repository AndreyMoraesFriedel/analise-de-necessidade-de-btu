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
            "../../simulador.db",
            SQLITE_OPEN_READWRITE |
            SQLITE_OPEN_CREATE
        );

{
    odb::transaction t(
        db.begin()
    );

    db.execute(
        "DELETE FROM ResultadoSimulacao"
    );

    t.commit();
}	

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
           for (int i = 0;i < cenario.getTelevisoes();i++) {
	    	auto* tv = new Televisao();
	    	amb.adicionarAparelho(tv);
    	   }

            //PCs
            for (int i = 0;i < cenario.getComputadores(); i++) {
                auto* pc = new Computador();
                amb.adicionarAparelho(pc);
            }

            //Celulares
            for (int i = 0;i < cenario.getCelulares();i++) {
                auto* cl = new Celular();
                amb.adicionarAparelho(cl);
            }

            double resultado =
                calculos::CalculadoraBTU
                    ::calcular(amb);

	    ResultadoSimulacao r(
    		cenario.getLargura(),
    		cenario.getComprimento(),
    		cenario.getPessoas(),
    		cenario.getTelevisoes(),
    		cenario.getComputadores(),
                cenario.getCelulares(),
    		cenario.getSolDireto(),
    		resultado
	    );

            odb::transaction t(
                db.begin()
            );

            db.persist(r);

            t.commit();
        }

    }

}
