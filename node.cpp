#include "node.h"

Node::Node()
{
    frequency = 0;
    type = 0;
    left = 0;
    right = 0;
    mapKey = 0;
    parent = 0;
}
Node::Node(int i)
{
    frequency = i;
    type = 0;
    left = 0;
    right = 0;
    mapKey = 0;
    parent = 0;
}
Node::Node(Node *pai)
{
    frequency = 0;
    type = 0;
    left = 0;
    right = 0;
    mapKey = 0;
    parent = pai;
}

int Node::getFrequency() const
{
    return this->frequency;
}

void Node::setFrequency(int frequency)
{
    this->frequency = frequency;
}

unsigned char Node::getByte() const
{
    return byte;
}

void Node::setByte(unsigned char byte)
{
    this->byte = byte;
}

Node *Node::getLeft()const
{
    return left;
}

void Node::setLeft(Node *left)
{
    this->left = left;
    left->setParent(this);
}

Node *Node::getRight()const
{
    return right;
}

void Node::setRight(Node *right)
{
    this->right = right;
    right->setParent(this);
}

void Node::setType(bool i)
{
    type = i;
}

bool Node::getType()
{
    return type;
}

void Node::setMapKey(bool i)
{
    mapKey = i;
}

bool Node::getMapKey()
{
    return mapKey;
}

Node *Node::getParent()
{
    return parent;
}

Node *Node::setParent(Node *node)
{
    parent = node;
}

