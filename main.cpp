#include "data_file.h"
#include "tree.h"
#include "codification.h"
#include <iostream>

using namespace std;

void Ajuda(){
    cout << "{...........}Huffman HELP{................}" << endl ;
    cout << "{.........................................}" << endl ;
    cout << " -c 'file'  para comprimir o arquivo." << endl ;
    cout << " -c 'file' -o 'Nome_de_Saida.huff''  comprimir alterando o nome." << endl ;
    cout << "{.........................................}" << endl ;
    cout << " file.huff descomprimir o arquivo." << endl ;
    cout << " file.huff -d 'caminho_de_saida' // Descomprimi o arquivo em um caminho diferente" << endl ;
    cout << "{.........................................}" << endl ;
}
QString GetName(QString name)
{
    int size = name.size();

    QString nome = "";
    for(int i = size; i > 0; i--)//identificando a extensão do arquivo
    {
        if(name[i - 1] == '/')
        {
            int k = i;
            for(int j = 0; j < size - k; j++, i++){

                nome[j] = name[i];//armazenando extensão na QString type

            }
            break;
        }
    }

    return nome;

}

int main(int argc, char *argv[])
{
    QString a;
    a = argv[1];
    QString b;
    b = argv[2];
    QString c;
    c = argv[3];
    QString d;
    d = argv[4];



    if(argc <= 6){
        if(a=="-h"){
            Ajuda();
        }

        else if(a == "-c"){
            Data_File file(b);//Testando com Imagem


            QList<Node*> list = file.toList();

            Tree test(list);
            test.fill();
            test.MinimizedForm(test.root);

            test.WritingCodification();
            test.Data_Codification(b,"",GetName(b));

            if(c == "-o"){
                if(d.contains(".huff"))
                {
                    Data_File file(b);

                    QList<Node*> list = file.toList();

                    Tree test(list);
                    test.fill();
                    test.MinimizedForm(test.root);

                    test.WritingCodification();
                    test.Data_Codification(b,"",d);

                } else {
                    cout << "Comando Inexistente. Digite -h para que apareção as instruções." << endl;
                }
            } else {

                Data_File file(b);//Testando com Imagem


                QList<Node*> list = file.toList();

                Tree test(list);
                test.fill();
                test.MinimizedForm(test.root);

                test.WritingCodification();
                test.Data_Codification(b,"","out.huff");
            }

        }
        else if(a.contains(".huff"))
        {

            Tree test;
            test.Data_Decodification(a,"");


            if(b=="-d")
            {
                Tree test;
                test.Data_Decodification(a,c);
            }
            else
            {
                Tree test;
                test.Data_Decodification(a,"");
            }
        } else {
            cout << "Comando Inexistente. Digite -h para que apareção as instruções." << endl;
        }
    }

    else {
        cout << "Comando Inexistente. Digite -h para que apareção as instruções." << endl;
    }

    return 0;
}
