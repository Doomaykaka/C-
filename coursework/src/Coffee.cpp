#include <iostream>
#include <fstream>

#include "Coffee.h"

using namespace std;

Coffee::Coffee(): Hot() {
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
    this->is_cooking_method_traditional = is_cooking_method_traditional;
}

bool Coffee::get_is_cooking_method_traditional()
{
    return is_cooking_method_traditional;
}

void Coffee::save(std::ofstream& fout) {
    Hot::save(fout);
    this->save_sized_string(fout, this->advantages);
    this->save_primitive_type(fout, this->is_cooking_method_traditional);
}


void Coffee::load(std::ifstream& fin) {
    Hot::load(fin);
    this->advantages = this->load_sized_string(fin);
    this->is_cooking_method_traditional = this->load_primitive_type<bool>(fin);
}

void Coffee::print(std::ostream& ostream) const {
    Hot::print(ostream);
    ostream << "subtype Coffee" << std::endl
    << "\tadvantages=" << advantages << std::endl
    << "\tis cooking method traditional=" << is_cooking_method_traditional << std::endl;
}
