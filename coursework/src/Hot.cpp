#include <iostream>
#include <fstream>

#include "Hot.h"

using namespace std;

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
    fout.write(reinterpret_cast<char *>(&degree_of_taste), sizeof(degree_of_taste));
    fout.write(reinterpret_cast<char *>(&readiness), sizeof(readiness));
}

void Hot::load(std::ifstream &fin)
{
    Drink::load(fin);
    fin.read(reinterpret_cast<char *>(&degree_of_taste), sizeof(degree_of_taste));
    fin.read(reinterpret_cast<char *>(&readiness), sizeof(readiness));
}
