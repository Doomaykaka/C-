#include <string>
#include <iostream>
#include <fstream>

#include "Tea.h"

using namespace std;

Tea::Tea() : Hot()
{
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

  this->save_sized_string(fout, advantages);
  this->save_primitive_type<bool>(fout, is_cooking_method_traditional);
}

void Tea::load(std::ifstream &fin)
{
  Hot::load(fin);

  advantages = this->load_sized_string(fin);
  is_cooking_method_traditional = this->load_primitive_type<bool>(fin);
}

void Tea::print(std::ostream &ostream) const
{
  Hot::print(ostream);
  ostream << "subtype Tea" << std::endl
          << "\tadvantages=" << advantages << std::endl
          << "\tis cooking method traditional=" << is_cooking_method_traditional << std::endl;
}
