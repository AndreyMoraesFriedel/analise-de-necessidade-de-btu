#include "MainWindow.h"
#include "MapaCalorBTU.h"

#include <QSqlDatabase>
#include <QSqlError>

#include <QVBoxLayout>
#include <QLabel>
#include <QWidget>

#include <QDebug>

MainWindow::MainWindow() {

    setWindowTitle(
        "Mapa de Calor - BTU"
    );

    resize(
        900,
        600
    );

    QWidget* central =
        new QWidget();

    QVBoxLayout* layout =
        new QVBoxLayout();

    QLabel* titulo =
        new QLabel(
            "Influência de Pessoas e Computadores no BTU"
        );

    titulo->setAlignment(
        Qt::AlignCenter
    );

    titulo->setStyleSheet(
        "font-size: 20px;"
        "font-weight: bold;"
    );

    layout->addWidget(
        titulo
    );

    if (abrirBanco()) {

        mapaCalor =
            new MapaCalorBTU();

        layout->addWidget(
            mapaCalor
        );
    }

    central->setLayout(
        layout
    );

    setCentralWidget(
        central
    );
}

bool MainWindow::abrirBanco() {

    QSqlDatabase db;

    if (QSqlDatabase::contains()) {

        db =
            QSqlDatabase::database();

    } else {

        db =
            QSqlDatabase::addDatabase(
                "QSQLITE"
            );
    }

    db.setDatabaseName(
        "../../simulador.db"
    );

    if (!db.open()) {

        qDebug()
            << db.lastError().text();

        return false;
    }

    return true;
}
