#ifndef DRINKS_H_INCLUDED
#define DRINKS_H_INCLUDED

using namespace std;

class Drink
{
private:
    int drinking_time;
    string dishes;

public:
    void set_drinking_time(int time);

    int get_drinking_time();

    void set_dishes(string dishes);

    string get_dishes();

    void save(std::ofstream &);

    void load(std::ifstream &);
};

#endif
