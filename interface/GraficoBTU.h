#ifndef GRAFICOBTU_H
#define GRAFICOBTU_H

#include <QChartView>

class GraficoBTU : public QChartView {

public:
    explicit GraficoBTU(
        QWidget* parent = nullptr
    );

private:
    void carregarDados();
};

#endif
