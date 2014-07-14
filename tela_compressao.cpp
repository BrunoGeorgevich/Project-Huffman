#include "tela_compressao.h"
#include "ui_tela_compressao.h"
#include "menu_inicial.h"

Tela_Compressao::Tela_Compressao(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Tela_Compressao)
{
    ui->setupUi(this);

    ui->lineEdit_2->setDisabled(1);
}

Tela_Compressao::~Tela_Compressao()
{
    delete ui;
}

QString Tela_Compressao::openFile()
{
    QString filename = QFileDialog::getOpenFileName(
                this,
                tr("Open Document"),
                QDir::currentPath(),
                tr("Document files All files (*.*)"),
                0,
                QFileDialog::DontUseNativeDialog );
    return filename;
}

void Tela_Compressao::on_pushButton_clicked()
{
    Menu_Inicial *tela = new Menu_Inicial;
    tela->show();
    this->close();
}

void Tela_Compressao::on_toolButton_clicked()
{
    QString filename = openFile();
    ui->lineEdit->setText(filename);
}


void Tela_Compressao::on_checkBox_toggled(bool checked)
{
    if(checked == 1)
    {
        ui->lineEdit_2->setEnabled(1);
    }
    else
    {
        ui->lineEdit_2->setDisabled(1);
    }
}


void Tela_Compressao::on_pushButton_2_clicked()
{
    if(ui->checkBox->isChecked() == 1)
    {
        if(ui->lineEdit->text() == "")
        {
            QMessageBox *Msgbox = new QMessageBox;
            Msgbox->setText("Por Favor, selecione um arquivo para compressão!");
            Msgbox->setWindowTitle("Erro");
            Msgbox->show();
        }
        else
        {
            if(ui->lineEdit_2->text().contains(".huff") == 1)
            {
                EncodingTree(ui->lineEdit->text(), ui->lineEdit_2->text());
                QMessageBox *Msgbox = new QMessageBox;
                Msgbox->setText("Compressão Finalizada com Sucesso!!");
                Msgbox->setWindowTitle("Compressão");
                Msgbox->show();
            }
            else
            {
                QMessageBox *Msgbox = new QMessageBox;
                Msgbox->setText("Por Favor, Coloque o .huff no final do nome desejado!");
                Msgbox->setWindowTitle("Erro");
                Msgbox->show();
            }
        }
    }
    else
    {
        if(ui->lineEdit->text() == "")
        {
            QMessageBox *Msgbox = new QMessageBox;
            Msgbox->setText("Por Favor, selecione um arquivo para compressão!");
            Msgbox->setWindowTitle("Erro");
            Msgbox->show();
        }
        else
        {
            EncodingTree(ui->lineEdit->text());
            QMessageBox *Msgbox = new QMessageBox;
            Msgbox->setText("Compressão Finalizada com Sucesso!!");
            Msgbox->setWindowTitle("Compressão");
            Msgbox->show();
        }

    }


}
