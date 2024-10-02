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

  size_t advantages_str_size = advantages.size() - 1;
  const char *advantages_c_str = advantages.c_str();

  fout.write(reinterpret_cast<char *>(&advantages_str_size), sizeof(size_t));
  fout.write(const_cast<char *>(advantages_c_str), advantages_str_size);
  fout.write(reinterpret_cast<char *>(&is_cooking_method_traditional), sizeof(bool));
}

void Tea::load(std::ifstream &fin)
{
  Hot::load(fin);

  size_t advantages_str_size = 0;

  fin.read(reinterpret_cast<char *>(&advantages_str_size), sizeof(size_t));
  const char *advantages_c_str = new char[advantages_str_size];
  fin.read(const_cast<char *>(advantages_c_str), advantages_str_size);
  advantages = string(advantages_c_str);
  delete[] advantages_c_str;

  fin.read(reinterpret_cast<char *>(&is_cooking_method_traditional), sizeof(bool));
}

void Tea::print(std::ostream &ostream) const
{
  Hot::print(ostream);
  ostream << "subtype Tea" << std::endl
          << "\tadvantages=" << advantages << std::endl
          << "\tis cooking method traditional=" << is_cooking_method_traditional << std::endl;
}
