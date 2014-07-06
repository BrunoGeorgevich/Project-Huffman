#ifndef TREE_H
#define TREE_H

#include "node.h"
#include "codification.h"
#include <QList>
#include <QString>
#include <fstream>

class Tree
{

public:

    Node *root;
    QString auxCode;
    QList<Node*> DList;
    Codification *cod;
    QString BinaryCode;
    QString BinTree;
    char MapChar;

    Tree(QList<Node*> list);
    void TreeSort(QList<Node *> *content);
    void fill();
    void print(Node *node, int level = 0);
    void MinimizedForm(Node *node);
    Node *CodificationPerChar(Node *node, unsigned char carac);
    void WritingCodification();
    QString Data_Codification(QString path , QString destiny);
    unsigned short SizeTrashTree();
};

#endif // TREE_H
