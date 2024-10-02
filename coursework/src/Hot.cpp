#include <iostream>
#include <fstream>

#include "Hot.h"

using namespace std;

Hot::Hot(): Drink() {
    classname = HOT;

    set_name("hot");
    set_dishes("good");
    set_drinking_time(60);
    set_degree_of_taste(9);
    set_readiness(0);
}

void Hot::set_degree_of_taste(int degree_of_taste)
{
    this->degree_of_taste = degree_of_taste;
}

int Hot::get_degree_of_taste()
{
    return degree_of_taste;
}

void Hot::set_readiness(bool readiness)
{
    this->readiness = readiness;
}

bool Hot::get_readiness()
{
    return readiness;
}

void Hot::save(std::ofstream &fout)
{
    Drink::save(fout);
    fout.write(reinterpret_cast<char *>(&degree_of_taste), sizeof(int));
    fout.write(reinterpret_cast<char *>(&readiness), sizeof(bool));
}

void Hot::load(std::ifstream &fin)
{
    Drink::load(fin);
    fin.read(reinterpret_cast<char *>(&degree_of_taste), sizeof(int));
    fin.read(reinterpret_cast<char *>(&readiness), sizeof(bool));
}

void Hot::print(std::ostream& ostream) const {
    Drink::print(ostream);
    ostream << "subtype Hot" << std::endl
    << "\tdegree of taste=" << degree_of_taste << std::endl
    << "\treadiness=" << readiness << std::endl;
}
