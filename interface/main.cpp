#include "../entrada/GeradorEntrada.h"
#include "../simulacao/Simulador.h"

#include <QApplication>

#include "MainWindow.h"

int main(
    int argc,
    char* argv[]
) {

    entrada::GeradorEntrada::gerar(
        "../../entrada.csv",
        20,
        20
    );

    simulacao::Simulador simulador;

    simulador.executar(
        "../../entrada.csv"
    );

    QApplication app(
        argc,
        argv
    );

    MainWindow janela;

    janela.show();

    return app.exec();
}
