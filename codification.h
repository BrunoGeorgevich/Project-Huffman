#ifndef CODIFICATION_H
#define CODIFICATION_H

#include <QString>
//#include "tree.h"

class Codification
{
public:

    Codification();
    unsigned char symbol;
    QString BinSymbol;

public:

    void define(unsigned char nextSymbol , QString BinaryS);

};

#endif // CODIFICATION_H
