#ifndef TELA_COMPRESSAO_H
#define TELA_COMPRESSAO_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>

#include "encodingTree.h"


namespace Ui {
class Tela_Compressao;
}

class Tela_Compressao : public QMainWindow
{
    Q_OBJECT

public:
    explicit Tela_Compressao(QWidget *parent = 0);
    ~Tela_Compressao();    
    QString openFile();

private slots:

    void on_pushButton_clicked();

    void on_toolButton_clicked();

    void on_checkBox_toggled(bool checked);

    void on_pushButton_2_clicked();

private:

    Ui::Tela_Compressao *ui;

};

#endif // TELA_COMPRESSAO_H
