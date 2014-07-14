#include "encodingTree.h"
#include "decodingtree.h"
#include <iostream>

#include <QApplication>
#include "menu_inicial.h"

using namespace std;

void Ajuda(){

    cout << endl << endl;
    cout << "{..........................}Huffman HELP{.............................}" << endl << endl;
    cout << "{...........................Compressão................................}" << endl<< endl ;
    cout << "[-c] 'file' -> para comprimir o arquivo." << endl << endl ;
    cout << "[-c] 'file' [-o] 'Nome_de_Saida.huff'' - >  comprimir alterando o nome." << endl << endl;
    cout << "{..........................Descompressão..............................}" << endl << endl;
    cout << "file.huff -> descomprimir o arquivo." << endl << endl ;
    cout << "file.huff [-d] 'caminho_saida' -> Descomprimir em uma pasta diferente" << endl << endl ;
    cout << "{.....................................................................}" << endl << endl;
    cout << "{.......................Interface..Gráfica............................}" << endl << endl;
    cout << "[--gui] -> Executará o programa com uma Interface Gráfica" << endl << endl ;
    cout << "{.....................................................................}" << endl << endl;
    cout << endl << endl;
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



    if( argc <= 6 || argc >= 2 )
    {
        if( a=="-h" )
        {
            Ajuda();
        }

        else if( a == "-c" )
        {

            EncodingTree a(b);


            if( c == "-o" )
            {
                if(d.contains(".huff"))
                {

                    EncodingTree a(b, d);

                    cout << endl << "-----------------------------------------------------------------"
                         << endl << "             Compressão realizada com Sucesso!!"
                         << endl << "-----------------------------------------------------------------"
                         << endl << endl;

                }

                else
                {
                    cout << endl << "-----------------------------------------------------------------"
                         << endl << "                     Compressão Falhou!!!!"
                         << endl << "-----------------------------------------------------------------"
                         << endl << "Necessário que o Novo Nome do arquivo acompanhe o .huff no final."
                         << endl << "-----------------------------------------------------------------"
                         << endl << endl;
                }
            }

            else
            {

                EncodingTree a(b);

                cout << endl << "-----------------------------------------------------------------"
                     << endl << "               Compressão realizada com Sucesso!!"
                     << endl << "-----------------------------------------------------------------"
                     << endl << endl;
            }

        }

        else if(a.contains(".huff"))
        {

            DecodingTree *Decode = new DecodingTree;

            if( b == "-d" )
            {
                Decode->decodeFile(a,c);
            }

            else
            {
                Decode->decodeFile(a,"");
            }
        }

        else if(a == "--gui")
        {
            QApplication a(argc,argv);
            a.setStyleSheet("QWidget {background-color : white}");
            a.setStyleSheet("QMainWindow {border-image : url(:/Resource/Resource/background.jpg);}");
            Menu_Inicial w;
            w.show();

            return a.exec();
        }

        else
        {
            cout << endl << "-----------------------------------------------------------------"
                 << endl << " Comando Inexistente. Digite -h para que apareção as instruções."
                 << endl << "-----------------------------------------------------------------"
                 << endl << endl;
        }
}

     else
     {
        cout << endl << "-----------------------------------------------------------------"
             << endl << " Comando Inexistente. Digite -h para que apareção as instruções."
             << endl << "-----------------------------------------------------------------"
             << endl << endl;
     }

        return 0;

}
