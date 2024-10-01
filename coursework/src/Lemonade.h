#ifndef LEMONADE_H_INCLUDED
#define LEMONADE_H_INCLUDED

#include "Cold.h"

using namespace std;

class Lemonade : public Cold
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
