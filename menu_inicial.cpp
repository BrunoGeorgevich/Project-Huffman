#include "menu_inicial.h"
#include "ui_menu_inicial.h"

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
