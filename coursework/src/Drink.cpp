
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
    this->save_primitive_type(fout, classname);
    this->save_primitive_type(fout, drinking_time);
    this->save_sized_string(fout, dishes);
    this->save_sized_string(fout, name);
}

void Drink::load(std::ifstream &fin)
{
    this->classname = this->load_primitive_type<ClassName>(fin);
    this->drinking_time = this->load_primitive_type<int>(fin);
    this->dishes = this->load_sized_string(fin);
    this->name = this->load_sized_string(fin);
}

template <typename T>
void Drink::save_primitive_type(std::ofstream& fout, T& obj) {
    fout.write(reinterpret_cast<char *>(&obj), sizeof(T));
}

template <typename T>
T Drink::load_primitive_type(std::ifstream& fin) {
    T result;
    fin.read(reinterpret_cast<char *>(&result), sizeof(T));
    return result;
}

std::string Drink::load_sized_string(std::ifstream& fin) {
    size_t string_size;
    fin.read(reinterpret_cast<char *>(&string_size), sizeof(size_t));

    if (fin.tellg() < 0) {
        return std::string("");
    }

    char* string_buffer = new char[string_size + 1];
    string_buffer[string_size] = '\0';
    fin.read(string_buffer, string_size);

    std::string result = string(string_buffer);

    delete[] string_buffer;
    return result;
}

void Drink::save_sized_string(std::ofstream& fout, std::string& str) {
    size_t string_size = str.size();

    fout.write(reinterpret_cast<char *>(&string_size), sizeof(size_t));
    fout.write(const_cast<char *>(str.c_str()), string_size);
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
