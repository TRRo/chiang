#include "table.h"
#include "ui_table.h"

#include <QTime>
#include <QPushButton>
#include <QLabel>
#include <iostream>
#include <stdlib.h>
#include <QIcon>

using namespace std;


void set_icon(int co, int ty, QPushButton *p)
{
    if(ty==1)
    {
        switch (co)
        {
            case 1:
                p->setIcon(QIcon("D:/060819/0611/0611/img/red.png"));
                break;
            case 2:
                p->setIcon(QIcon("D:/060819/0611/0611/img/orange.png"));
                break;
            case 3:
                p->setIcon(QIcon("D:/060819/0611/0611/img/yellow.png"));
                break;
            case 4:
                p->setIcon(QIcon("D:/060819/0611/0611/img/green.png"));
                break;
            case 5:
                p->setIcon(QIcon("D:/060819/0611/0611/img/blue.png"));
                break;
            case 6:
                p->setIcon(QIcon("D:/060819/0611/0611/img/purple.png"));
                break;
        }
    }
    else if(ty==4)
    {
        switch (co)
        {
            case 1:
                //p->setIcon(QIcon("D:/060819/0611/0611/img/red.png"));
                break;
            case 2:
                //p->setIcon(QIcon("D:/060819/0611/0611/img/orange.png"));
                break;
            case 3:
                //p->setIcon(QIcon("D:/060819/0611/0611/img/yellow.png"));
                break;
            case 4:
                //p->setIcon(QIcon("D:/060819/0611/0611/img/green.png"));
                break;
            case 5:
                //p->setIcon(QIcon("D:/060819/0611/0611/img/blue.png"));
                break;
            case 6:
                //p->setIcon(QIcon("D:/060819/0611/0611/img/purple.png"));
                break;
        }
    }
    else if(ty==5)
    {

    }
    else if(ty==6)
    {
        switch (co)
        {
            case 1:
                //p->setIcon(QIcon("D:/060819/0611/0611/img/red.png"));
                break;
            case 2:
                //p->setIcon(QIcon("D:/060819/0611/0611/img/orange.png"));
                break;
            case 3:
                //p->setIcon(QIcon("D:/060819/0611/0611/img/yellow.png"));
                break;
            case 4:
                //p->setIcon(QIcon("D:/060819/0611/0611/img/green.png"));
                break;
            case 5:
                //p->setIcon(QIcon("D:/060819/0611/0611/img/blue.png"));
                break;
            case 6:
                //p->setIcon(QIcon("D:/060819/0611/0611/img/purple.png"));
                break;
        }
    }
}


Table::Table(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Table)
{
    ui->setupUi(this);

    length = 0;
    width = 0;
    choco_num = 0;
    chain_num = 0;
    peel_num = 0;

    cc=0;
    a=b=c=d=-1;
    qsrand(time(NULL));
}

Table::~Table()
{
    delete ui;
}

Candy::Candy()
{
    //qsrand(time(NULL));  //include<time.h>
    color = qrand()%6 + 1;  //include<stdlib.h>

    candy_type = 1;  //0==barrier, 1==ori, 2==four, 3==L, 4==five(not color);
    barrier_type = 0;
    //cout << color << endl;
    //int n = qrand();
}

void Table::move_candy()
{
    for(int w=0; w<width; w++)
    {
        for(int le=length-1; le>=0; le--)
        {
            if(candy[le][w].color==0)
            {
                if(le==0)
                {
                    candy[le][w].color=qrand()%6+1;
                    candy[le][w].candy_type = 1;
                    continue;
                }
                for(int k=le-1; k>=0; k--)
                {
                    if(candy[k][w].color!=0)  //先不考慮障礙物
                    {
                        candy[le][w].color=candy[k][w].color;
                        candy[le][w].candy_type=candy[k][w].candy_type;
                        candy[k][w].color=0;
                        candy[k][w].candy_type=1;
                        break;
                    }
                    if(k==0)
                    {
                        candy[le][w].color=qrand()%6 +1;
                        candy[le][w].candy_type = 1;
                    }
                }
            }
        }
    }
    cout << "move" << '\n';
    for(int i=0; i<length; i++){
        for(int j=0; j<width; j++){
            cout << candy[i][j].color << ' ';
        }
        cout << '\n';
    }
}

void Table::create_barrier(int len, int wid, int choco, int chain, int peel)  //先不考慮障礙物
{
    candy = new Candy *[len];
    for(int i=0; i<len; i++)
    {
        candy[i] = new Candy [wid];

    }

    length=len;
    width=wid;

    choco_num = choco;
    chain_num = chain;
    peel_num = peel;


    cout << "create" << '\n';
    for(int i=0; i<length; i++){
        for(int j=0; j<width; j++){
            cout << candy[i][j].color << ' ';
        }
        cout << '\n';
    }
}

void Table::recreate_table()  //先不考慮障礙物
{
    for(int le=0; le<length; le++)
    {
        for(int w=0; w<width; w++)
        {
            candy[le][w].color = qrand()%6 +1;
            candy[le][w].candy_type = 1;
        }
    }

    cout << "recreate" << '\n';
    for(int i=0; i<length; i++){
        for(int j=0; j<width; j++){
            cout << candy[i][j].color << ' ';
        }
        cout << '\n';
    }
}

bool Table::eliminate_candy()  //先不考慮障礙物  //return flag;
{
    bool flag=false;  //if we can eliminate any candy, flag=true;
    //判斷五顆
    for(int le=0; le<length; le++)  //判斷左右
    {
        for(int w=0; w<width-4; w++)
        {
            if(candy[le][w].color==candy[le][w+1].color && candy[le][w].color==candy[le][w+2].color && candy[le][w].color==candy[le][w+3].color && candy[le][w].color==candy[le][w+4].color)
            {
                flag=true;
                candy[le][w].color=0;
                candy[le][w+1].color=0;
                candy[le][w+2].color=0;
                candy[le][w+3].color=0;
                candy[le][w+4].color=0;
            }
        }
    }
    for(int w=0; w<width; w++)  //判斷上下
    {
        for(int le=0; le<length-4; le++)
        {
            if(candy[le][w].color==candy[le+1][w].color && candy[le][w].color==candy[le+2][w].color && candy[le][w].color==candy[le+3][w].color && candy[le][w].color==candy[le+4][w].color)
            {
                flag=true;
                candy[le][w].color=0;
                candy[le+1][w].color=0;
                candy[le+2][w].color=0;
                candy[le+3][w].color=0;
                candy[le+4][w].color=0;
            }
        }
    }

    //判斷L型
    for(int le=0; le<length-2; le++)  //左右---往下
    {
        for(int w=0; w<width-2; w++)
        {
            if(candy[le][w].color==candy[le][w+1].color && candy[le][w].color==candy[le][w+2].color && candy[le][w].color==candy[le+1][w+2].color && candy[le][w].color==candy[le+2][w+2].color)
            {
                flag=true;
                candy[le][w].color=0;
                candy[le][w+1].color=0;
                candy[le][w+2].color=0;
                candy[le+1][w+2].color=0;
                candy[le+2][w+2].color=0;

            }
            if(candy[le][w].color==candy[le][w+1].color && candy[le][w].color==candy[le+1][w+1].color && candy[le][w].color==candy[le+2][w+1].color && candy[le][w].color==candy[le][w+2].color)
            {
                flag=true;
                candy[le][w].color=0;
                candy[le][w+1].color=0;
                candy[le+1][w+1].color=0;
                candy[le+2][w+1].color=0;
                candy[le][w+2].color=0;
            }
            if(candy[le][w].color==candy[le+1][w].color && candy[le][w].color==candy[le+2][w].color && candy[le][w].color==candy[le][w+1].color && candy[le][w].color==candy[le][w+2].color)
            {
                flag=true;
                candy[le][w].color=0;
                candy[le+1][w].color=0;
                candy[le+2][w].color=0;
                candy[le][w+1].color=0;
                candy[le][w+2].color=0;
            }
        }
    }
    for(int le=2; le<length; le++)  //左右---往上
    {
        for(int w=0; w<width-2; w++)
        {
            if(candy[le][w].color==candy[le][w+1].color && candy[le][w].color==candy[le][w+2].color && candy[le][w].color==candy[le-1][w+2].color && candy[le][w].color==candy[le-2][w+2].color)
            {
                flag=true;
                candy[le][w].color=0;
                candy[le][w+1].color=0;
                candy[le][w+2].color=0;
                candy[le-1][w+2].color=0;
                candy[le-2][w+2].color=0;
            }
            if(candy[le][w].color==candy[le][w+1].color && candy[le][w].color==candy[le-1][w+1].color && candy[le][w].color==candy[le-2][w+1].color && candy[le][w].color==candy[le][w+2].color)
            {
                flag=true;
                candy[le][w].color=0;
                candy[le][w+1].color=0;
                candy[le-1][w+1].color=0;
                candy[le-2][w+1].color=0;
                candy[le][w+2].color=0;
            }
            if(candy[le][w].color==candy[le-1][w].color && candy[le][w].color==candy[le-2][w].color && candy[le][w].color==candy[le][w+1].color && candy[le][w].color==candy[le][w+2].color)
            {
                flag=true;
                candy[le][w].color=0;
                candy[le-1][w].color=0;
                candy[le-2][w].color=0;
                candy[le][w+1].color=0;
                candy[le][w+2].color=0;
            }
        }
    }
    for(int w=0; w<width-2; w++)  //上下---往右
    {
        for(int le=1; le<length-1; le++)
        {
            if(candy[le-1][w].color==candy[le][w].color && candy[le-1][w].color==candy[le][w+1].color && candy[le-1][w].color==candy[le][w+2].color && candy[le-1][w].color==candy[le+1][w].color)
            {
                flag=true;
                candy[le-1][w].color=0;
                candy[le][w].color=0;
                candy[le][w+1].color=0;
                candy[le][w+2].color=0;
                candy[le+1][w].color=0;
            }
        }
    }
    for(int w=2; w<width; w++)  //上下---往左
    {
        for(int le=1; le<length-1; le++)
        {
            if(candy[le-1][w].color==candy[le][w].color && candy[le-1][w].color==candy[le][w-1].color && candy[le-1][w].color==candy[le][w-2].color && candy[le-1][w].color==candy[le+1][w].color)
            {
                flag=true;
                candy[le-1][w].color=0;
                candy[le][w].color=0;
                candy[le][w-1].color=0;
                candy[le][w-2].color=0;
                candy[le+1][w].color=0;
            }
        }
    }

    //判斷四顆
    for(int le=0; le<length; le++)  //判斷左右
    {
        for(int w=0; w<width-3; w++)
        {
            if(candy[le][w].color==candy[le][w+1].color && candy[le][w].color==candy[le][w+2].color && candy[le][w].color==candy[le][w+3].color)
            {
                flag=true;
                candy[le][w].color=0;
                candy[le][w+1].color=0;
                candy[le][w+2].color=0;
                candy[le][w+3].color=0;
            }
        }
    }
    for(int w=0; w<width; w++)  //判斷上下
    {
        for(int le=0; le<length-3; le++)
        {
            if(candy[le][w].color==candy[le+1][w].color && candy[le][w].color==candy[le+2][w].color && candy[le][w].color==candy[le+3][w].color)
            {
                flag=true;
                candy[le][w].color=0;
                candy[le+1][w].color=0;
                candy[le+2][w].color=0;
                candy[le+3][w].color=0;
            }
        }
    }
    //判斷三顆
    for(int le=0; le<length; le++)  //判斷左右
    {
        for(int w=0; w<width-2; w++)
        {
            if(candy[le][w].color==candy[le][w+1].color && candy[le][w].color==candy[le][w+2].color)
            {
                flag=true;
                candy[le][w].color=0;
                candy[le][w+1].color=0;
                candy[le][w+2].color=0;
            }
        }
    }
    for(int w=0; w<width; w++)  //判斷上下
    {
        for(int le=0; le<length-2; le++)
        {
            if(candy[le][w].color==candy[le+1][w].color && candy[le][w].color==candy[le+2][w].color)
            {
                flag=true;
                candy[le][w].color=0;
                candy[le+1][w].color=0;
                candy[le+2][w].color=0;
            }
        }
    }

    cout << "eliminate" << '\n';
    for(int i=0; i<length; i++){
        for(int j=0; j<width; j++){
            cout << candy[i][j].color << ' ';
        }
        cout << '\n';
    }

    return flag;
}
//eliminate candy; create high_level candy or use high_level candy function; decrease the number of barrier;

bool Table::check_candy()  //先不考慮障礙物
{
    for(int le=0; le<length; le++)    //是否包含五顆連線升級
    {
        for(int w=0; w<width; w++)
        {
            if(candy[le][w].candy_type==5)
            {
                return 1;
            }
        }
    }

    for(int le=0; le<length; le++)  //考慮左右--左右移
    {
        for(int w=0; w<width-3; w++)
        {
            if(candy[le][w].color==candy[le][w+1].color && candy[le][w].color==candy[le][w+3].color)
            {
                return 1;
            }
            if(candy[le][w].color==candy[le][w+2].color && candy[le][w].color==candy[le][w+3].color)
            {
                return 1;
            }
        }
    }
    for(int w=0; w<width; w++)  //考慮上下--上下移
    {
        for(int le=0; le<le-3; le++)
        {
            if(candy[le][w].color==candy[le+1][w].color && candy[le][w].color==candy[le+3][w].color)
            {
                return 1;
            }
            if(candy[le][w].color==candy[le+2][w].color && candy[le][w].color==candy[le+3][w].color)
            {
                return 1;
            }
        }
    }
    for(int le=1; le<length; le++)  //考慮左右--上移
    {
        for(int w=0; w<width-2; w++)
        {
            if(candy[le][w].color==candy[le][w+1].color && candy[le][w].color==candy[le-1][w+2].color)
            {
                return 1;
            }
            if(candy[le][w].color==candy[le-1][w+1].color && candy[le][w].color==candy[le][w+2].color)
            {
                return 1;
            }
            if(candy[le-1][w].color==candy[le][w+1].color && candy[le-1][w].color==candy[le][w+2].color)
            {
                return 1;
            }
        }
    }
    for(int le=0; le<length-1; le++)  //考慮左右--下移
    {
        for(int w=0; w<width-2; w++)
        {
            if(candy[le][w].color==candy[le][w+1].color && candy[le][w].color==candy[le+1][w+2].color)
            {
                return 1;
            }
            if(candy[le][w].color==candy[le+1][w+1].color && candy[le][w].color==candy[le][w+2].color)
            {
                return 1;
            }
            if(candy[le+1][w].color==candy[le][w+1].color && candy[le+1][w].color==candy[le][w+2].color)
            {
                return 1;
            }
        }
    }
    for(int w=1; w<width; w++)  //考慮上下--左移
    {
        for(int le=0; le<length-2; le++)
        {
            if(candy[le][w].color==candy[le+1][w].color && candy[le][w].color==candy[le+2][w-1].color)
            {
                return 1;
            }
            if(candy[le][w].color==candy[le+1][w-1].color && candy[le][w].color==candy[le+2][w].color)
            {
                return 1;
            }
            if(candy[le][w-1].color==candy[le+1][w].color && candy[le][w-1].color==candy[le+2][w].color)
            {
                return 1;
            }
        }
    }
    for(int w=0; w<width-1; w++)  //考慮上下--右移
    {
        for(int le=0; le<length-2; le++)
        {
            if(candy[le][w].color==candy[le+1][w].color && candy[le][w].color==candy[le+2][w+1].color)
            {
                return 1;
            }
            if(candy[le][w].color==candy[le+1][w+1].color && candy[le][w].color==candy[le+2][w].color)
            {
                return 1;
            }
            if(candy[le][w+1].color==candy[le+1][w].color && candy[le][w+1].color==candy[le+2][w].color)
            {
                return 1;
            }
        }
    }
    return 0;
}

void Table::print()
{
    set_icon(candy[0][0].color, candy[0][0].candy_type, ui->A00_pushButton);
    set_icon(candy[0][1].color, candy[0][1].candy_type, ui->A01_pushButton);
    set_icon(candy[0][2].color, candy[0][2].candy_type, ui->A02_pushButton);
    set_icon(candy[0][3].color, candy[0][3].candy_type, ui->A03_pushButton);
    set_icon(candy[0][4].color, candy[0][4].candy_type, ui->A04_pushButton);
    set_icon(candy[0][5].color, candy[0][5].candy_type, ui->A05_pushButton);

    set_icon(candy[1][0].color, candy[1][0].candy_type, ui->A10_pushButton);
    set_icon(candy[1][1].color, candy[1][1].candy_type, ui->A11_pushButton);
    set_icon(candy[1][2].color, candy[1][2].candy_type, ui->A12_pushButton);
    set_icon(candy[1][3].color, candy[1][3].candy_type, ui->A13_pushButton);
    set_icon(candy[1][4].color, candy[1][4].candy_type, ui->A14_pushButton);
    set_icon(candy[1][5].color, candy[1][5].candy_type, ui->A15_pushButton);

    set_icon(candy[2][0].color, candy[2][0].candy_type, ui->A20_pushButton);
    set_icon(candy[2][1].color, candy[2][1].candy_type, ui->A21_pushButton);
    set_icon(candy[2][2].color, candy[2][2].candy_type, ui->A22_pushButton);
    set_icon(candy[2][3].color, candy[2][3].candy_type, ui->A23_pushButton);
    set_icon(candy[2][4].color, candy[2][4].candy_type, ui->A24_pushButton);
    set_icon(candy[2][5].color, candy[2][5].candy_type, ui->A25_pushButton);

    set_icon(candy[3][0].color, candy[3][0].candy_type, ui->A30_pushButton);
    set_icon(candy[3][1].color, candy[3][1].candy_type, ui->A31_pushButton);
    set_icon(candy[3][2].color, candy[3][2].candy_type, ui->A32_pushButton);
    set_icon(candy[3][3].color, candy[3][3].candy_type, ui->A33_pushButton);
    set_icon(candy[3][4].color, candy[3][4].candy_type, ui->A34_pushButton);
    set_icon(candy[3][5].color, candy[3][5].candy_type, ui->A35_pushButton);

    set_icon(candy[4][0].color, candy[4][0].candy_type, ui->A40_pushButton);
    set_icon(candy[4][1].color, candy[4][1].candy_type, ui->A41_pushButton);
    set_icon(candy[4][2].color, candy[4][2].candy_type, ui->A42_pushButton);
    set_icon(candy[4][3].color, candy[4][3].candy_type, ui->A43_pushButton);
    set_icon(candy[4][4].color, candy[4][4].candy_type, ui->A44_pushButton);
    set_icon(candy[4][5].color, candy[4][5].candy_type, ui->A45_pushButton);

    set_icon(candy[5][0].color, candy[5][0].candy_type, ui->A50_pushButton);
    set_icon(candy[5][1].color, candy[5][1].candy_type, ui->A51_pushButton);
    set_icon(candy[5][2].color, candy[5][2].candy_type, ui->A52_pushButton);
    set_icon(candy[5][3].color, candy[5][3].candy_type, ui->A53_pushButton);
    set_icon(candy[5][4].color, candy[5][4].candy_type, ui->A54_pushButton);
    set_icon(candy[5][5].color, candy[5][5].candy_type, ui->A55_pushButton);

}


void Table::on_A00_pushButton_clicked()
{
    cc++;
    if(cc%2)
    {
        a=0;
        b=0;
    }
    else
    {
        c=0;
        d=0;
        test();
    }

}

void Table::on_A10_pushButton_clicked()
{
    cc++;
    if(cc%2)
    {
        a=1;
        b=0;
    }
    else
    {
        c=1;
        d=0;
        test();
    }
    /*cc++;cout<<cc<<endl;
    if(cc%2==0){
        c=1;
        d=0;cout<<"ok"<<endl;
        test();
    }
    else{
        a=1;
        b=0;
    }*/
}



void Table::on_A20_pushButton_clicked()
{
    cc++;
    if(cc%2)
    {
        a=2;
        b=0;
    }
    else
    {
        c=2;
        d=0;
        test();
    }
}

void Table::on_A30_pushButton_clicked()
{
    cc++;
    if(cc%2)
    {
        a=3;
        b=0;
    }
    else
    {
        c=3;
        d=0;
        test();
    }
}

void Table::on_A40_pushButton_clicked()
{
    cc++;
    if(cc%2)
    {
        a=4;
        b=0;
    }
    else
    {
        c=4;
        d=0;
        test();
    }
}

void Table::on_A50_pushButton_clicked()
{
    cc++;
    if(cc%2)
    {
        a=5;
        b=0;
    }
    else
    {
        c=5;
        d=0;
        test();
    }

}

void Table::on_A01_pushButton_clicked()
{
    cc++;
    if(cc%2)
    {
        a=0;
        b=1;
    }
    else
    {
        c=0;
        d=1;
        test();
    }

}

void Table::on_A11_pushButton_clicked()
{
    cc++;
    if(cc%2)
    {
        a=1;
        b=1;
    }
    else
    {
        c=1;
        d=1;
        test();
    }
}

void Table::on_A21_pushButton_clicked()
{
    cc++;
    if(cc%2)
    {
        a=2;
        b=1;
    }
    else
    {
        c=2;
        d=1;
        test();
    }

}

void Table::on_A31_pushButton_clicked()
{
    cc++;
    if(cc%2)
    {
        a=3;
        b=1;
    }
    else
    {
        c=3;
        d=1;
        test();
    }
}

void Table::on_A41_pushButton_clicked()
{
    cc++;
    if(cc%2)
    {
        a=4;
        b=1;
    }
    else
    {
        c=4;
        d=1;
        test();
    }
}

void Table::on_A51_pushButton_clicked()
{
    cc++;
    if(cc%2)
    {
        a=5;
        b=1;
    }
    else
    {
        c=5;
        d=1;
        test();
    }
}

void Table::on_A02_pushButton_clicked()
{
    cc++;
    if(cc%2)
    {
        a=0;
        b=2;
    }
    else
    {
        c=0;
        d=2;
        test();
    }

}

void Table::on_A12_pushButton_clicked()
{
    cc++;
    if(cc%2)
    {
        a=1;
        b=2;
    }
    else
    {
        c=1;
        d=2;
        test();
    }

}

void Table::on_A22_pushButton_clicked()
{
    cc++;
    if(cc%2)
    {
        a=2;
        b=2;
    }
    else
    {
        c=2;
        d=2;
        test();
    }
}

void Table::on_A32_pushButton_clicked()
{
    cc++;
    if(cc%2)
    {
        a=3;
        b=2;
    }
    else
    {
        c=3;
        d=2;
        test();
    }

}

void Table::on_A42_pushButton_clicked()
{
    cc++;
    if(cc%2)
    {
        a=4;
        b=2;
    }
    else
    {
        c=4;
        d=2;
        test();
    }
}

void Table::on_A52_pushButton_clicked()
{
    cc++;
    if(cc%2)
    {
        a=5;
        b=2;
    }
    else
    {
        c=5;
        d=2;
        test();
    }
}

void Table::on_A03_pushButton_clicked()
{
    cc++;
    if(cc%2)
    {
        a=0;
        b=3;
    }
    else
    {
        c=0;
        d=3;
        test();
    }

}

void Table::on_A13_pushButton_clicked()
{
    cc++;
    if(cc%2)
    {
        a=1;
        b=3;
    }
    else
    {
        c=1;
        d=3;
        test();
    }
}

void Table::on_A23_pushButton_clicked()
{
    cc++;
    if(cc%2)
    {
        a=2;
        b=3;
    }
    else
    {
        c=2;
        d=3;
        test();
    }
}

void Table::on_A33_pushButton_clicked()
{
    cc++;
    if(cc%2)
    {
        a=3;
        b=3;
    }
    else
    {
        c=3;
        d=3;
        test();
    }
}

void Table::on_A43_pushButton_clicked()
{
    cc++;
    if(cc%2)
    {
        a=4;
        b=3;
    }
    else
    {
        c=4;
        d=3;
        test();
    }
}

void Table::on_A53_pushButton_clicked()
{

    cc++;
    if(cc%2)
    {
        a=5;
        b=3;
    }
    else
    {
        c=5;
        d=3;
        test();
    }
}

void Table::on_A04_pushButton_clicked()
{
    cc++;
    if(cc%2)
    {
        a=0;
        b=4;
    }
    else
    {
        c=0;
        d=4;
        test();
    }

}

void Table::on_A14_pushButton_clicked()
{
    cc++;
    if(cc%2)
    {
        a=1;
        b=4;
    }
    else
    {
        c=1;
        d=4;
        test();
    }
}

void Table::on_A24_pushButton_clicked()
{
    cc++;
    if(cc%2)
    {
        a=2;
        b=4;
    }
    else
    {
        c=2;
        d=4;
        test();
    }
}

void Table::on_A34_pushButton_clicked()
{
    cc++;
    if(cc%2)
    {
        a=3;
        b=4;
    }
    else
    {
        c=3;
        d=4;
        test();
    }
}

void Table::on_A44_pushButton_clicked()
{
    cc++;
    if(cc%2)
    {
        a=4;
        b=4;
    }
    else
    {
        c=4;
        d=4;
        test();
    }
}

void Table::on_A54_pushButton_clicked()
{
    cc++;
    if(cc%2)
    {
        a=5;
        b=4;
    }
    else
    {
        c=5;
        d=4;
        test();
    }

}

void Table::on_A05_pushButton_clicked()
{
    cc++;
    if(cc%2)
    {
        a=0;
        b=5;
    }
    else
    {
        c=0;
        d=5;
        test();
    }
}

void Table::on_A15_pushButton_clicked()
{
    cc++;
    if(cc%2)
    {
        a=1;
        b=5;
    }
    else
    {
        c=1;
        d=5;
        test();
    }
}

void Table::on_A25_pushButton_clicked()
{
    cc++;
    if(cc%2)
    {
        a=2;
        b=5;
    }
    else
    {
        c=2;
        d=5;
        test();
    }

}

void Table::on_A35_pushButton_clicked()
{
    cc++;
    if(cc%2)
    {
        a=3;
        b=5;
    }
    else
    {
        c=3;
        d=5;
        test();
    }
}

void Table::on_A45_pushButton_clicked()
{
    cc++;
    if(cc%2)
    {
        a=4;
        b=5;
    }
    else
    {
        c=4;
        d=5;
        test();
    }

}

void Table::on_A55_pushButton_clicked()
{
    cc++;
    if(cc%2)
    {
        a=5;
        b=5;
    }
    else
    {
        c=5;
        d=5;
        test();
    }

}

void Table::test(){
    //if(candy[a[0][0]][a[i][1]].candy_type==5){

    //} set_icon(candy[0][0].color, candy[0][0].candy_type, ui->A00_pushButton);

    int tx=0, ty=0;
    ty=d-b;
    if(ty<0)
        ty=-ty;
    tx=c-a;
    if(tx<0)
        tx=-tx;

    if(candy[a][b].color!=candy[c][d].color||candy[a][b].candy_type!=candy[c][d].candy_type)
    {
        if(tx<2 && ty<2&& tx!=ty)
        {
            int temp;

            temp=candy[a][b].color;
            candy[a][b].color=candy[c][d].color;
            candy[c][d].color=temp;
            temp=candy[a][b].candy_type;
            candy[a][b].candy_type=candy[c][d].candy_type;
            candy[c][d].candy_type=temp;


            if(eliminate_candy())
            {
                bool flag=1;
                do{
                    move_candy();
                    if(flag){
                        while(flag){
                            flag=eliminate_candy();
                            move_candy();
                        }
                        if(!check_candy()){
                            recreate_table();
                        }
                    }
                }
                while(eliminate_candy());
            }
            else
            {
                temp=candy[a][b].color;
                candy[a][b].color=candy[c][d].color;
                candy[c][d].color=temp;
                temp=candy[a][b].candy_type;
                candy[a][b].candy_type=candy[c][d].candy_type;
                candy[c][d].candy_type=temp;
            }
            print();
        }
    }
}

//原地好可愛
