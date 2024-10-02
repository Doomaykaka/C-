#include <string>
#include <iostream>
#include <fstream>

#include "Tea.h"

using namespace std;

Tea::Tea() : Hot(){
    classname = TEA;

    set_name("tea");
    set_dishes("some");
    set_drinking_time(30);
    set_degree_of_taste(5);
    set_readiness(0);
    set_advantages("hot");
    set_is_cooking_method_traditional(1);
}

void Tea::set_advantages(string advantages_repr)
{
  advantages = advantages_repr;
}

string Tea::get_advantages()
{
  return advantages;
}

void Tea::set_is_cooking_method_traditional(bool is_cooking_method_traditional)
{
  (*this).is_cooking_method_traditional = is_cooking_method_traditional;
}

bool Tea::get_is_cooking_method_traditional()
{
  return is_cooking_method_traditional;
}

void Tea::save(std::ofstream &fout)
{
    Hot::save(fout);
    fout.write(reinterpret_cast<char *>(&advantages), sizeof(advantages));
    fout.write(reinterpret_cast<char *>(&is_cooking_method_traditional), sizeof(is_cooking_method_traditional));
}

void Tea::load(std::ifstream &fin)
{
    Hot::load(fin);
    fin.read(reinterpret_cast<char *>(&advantages), sizeof(advantages));
    fin.read(reinterpret_cast<char *>(&is_cooking_method_traditional), sizeof(is_cooking_method_traditional));
}

void Tea::print(std::ostream& ostream) const {
    Hot::print(ostream);
    ostream << "subtype Tea" << std::endl
    << "  advantages=" << advantages << std::endl
    << "  ,is cooking method traditional=" << is_cooking_method_traditional << std::endl;
}
