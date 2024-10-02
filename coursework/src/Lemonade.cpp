#include <string>
#include <iostream>
#include <fstream>

#include "Lemonade.h"

using namespace std;

Lemonade::Lemonade() : Cold(){
    classname = LEMONADE;

    set_name("lemonade");
    set_dishes("sweet");
    set_drinking_time(5);
    set_degree_of_taste(9);
    set_readiness(0);
}

void Lemonade::set_degree_of_taste(int degree_of_taste)
{
    this->degree_of_taste = degree_of_taste;
}

int Lemonade::get_degree_of_taste()
{
    return degree_of_taste;
}

void Lemonade::save(std::ofstream &fout)
{
    Cold::save(fout);
    fout.write(reinterpret_cast<char *>(&degree_of_taste), sizeof(degree_of_taste));
}

void Lemonade::load(std::ifstream &fin)
{
    Cold::load(fin);
    fin.read(reinterpret_cast<char *>(&degree_of_taste), sizeof(degree_of_taste));
}

void Lemonade::print(std::ostream& ostream) const {
    Cold::print(ostream);
    ostream << "subtype Lemonade" << std::endl
    << "    degree of taste=" << degree_of_taste << std::endl;
}
