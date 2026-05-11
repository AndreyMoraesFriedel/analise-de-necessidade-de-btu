#ifndef RESULTADO_SIMULACAO_H
#define RESULTADO_SIMULACAO_H

namespace simulacao {

    class ResultadoSimulacao {
        private:
            int id;
            double btu;
        public:
            ResultadoSimulacao(int id, double btu);
            int getId() const;
            double getBTU() const;
    };

}

#endif