
#include <string>
#include <iostream>
#include <fstream>

#include "Drink.h"

using namespace std;

Drink::Drink()
{
    classname = DRINK;

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
    size_t dishes_str_size = dishes.size();
    const char* dishes_c_str = dishes.c_str();

    size_t name_str_size = name.size();
    const char* name_c_str = name.c_str();

    fout.write(reinterpret_cast<char *>(&classname), sizeof(ClassName));
    fout.write(reinterpret_cast<char *>(&drinking_time), sizeof(int));
    fout.write(reinterpret_cast<char *>(&dishes_str_size), sizeof(size_t));
    fout.write(const_cast<char *>(dishes_c_str), dishes_str_size);
    fout.write(reinterpret_cast<char *>(&name_str_size), sizeof(size_t));
    fout.write(const_cast<char *>(name_c_str), name_str_size);
}

void Drink::load(std::ifstream &fin)
{
    size_t dishes_str_size = 0;

    size_t name_str_size = 0;

    fin.read(reinterpret_cast<char *>(&classname), sizeof(ClassName));
    fin.read(reinterpret_cast<char *>(&drinking_time), sizeof(int));

    fin.read(reinterpret_cast<char *>(&dishes_str_size), sizeof(size_t));
    const char* dishes_c_str = new char[dishes_str_size];
    fin.read(const_cast<char *>(dishes_c_str), dishes_str_size);
    dishes = string(dishes_c_str);
    delete[] dishes_c_str;

    fin.read(reinterpret_cast<char *>(&name_str_size), sizeof(size_t));
    const char* name_c_str = new char[name_str_size];
    fin.read(const_cast<char *>(name_c_str), name_str_size);
    name = string(name_c_str);
    delete[] name_c_str;
}

void Drink::print(std::ostream &ostream) const
{
    ostream
        << "Drink:" << std::endl
        << "\tname: " << name << std::endl
        << "\tdrinking time: " << drinking_time << std::endl
        << "\tdishes: " << dishes << std::endl;
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
