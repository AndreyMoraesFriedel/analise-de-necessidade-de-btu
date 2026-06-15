#include "MainWindow.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHeaderView>

#include <QDebug>

#include "GraficoBTU.h"

#include <QVBoxLayout>
#include <QWidget>

MainWindow::MainWindow() {

   setWindowTitle(
        "Simulador BTU"
    );

    resize(
        1000,
        700
    );

    tabela = new QTableWidget(this);

    QWidget* central =
        new QWidget();

    QVBoxLayout* layout =
        new QVBoxLayout();

    if (abrirBanco()) {

        grafico =
            new GraficoBTU();

        carregarResultados();
    }


	layout->addWidget(
	    grafico
	);

	layout->addWidget(
	    tabela
	);

	central->setLayout(
	    layout
	);

	setCentralWidget(
	    central
	);

    tabela->setColumnCount(2);

    tabela->setHorizontalHeaderLabels(
        {
            "ID",
            "BTU"
        }
    );

    tabela->horizontalHeader()
          ->setStretchLastSection(true);
    if (abrirBanco()) { 
	    carregarResultados(); 
    }
}

bool MainWindow::abrirBanco() {

    QSqlDatabase db;

    if (QSqlDatabase::contains()) {
        db = QSqlDatabase::database();
    } else {
        db = QSqlDatabase::addDatabase(
            "QSQLITE"
        );
    }

    db.setDatabaseName(
        "../../simulador.db"
    );

    if (!db.open()) {

        qDebug()
            << "Erro ao abrir banco:"
            << db.lastError().text();

        return false;
    }

    return true;
}

void MainWindow::carregarResultados() {

    tabela->setRowCount(0);

    QSqlQuery query;

    bool ok = query.exec(
        "SELECT id, btu "
        "FROM ResultadoSimulacao "
        "ORDER BY id"
    );

    if (!ok) {

        qDebug()
            << "Erro SQL:"
            << query.lastError().text();

        return;
    }

    int linha = 0;

    while (query.next()) {

        tabela->insertRow(
            linha
        );

        tabela->setItem(
            linha,
            0,
            new QTableWidgetItem(
                query.value(0).toString()
            )
        );

        tabela->setItem(
            linha,
            1,
            new QTableWidgetItem(
                query.value(1).toString()
            )
        );

        linha++;
    }

    qDebug()
        << "Registros carregados:"
        << linha;
}
