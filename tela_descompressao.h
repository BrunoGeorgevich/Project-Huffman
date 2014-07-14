#ifndef TELA_DESCOMPRESSAO_H
#define TELA_DESCOMPRESSAO_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>

#include "decodingtree.h"

namespace Ui {
class Tela_Descompressao;
}

class Tela_Descompressao : public QMainWindow
{
    Q_OBJECT

public:

    explicit Tela_Descompressao(QWidget *parent = 0);
    ~Tela_Descompressao();
    QString openFile();
    QString openDir();

private slots:
    void on_pushButton_clicked();

    void on_checkBox_toggled(bool checked);

    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

    void on_pushButton_2_clicked();

private:

    Ui::Tela_Descompressao *ui;
};

#endif // TELA_DESCOMPRESSAO_H
