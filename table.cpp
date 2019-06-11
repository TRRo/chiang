#include "table.h"
#include <QTime>
#include <time.h>
#include <stdlib.h>
#include <QLabel>
#include <iostream>

using namespace std;

Candy::Candy()
{
    //QTime t;
    //t= QTime::currentTime();
    //qsrand(t.msec()*59+t.second()*93);
    //qsrand(time(NULL));  //include<time.h>
    color = qrand()%6 + 1;  //include<stdlib.h>

    /*for(int i=0; i<10000; i++)
    {
        if(color==0)
        {
            color=i+1;
            color%=6;
            color+=i;
        }
        color*=qrand();
        color%=6;
        color++;

    }*/
    candy_type = 1;  //0==barrier, 1==ori, 2==four, 3==L, 4==five(not color);
    barrier_type = 0;
    cout << color << endl;
    //int n = qrand();
}

Table::Table()
{
    length = 0;
    width = 0;
    choco_num = 0;
    chain_num = 0;
    peel_num = 0;
    qsrand(time(NULL));
}

void Table::move_candy()
{
    for(int w=0; w<width; w++)
    {
        for(int le=length-1; le>=0; le--)
        {
            if(candy[le][w].color==0)
            {
                for(int k=le-1; k>=0; k--)
                {
                    if(candy[k][w].color!=0)  //先不考慮障礙物
                    {
                        candy[le][w].color=candy[k][w].color;
                        candy[le][w].candy_type=candy[k][w].candy_type;
                        break;
                    }
                    if(k==0)
                    {
                        candy[le][w].color=rand()%6 +1;
                        candy[le][w].candy_type = 1;
                    }
                }
            }
        }
    }
}

void Table::create_barrier(int len, int wid, int choco, int chain, int peel)  //先不考慮障礙物
{
    candy = new Candy *[len];
    for(int i=0; i<len; i++)
    {
        candy[i] = new Candy [wid];
    }
    choco_num = choco;
    chain_num = chain;
    peel_num = peel;
}

void Table::recreate_table()  //先不考慮障礙物
{
    for(int le=0; le<length; le++)
    {
        for(int w=0; w<width; w++)
        {
            candy[le][w].color = qrand()%6;
            candy[le][w].candy_type = 1;
        }
    }
}

void swap_candy(int x_1, int y_1, int x_2, int y_2)    //exchange the clicked two candy; after this, set flag=eliminate()
{
    //buttons[0]->icon().swap(buttons[1]->icon());
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

            }
            if(candy[le][w].color==candy[le][w+1].color && candy[le][w].color==candy[le+1][w+1].color && candy[le][w].color==candy[le+2][w+1].color && candy[le][w].color==candy[le][w+2].color)
            {
                flag=true;

            }
            if(candy[le][w].color==candy[le+1][w].color && candy[le][w].color==candy[le+2][w].color && candy[le][w].color==candy[le][w+1].color && candy[le][w].color==candy[le][w+2].color)
            {
                flag=true;

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

            }
            if(candy[le][w].color==candy[le][w+1].color && candy[le][w].color==candy[le-1][w+1].color && candy[le][w].color==candy[le-2][w+1].color && candy[le][w].color==candy[le][w+2].color)
            {
                flag=true;

            }
            if(candy[le][w].color==candy[le-1][w].color && candy[le][w].color==candy[le-2][w].color && candy[le][w].color==candy[le][w+1].color && candy[le][w].color==candy[le][w+2].color)
            {
                flag=true;

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

            }
        }
    }

    return flag;
}
//eliminate candy; create high_level candy or use high_level candy function; decrease the number of barrier;

bool Table::check_candy()  //先不考慮障礙物
{
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

}
