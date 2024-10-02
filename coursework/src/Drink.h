#ifndef DRINKS_H_INCLUDED
#define DRINKS_H_INCLUDED

#include "config.h"

using namespace std;

class Drink
{
private:
    int drinking_time;
    string dishes;

    string name = "drink name";
protected:
    ClassName classname = DRINK;

public:
    Drink();

    void set_drinking_time(int time);

    int get_drinking_time();

    void set_dishes(string dishes);

    string get_dishes();

    string get_name();

    void set_name(string name);

    void save(std::ofstream &);

    void load(std::ifstream &);

    virtual void print(std::ostream& ostream) const;

    friend std::ostream& operator<<(std::ostream&, const Drink&);

    ClassName get_classname() const;
};

#endif
