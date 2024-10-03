#include <string>
#include <iostream>
#include <fstream>

#include "Water.h"

using namespace std;

Water::Water() : Cold()
{
     classname = WATER;

     set_name("water");
     set_dishes("none");
     set_drinking_time(1);
     set_color(0);
     set_readiness(1);
}

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
     this->save_primitive_type(fout, color);
}

void Water::load(std::ifstream &fin)
{
     Cold::load(fin);
     this->color = this->load_primitive_type<int>(fin);
}

void Water::print(std::ostream &ostream) const
{
     Cold::print(ostream);
     ostream << "subtype Water" << std::endl
             << "\tcolor=" << color << std::endl;
}
