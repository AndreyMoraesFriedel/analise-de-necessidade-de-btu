#include "MapaCalorBTU.h"

#include <QSqlQuery>
#include <QHeaderView>
#include <QTableWidgetItem>
#include <QColor>

#include <set>
#include <algorithm>

MapaCalorBTU::MapaCalorBTU(
    QWidget* parent
)
    : QTableWidget(parent)
{
    menorBTU = 999999999;
    maiorBTU = 0;

    camadaAtual = 0;
    etapaAtual = 0;

    carregarDados();

    connect(
        &timer,
        &QTimer::timeout,
        this,
        &MapaCalorBTU::atualizarAnimacao
    );

    timer.start(200);
}

QColor MapaCalorBTU::calcularCor(
    double valor,
    double minimo,
    double maximo
)
{
    if(maximo <= minimo)
        return QColor(255,255,0);

    double t =
        (valor-minimo)/
        (maximo-minimo);

    t = std::clamp(
        t,
        0.0,
        1.0
    );

    auto interpolar =
        [](QColor a,
           QColor b,
           double p)
        {
            return QColor(
                a.red()   + (b.red()   - a.red())   * p,
                a.green() + (b.green() - a.green()) * p,
                a.blue()  + (b.blue()  - a.blue())  * p
            );
        };

    QColor verde(
        0,
        190,
        0
    );

    QColor amarelo(
        255,
        255,
        0
    );

    QColor laranja(
        255,
        150,
        0
    );

    QColor vermelho(
        220,
        0,
        0
    );

    if(t < 0.33)
        return interpolar(
            verde,
            amarelo,
            t/0.33
        );

    if(t < 0.66)
        return interpolar(
            amarelo,
            laranja,
            (t-0.33)/0.33
        );

    return interpolar(
        laranja,
        vermelho,
        (t-0.66)/0.34
    );
}

void MapaCalorBTU::carregarDados()
{
    std::set<int> pessoasSet;
    std::set<int> computadoresSet;

    QSqlQuery query;

    query.exec(
        "SELECT pessoas, computadores, btu "
        "FROM ResultadoSimulacao "
        "ORDER BY pessoas, computadores"
    );

    while(query.next())
    {
        RegistroBTU reg;

        reg.pessoas =
            query.value(0).toInt();

        reg.computadores =
            query.value(1).toInt();

        reg.btu =
            query.value(2).toDouble();

        registros.push_back(reg);

        pessoasSet.insert(
            reg.pessoas
        );

        computadoresSet.insert(
            reg.computadores
        );

        menorBTU =
            std::min(
                menorBTU,
                reg.btu
            );

        maiorBTU =
            std::max(
                maiorBTU,
                reg.btu
            );
    }

    pessoas.assign(
        pessoasSet.begin(),
        pessoasSet.end()
    );

    computadores.assign(
        computadoresSet.begin(),
        computadoresSet.end()
    );

    setRowCount(
        pessoas.size()
    );

    setColumnCount(
        computadores.size()
    );

    QStringList linhas;

    for(int p : pessoas)
        linhas << QString::number(p);

    QStringList colunas;

    for(int c : computadores)
        colunas << QString::number(c);

    setVerticalHeaderLabels(
        linhas
    );

    setHorizontalHeaderLabels(
        colunas
    );

    horizontalHeader()->setDefaultAlignment(
        Qt::AlignCenter
    );

    verticalHeader()->setDefaultAlignment(
        Qt::AlignCenter
    );

    horizontalHeader()->setSectionResizeMode(
        QHeaderView::Stretch
    );

    verticalHeader()->setSectionResizeMode(
        QHeaderView::Stretch
    );

    horizontalHeader()->setMinimumSectionSize(
        20
    );

    verticalHeader()->setMinimumSectionSize(
        20
    );

    horizontalHeader()->setFixedHeight(
        35
    );

    verticalHeader()->setDefaultSectionSize(
        30
    );

    setSelectionMode(
        NoSelection
    );

    setEditTriggers(
        NoEditTriggers
    );

    setFocusPolicy(
        Qt::NoFocus
    );

    setCornerButtonEnabled(
        false
    );

    setShowGrid(
        true
    );

    setVerticalScrollBarPolicy(
        Qt::ScrollBarAlwaysOff
    );

    setHorizontalScrollBarPolicy(
        Qt::ScrollBarAlwaysOff
    );

    setSizePolicy(
        QSizePolicy::Expanding,
        QSizePolicy::Expanding
    );
}

void MapaCalorBTU::desenharCelula(
    int linha,
    int coluna
)
{
    for(const auto& r : registros)
    {
        auto itLinha =
            std::find(
                pessoas.begin(),
                pessoas.end(),
                r.pessoas
            );

        auto itColuna =
            std::find(
                computadores.begin(),
                computadores.end(),
                r.computadores
            );

        if(
            itLinha==pessoas.end() ||
            itColuna==computadores.end()
        )
            continue;

        int l =
            itLinha-pessoas.begin();

        int c =
            itColuna-computadores.begin();

        if(
            l!=linha ||
            c!=coluna
        )
            continue;

        QTableWidgetItem* item =
            new QTableWidgetItem(
                QString::number(
                    r.btu,
                    'f',
                    0
                )
            );

        item->setTextAlignment(
            Qt::AlignCenter
        );

        QFont fonte =
            item->font();

        fonte.setBold(
            true
        );

        fonte.setPointSize(
            8
        );

        item->setFont(
            fonte
        );

        item->setFlags(
            Qt::ItemIsEnabled
        );

        item->setBackground(
            calcularCor(
                r.btu,
                menorBTU,
                maiorBTU
            )
        );

        setItem(
            l,
            c,
            item
        );

        break;
    }
}

void MapaCalorBTU::atualizarAnimacao()
{
    int maxLinha =
        std::min(
            camadaAtual,
            (int)pessoas.size()-1
        );

    int maxColuna =
        std::min(
            camadaAtual,
            (int)computadores.size()-1
        );

    std::vector<std::pair<int,int>> borda;

    for(int c=0;c<=maxColuna;c++)
        borda.push_back(
            {
                maxLinha,
                c
            }
        );

    for(int l=0;l<maxLinha;l++)
        borda.push_back(
            {
                l,
                maxColuna
            }
        );

    if(etapaAtual < (int)borda.size())
    {
        desenharCelula(
            borda[etapaAtual].first,
            borda[etapaAtual].second
        );

        etapaAtual++;
        return;
    }

    camadaAtual++;
    etapaAtual = 0;

    if(
        camadaAtual >=
        std::max(
            pessoas.size(),
            computadores.size()
        )
    )
    {
        timer.stop();
    }
}
