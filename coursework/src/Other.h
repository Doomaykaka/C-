#ifndef OTHER_H_INCLUDED
#define OTHER_H_INCLUDED

#include "Drink.h"

using namespace std;

class Other : public Drink
{
private:
    int degree_of_taste;

public:
    void set_degree_of_taste(int degree_of_taste);

    int get_degree_of_taste();

    void save(std::ofstream&);

    void load(std::ifstream&);
};

#endif
