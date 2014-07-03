#ifndef NODE_H
#define NODE_H

class Node
{
    int frequency;
    unsigned char byte;
    Node *right;
    Node *left;
    bool type;

public:

    Node();
    Node(int i);
//    bool isSingle();
//    bool isLeaf();
    void incFrequency(int increase);
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
};

#endif // NODE_H
