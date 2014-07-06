#include "codification.h"

Codification::Codification()
{
    symbol = 0;
    BinSymbol = "***";
}

void Codification::define(char nextSymbol, QString BinaryS)
{
    symbol = nextSymbol;
    BinSymbol = BinaryS;
}
