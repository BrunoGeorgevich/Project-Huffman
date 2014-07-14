#include "menu_inicial.h"
#include "tela_compressao.h"
#include "tela_descompressao.h"
#include "ui_menu_inicial.h"
#include "warning.h"


Menu_Inicial::Menu_Inicial(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Menu_Inicial)
{
    ui->setupUi(this);
}

Menu_Inicial::~Menu_Inicial()
{
    delete ui;
}

void Menu_Inicial::on_pushButton_clicked()
{
    Tela_Compressao *tela = new Tela_Compressao;
    tela->show();
    this->close();
}

void Menu_Inicial::on_actionComprimir_triggered()
{
    Tela_Compressao *tela = new Tela_Compressao;
    tela->show();
    this->close();
}

void Menu_Inicial::on_actionDescomprimir_triggered()
{
    Tela_Descompressao *tela = new Tela_Descompressao;
    tela->show();
    this->close();
}

void Menu_Inicial::on_actionSair_triggered()
{
    Warning *tela = new Warning(this);
    tela->show();
}

void Menu_Inicial::on_pushButton_2_clicked()
{
    Tela_Descompressao *tela = new Tela_Descompressao;
    tela->show();
    this->close();
}

void Menu_Inicial::on_actionDevelopment_triggered()
{
    QMessageBox *Msgbox = new QMessageBox;
    Msgbox->setText("Desenvolvido por Bruno Georgevich Ferreira");
    Msgbox->setWindowTitle("Desenvolvimento");
    Msgbox->show();
}
