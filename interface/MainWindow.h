#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MapaCalorBTU;

class MainWindow : public QMainWindow {

    Q_OBJECT

private:
    MapaCalorBTU* mapaCalor;

    bool abrirBanco();

public:
    MainWindow();
};

#endif
