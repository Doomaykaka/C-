
#include <string>
#include <iostream>
#include <fstream>

#include "Drink.h"

using namespace std;

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

void Drink::save(std::ofstream &fout)
{
    fout.write(reinterpret_cast<char *>(&drinking_time), sizeof(drinking_time));
    fout.write(reinterpret_cast<char *>(&dishes), sizeof(dishes));
}

void Drink::load(std::ifstream &fin)
{
    fin.read(reinterpret_cast<char *>(&drinking_time), sizeof(drinking_time));
    fin.read(reinterpret_cast<char *>(&dishes), sizeof(dishes));
}
