
#include <string>
#include <iostream>
#include <fstream>

#include "Drink.h"

using namespace std;

Drink::Drink()
{
    set_name("drink");
    set_dishes("unknown");
    set_drinking_time(0);
}

void Drink::set_drinking_time(int time)
{
    drinking_time = time;
}

int Drink::get_drinking_time()
{
    return drinking_time;
}

void Drink::set_dishes(string dishes)
{
    this->dishes = dishes;
}

string Drink::get_dishes()
{
    return dishes;
}

string Drink::get_name()
{
    return name;
}

void Drink::set_name(string name)
{
    this->name = name;
}

void Drink::save(std::ofstream &fout)
{
    fout.write(reinterpret_cast<char *>(&classname), sizeof(classname));
    fout.write(reinterpret_cast<char *>(&drinking_time), sizeof(drinking_time));
    fout.write(reinterpret_cast<char *>(&dishes), sizeof(dishes));
}

void Drink::load(std::ifstream &fin)
{
    fin.read(reinterpret_cast<char *>(&classname), sizeof(classname));
    fin.read(reinterpret_cast<char *>(&drinking_time), sizeof(drinking_time));
    fin.read(reinterpret_cast<char *>(&dishes), sizeof(dishes));
}

void Drink::print(std::ostream &ostream) const
{
    ostream
        << "Drink" << std::endl
        << "    name=" << name << std::endl
        << "    ,drinking time=" << drinking_time << std::endl
        << "    ,dishes=" << dishes << std::endl;
}

std::ostream &operator<<(std::ostream &ostream, const Drink &drink)
{
    drink.print(ostream);
    return ostream;
}

ClassName Drink::get_classname() const
{
    return classname;
}
