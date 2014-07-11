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
    DecodeData = "";
    cod = new Codification[265];
    BinaryCode = "";


}
Tree::Tree()
{
    root = new Node;
    MapChar = 0;
    BinTree = "";
    DecodeData = "";
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

void Tree::print(Node *Node, int level)
{
    if(Node != 0) {
        if(Node->getType() != 1)
        {
            print(Node->getRight(), level + 1);
            if((int)Node->getByte() == 10)
            {
                cout << qPrintable(QString("\t").repeated(level))
                     << "_" << endl;
                print(Node->getLeft(), level + 1);
            }
            else
            {
                cout << qPrintable(QString("\t").repeated(level))
                     << Node->getByte() << endl;
            }
            print(Node->getLeft(), level + 1);

        }
        else
        {
            print(Node->getRight(), level + 1);
            if((int)Node->getByte() == 10)
            {
                cout << qPrintable(QString("\t").repeated(level))
                     << (int)Node->getFrequency() << endl;
                print(Node->getLeft(), level + 1);
            }
            else
            {
                cout << qPrintable(QString("\t").repeated(level))
                     << (int)Node->getFrequency() << endl;
            }
            print(Node->getLeft(), level + 1);

        }
    }
}

void Tree::MinimizedForm(Node *Node)
{

    if(Node->getType() == 1) {

        BinTree.append("(");

        MinimizedForm(Node->getLeft());
        MinimizedForm(Node->getRight());

        BinTree.append(")");
    }
    else
    {
        if((int)Node->getByte() == 39)
        {
            BinTree.append("''");
        }
        else if((int)Node->getByte() == 40)
        {
            BinTree.append("'(");
        }
        else if((int)Node->getByte() == 41)
        {
            BinTree.append("')");
        }
        else
        {
            BinTree.append(Node->getByte());
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

char *Tree::toBinary(int x)
{
    char *result = new char[8];
    unsigned int aux = x;
    for(int i = 7 ; i >= 0 ; i--)
    {
        result[7 - i] = aux/pow(2,i);
        aux = aux - result[7 - i]*pow(2,i);
    }

    return result;
}

Node * Tree::CodificationPerChar(Node *Node, unsigned char carac)
{

    if(Node->getType() == 1)
    {
        auxCode += '0';

        CodificationPerChar(Node->getLeft(),carac);

        auxCode.remove(auxCode.size() - 1,1);

        auxCode += '1';

        CodificationPerChar(Node->getRight(),carac);


        auxCode.remove(auxCode.size() - 1,1);


    }
    else if(Node->getByte() == carac)
    {
        cod[(int)Node->getByte()].define(carac,auxCode);
        //        cout << Node->getByte() << " = " << qPrintable(cod[(int)Node->getByte()].BinSymbol) << endl;
        return Node;
    }

}
void Tree::Data_Codification(QString path , QString destiny, QString nome)
{
    QString destino = destiny + nome;
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
    out << (unsigned char)nome.size();
    out << nome.toLatin1().data();
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
            //            cout << ((float)i/sourceData_Size)*100 << "%" << endl;
        }
    }

    if(trash % 8 != 0)
    {
        trash = (((trash/8)+1)*8) - trash;
        for(int i = 0; i < trash ; i++)
        {
            sum.append('0');
            //            cout << qPrintable(sum) << endl;
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
    cout << SizeTrash << "  " << SizeTree  << endl;
    out << (unsigned char)SizeTrash << (unsigned char)SizeTree;
    cout  << endl;
    cout << "Tamanho do Arquivo : " << sourceData_Size << "  Tamanho do Lixo : " << trash << "   Tamanho da Árvore : " << BinTree.size() << endl;


}

void Tree::Data_Decodification(QString path, QString Destiny)
{
    ifstream data(path.toLatin1().data(),ios::binary);//Ler bytes do arquivo
    unsigned int sourceData_Size;

    data.seekg(0,ios::end);//procura o fim do arquivo
    sourceData_Size = data.tellg();//define o tamanho do arquivo como sourceData_Size
    data.seekg(0,ios::beg);//volta para o início do arquivo

    unsigned char *bytes = new unsigned char[1];
    char *tmp = "";
    Node *Node;
    lixo = 0;
    unsigned long int treeSize = 0;
    int position = 0;

    bytes = new unsigned char[2];
    data.read((char *)bytes,2);//lendo os bytes
    position += 2;

    int aux = (int)bytes[0];
    int aux2 = (int)bytes[1];

    for(int i = 0 ; i < 8; i++)
    {
        int y = 0;
        int z = 0;
        if(i < 4)
        {
            z = aux/pow(2,7 - i);
            aux = aux - z*pow(2,7 - i);
            lixo += z*pow(2,2 - i);

        }
        else
        {
            z = aux/pow(2,7 - i);
            aux = aux - z*pow(2,7 - i);
            treeSize += z*pow(2,15 - i);
        }
        y = aux2/pow(2,7 - i);
        aux2 = aux2 - y*pow(2,7 - i);
        treeSize += y*pow(2,7 - i);
    }

    cout << "TREE SIZE :: " << treeSize << "   LIXO :: " << lixo << endl;

    bytes = new unsigned char[1];
    data.read((char *)bytes,1);//lendo os bytes
    position += 1;

    //    cout << "Tamanho do Nome :: " << aux << endl;

    aux = (int)bytes[0];


    bytes = new unsigned char[aux];
    data.read((char *)bytes,aux);//lendo os bytes
    position += aux;

    unsigned char *Nome = new unsigned char[aux];
    Nome = bytes;
    QString name = "";

            for(int i =0 ; i < aux; i++)
            {
//                cout << Nome[i];
                name[i] = Nome[i];
                cout << qPrintable(name[i]) << endl;
            }
    //            cout << endl;


    QString destino = Destiny + name;
    ofstream out(destino.toLatin1().data());//salvando o arquivo


    bytes = new unsigned char[treeSize];
    data.read((char *)bytes,treeSize);//lendo os bytes
    position += treeSize;

    BinTree = "";

    for(int i = 0 ; i < treeSize; i++ )
    {
//        cout << bytes[i];
        BinTree.append(bytes[i]);
    }

    remountTree();
    Node = root;

    for(int i  = position; i < sourceData_Size - 1; i++)
    {
        bytes = new unsigned char[1];
        data.read((char *)bytes,1);//lendo os bytes
        tmp = toBinary((int)bytes[0]);

        for(int i = 0 ; i < 8 ; i++)
        {
            if(Node->getType() == 1)
            {
                if((int)tmp[i] == 1)
                {
//                    Node = Node->getRight();
                }
                else if((int)tmp[i] == 0)
                {
//                    Node = Node->getLeft();
                }
            }
            if(Node->getType() == 0)
            {
                DecodeData.append(Node->getByte());
                //                cout << Node->getByte();
                out << Node->getByte();
                Node = root;


            }
        }
    }

    bytes = new unsigned char[1];
    data.read((char *)bytes,1);//lendo os bytes
    tmp = toBinary((int)bytes[0]);

    for(int i = 0 ; i < 8 - lixo ; i++)
    {
        if(Node->getType() == 1)
        {
            if((int)tmp[i] == 1)
            {
//                Node = Node->getRight();
            }
            else if((int)tmp[i] == 0)
            {
//                Node = Node->getLeft();
            }
        }
        if(Node->getType() == 0)
        {
            DecodeData.append(Node->getByte());
            out << Node->getByte();
            Node = root;


        }
    }
}

unsigned short Tree::SizeTrashTree()
{
    unsigned short trash = lixo;
    int tree = BinTree.size();

    cout << "BINTREE :: " << tree << endl;


    trash = trash << 13;
    trash = trash | tree;

    return trash;
}

unsigned char Tree::nameSize(QString nome)
{
    unsigned char a = nome.size();
    return a;
}

char *Tree::Short_to_Caracter(unsigned short x)
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
void Tree::remountTree()
{
    char ch;
    bool warn = false;
    int count = 0;

    for(count = 0 ; count < BinTree.size() ; count++){


        ch = BinTree.toStdString()[count];
//        cout  << count << "   " << ch << "    " << root->right;

        if(ch=='('){
            if(warn == true){
                //cout  << ch;
                warn = false;
                if(root->left==NULL) {
                    root->left = new Node;
                    root->left->setByte(ch);
                    //cout  << root->left->contain;
                    root->left->setType(1);
                }

                else {
                    //cout  << ch << "Right";
                    root->right = new Node;
                    root->right->parent = new Node;
                    root->right->parent = root;
                    root = root->right;
                    root->setByte(ch);
                    root->setType(1);
                    root = root->parent;
                }

            }

            else if(root == NULL){
                root = new Node;
                root->setType(0);
                root->left = root->right = 0;
                root->parent = new Node;
                root->parent = root;
            }

            else if(root->left==NULL){
                //cout  << "Left";
                root->left = new Node;
                root->left->parent = new Node;
                root->left->parent = root;
                root = root->left;
                root->left = root->right = 0;
                root->setType(0);
            }

            else if(root->right==NULL){
                //cout  << "Right";
                root->right = new Node;
                root->right->parent = new Node;
                root->right->parent = root;
                root = root->right;
                root->left = root->right = 0;
                root->setType(0);
            }
        }

        else if(ch==')'){
            if(warn == true){
                //cout  << ch;
                warn = false;
                if(root->left==NULL) {
                    root->left = new Node;
                    root->left->setByte(ch);
                    //cout  << root->left->contain;
                    root->left->setType(1);
                }

                else {
                    //cout  << ch << "Right";
                    root->right = new Node;
                    root->right->parent = new Node;
                    root->right->parent = root;
                    root = root->right;
                    root->setByte(ch);
                    root->setType(1);
                    root = root->parent;
                }
            } else {
                //cout  << "Back";
                if(root->parent != NULL){
                    root = root->parent;
                }
            }
        }

        else {

            if(ch == '0'){
                if(warn == true){
                    //cout  << ch;
                    warn = false;
                    if(root->left==NULL) {
                        root->left = new Node;
                        root->left->setByte(ch);
                        //cout  << root->left->contain;
                        root->left->setType(1);
                    }

                    else {
                        //cout  << ch << "Right";
                        root->right = new Node;
                        root->right->parent = new Node;
                        root->right->parent = root;
                        root = root->right;
                        root->setByte(ch);
                        root->setType(1);
                        root = root->parent;
                    }
                } else {
                    warn = true;
                }
            }

            else if(root->left==NULL) {
                root->left = new Node;
                root->left->setByte(ch);
                //cout  << root->left->contain;
                root->left->setType(1);
            }

        }

    }

}



