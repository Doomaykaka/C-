#include <string>
#include <iostream>
#include <fstream>

#include "Water.h"

using namespace std;

void Water::set_color(int color)
{
     this->color = color;
}

int Water::get_color()
{
     return color;
}

void Water::save(std::ofstream &fout)
{
     Cold::save(fout);
     fout.write(reinterpret_cast<char *>(&color), sizeof(color));
}

void Water::load(std::ifstream &fin)
{
     Cold::load(fin);
     fin.read(reinterpret_cast<char *>(&advantages), sizeof(advantages));
}
