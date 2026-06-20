#include "MapaCalorBTU.h"

#include <QSqlQuery>

#include <QHeaderView>
#include <QTableWidgetItem>

#include <QBrush>
#include <QColor>

MapaCalorBTU::MapaCalorBTU(
    QWidget* parent
)
    : QTableWidget(parent)
{
    carregarDados();
}

void MapaCalorBTU::carregarDados() {

    setRowCount(6);
    setColumnCount(6);

    setVerticalHeaderLabels(
        {
            "1 Pessoa",
            "3 Pessoas",
            "5 Pessoas",
            "7 Pessoas",
            "9 Pesssoas",
            "11 Pessoas"
        }
    );

    setHorizontalHeaderLabels(
        {
            "0 Computador",
            "2 Computadores",
            "4 Computadores",
            "6 Computadores",
            "8 Computadores",
            "10 Computadores"
        }
    );

    horizontalHeader()->setSectionResizeMode(
        QHeaderView::Stretch
    );

    verticalHeader()->setSectionResizeMode(
        QHeaderView::Stretch
    );

    QSqlQuery query;

    query.exec(
        "SELECT pessoas, computadores, btu "
        "FROM ResultadoSimulacao"
    );

    while (query.next()) {

        int pessoas =
            query.value(0).toInt();

        int computadores =
            query.value(1).toInt();

        double btu =
            query.value(2).toDouble();

        int linha =
            (pessoas - 1) / 2;

        int coluna =
            computadores / 2;

        QTableWidgetItem* item =
            new QTableWidgetItem(
                QString::number(btu)
            );

        QColor cor;

        if (btu < 7000)
            cor = QColor(0,255,0);          // verde
        else if (btu < 9000)
            cor = QColor(255,255,0);        // amarelo
        else if (btu < 11000)
            cor = QColor(255,165,0);        // laranja
        else
            cor = QColor(255,0,0);          // vermelho

        item->setBackground(cor);

        setItem(
            linha,
            coluna,
            item
        );
    }
}
