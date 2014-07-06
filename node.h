#ifndef NODE_H
#define NODE_H

#include <QString>

class Node
{
    int frequency;
    unsigned char byte;
    Node *right;
    Node *left;
    bool type;
    int mapKey;

public:

    Node();
    Node(int i);
    int getFrequency() const;
    void setFrequency(int frequency);
    unsigned char getByte()const ;
    void setByte(unsigned char byte);
    Node *getLeft() const;
    void setLeft(const Node *left);
    Node *getRight() const;
    void setRight(const Node *right);
    void setType(bool i);
    bool getType();
    void setMapKey(bool i);
    bool getMapKey();
};

#endif // NODE_H
