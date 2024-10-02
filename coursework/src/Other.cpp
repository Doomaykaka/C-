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
    fout.write(reinterpret_cast<char *>(&degree_of_taste), sizeof(degree_of_taste));
}

void Other::load(std::ifstream &fin)
{
    Drink::load(fin);
    fin.read(reinterpret_cast<char *>(&degree_of_taste), sizeof(degree_of_taste));
}

void Other::print(std::ostream& ostream) const {
    Drink::print(ostream);
    ostream << "subtype Other" << std::endl
    << "    degree of taste=" << degree_of_taste << std::endl;
}
