#ifndef PESSOA_H
#define PESSOA_H

namespace ambiente {

class Pessoa {

private:
    int percepcaoCalor;

public:

    Pessoa(
        int percepcaoCalor = 3
    );

    int getPercepcaoCalor() const;
};

}

#endif
