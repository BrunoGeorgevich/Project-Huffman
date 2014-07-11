#ifndef MENU_INICIAL_H
#define MENU_INICIAL_H

#include <QMainWindow>

namespace Ui {
class Menu_Inicial;
}

class Menu_Inicial : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menu_Inicial(QWidget *parent = 0);
    ~Menu_Inicial();

private:
    Ui::Menu_Inicial *ui;
};

#endif // MENU_INICIAL_H
