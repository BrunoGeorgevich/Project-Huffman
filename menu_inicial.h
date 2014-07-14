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

private slots:
    void on_pushButton_clicked();

    void on_actionComprimir_triggered();

    void on_actionDescomprimir_triggered();

    void on_actionSair_triggered();

    void on_pushButton_2_clicked();

    void on_actionDevelopment_triggered();

private:
    Ui::Menu_Inicial *ui;
};

#endif // MENU_INICIAL_H
