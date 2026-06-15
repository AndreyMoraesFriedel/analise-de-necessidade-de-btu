#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QTableWidget;
class GraficoBTU;

class MainWindow : public QMainWindow {

    Q_OBJECT

private:
    QTableWidget* tabela;
    GraficoBTU* grafico;
    bool abrirBanco();
    void carregarResultados();

public:
    MainWindow();
};

#endif
