#include <string>
#include <iostream>
#include <fstream>

#include "Lemonade.h"

using namespace std;

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
