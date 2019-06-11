#ifndef TABLE_H
#define TABLE_H

class Candy
{
    public:
        Candy();    //color is random; barrier_type=0;

        int color;
        int candy_type;  //0==barrier, 1==ori, 2==four, 3==L, 4==five(not color);
        int barrier_type;
};

class Table
{
    public:
        Table();    //length=0; width=0; choco_num=0; chain_num=0; peel_num=0; check candy[][];

        void move_candy();    //down from the above; create the top candy;

        void create_barrier(int len, int wid, int choco, int chain, int peel);    //the position is random; Candy candy = new int [] to set up length and width;

        void recreate_table();  //recreate candy; after this, check_candy();

        void swap_candy(int x_1, int y_1, int x_2, int y_2);    //exchange the clicked two candy; after this, set flag=eliminate();

        bool eliminate_candy();    //eliminate candy; create high_level candy or use high_level candy function; decrease the number of barrier;

        bool check_candy();    //if return true, recreate table; else, continue;

        //the way of using functions : click two candy, execute swap(), bool flag=eliminate(), if(flag){while(flag){move(), flag=eliminate()}, if(check()){reset table}}, else{swap()};

        void print();    //show table and candy and barrier;

        Candy **candy;//nested class

    private:
        int length;
        int width;


        int choco_num;

        int chain_num;
        int peel_num;
};

#endif // TABLE_H
