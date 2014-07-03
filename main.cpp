#include "data_file.h"
#include "tree.h"
#include <iostream>

using namespace std;
int main()
{
//    Data_File file("../../Project/Project/Arquivos/black.png","../../Project/Project/Test/");//Testando com Imagem
//    Data_File file("../../Project/Project/Arquivos/final.wav","../../Project/Project/Test/");//Testando com Musica Pequena
//    Data_File file("../../Project/Project/Arquivos/Nothing Else Matters.mp3","../../Project/Project/Test/");//Testando com Musica Grande
//    Data_File file("../../Project/Project/Arquivos/in.txt","../../Project/Project/Test/");//Testando com Texto

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

    Tree test;

    test.fill(list);
//    test.print(test.root);

    test.MinimizedForm(test.root);
    cout << endl;
    return 0;
}
