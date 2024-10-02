#include <iostream>
#include <fstream>

#include "Coffee.h"

using namespace std;

Coffee::Coffee():Hot() {
    classname = COFFEE;

    set_name("coffee");
    set_dishes("nice");
    set_drinking_time(30);
    set_degree_of_taste(8);
    set_readiness(0);
    set_advantages("tasty");
    set_is_cooking_method_traditional(1);
}

void Coffee::set_advantages(string advantages_repr)
{
    advantages = advantages_repr;
}

string Coffee::get_advantages()
{
    return advantages;
}

void Coffee::set_is_cooking_method_traditional(bool is_cooking_method_traditional)
{
    (*this).is_cooking_method_traditional = is_cooking_method_traditional;
}

bool Coffee::get_is_cooking_method_traditional()
{
    return is_cooking_method_traditional;
}

void Coffee::save(std::ofstream& fout) {
    Hot::save(fout);
    fout.write(reinterpret_cast<char*>(&advantages), sizeof(advantages));
    fout.write(reinterpret_cast<char*>(&is_cooking_method_traditional), sizeof(is_cooking_method_traditional));
}


void Coffee::load(std::ifstream& fin) {
    Hot::load(fin);
    fin.read(reinterpret_cast<char*>(&advantages), sizeof(advantages));
    fin.read(reinterpret_cast<char*>(&is_cooking_method_traditional), sizeof(is_cooking_method_traditional));
}

void Coffee::print(std::ostream& ostream) const {
    Hot::print(ostream);
    ostream << "subtype Coffee" << std::endl
    << "    advantages=" << advantages << std::endl
    << "    ,is cooking method traditional=" << is_cooking_method_traditional << std::endl;
}
