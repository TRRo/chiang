#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "table.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void print();

private slots:
    void on_E_label_click();

    void on_O_pushButton_clicked();

    void on_N_pushButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Table table;
};

#endif // MAINWINDOW_H
