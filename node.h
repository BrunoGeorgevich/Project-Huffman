#ifndef NODE_H
#define NODE_H

#include <QString>

class Node
{
    int frequency;
    unsigned char byte;
    bool type;
    int mapKey;

public:

    Node *right;
    Node *parent;
    Node *left;

    Node();
    Node(int i);
    Node(Node *pai);
    int getFrequency() const;
    void setFrequency(int frequency);
    unsigned char getByte()const ;
    void setByte(unsigned char byte);
    Node *getLeft() const;
    void setLeft(Node *left);
    Node *getRight() const;
    void setRight(Node *right);
    void setType(bool i);
    bool getType();
    void setMapKey(bool i);
    bool getMapKey();
    Node *getParent();
    Node *setParent(Node *node);
};

#endif // NODE_H
