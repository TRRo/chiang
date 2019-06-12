#include "table.h"
#include <QApplication>


#include<iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Table w;
    w.create_barrier(6,6,0,0,0);
    bool flag=w.eliminate_candy();
    do{
        w.move_candy();
        if(flag){
            while(flag){
                flag=w.eliminate_candy();
                w.move_candy();
            }
            if(w.check_candy()){
                w.recreate_table();
            }
        }
    }
    while(w.eliminate_candy());
    w.move_candy();
    while(1){
        bool k=0;
        for(int i=0; i<6; i++){
            if(w.candy[0][i].color==0){
                k=1;
                break;
            }
        }
        if(k){
            w.move_candy();
        }
        else {
            break;
        }
    }
    w.print();
    w.show();
    return a.exec();
}
