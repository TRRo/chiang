#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <iostream>

using namespace std;
bool flag=0;
int used=0;
QPushButton *tempbutton;
int ii,jj;

Candy candytemp;

void set_icon(QPushButton *Q, int n)
{
    switch(n){
    case 1:
        Q->setIcon(QIcon("C:/Users/Talia/Desktop/img/Codat/blue.png"));
        break;
    case 2:
        Q->setIcon(QIcon("C:/Users/Talia/Desktop/img/Codat/yellow.png"));
        break;
    case 3:
        Q->setIcon(QIcon("C:/Users/Talia/Desktop/img/Codat/red.png"));
        break;
    case 4:
        Q->setIcon(QIcon("C:/Users/Talia/Desktop/img/Codat/orange.png"));
        break;
    case 5:
        Q->setIcon(QIcon("C:/Users/Talia/Desktop/img/Codat/green.png"));
        break;
    case 6:
        Q->setIcon(QIcon("C:/Users/Talia/Desktop/img/Codat/purple.png"));
        break;
    }
}

QString change(int n){
    QString tt= QString::number(n);
    return tt;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Table table;
    table.create_barrier(4,4,0,0,0);
    QString s = QString::number((table.candy[0][0]).color);
    ui->A_label->setText(s);
    s = QString::number((table.candy[0][1]).color);
    ui->B_label->setText(s);
    s = QString::number((table.candy[0][2]).color);
    ui->C_label->setText(s);
    s = QString::number((table.candy[0][3]).color);
    ui->D_label->setText(s);
    s = QString::number((table.candy[1][0]).color);
    ui->E_label->setText(s);
    s = QString::number((table.candy[1][1]).color);
    ui->F_label->setText(s);
    s = QString::number((table.candy[1][2]).color);
    ui->G_label->setText(s);
    s = QString::number((table.candy[1][2]).color);
    ui->H_label->setText(s);
    s = QString::number((table.candy[2][0]).color);
    ui->I_label->setText(s);
    s = QString::number((table.candy[2][1]).color);
    ui->J_label->setText(s);
    s = QString::number((table.candy[2][2]).color);
    ui->K_label->setText(s);
    s = QString::number((table.candy[2][3]).color);
    ui->L_label->setText(s);
    s = QString::number((table.candy[3][0]).color);
    ui->M_label->setText(s);
    s = QString::number((table.candy[3][1]).color);
    ui->N_label->setText(s);
    s = QString::number((table.candy[3][2]).color);
    ui->O_label->setText(s);
    s = QString::number((table.candy[3][2]).color);
    ui->P_label->setText(s);








    set_icon(ui->P_pushButton,table.candy[3][3].color);
    //QString temp=QString::number(table.candy[3][3].color);
    QString temp=change(table.candy[3][3].color);
    ui->P_pushButton->setText(temp);

    set_icon(ui->A_pushButton,table.candy[0][0].color);
    set_icon(ui->B_pushButton,table.candy[1][0].color);
    set_icon(ui->C_pushButton,table.candy[2][0].color);
    set_icon(ui->D_pushButton,table.candy[3][0].color);
    set_icon(ui->E_pushButton,table.candy[0][1].color);
    set_icon(ui->F_pushButton,table.candy[0][2].color);
    set_icon(ui->G_pushButton,table.candy[0][3].color);
    set_icon(ui->O_pushButton,table.candy[2][3].color);
    set_icon(ui->N_pushButton,table.candy[1][3].color);


    ui->K_pushButton->setIcon(QIcon("C:/Users/Talia/Desktop/codat_re/123.jpg"));
    ui->K_pushButton->setIconSize(QSize(100,100));
    ui->N_pushButton->setIconSize(QSize(100,100));
    //ui->O_pushButton->setIconSize(QSize(100,100));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::print()
{
    //QPushButton *A_pushButton = new QPushButton(this);

    if(table.candy[0][0].color==1)
        ui->A_pushButton->setIcon(QIcon("C:/Users/Talia/Desktop/codat_re/123.jpg"));
    else{
        ui->A_pushButton->setIcon(QIcon("C:/Users/Talia/Desktop/codat_re/Logo.png"));
    }
    //ui->A_pushButton->setGeometry(30,30,80,30);
    //ui->lebel->setText(tr("change"));

}

void MainWindow::on_E_label_click()
{
    //ui->label_4->setText(tr("hhhhhh"));
}

void MainWindow::on_O_pushButton_clicked()
{
    cout << used << '\n';
    if(flag){

    //cout << "---" << used << '\n';
        if(used%2==0){
            tempbutton=ui->O_pushButton;
            ii=2;
            jj=3;
        }
        else{
            candytemp=table.candy[ii][jj];
            table.candy[ii][jj]=table.candy[2][3];
            table.candy[2][3]=candytemp;
            set_icon(ui->O_pushButton,table.candy[ii][jj].color);
            set_icon(ui->N_pushButton,table.candy[2][3].color);
            ii=0;
            jj=0;
        }
        used++;
    }
}



void MainWindow::on_N_pushButton_clicked()
{
    cout << used << '\n';
    if(flag){
        //cout << "++++" << used << '\n';
        if(used%2==0){
            tempbutton=ui->N_pushButton;
            ii=1;
            jj=3;
        }
        else{
            candytemp=table.candy[ii][jj];
            table.candy[ii][jj]=table.candy[1][3];
            table.candy[1][3]=candytemp;
            set_icon(ui->O_pushButton,table.candy[ii][jj].color);
            set_icon(ui->N_pushButton,table.candy[1][3].color);
            ii=0;
            jj=0;
        }
        used++;
    }
}

void MainWindow::on_pushButton_clicked()
{
    flag=1;
}
