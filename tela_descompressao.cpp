#include "tela_descompressao.h"
#include "ui_tela_descompressao.h"
#include "menu_inicial.h"

Tela_Descompressao::Tela_Descompressao(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Tela_Descompressao)
{
    ui->setupUi(this);

    ui->lineEdit_2->setDisabled(1);
    ui->toolButton_2->setDisabled(1);
}

Tela_Descompressao::~Tela_Descompressao()
{
    delete ui;
}

QString Tela_Descompressao::openFile()
{
    QString filename = QFileDialog::getOpenFileName(
                this,
                tr("Open Document"),
                QDir::currentPath(),
                tr("Document files Huffman File (*.huff)"),
                0,
                QFileDialog::DontUseNativeDialog );
    return filename;
}

QString Tela_Descompressao::openDir()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                    QDir::currentPath(),
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);
    return dir;
}

void Tela_Descompressao::on_pushButton_clicked()
{
    Menu_Inicial *tela = new Menu_Inicial;
    tela->show();
    this->close();
}

void Tela_Descompressao::on_checkBox_toggled(bool checked)
{
    if(checked == 1)
    {
        ui->lineEdit_2->setEnabled(1);
        ui->toolButton_2->setEnabled(1);
    }
    else
    {
        ui->lineEdit_2->setDisabled(1);
        ui->toolButton_2->setDisabled(1);
    }
}

void Tela_Descompressao::on_toolButton_clicked()
{
    QString filename = openFile();
    ui->lineEdit->setText(filename);
}

void Tela_Descompressao::on_toolButton_2_clicked()
{
    QString dir = openDir();
    ui->lineEdit_2->setText(dir + "/");
}

void Tela_Descompressao::on_pushButton_2_clicked()
{
    if(ui->checkBox->isChecked() == 1)
    {
        if(ui->lineEdit->text() == "")
        {
            QMessageBox *Msgbox = new QMessageBox;
            Msgbox->setText("Por Favor, selecione um arquivo para descompressão!");
            Msgbox->setWindowTitle("Erro");
            Msgbox->show();
        }
        else
        {
            DecodingTree decode;
            decode.decodeFile(ui->lineEdit->text(), ui->lineEdit_2->text());
            QMessageBox *Msgbox = new QMessageBox;
            Msgbox->setText("Descompressão Finalizada com Sucesso!!");
            Msgbox->setWindowTitle("Descompressão");
            Msgbox->show();
        }
    }
    else
    {
        if(ui->lineEdit->text() == "")
        {
            QMessageBox *Msgbox = new QMessageBox;
            Msgbox->setText("Por Favor, selecione um arquivo para descompressão!");
            Msgbox->setWindowTitle("Erro");
            Msgbox->show();
        }
        else
        {
            DecodingTree decode;
            decode.decodeFile(ui->lineEdit->text(), "");
            QMessageBox *Msgbox = new QMessageBox;
            Msgbox->setText("Descompressão Finalizada com Sucesso!!");
            Msgbox->setWindowTitle("Descompressão");
            Msgbox->show();
        }
    }
}
