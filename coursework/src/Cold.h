#ifndef COLD_H_INCLUDED
#define COLD_H_INCLUDED

#include <string>

#include "Drink.h"

using namespace std;

class Cold : public Drink
{
private:
    bool readiness;

public:
    void set_readiness(bool readiness);

    bool get_readiness();

    void save(std::ofstream&);

    void load(std::ifstream&);
};

#endif
