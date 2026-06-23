#include "MapaCalorBTU.h"

#include <QSqlQuery>

#include <QHeaderView>
#include <QTableWidgetItem>

#include <QColor>

#include <vector>
#include <set>

struct RegistroBTU {

    int pessoas;
    int computadores;
    double btu;
};

MapaCalorBTU::MapaCalorBTU(
    QWidget* parent
)
    : QTableWidget(parent)
{
    carregarDados();
}

QColor MapaCalorBTU::calcularCor(
    double valor,
    double minimo,
    double maximo
) {

    if (maximo == minimo) {

        return QColor(
            255,
            255,
            0
        );
    }

    double proporcao =
        (valor - minimo)
        /
        (maximo - minimo);

    int vermelho =
        static_cast<int>(
            255 * proporcao
        );

    int verde =
        static_cast<int>(
            255 * (1.0 - proporcao)
        );

    return QColor(
        vermelho,
        verde,
        0
    );
}

void MapaCalorBTU::carregarDados() {

    std::vector<RegistroBTU> registros;

    std::set<int> pessoasSet;
    std::set<int> computadoresSet;

    double menorBTU =
        999999999;

    double maiorBTU =
        0;

    QSqlQuery query;

    query.exec(
        "SELECT pessoas, computadores, btu "
        "FROM ResultadoSimulacao "
        "ORDER BY pessoas, computadores"
    );

    while (query.next()) {

        RegistroBTU r;

        r.pessoas =
            query.value(0).toInt();

        r.computadores =
            query.value(1).toInt();

        r.btu =
            query.value(2).toDouble();

        registros.push_back(r);

        pessoasSet.insert(
            r.pessoas
        );

        computadoresSet.insert(
            r.computadores
        );

        if (r.btu < menorBTU)
            menorBTU = r.btu;

        if (r.btu > maiorBTU)
            maiorBTU = r.btu;
    }

    QStringList linhas;
    QStringList colunas;

    for (int p : pessoasSet) {

        linhas
            << QString::number(p);
    }

    for (int c : computadoresSet) {

        colunas
            << QString::number(c);
    }

    setRowCount(
        linhas.size()
    );

    setColumnCount(
        colunas.size()
    );

    setVerticalHeaderLabels(
        linhas
    );

    setHorizontalHeaderLabels(
        colunas
    );

    horizontalHeader()
        ->setSectionResizeMode(
            QHeaderView::Stretch
        );

    verticalHeader()
        ->setSectionResizeMode(
            QHeaderView::Stretch
        );

    for (const auto& r : registros) {

        int linha = 0;
        int coluna = 0;

        for (int p : pessoasSet) {

            if (p == r.pessoas)
                break;

            linha++;
        }

        for (int c : computadoresSet) {

            if (c == r.computadores)
                break;

            coluna++;
        }

        QTableWidgetItem* item =
            new QTableWidgetItem(
                QString::number(
                    r.btu,
                    'f',
                    0
                )
            );

        item->setBackground(
            calcularCor(
                r.btu,
                menorBTU,
                maiorBTU
            )
        );

        setItem(
            linha,
            coluna,
            item
        );
    }
}
