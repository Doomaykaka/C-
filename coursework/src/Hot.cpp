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
    this->save_primitive_type(fout, degree_of_taste);
    this->save_primitive_type(fout, readiness);
}

void Hot::load(std::ifstream &fin)
{
    Drink::load(fin);
    this->degree_of_taste = this->load_primitive_type<bool>(fin);
    this->readiness = this->load_primitive_type<int>(fin);
}

void Hot::print(std::ostream& ostream) const {
    Drink::print(ostream);
    ostream << "subtype Hot" << std::endl
    << "\tdegree of taste=" << degree_of_taste << std::endl
    << "\treadiness=" << readiness << std::endl;
}
