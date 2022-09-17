#ifndef COFFEE_H_INCLUDED
#define COFFEE_H_INCLUDED

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <list>
#include <windows.h>
#include "main.h"

using namespace std;


class Coffee : public Hot{
private:
 string preimushestva;
 bool kakGotovit;
public:
 void SetVchemPreimushestva(string pr);

string GetVchemPreimushestva();

    void SetKakGotovyat(bool kG);

    bool GetKakGotovyat();

};

#endif // COFFEE_H_INCLUDED
