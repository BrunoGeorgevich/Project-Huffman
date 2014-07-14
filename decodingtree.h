#ifndef DECODING_H
#define DECODING_H

#include "decodingNode.h"

class DecodingTree
{
public:

    int TreeSize;
    int TrashSize;
    int SizeName;
    DecodingNode *root;
    QByteArray cod;

    QByteArray DecimalToBin(int dec);
    int BinaryToDec(QByteArray bin);
    void Measuring_Tree(QFile * Archive);
    QByteArray GetName(QFile * Archive);
    void remountingTree(QFile * Archive);
    void remountingCode(QFile *Archive);
    void rewritingCode(QFile * Data);
    void decodeFile(QString Nome, QString destiny);

};

#endif // DECODING_H
