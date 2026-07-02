#ifndef MAPACALORBTU_H
#define MAPACALORBTU_H

#include <QTableWidget>
#include <QTimer>

#include <vector>

struct RegistroBTU {

    int pessoas;
    int computadores;
    double btu;
};

class MapaCalorBTU : public QTableWidget {

    Q_OBJECT

public:

    explicit MapaCalorBTU(
        QWidget* parent = nullptr
    );

private:

    void carregarDados();

    QColor calcularCor(
        double valor,
        double minimo,
        double maximo
    );

    void desenharCelula(
        int linha,
        int coluna
    );

private slots:

    void atualizarAnimacao();

private:

    std::vector<RegistroBTU> registros;

    std::vector<int> pessoas;

    std::vector<int> computadores;

    double menorBTU;
    double maiorBTU;

    QTimer timer;

    int camadaAtual;
    int etapaAtual;
};

#endif
