#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <list>
#include <windows.h>
#include "main.h"

using namespace std;


      void Lemonade::SetKakoyVkus(int vk){
    vkus=vk;
    vkus=2;
    }

     int Lemonade::GetKakoyVkus(){
    return(vkus);
     }

    void Lemonade::SetGotovka(bool gt){
    got=gt;
    got=true;
    }

    bool Lemonade::GetGotovka(){
    return(got);
    }

