#ifndef COLD_H_INCLUDED
#define COLD_H_INCLUDED

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <list>
#include <windows.h>
#include "main.h"

using namespace std;


class Cold : public Drinks{
private:
 int tod;
 string posuda;
 int vkus;
 bool got;
 public:

    void SetWhenDrink(int t);

    int GetWhenDrink();

    void SetKakPodayut(string ps);

    string GetKakPodayut();

    void SetKakoyVkus(int vk);

    int GetKakoyVkus();

    void SetGotovka(bool gt);

    bool GetGotovka();
};

#endif // COLD_H_INCLUDED
