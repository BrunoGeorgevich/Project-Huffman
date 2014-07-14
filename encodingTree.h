#ifndef TREE_H
#define TREE_H

#include "encodingNode.h"
#include "codification.h"
#include "data_file.h"
#include <QList>
#include <QString>
#include <fstream>
#include <math.h>

class EncodingTree
{

public:

    EncondingNode *root;
    QString auxCode;
    QList<EncondingNode*> DList;
    Codification *cod;
    QString BinaryCode;
    QString BinTree;
    char MapChar;
    int lixo;

    EncodingTree(QString path);
    EncodingTree(QString path, QString name);
    void fill();
    void print(EncondingNode *node, int level = 0);
    EncondingNode *CodificationPerChar(EncondingNode *node, unsigned char carac);
    void WritingCodification();
    void Data_Codification(QString path , QString destiny, QString nomeExt, QString nome, bool decision);
    unsigned short SizeTrashTree();
    char *Short_to_Caracter(unsigned short x);
    QString GetName(QString name, bool c );
    void MinimizedForm(EncondingNode *Node);
};

#endif // ENCODINGTREE_H
