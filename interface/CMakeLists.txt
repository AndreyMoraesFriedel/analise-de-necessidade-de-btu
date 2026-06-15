cmake_minimum_required(VERSION 3.16)

project(
    SimuladorBTUQt
)

set(
    CMAKE_CXX_STANDARD 17
)

find_package(
    Qt6 REQUIRED COMPONENTS
    Widgets
    Sql
    Charts
)

qt_standard_project_setup()

qt_add_executable(
    SimuladorBTUQt

    main.cpp
    MainWindow.cpp
    GraficoBTU.cpp

    ../simulacao/Simulador.cpp
    ../simulacao/CenarioSimulacao.cpp
    ../simulacao/ResultadoSimulacao.cpp
    ../simulacao/ResultadoSimulacao-odb.cxx

    ../entrada/LeitorCSV.cpp

    ../ambiente/Ambiente.cpp
    ../ambiente/Pessoa.cpp

    ../equipamentos/Televisao.cpp
    ../equipamentos/Computador.cpp
    ../equipamentos/Celular.cpp

    ../calculos/CalculadoraBTU.cpp
)

target_link_libraries(
    SimuladorBTUQt
    PRIVATE
    Qt6::Widgets
    Qt6::Sql
    Qt6::Charts

    odb
    odb-sqlite
    sqlite3
)
