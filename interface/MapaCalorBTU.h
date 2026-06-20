#ifndef MAPACALORBTU_H
#define MAPACALORBTU_H

#include <QTableWidget>

class MapaCalorBTU : public QTableWidget {

public:

    explicit MapaCalorBTU(
        QWidget* parent = nullptr
    );

private:

    void carregarDados();
};

#endif
