#ifndef WATER_H_INCLUDED
#define WATER_H_INCLUDED

#include "Cold.h"

using namespace std;

class Water : public Cold
{
private:
    int color;

public:
    Water();

    void set_color(int color);

    int get_color();

    void save(std::ofstream &);

    void load(std::ifstream &);

    void print(std::ostream& ostream) const;
};

#endif // WATER_H_INCLUDED
