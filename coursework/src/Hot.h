#ifndef HOT_H_INCLUDED
#define HOT_H_INCLUDED

#include <string>

#include "Drink.h"

using namespace std;

class Hot : public Drink
{
private:
    int degree_of_taste;
    bool readiness;

public:
    Hot();

    void set_degree_of_taste(int degree_of_taste);

    int get_degree_of_taste();

    void set_readiness(bool readiness);

    bool get_readiness();

    void save(std::ofstream &);

    void load(std::ifstream &);

    void print(std::ostream& ostream) const;
};

#endif
