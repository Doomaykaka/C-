#ifndef HOT_H_INCLUDED
#define HOT_H_INCLUDED

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <list>
#include <windows.h>
#include "main.h"

using namespace std;



class Hot : public Drinks{
 private:
     int tod;
     string posuda;
     string preimushestva;
     bool kakGotovit;
 public:


    void SetWhenDrink(int t);

    int GetWhenDrink();


    void SetKakPodayut(string ps);

    string GetKakPodayut();

    void SetVchemPreimushestva(string pr);

    string GetVchemPreimushestva();

    void SetKakGotovyat(bool kG);

    bool GetKakGotovyat();
};

#endif // HOT_H_INCLUDED
