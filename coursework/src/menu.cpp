#include <iostream>
#include <cstring>
#include <map>
#include <fstream>

#include "config.h"
#include "List.h"


class CStringComparator {
public:
    bool operator()(const char* first, const char* second) const {
        return std::strcmp(first, second) < 0;
    }
};


using CmdMap = std::map<const char*, void (*)(const char*), CStringComparator>;

List<Drink> list;

void help(const char* line) {
    std::cout
        << "help -- Prints the Help Message" << std::endl
        << "exit -- Exit" << std::endl
        << "load <filename> -- Loads objects from <filename> into the Drink" << std::endl
        << "save <filename> -- Saves the Drink in <filename>" << std::endl
        << "print -- Prints the Drink" << std::endl
        << "len -- Prints Drink length" << std::endl
        << "remove <name> -- Removes all occurrences of <name>" << std::endl
        << "search <name> -- Prints first occurrence of <name>" << std::endl
        << "add -- Adds a new object to the Drink" << std::endl;
}


void exit(const char* line) {
    std::exit(0);
}


void load(const char* line) {
    if (!std::strlen(line)) {
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


void save(const char* line) {
    if (!std::strlen(line)) {
        std::cout << "filename is required" << std::endl;
        return;
    }

    list.save_all(line);
}


void print(const char* line) {
    list.print_all();
}


void len(const char* line) {
    std::cout << list.get_length() << std::endl;
}


void remove_object(const char* line) {
    if (!std::strlen(line)) {
        std::cout << "filename is required" << std::endl;
        return;
    }

    if (std::strcmp(line, "*") == 0) {
        list.remove_all();
    } else {
        list.remove(line);
    }
}


void search(const char* line) {
    if (!std::strlen(line)) {
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


// void add(const char* line) {
//     Basedrink* drink;

//     char classname[MAX_STRING_LENGTH] = {};
//     char name[MAX_STRING_LENGTH] = {};
//     uint16_t level;
//     uint32_t hp;
//     uint32_t max_hp;
//     double gold;
//     std::cout << "Classname (Summoner, Attacker, Melee, Ranged): ";
//     std::cin.getline(classname, MAX_STRING_LENGTH);
//     std::cout << "name: ";
//     std::cin.getline(name, MAX_STRING_LENGTH);
//     std::cout << "level: ";
//     std::cin >> level;
//     std::cout << "hp: ";
//     std::cin >> hp;
//     std::cout << "max_hp: ";
//     std::cin >> max_hp;
//     std::cout << "gold: ";
//     std::cin >> gold;

//     if (std::strcmp(classname, "Attacker") == 0 || std::strcmp(classname, "Summoner") == 0) {
//         uint32_t mana;
//         uint32_t max_mana;
//         std::cout << "mana: ";
//         std::cin >> mana;
//         std::cout << "max_mana: ";
//         std::cin >> max_mana;

//         if (std::strcmp(classname, "Attacker") == 0) {
//             char spell[MAX_STRING_LENGTH];
//             std::cout << "spell: ";
//             clearcin();
//             std::cin.getline(spell, MAX_STRING_LENGTH);

//             drink = new Attacker(name, level, hp, max_hp, gold, mana, max_mana, spell);
//         } else {
//             char creature[MAX_STRING_LENGTH];
//             std::cout << "creature: ";
//             clearcin();
//             std::cin.getline(creature, MAX_STRING_LENGTH);

//             drink = new Summoner(name, level, hp, max_hp, gold, mana, max_mana, creature);
//         }
//     } else if (std::strcmp(classname, "Melee") == 0 || std::strcmp(classname, "Ranged") == 0) {
//         uint32_t strength;
//         std::cout << "strength: ";
//         std::cin >> strength;

//         if (std::strcmp(classname, "Melee") == 0) {
//             uint16_t attack_speed;
//             std::cout << "attack_speed: ";
//             std::cin >> attack_speed;

//             drink = new Melee(name, level, hp, max_hp, gold, strength, attack_speed);
//         } else {
//             float accuracy;
//             std::cout << "accuracy: ";
//             std::cin >> accuracy;

//             drink = new Ranged(name, level, hp, max_hp, gold, strength, accuracy);
//         }
//         clearcin();
//     } else {
//         std::cout << "Unknown class" << std::endl;
//     }
//     list.append(drink);
// }


void run_menu() {
    CmdMap commands;
    commands["help"] = help;
    commands["exit"] = exit;
    commands["print"] = print;
    commands["load"] = load;
    commands["save"] = save;
    // commands["remove"] = remove_object;
    // commands["search"] = search;
    // commands["add"] = add;
    // commands["len"] = len;
    std::cout << "Type `help` to get help" << std::endl;

    while (true) {
        char prompt[MAX_STRING_LENGTH] = {};
        std::cout << "Drink Manager$ ";
        std::cin.getline(prompt, MAX_STRING_LENGTH);

        if (std::cin.fail()) {
            std::cout << "ERROR!";
            break;
        }

        if (std::strlen(prompt) == 0) {
            continue;
        }

        char prompt_copy[MAX_STRING_LENGTH];
        std::strcpy(prompt_copy, prompt);
        const char* command = std::strtok(prompt_copy, word_sep);
        const char* line = prompt_copy + std::strlen(command) + 1;

        if (commands.find(command) == commands.end()) {
            std::system(prompt);
            continue;
        }

        commands[command](line);
    }
}
