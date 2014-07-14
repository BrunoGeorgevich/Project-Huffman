#include "decodingtree.h"

//Método que transforma números de Binário para Decimal
int DecodingTree::BinaryToDec(QByteArray bin){

    //Definindo o número como 0
    int num = 0;

    //Criando um laço para que possamos calcular o número desejado
    for( int i = 0 ; i < bin.size() ; i++ )
    {
        int expoente = bin.size() - 1;

        expoente -= i;

        if( bin[i] == '1' )
        {
            //Adicionando os correspondentes do binário em decimal
            num += pow(2,expoente);

        }
    }

    //retornando o número desejado
    return num;

}

//Método que transforma números de Decimal para Binário
QByteArray DecodingTree::DecimalToBin(int dec){

    //Definindo o número binário
    QByteArray BinNum;

    //Zerando o Array
    int BinData[8] = {0};

    //Definindo Limite do while
    int lim = 7;

    do
    {
        BinData[lim] = dec % 2;
        lim--;

        if( dec == 2 )
        {

            BinData[lim] = dec/2;

        }

        dec = dec/2;

    }
    while( dec >= 2 );

    if( dec == 1 )
    {

        BinData[lim] = 1;

    }

    for( int i = 0 ; i < 8 ; i++ )
    {
        if( BinData[i] == 0 )
        {

            BinNum += '0';

        }
        if( BinData[i] == 1 )
        {

            BinNum += '1';

        }

    }

    return BinNum;

}
//Método que Armazena o tamanho do lixo, da árvore o do nome
void DecodingTree::Measuring_Tree(QFile *Archive){

    //Onde armazenaremos o binário das três primeiras partes do cabeçalho (T. Lixo, T. Árvore, T. Nome)
    QByteArray DataByte;

    int Counter = 0;
    char carac = 0;

    //Lendo o binário
    while( Counter < 3 )
    {

        Counter++;
        Archive->getChar(&carac);
        DataByte += DecimalToBin((unsigned char)carac);

    }

    //Criando variáveis provisórias
    QByteArray TrashBits;
    QByteArray TreeBits;
    QByteArray NameSize;

    for( int i = 0 ; i < DataByte.size(); i++ )
    {

        if( i < 3 )
        {
            TrashBits += DataByte[i];
        }
        else if( i >= 3 && i < 16 )
        {
            TreeBits += DataByte[i];
        }
        else
        {
            NameSize += DataByte[i];
        }
    }

    TrashSize = BinaryToDec(TrashBits);
    TreeSize = BinaryToDec(TreeBits);
    SizeName = BinaryToDec(NameSize);

}
//Método que localiza apenas o nome do arquivo inicial
QByteArray DecodingTree::GetName(QFile *Archive){

    QByteArray Nome;

    char carac;
    int Counter = 0;

    while( Counter != SizeName )
    {
        Archive->getChar(&carac);
        Counter++;
        Nome += carac;
    }

    return Nome;
}
//Método que remonta a árvore
void DecodingTree::remountingTree(QFile *Archive){

    char carac;
    bool Signal = 0;
    int Counter = 0;

    while(Counter < TreeSize){

        Counter++;

        Archive->getChar(&carac);

        if( carac == '(' )
        {

            if( Signal == 1 )
            {

                Signal = 0;

                if( root->Left == 0 )
                {

                    root->Left = new DecodingNode;
                    root->Left->Byte = carac;
                    root->Left->Type = 1;

                }

                else
                {
                    root->Right = new DecodingNode;
                    root->Right->Parent = new DecodingNode;
                    root->Right->Parent = root;
                    root = root->Right;
                    root->Byte = carac;
                    root->Type = 1;
                    root = root->Parent;
                }

            }

            else if( root == 0 )
            {
                root = new DecodingNode;
                root->Type = 0;
                root->Left = root->Right = 0;
                root->Parent = new DecodingNode;
                root->Parent = root;
            }

            else if( root->Left == 0 )
            {
                root->Left = new DecodingNode;
                root->Left->Parent = new DecodingNode;
                root->Left->Parent = root;
                root = root->Left;
                root->Left = root->Right = 0;
                root->Type = 0;
            }

            else if( root->Right == 0 )
            {
                root->Right = new DecodingNode;
                root->Right->Parent = new DecodingNode;
                root->Right->Parent = root;
                root = root->Right;
                root->Left = root->Right = 0;
                root->Type = 0;
            }
        }

        else if( carac == ')' )
        {
            if( Signal == 1 )
            {
                Signal = 0;

                if( root->Left == 0 )
                {
                    root->Left = new DecodingNode;
                    root->Left->Byte = carac;
                    root->Left->Type = 1;
                }

                else
                {
                    root->Right = new DecodingNode;
                    root->Right->Parent = new DecodingNode;
                    root->Right->Parent = root;
                    root = root->Right;
                    root->Byte = carac;
                    root->Type = 1;
                    root = root->Parent;
                }
            }

            else
            {
                if( root->Parent != 0 )
                {
                    root = root->Parent;
                }
            }
        }

        else
        {

            if( carac == '0' )
            {
                if( Signal == 1 )
                {

                    Signal = 0;

                    if( root->Left == 0 )
                    {
                        root->Left = new DecodingNode;
                        root->Left->Byte = carac;
                        root->Left->Type = 1;
                    }

                    else
                    {
                        root->Right = new DecodingNode;
                        root->Right->Parent = new DecodingNode;
                        root->Right->Parent = root;
                        root = root->Right;
                        root->Byte = carac;
                        root->Type = 1;
                        root = root->Parent;
                    }
                }

                else
                {
                    Signal = 1;
                }
            }

            else if( root->Left == 0 )
            {
                root->Left = new DecodingNode;
                root->Left->Byte = carac;
                root->Left->Type = 1;
            }

            else
            {
                root->Right = new DecodingNode;
                root->Right->Parent = new DecodingNode;
                root->Right->Parent = root;
                root = root->Right;
                root->Byte = carac;
                root->Type = 1;
                root = root->Parent;
            }

        }

    }
}
//Método que remonta o código (binário)
void DecodingTree::remountingCode(QFile * Archive){

    char carac;

    while( !Archive->atEnd() )
    {
        Archive->getChar(&carac);
        cod += DecimalToBin((unsigned char) carac);
    }

    int tamanho = cod.size() - TrashSize;
    cod.resize(tamanho);

}
//Método que pegará o binário gerado no método anterior e gerará o código inicial (pré compactação)
void DecodingTree::rewritingCode(QFile *Data){

    DecodingNode *CurrentNode = new DecodingNode;
    QByteArray FinalData;
    CurrentNode = root;

    cout << root->Right->Byte << endl;

    for( int i = 0 ; i < cod.size() ; i++ )
    {
        if( cod[i] == '0' )
        {
            CurrentNode = CurrentNode->Left;

        }

        else
        {
            CurrentNode = CurrentNode->Right;
        }

        if( CurrentNode->Type == 1 )
        {
            FinalData += ((char )CurrentNode->Byte);
            CurrentNode = root;
        }
    }

    Data->write(FinalData);
}
//Método que agrupa os métodos anteriores
void DecodingTree::decodeFile(QString Nome, QString destiny)
{
    QFile InData(Nome);

    root = 0;

    if( !InData.open(QIODevice::ReadOnly) )
    {
        cout << endl << "-----------------------------------------------------------------"
             << endl << "           Arquivo .huff Corrompido. Erro na leitura!!"
             << endl << "-----------------------------------------------------------------"
             << endl << endl;
    }


    Measuring_Tree(&InData);

    QString FinalName;
    FinalName = GetName(&InData);



    remountingTree(&InData);

    remountingCode(&InData);

    QFile OutData(destiny + FinalName);

    if( !OutData.open(QIODevice::WriteOnly) )
    {
        cout << endl << "-----------------------------------------------------------------"
             << endl << "           Arquivo .huff Corrompido. Erro na escrita!!"
             << endl << "-----------------------------------------------------------------"
             << endl << endl;
    }
    rewritingCode(&OutData);

    cout << endl << "-----------------------------------------------------------------"
         << endl << "             Descompressão Realizada Com Sucesso!"
         << endl << "-----------------------------------------------------------------"
         << endl << endl;

    root = 0;
    InData.close();
    OutData.close();
}
