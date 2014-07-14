#include "encodingNode.h"

EncondingNode::EncondingNode()
{
    frequency = 0;
    type = 0;
    left = 0;
    right = 0;
}
EncondingNode::EncondingNode(int i)
{
    frequency = i;
    type = 0;
    left = 0;
    right = 0;
}

int EncondingNode::getFrequency() const
{
    return this->frequency;
}

void EncondingNode::setFrequency(int frequency)
{
    this->frequency = frequency;
}

unsigned char EncondingNode::getByte() const
{
    return byte;
}

void EncondingNode::setByte(unsigned char byte)
{
    this->byte = byte;
}

EncondingNode *EncondingNode::getLeft()const
{
    return left;
}

void EncondingNode::setLeft(EncondingNode *left)
{
    this->left = left;
}

EncondingNode *EncondingNode::getRight()const
{
    return right;
}

void EncondingNode::setRight(EncondingNode *right)
{
    this->right = right;
}

void EncondingNode::setType(bool i)
{
    type = i;
}

bool EncondingNode::getType()
{
    return type;
}
