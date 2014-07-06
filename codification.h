#ifndef CODIFICATION_H
#define CODIFICATION_H

#include <QString>
//#include "tree.h"

class Codification
{
public:

    Codification();
    char symbol;
    QString BinSymbol;

public:

    void define(char nextSymbol , QString BinaryS);

};

#endif // CODIFICATION_H
