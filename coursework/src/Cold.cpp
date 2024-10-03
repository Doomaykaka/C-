#include <string>
#include <iostream>
#include <fstream>

#include "Cold.h"

using namespace std;

Cold::Cold(): Drink() {
    classname = COLD;

    set_name("cold");
    set_dishes("frozen");
    set_drinking_time(1);
    set_readiness(1);
}

void Cold::set_readiness(bool readiness)
{
    this->readiness = readiness;
}

bool Cold::get_readiness()
{
    return readiness;
}

void Cold::save(std::ofstream& fout) {
    Drink::save(fout);
    this->save_primitive_type(fout, this->readiness);
}


void Cold::load(std::ifstream& fin) {
    Drink::load(fin);
    this->readiness = this->load_primitive_type<bool>(fin);
}

void Cold::print(std::ostream& ostream) const {
    Drink::print(ostream);
    ostream << "subtype Cold" << std::endl
    << "\treadiness=" << readiness << std::endl;
}
