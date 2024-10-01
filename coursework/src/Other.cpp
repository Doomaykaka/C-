#include <string>
#include <iostream>
#include <fstream>

#include "Other.h"

using namespace std;

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
