#ifndef RESULTADO_SIMULACAO_H
#define RESULTADO_SIMULACAO_H

#include <odb/core.hxx>

namespace simulacao {


    #pragma db object
    class ResultadoSimulacao {

	friend class odb::access;

        private:
	    #pragma db id auto
            int id;
            double btu;
        public:
	    ResultadoSimulacao();
            ResultadoSimulacao(double btu);
            int getId() const;
            double getBTU() const;
    };

}

#endif
