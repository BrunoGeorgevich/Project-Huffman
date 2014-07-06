#include "node.h"

Node::Node()
{
    frequency = 0;
    type = 0;
    left = 0;
    right = 0;
    mapKey = 0;
}
Node::Node(int i)
{
    frequency = i;
    type = 0;
    left = 0;
    right = 0;
    mapKey = 0;
}

//bool Node::isSingle()
//{
//    bool answer = true;
//    if(this->left != 0 && this->right != 0){
//        answer = false;
//    }
//    return answer;
//}

//bool Node::isLeaf()
//{
//    bool answer = false;
//    if(this->left == 0 && this->right == 0){
//        answer = true;
//    }
//    return answer;
//}

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

void Node::setLeft(const Node *left)
{
    this->left = (Node*)left;
}

Node *Node::getRight()const
{
    return right;
}

void Node::setRight(const Node *right)
{
    this->right = (Node*)right;
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
