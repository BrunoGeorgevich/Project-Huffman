#ifndef ENCODINGNODE_H
#define ENCODINGNODE_H

#include <QFile>
#include <iostream>
#include <math.h>

using namespace std;

class DecodingNode {

public:

    bool Type;
    unsigned char Byte;
    DecodingNode *Left;
    DecodingNode *Right;
    DecodingNode *Parent;

};

#endif // ENCODINGNODE_H
