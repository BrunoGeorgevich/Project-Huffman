#include "encodingTree.h"
#include <stdio.h>
#include <iostream>

using namespace std;

EncodingTree::EncodingTree(QString path)
{

    Data_File file(path);
    QList<EncondingNode*> lista = file.toList();

    DList = lista;
    auxCode = "";
    BinTree = "";
    cod = new Codification[265];
    BinaryCode = "";

    fill();
    MinimizedForm(root);
    WritingCodification();
    Data_Codification(path,"", GetName(path,0) , GetName(path,1), 0);

}
EncodingTree::EncodingTree(QString path, QString name)
{

    Data_File file(path);
    QList<EncondingNode*> lista = file.toList();

    DList = lista;
    auxCode = "";
    BinTree = "";
    cod = new Codification[265];
    BinaryCode = "";

    fill();
    MinimizedForm(root);
    WritingCodification();
    Data_Codification(path,"", GetName(path,0) , name, 1);

}

void EncodingTree::fill(){

    QList<EncondingNode *> lista = DList;

    while(lista.size() > 1)
    {

        EncondingNode *tmp = new EncondingNode(lista.at(0)->getFrequency() + lista.at(1)->getFrequency());
        int z = 0;

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
    }
}
void EncodingTree::MinimizedForm(EncondingNode *EncondingNode)
{

    if(EncondingNode->getType() == 1) {

        BinTree.append("(");

        MinimizedForm(EncondingNode->getLeft());
        MinimizedForm(EncondingNode->getRight());

        BinTree.append(")");
    }
    else
    {
        if((int)EncondingNode->getByte() == '0')
        {
            BinTree.append("00");
        }
        else if((int)EncondingNode->getByte() == 40)
        {
            BinTree.append("0(");
        }
        else if((int)EncondingNode->getByte() == 41)
        {
            BinTree.append("0)");
        }
        else
        {
            BinTree.append(EncondingNode->getByte());
        }
    }
}

void EncodingTree::print(EncondingNode *EncondingNode, int level)
{
    if(EncondingNode != 0) {
        if(EncondingNode->getType() != 1)
        {
            print(EncondingNode->getRight(), level + 1);
            if((int)EncondingNode->getByte() == 10)
            {
                cout << qPrintable(QString("\t").repeated(level))
                     << "_" << endl;
                print(EncondingNode->getLeft(), level + 1);
            }
            else
            {
                cout << qPrintable(QString("\t").repeated(level))
                     << EncondingNode->getByte() << endl;
            }
            print(EncondingNode->getLeft(), level + 1);

        }
        else
        {
            print(EncondingNode->getRight(), level + 1);
            if((int)EncondingNode->getByte() == 10)
            {
                cout << qPrintable(QString("\t").repeated(level))
                     << (int)EncondingNode->getFrequency() << endl;
                print(EncondingNode->getLeft(), level + 1);
            }
            else
            {
                cout << qPrintable(QString("\t").repeated(level))
                     << (int)EncondingNode->getFrequency() << endl;
            }
            print(EncondingNode->getLeft(), level + 1);

        }
    }
}

void EncodingTree::WritingCodification()
{
    for(int i = 0 ; i < DList.size() ; i++ , auxCode = "")
    {
        CodificationPerChar(root,DList[i]->getByte());
    }
}

EncondingNode *EncodingTree::CodificationPerChar(EncondingNode *EncondingNode, unsigned char carac)
{

    if(EncondingNode->getType() == 1)
    {
        auxCode += '0';

        CodificationPerChar(EncondingNode->getLeft(),carac);

        auxCode.remove(auxCode.size() - 1,1);

        auxCode += '1';

        CodificationPerChar(EncondingNode->getRight(),carac);


        auxCode.remove(auxCode.size() - 1,1);


    }
    else if(EncondingNode->getByte() == carac)
    {
        cod[(int)EncondingNode->getByte()].define(carac,auxCode);
    }

    return EncondingNode;
}
void EncodingTree::Data_Codification(QString path , QString destiny, QString nomeExt , QString nome, bool decision)
{
    QString destino = "";

    if(decision == 1)
    {
        destino = destiny + nome;
    }
    else
    {
        destino = destiny + nome + ".huff";
    }
    ifstream data(path.toLatin1().data(),ios::binary);//Ler bytes do arquivo
    ofstream out(destino.toLatin1().data());//salvando o arquivo
    unsigned char *bytes;
    int trash = 0;
    unsigned long int sourceData_Size;
    QString sum = "";

    data.seekg(0,ios::end);//procura o fim do arquivo
    sourceData_Size = data.tellg();//define o tamanho do arquivo como sourceData_Size
    data.seekg(0,ios::beg);//volta para o início do arquivo

    out << char(97);
    out << char(98);
    out << (unsigned char)nomeExt.size();
    out << nomeExt.toLatin1().data();
    for(int i = 0 ; i < BinTree.size() ; i++)
    {
        out << BinTree.toLatin1().data()[i];
    }

    for(int i = 0; i < sourceData_Size ; i++)
    {
        bytes =new unsigned char[1];
        data.read((char *)bytes,1);
        for(int k = 0 ; k < cod[bytes[0]].BinSymbol.size() ; k++ , trash++)
        {
            if(sum.size() == 8)
            {
                BinaryCode.append(sum.toInt(0,2));
                out << (char)sum.toInt(0,2);
                sum = "";
            }
            sum.append(qPrintable(cod[bytes[0]].BinSymbol[k]));
        }
    }

    if(trash % 8 != 0)
    {
        trash = (((trash/8)+1)*8) - trash;
        for(int i = 0; i < trash ; i++)
        {
            sum.append('0');
        }

        BinaryCode.append(sum.toInt(0,2));
        out << (char)sum.toInt(0,2);
        sum = "";
        lixo = trash;
    }
    else
    {
        trash = 0;
        lixo = trash;
    }

    out.seekp(ios::beg);

    unsigned short aux = SizeTrashTree();
    char *TrashNTree = Short_to_Caracter(aux);
    int SizeTrash = 0;
    int SizeTree = 0;

    for(int i = 0; i < 8 ; i++)
    {
        int y = (int)TrashNTree[i + 8];
        int z = (int)TrashNTree[i];
        SizeTrash += z*pow(2,7 - i);
        SizeTree += y*pow(2,7 - i);
    }
    out << (unsigned char)SizeTrash << (unsigned char)SizeTree;

}
unsigned short EncodingTree::SizeTrashTree()
{
    unsigned short trash = lixo;
    int tree = BinTree.size();

    trash = trash << 13;
    trash = trash | tree;

    return trash;
}

char *EncodingTree::Short_to_Caracter(unsigned short x)
{
    char *result = new char[16];
    unsigned short aux = x;
    for(int i = 15 ; i >= 0 ; i--)
    {
        result[15 - i] = aux/pow(2,i);
        aux = aux - result[15 - i]*pow(2,i);
    }

    return result;

}

QString EncodingTree::GetName(QString name, bool c)
{
    QString nome = "";

    if(c == 0)
    {
        int size = name.size();

        for(int i = size; i >= 0; i--)//identificando a extensão do arquivo
        {
            if(name[i - 1] == '/' || i == 0 )
            {
                int k = i;
                for(int j = 0; j < size - k; j++, i++){

                    nome[j] = name[i];//armazenando extensão na QString type

                }
                break;
            }
        }
    }
    else if(c == 1)
    {
        int size = name.size();
        int FirstDot = 0;
        int signal = 1;

        for(int i = size; i >= 0; i--)//identificando a extensão do arquivo
        {
            if(name[i] == '.' && signal == 1)
            {
                FirstDot = i;
                signal = 0;
            }
            if(name[i - 1] == '/' || i == 0 )
            {
                int k = i;

                for(int j = 0; j < FirstDot - k; j++, i++){

                    nome[j] = name[i];//armazenando extensão na QString type
                }
                break;
            }
        }
    }

    return nome;
}





