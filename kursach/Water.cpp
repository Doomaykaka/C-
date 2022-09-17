#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <list>
#include <windows.h>
#include "main.h"

using namespace std;



     void Water::SetKakoyVkus(int vk){
    vkus=vk;
    vkus=1;
    }

    int Water::GetKakoyVkus(){
    return(vkus);
    }

    void Water::SetGotovka(bool gt){
    got=gt;
    got=false;
    }

    bool Water::GetGotovka(){
    return(got);
    }

