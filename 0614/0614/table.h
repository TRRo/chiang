#ifndef TABLE_H
#define TABLE_H

#include <QMainWindow>

namespace Ui {
class Table;
}

class Candy
{
    public:
        Candy();    //color is random; barrier_type=0;

        int color;    //1~6
        int candy_type;  //0==barrier, 1==ori, 4==four, 6==L, 5==five(not color);
        int barrier_type;
};

class Table : public QMainWindow
{
    Q_OBJECT

    public:
        explicit Table(QWidget *parent = nullptr);    //length=0; width=0; choco_num=0; chain_num=0; peel_num=0; check candy[][];

    void move_candy();    //down from the above; create the top candy;

    void create_barrier(int len, int wid, int choco, int chain, int peel);    //the position is random; Candy candy = new int [] to set up length and width;

    void recreate_table();  //recreate candy; after this, check_candy();

    bool eliminate_candy();    //eliminate candy; create high_level candy or use high_level candy function; decrease the number of barrier;

    void eliminate_high(int le, int w, int type);

    bool check_candy();    //if return true, recreate table; else, continue;

    //the way of using functions : click two candy, execute swap(), bool flag=eliminate(), if(flag){while(flag){move(), flag=eliminate()}, if(check()){reset table}}, else{swap()};

    void print();

    void test();

    Candy **candy;//nested class

        ~Table();

private slots:
    void on_A00_pushButton_clicked();

    void on_A10_pushButton_clicked();



    void on_A20_pushButton_clicked();

    void on_A30_pushButton_clicked();

    void on_A40_pushButton_clicked();

    void on_A50_pushButton_clicked();

    void on_A01_pushButton_clicked();

    void on_A11_pushButton_clicked();

    void on_A21_pushButton_clicked();

    void on_A31_pushButton_clicked();

    void on_A41_pushButton_clicked();

    void on_A51_pushButton_clicked();

    void on_A02_pushButton_clicked();

    void on_A12_pushButton_clicked();

    void on_A22_pushButton_clicked();

    void on_A32_pushButton_clicked();

    void on_A42_pushButton_clicked();

    void on_A52_pushButton_clicked();

    void on_A03_pushButton_clicked();

    void on_A13_pushButton_clicked();

    void on_A23_pushButton_clicked();

    void on_A33_pushButton_clicked();

    void on_A43_pushButton_clicked();

    void on_A53_pushButton_clicked();

    void on_A04_pushButton_clicked();

    void on_A14_pushButton_clicked();

    void on_A24_pushButton_clicked();

    void on_A34_pushButton_clicked();

    void on_A44_pushButton_clicked();

    void on_A54_pushButton_clicked();

    void on_A05_pushButton_clicked();

    void on_A15_pushButton_clicked();

    void on_A25_pushButton_clicked();

    void on_A35_pushButton_clicked();

    void on_A45_pushButton_clicked();

    void on_A55_pushButton_clicked();

private:
        Ui::Table *ui;

        int length;
        int width;


        int choco_num;

        int chain_num;
        int peel_num;

        int cc;

        int a, b, c, d;
};

#endif // TABLE_H
