#include "tree.h"
#include <stdio.h>
#include <iostream>

using namespace std;

Tree::Tree(QList<Node *> list)
{
    root = new Node;
    MapChar = 0;
    DList = list;
    auxCode = "";
    BinTree = "";
    cod = new Codification[265];

}

void Tree::fill(){

    QList<Node *> lista = DList;

    while(lista.size() > 1)
    {

        Node *tmp = new Node(lista.at(0)->getFrequency() + lista.at(1)->getFrequency());
        int z = 0;

        lista.at(0)->setMapKey(0);
        lista.at(1)->setMapKey(1);
        tmp->setLeft(lista.at(0));
        tmp->setRight(lista.at(1));
        tmp->setType(1);

        lista.removeAt(0);
        lista.removeAt(0);
        lista.insert(z, tmp);

        root = tmp;

        while(1)
        {
            if(z == lista.size() - 1)
            {
                break;
            }
            if(lista.at(z)->getFrequency() > lista.at(z + 1)->getFrequency())
            {
                lista.swap(z,z+1);
            }
            else
            {
                break;
            }
            z++;
        }

//                for(int i = 0 ; i < lista.size(); i++)
//                {
//                    cout << lista.at(i)->getFrequency() << " ";
//                }
//                cout << endl;
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
                     << "_" << endl;
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

        BinTree.append("(");

        MinimizedForm(node->getLeft());
        MinimizedForm(node->getRight());

        BinTree.append(")");
    }
    else
    {
        if((int)node->getByte() != 10)
        {
            BinTree.append(node->getByte());
        }
        else
        {
            BinTree.append("_");
        }
    }
}

void Tree::WritingCodification()
{
    for(int i = 0 ; i < DList.size() ; i++ , auxCode = "")
    {
        CodificationPerChar(root,DList[i]->getByte());
    }
}

Node * Tree::CodificationPerChar(Node *node, unsigned char carac)
{

    if(node->getType() == 1)
    {
        auxCode += '0';

        CodificationPerChar(node->getLeft(),carac);

        auxCode.remove(auxCode.size() - 1,1);

        auxCode += '1';

        CodificationPerChar(node->getRight(),carac);


        auxCode.remove(auxCode.size() - 1,1);


    }
    else if(node->getByte() == carac)
    {
        cod[(int)node->getByte()].define(node->getByte(),auxCode);
//        cout << (int)node->getByte() << " = " << qPrintable(auxCode) << endl;
        return node;
    }

}
QString Tree::Data_Codification(QString path , QString destiny)
{

    char *bytes;
    int sourceData_Size;
    ifstream data(path.toLatin1().data(),ios::binary);//Ler bytes do arquivo

    data.seekg(0,ios::end);//procura o fim do arquivo
    sourceData_Size = data.tellg();//define o tamanho do arquivo como sourceData_Size
    data.seekg(0,ios::beg);//volta para o início do arquivo

 while(1)
 {

    int position = data.tellg();

    cout << position <<  endl;

    if(position + 8 >= sourceData_Size)
    {
        cout << "---1---" << endl;
        bytes = new char[sourceData_Size - position];//declarando o array que portará os bytes
        data.read(bytes,sourceData_Size - position);//lendo os bytes

        for(int i = 0 ; i < (sourceData_Size - position) ; i++)
        {
            BinaryCode.append(cod[bytes[i]].BinSymbol);
        }
        data.close();//fechando o arquivo
        goto end;

    }
    else
    {
        cout << "---2---" << endl;
        bytes = new char[8];//declarando o array que portará os bytes
        data.read(bytes,8);//lendo os bytes
        for(int i = 0 ; i < 8 ; i++)
        {
            BinaryCode.append(cod[bytes[i]].BinSymbol);
        }

    }

 }

    end:;
    cout << qPrintable(BinaryCode)  << "  Size : " << BinaryCode.size() << endl;
    return BinaryCode;
}

unsigned short Tree::SizeTrashTree()
{
    unsigned short trash;
    int tree = BinTree.size();

    if(tree % 8 != 0)
    {
        trash = 8 - (tree % 8);
    }
    else
    {
        trash = 0;
    }


    trash = trash << 13;
    trash = trash | tree;

    return trash;
}

