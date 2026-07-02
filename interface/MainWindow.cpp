#include "MainWindow.h"
#include "MapaCalorBTU.h"

#include <QSqlDatabase>
#include <QSqlError>

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QFrame>

#include <QDebug>

MainWindow::MainWindow() {

    setWindowTitle(
        "Simulador de Necessidade de BTUs"
    );

    QWidget* central =
        new QWidget();

    QVBoxLayout* layout =
        new QVBoxLayout();

    layout->setSpacing(15);

    layout->setContentsMargins(
        20,
        20,
        20,
        20
    );

    //--------------------------------------------------
    // Título
    //--------------------------------------------------

    QLabel* titulo =
        new QLabel(
            "MAPA DE CALOR DA NECESSIDADE DE BTUs"
        );

    titulo->setAlignment(
        Qt::AlignCenter
    );

    titulo->setStyleSheet(

        "font-size:28px;"
        "font-weight:bold;"

    );

    layout->addWidget(
        titulo
    );

    //--------------------------------------------------
    // Informações dos eixos
    //--------------------------------------------------

    QLabel* descricao =
        new QLabel(

            "Linhas → Número de Pessoas\n"
            "Colunas → Número de Computadores"

        );

    descricao->setAlignment(
        Qt::AlignCenter
    );

    descricao->setStyleSheet(

        "font-size:16px;"
        "font-weight:bold;"

    );

    layout->addWidget(
        descricao
    );

    //--------------------------------------------------
    // Mapa de calor
    //--------------------------------------------------

    if (abrirBanco()) {

        mapaCalor =
            new MapaCalorBTU();

        layout->addWidget(
            mapaCalor,
            1
        );
    }

    //--------------------------------------------------
    // Legenda
    //--------------------------------------------------

    QLabel* legendaTitulo =
        new QLabel(
            "Legenda das Cores"
        );

    legendaTitulo->setAlignment(
        Qt::AlignCenter
    );

    legendaTitulo->setStyleSheet(

        "font-size:16px;"
        "font-weight:bold;"

    );

    layout->addWidget(
        legendaTitulo
    );

    QHBoxLayout* legenda =
        new QHBoxLayout();

    legenda->setSpacing(0);

    auto criarFaixa =
        [](QString cor) {

            QFrame* faixa =
                new QFrame();

            faixa->setFixedHeight(
                25
            );

            faixa->setStyleSheet(

                "background:" + cor +
                ";border:none;"

            );

            faixa->setSizePolicy(
                QSizePolicy::Expanding,
                QSizePolicy::Fixed
            );

            return faixa;
        };

    legenda->addWidget(
        criarFaixa("#00AA00")
    );

    legenda->addWidget(
        criarFaixa("#FFFF00")
    );

    legenda->addWidget(
        criarFaixa("#FF9900")
    );

    legenda->addWidget(
        criarFaixa("#CC0000")
    );

    layout->addLayout(
        legenda
    );

    //--------------------------------------------------

    QHBoxLayout* textoLegenda =
        new QHBoxLayout();

    QLabel* minimo =
        new QLabel(
            "Menor BTU"
        );

    QLabel* maximo =
        new QLabel(
            "Maior BTU"
        );

    minimo->setStyleSheet(
        "font-weight:bold;"
    );

    maximo->setStyleSheet(
        "font-weight:bold;"
    );

    textoLegenda->addWidget(
        minimo
    );

    textoLegenda->addStretch();

    textoLegenda->addWidget(
        maximo
    );

    layout->addLayout(
        textoLegenda
    );

    //--------------------------------------------------

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
