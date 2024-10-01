#ifndef TEA_H_INCLUDED
#define TEA_H_INCLUDED

#include "Hot.h"

using namespace std;

class Tea : public Hot
{
private:
    string advantages;
    bool is_cooking_method_traditional;

public:
    void set_advantages(string advantages_repr);

    string get_advantages();

    void set_is_cooking_method_traditional(bool is_cooking_method_traditional);

    bool get_is_cooking_method_traditional();

    void save(std::ofstream&);

    void load(std::ifstream&);
};

#endif // TEA_H_INCLUDED
