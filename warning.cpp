#include "warning.h"
#include "ui_warning.h"

Warning::Warning(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Warning)
{
    ui->setupUi(this);
    ParentScreen = parent;
}

Warning::~Warning()
{
    delete ui;
}

void Warning::on_pushButton_2_clicked()
{
    this->close();
    ParentScreen->close();
}

void Warning::on_pushButton_clicked()
{
    this->close();
}
