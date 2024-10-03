#include <string>
#include <iostream>
#include <fstream>

#include "Other.h"

using namespace std;

Other::Other() : Drink(){
    classname = OTHER;

    set_name("other");
    set_dishes("unknown");
    set_drinking_time(-1);
    set_degree_of_taste(0);
}

void Other::set_degree_of_taste(int degree_of_taste)
{
    this->degree_of_taste = degree_of_taste;
}

int Other::get_degree_of_taste()
{
    return degree_of_taste;
}

void Other::save(std::ofstream &fout)
{
    Drink::save(fout);
    this->save_primitive_type(fout, degree_of_taste);
}

void Other::load(std::ifstream &fin)
{
    Drink::load(fin);
    degree_of_taste = this->load_primitive_type<int>(fin);
}

void Other::print(std::ostream& ostream) const {
    Drink::print(ostream);
    ostream << "subtype Other" << std::endl
    << "\tdegree of taste=" << degree_of_taste << std::endl;
}
