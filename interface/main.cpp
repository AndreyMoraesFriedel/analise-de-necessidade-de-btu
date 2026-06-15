#include "../simulacao/Simulador.h"
#include <QApplication>
#include "MainWindow.h"

int main(int argc, char* argv[]) {
    
    simulacao::Simulador s;

    s.executar(
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
