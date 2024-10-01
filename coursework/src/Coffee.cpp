#include "Coffee.h"

using namespace std;

void Coffee::set_advantages(string advantages_repr)
{
    advantages = advantages_repr;
}

string Coffee::get_advantages()
{
    return advantages;
}

void Coffee::set_is_cooking_method_traditional(bool is_cooking_method_traditional)
{
    (*this).is_cooking_method_traditional = is_cooking_method_traditional;
}

bool Coffee::get_is_cooking_method_traditional()
{
    return is_cooking_method_traditional;
}

void Coffee::save(std::ofstream& fout) {
    Hot::save(fout);
    fout.write(reinterpret_cast<char*>(&advantages), sizeof(is_cooking_method_traditional));
}


void Ranged::load(std::ifstream& fin) {
    Warrior::load(fin);
    fin.read(reinterpret_cast<char*>(&accuracy), sizeof(accuracy));
}
