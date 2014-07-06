#include "data_file.h"
#include "tree.h"
#include "codification.h"
#include <iostream>

using namespace std;

int main()
{
//    Data_File file("../../Project-Huffman/Arquivos/black.png","../../Project-Huffman/Test/");//Testando com Imagem
//    Data_File file("../../Project-Huffman/Arquivos/final.wav","../../Project-Huffman/Test/");//Testando com Musica Pequena
//    Data_File file("../../Project-Huffman/Arquivos/Nothing Else Matters.mp3","../../Project-Huffman/Test/");//Testando com Musica Grande
    Data_File file("../../Project-Huffman/Arquivos/in.txt","../../Project-Huffman/Test/");//Testando com Texto

    QList<Node*> list = file.toList();

//    for(int i = 0 ; i < list.size(); i++)
//    {
//        if(list.at(i)->getByte() == 10)
//        {
//            cout << "ETR.." << list.at(i)->getFrequency() <<  " ";
//            goto here;
//        }

//        cout << list.at(i)->getByte() << ".." << list.at(i)->getFrequency() << " ";
//        here:;
//    }
//    cout << endl;

    Tree test(list);

    test.fill();
    test.print(test.root);

    cout << endl;
    cout << endl;
    test.MinimizedForm(test.root);
    cout << qPrintable(test.BinTree) << endl;
    cout << endl;
    cout << endl;

    test.WritingCodification();
    QString binary = test.Data_Codification("../../Project-Huffman/Arquivos/in.txt","../../Project-Huffman/Test/");

    char * bin = new char[binary.size()];
    bin = binary.toLatin1().data();

    cout << "Tamanho da string : " << strlen(bin) << endl;

    char *archive = "../../Project-Huffman/Test/in.txt";//Unindo o nome do arquivo + a extensão do mesmo + o caminho para salva-lo

    ofstream out(archive);//salvando o arquivo

    cout << binary.size() << endl;

    for( int i = 0 ; i <= strlen(bin) ; i++ ){//passando os bytes em formato char para o arquivo

        cout << i << endl;
        out << ((bin[i]));

    }

    unsigned short a = test.SizeTrashTree();

    cout << a << endl;

    return 0;
}
