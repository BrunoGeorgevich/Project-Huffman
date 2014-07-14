#ifndef EncondingNode_H
#define EncondingNode_H

#include <QString>

class EncondingNode
{
    int frequency;
    unsigned char byte;
    bool type;
    EncondingNode *right;
    EncondingNode *left;

public:

    EncondingNode();
    EncondingNode(int i);

    int getFrequency() const;
    void setFrequency(int frequency);

    unsigned char getByte()const ;
    void setByte(unsigned char byte);

    EncondingNode *getLeft() const;
    void setLeft(EncondingNode *left);

    EncondingNode *getRight() const;
    void setRight(EncondingNode *right);

    void setType(bool i);
    bool getType();
};

#endif // EncondingNode_H
