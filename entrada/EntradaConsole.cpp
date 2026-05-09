#include <iostream> 
#include "EntradaConsole.h" 
using namespace std; 

namespace entrada { 

    double EntradaConsole::lerLargura() { 
        double l; 
        cout << "Largura do ambiente (m): "; 
        cin >> l; 
        return l; 
    } 

    double EntradaConsole::lerComprimento() { 
        double c; cout << "Comprimento do ambiente (m): "; 
        cin >> c; 
        return c; 
    }

    double EntradaConsole::lerAltura() {
        double a;
        cout << "Altura do ambiente (m): ";
        cin >> a;
        return a;
    } 

    int EntradaConsole::lerPessoas() { 
        int p; 
        cout << "Quantidade de pessoas: "; 
        cin >> p; 
        return p; 
    } 

    int EntradaConsole::lerEletronicos() { 
        int e; 
        cout << "Quantidade de eletronicos: "; 
        cin >> e; 
        return e; 
    } 

    bool EntradaConsole::lerSolDireto() { 
        char resposta; 
        cout << "Recebe sol direto? (s/n): "; 
        cin >> resposta; 
        return (resposta == 's' || resposta == 'S'); 
    } 

    double EntradaConsole::lerTemperaturaAtual() { 
        double t; 
        cout << "Temperatura atual: "; 
        cin >> t; 
        return t; 
    } 

    double EntradaConsole::lerTemperaturaExterna() { 
        double t; 
        cout << "Temperatura externa: "; 
        cin >> t; 
        return t; 
    } 

    int EntradaConsole::lerQuantidade(const char* mensagem) { 
        int q; 
        cout << mensagem; 
        cin >> q; 
        return q; 
    } 
}