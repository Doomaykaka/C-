#ifndef WATER_H_INCLUDED
#define WATER_H_INCLUDED

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <list>
#include <windows.h>
#include "main.h"

using namespace std;


class Water : public Cold{
private:
 int vkus;
 bool got;
public:
     void SetKakoyVkus(int vk);

    int GetKakoyVkus();

    void SetGotovka(bool gt);

    bool GetGotovka();

};


#endif // WATER_H_INCLUDED
