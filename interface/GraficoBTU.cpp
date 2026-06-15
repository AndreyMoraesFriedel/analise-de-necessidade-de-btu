#include "GraficoBTU.h"

#include <QBarSeries>
#include <QBarSet>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include <QChart>

#include <QSqlQuery>

GraficoBTU::GraficoBTU(
    QWidget* parent
)
    : QChartView(parent) {

    carregarDados();
}

void GraficoBTU::carregarDados() {

    QBarSet* conjunto =
        new QBarSet("BTU");

    QStringList categorias;

    QSqlQuery query;

    query.exec(
        "SELECT id, btu "
        "FROM ResultadoSimulacao "
        "ORDER BY id"
    );

    while (query.next()) {

        int id =
            query.value(0).toInt();

        double btu =
            query.value(1).toDouble();

        *conjunto << btu;

        categorias
            << QString::number(id);
    }

    QBarSeries* serie =
        new QBarSeries();

    serie->append(conjunto);

    QChart* chart =
        new QChart();

    chart->addSeries(serie);

    chart->setTitle(
        "BTU por Cenário"
    );

    chart->legend()->hide();

    QBarCategoryAxis* eixoX =
        new QBarCategoryAxis();

    eixoX->append(
        categorias
    );

    chart->addAxis(
        eixoX,
        Qt::AlignBottom
    );

    serie->attachAxis(
        eixoX
    );

    QValueAxis* eixoY =
        new QValueAxis();

    eixoY->setTitleText(
        "BTU"
    );

    chart->addAxis(
        eixoY,
        Qt::AlignLeft
    );

    serie->attachAxis(
        eixoY
    );

    setChart(chart);

    setRenderHint(
        QPainter::Antialiasing
    );
}
