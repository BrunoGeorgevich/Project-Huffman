#ifndef TREE_H
#define TREE_H

#include "node.h"
#include <QList>
#include <QString>

class Tree
{
public:
    Node *root;
    Tree();
    void TreeSort(QList<Node *> *content);
    void fill(QList<Node *> list);
    void print(Node *node, int level = 0);
    void MinimizedForm(Node *node);
    void SaveData(unsigned char *data, QString path, QString Name);
};

#endif // TREE_H
