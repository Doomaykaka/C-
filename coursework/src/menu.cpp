#include <iostream>
#include <cstring>
#include <map>
#include <fstream>

#include "config.h"
#include "List.h"

#include "Hot.h"
#include "Coffee.h"
#include "Tea.h"
#include "Cold.h"
#include "Lemonade.h"
#include "Water.h"
#include "Other.h"



using CmdMap = std::map<string, void (*)(string)>;

List<Drink> list;

void help(string line) {
    std::cout
        << "🆘 help ................ Prints the Help Message" << std::endl
        << "📴 exit ................ Exit" << std::endl
        << "🔼 load ... <filename> . Loads objects from <filename> into the Drink" << std::endl
        << "🔽 save ... <filename> . Saves the Drink in <filename>" << std::endl
        << "🖨️ print ............... Prints the Drink" << std::endl
        << "📏 len ................. Prints Drink length" << std::endl
        << "🗑️ remove . <name> ..... Removes all occurrences of <name>" << std::endl
        << "🔍 search . <name> ..... Prints first occurrence of <name>" << std::endl
        << "➕ add ................. Adds a new object to the Drink" << std::endl;
}


void exit(string line) {
    std::exit(0);
}


void load(string line) {
    if (!line.length()) {
        std::cout << "filename is required" << std::endl;
        return;
    }
    std::ifstream fin(line);
    if (!fin.good()) {
        std::cout << "Can't open `" << line << "`" << std::endl;
        return;
    }
    fin.close();

    list.load_from(line);
}


void save(string line) {
    if (!line.length()) {
        std::cout << "filename is required" << std::endl;
        return;
    }

    list.save_all(line);
}


void print(string line) {
    list.print_all();
}


void len(string line) {
    std::cout << list.get_length() << std::endl;
}


void remove_object(string line) {
    if (!line.length()) {
        std::cout << "filename is required" << std::endl;
        return;
    }

    if (line == "*") {
        list.remove_all();
    } else {
        list.remove(line);
    }
}


void search(string line) {
    if (!line.length()) {
        std::cout << "filename is required" << std::endl;
        return;
    }

    Drink* drink = list.search(line);
    if (drink == nullptr) {
        std::cout << "Drink is not found" << std::endl;
    } else {
        // std::cout << *drink;
    }
}


void add(string line) {
    int drinking_time;
    string dishes;
    string name;

    std::string classname;
    std::cout << "Classname (Drink, Hot, Coffee, Tea, Cold, Lemonade, Water, Other): ";
    std::cin >> classname;

    std::cout << "name: ";
    std::cin >> name;
    std::cout << "drinking time: ";
    std::cin >> drinking_time;
    std::cout << "dishes: ";
    std::cin >> dishes;

    if (classname == "Drink") {
        Drink* drink = new Drink();

        drink->set_name(name);
        drink->set_dishes(dishes);
        drink->set_drinking_time(drinking_time);

        list.append(drink);
    } else if (classname == "Hot") {
        int degree_of_taste;
        bool readiness;

        std::cout << "degree of taste: ";
        std::cin >> degree_of_taste;
        std::cout << "readiness: ";
        std::cin >> readiness;

        Hot* hot = new Hot();

        hot->set_name(name);
        hot->set_dishes(dishes);
        hot->set_drinking_time(drinking_time);
        hot->set_degree_of_taste(degree_of_taste);
        hot->set_readiness(readiness);

        list.append(hot);
    } else if (classname == "Coffee") {
        string advantages;
        bool is_cooking_method_traditional;
        int degree_of_taste;
        bool readiness;

        std::cout << "degree of taste: ";
        std::cin >> degree_of_taste;
        std::cout << "readiness: ";
        std::cin >> readiness;
        std::cout << "advantages: ";
        std::cin >> advantages;
        std::cout << "is cooking method traditional: ";
        std::cin >> is_cooking_method_traditional;

        Coffee* coffee = new Coffee();

        coffee->set_name(name);
        coffee->set_dishes(dishes);
        coffee->set_drinking_time(drinking_time);
        coffee->set_degree_of_taste(degree_of_taste);
        coffee->set_readiness(readiness);
        coffee->set_advantages(advantages);
        coffee->set_is_cooking_method_traditional(is_cooking_method_traditional);

        list.append(coffee);
    } else if (classname == "Tea") {
        int degree_of_taste;
        bool readiness;
        string advantages;
        bool is_cooking_method_traditional;

        std::cout << "degree of taste: ";
        std::cin >> degree_of_taste;
        std::cout << "readiness: ";
        std::cin >> readiness;
        std::cout << "advantages: ";
        std::cin >> advantages;
        std::cout << "is cooking method traditional: ";
        std::cin >> is_cooking_method_traditional;

        Tea* tea = new Tea();

        tea->set_name(name);
        tea->set_dishes(dishes);
        tea->set_drinking_time(drinking_time);
        tea->set_degree_of_taste(degree_of_taste);
        tea->set_readiness(readiness);
        tea->set_advantages(advantages);
        tea->set_is_cooking_method_traditional(is_cooking_method_traditional);

        list.append(tea);
    } else if (classname == "Cold") {
        bool readiness;

        std::cout << "readiness: ";
        std::cin >> readiness;

        Cold* cold = new Cold();

        cold->set_name(name);
        cold->set_dishes(dishes);
        cold->set_drinking_time(drinking_time);
        cold->set_readiness(readiness);

        list.append(cold);
    } else if (classname == "Lemonade") {
        int degree_of_taste;
        bool readiness;

        std::cout << "degree of taste: ";
        std::cin >> degree_of_taste;
        std::cout << "readiness: ";
        std::cin >> readiness;

        Lemonade* lemonade = new Lemonade();

        lemonade->set_name(name);
        lemonade->set_dishes(dishes);
        lemonade->set_drinking_time(drinking_time);
        lemonade->set_degree_of_taste(degree_of_taste);
        lemonade->set_readiness(readiness);

        list.append(lemonade);
    } else if (classname == "Water") {
        int color;
        bool readiness;

        std::cout << "color: ";
        std::cin >> color;
        std::cout << "readiness: ";
        std::cin >> readiness;


        Water* water = new Water();

        water->set_name(name);
        water->set_dishes(dishes);
        water->set_drinking_time(drinking_time);
        water->set_color(color);
        water->set_readiness(readiness);

        list.append(water);
    } else if (classname == "Other") {
        int degree_of_taste;

        std::cout << "degree of taste: ";
        std::cin >> degree_of_taste;

        Other* other = new Other();

        other->set_name(name);
        other->set_dishes(dishes);
        other->set_drinking_time(drinking_time);
        other->set_degree_of_taste(degree_of_taste);

        list.append(other);
    } else {
        std::cout << "Unknown class" << std::endl;
    }
}


void run_menu() {
    CmdMap commands;
    commands["help"] = help;
    commands["exit"] = exit;
    commands["print"] = print;
    commands["load"] = load;
    commands["save"] = save;
    commands["remove"] = remove_object;
    commands["search"] = search;
    commands["add"] = add;
    commands["len"] = len;
    std::cout << "Type `help` to get help" << std::endl;

    while (true) {
        char prompt[MAX_STRING_LENGTH] = {};
        std::cout << "Drink Manager$ ";
        std::cin.getline(prompt, MAX_STRING_LENGTH);

        if (std::cin.fail()) {
            std::cout << "ERROR!" << std::endl;
            break;
        }

        if (std::strlen(prompt) == 0) {
            continue;
        }

        char prompt_copy[MAX_STRING_LENGTH];
        std::strcpy(prompt_copy, prompt);
        string command = std::strtok(prompt_copy, word_sep);
        string line = prompt_copy + command.length() + 1;

        if (commands.find(command) == commands.end()) {
            std::system(prompt);
            continue;
        }

        commands[command](line);
    }
}
