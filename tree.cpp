#include "tree.h"
#include <stdio.h>
#include <iostream>

using namespace std;

Tree::Tree()
{
    root = new Node;
}

void Tree::fill(QList<Node*> list){
    while(list.size() > 1)
    {
//        cout << "-----------------" << endl;

        Node *tmp = new Node(list.at(0)->getFrequency() + list.at(1)->getFrequency());
        int z = 0;

        tmp->setLeft(list.at(0));
        tmp->setRight(list.at(1));
        tmp->setType(1);

        list.removeAt(0);
        list.removeAt(0);
        list.insert(z, tmp);

        root = tmp;

        while(1)
        {
            if(z == list.size() - 1)
            {
                break;
            }
            if(list.at(z)->getFrequency() > list.at(z + 1)->getFrequency())
            {
                list.swap(z,z+1);
            }
            else
            {
                break;
            }
            z++;
        }

//        for(int i = 0 ; i < list.size(); i++)
//        {
//            cout << list.at(i)->getFrequency() << " ";
//        }
//        cout << endl;
    }
}

void Tree::print(Node *node, int level)
{
    if(node != 0) {
        if(node->getType() != 1)
        {
            print(node->getRight(), level + 1);
            if((int)node->getByte() == 10)
            {
                cout << qPrintable(QString("\t").repeated(level))
                     << "ETR" << endl;
                print(node->getLeft(), level + 1);
            }
            else
            {
                cout << qPrintable(QString("\t").repeated(level))
                     << node->getByte() << endl;
            }
            print(node->getLeft(), level + 1);

        }
        else
        {
            print(node->getRight(), level + 1);
            if((int)node->getByte() == 10)
            {
                cout << qPrintable(QString("\t").repeated(level))
                     << (int)node->getFrequency() << endl;
                print(node->getLeft(), level + 1);
            }
            else
            {
                cout << qPrintable(QString("\t").repeated(level))
                     << (int)node->getFrequency() << endl;
            }
            print(node->getLeft(), level + 1);

        }
    }
}

void Tree::MinimizedForm(Node *node)
{
    if(node->getType() == 1) {

            cout << "(";

            MinimizedForm(node->getLeft());
            MinimizedForm(node->getRight());

            cout << ")";
    }
    else
    {
        if((int)node->getByte() != 10)
        {
            cout << node->getByte();
        }
        else
        {
            cout << "ETR";
        }
    }
}

void Tree::SaveData(unsigned char *data, QString path, QString Name)
{

}


