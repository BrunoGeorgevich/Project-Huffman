#ifndef TREE_H
#define TREE_H

#include "node.h"
#include "codification.h"
#include <QList>
#include <QString>
#include <fstream>
#include <math.h>

class Tree
{

public:

    Node *root;
    QString auxCode;
    QList<Node*> DList;
    Codification *cod;
    QString BinaryCode;
    QString DecodeData;
    QString BinTree;
    char MapChar;
    int lixo;
    QList<Node*> RemountedTree;

    Tree(QList<Node*> list);
    Tree();
    void TreeSort(QList<Node *> *content);
    void fill();
    void print(Node *node, int level = 0);
    void MinimizedForm(Node *node);
    Node *CodificationPerChar(Node *node, unsigned char carac);
    void WritingCodification();
    char *toBinary(int x);
    void Data_Codification(QString path , QString destiny, QString nome);
    void Data_Decodification(QString path, QString Destiny);
    unsigned short SizeTrashTree();
    unsigned char nameSize(QString nome);
    char *Short_to_Caracter(unsigned short x);
    void remountTree();
};

#endif // TREE_H
