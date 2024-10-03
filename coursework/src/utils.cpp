#include <fstream>
#include <iostream>
#include <cstring>
#include <limits>

#include "utils.h"
#include "config.h"

#include "Hot.h"
#include "Coffee.h"
#include "Tea.h"
#include "Cold.h"
#include "Lemonade.h"
#include "Water.h"
#include "Other.h"


Drink* read_from_file_smart(string filename, size_t& offset) {
    /*
        Note! This function doesn't free memory;
    */

    ClassName classname;
    std::ifstream fin(filename, std::ios::binary);
    fin.seekg(offset);
    fin.read(reinterpret_cast<char*>(&classname), sizeof(classname));
    fin.seekg(offset);

    Drink* drink;
    switch (classname) {
        case DRINK:
            drink = new Drink;
            break;
        case HOT:
            drink = new Hot;
            break;
        case COFFEE:
            drink = new Coffee;
            break;
        case TEA:
            drink = new Tea;
            break;
        case COLD:
            drink = new Cold;
            break;
        case LEMONADE:
            drink = new Lemonade;
            break;
        case WATER:
            drink = new Water;
            break;
        case OTHER:
            drink = new Other;
            break;
        default:
            return nullptr;
    }

    drink->load(fin);

    if (fin.fail()) {
        return nullptr;
    }

    offset = fin.tellg();
    fin.close();

    return drink;
}


void clearcin() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool is_bool_string(string* line)
{
    string value = *line;

    for (int i = 0; i < value.length(); i++)
    {
        if (value[i] != '1' && value[i] != '0')
        {
            return false;
        }
    }

    return true;
}

bool is_int_string(string* line)
{
    string value = *line;

    for (int i = 0; i < value.length(); i++)
    {
        if (!isdigit(value[i]) && value[i] != '-')
        {
            return false;
        }
    }

    return true;
}

void read_line(string* line)
{
    while (!std::getline(std::cin, *line) || line->empty())
    {
        ;
    }
}

void read_int(int* var)
{
    string int_repr;

    read_line(&int_repr);

    while (!is_int_string(&int_repr))
    {
        std::cout << "bad integer, repeat please" << std::endl;
        read_line(&int_repr);
    }

    *var = std::stoi(int_repr);
}

void read_bool(bool* var)
{
    string bool_repr;

    read_line(&bool_repr);

    while (!is_bool_string(&bool_repr))
    {
        std::cout << "bad boolean, repeat please" << std::endl;
        read_line(&bool_repr);
    }

    *var = std::stoi(bool_repr);
}
