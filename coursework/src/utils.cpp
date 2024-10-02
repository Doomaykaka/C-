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
