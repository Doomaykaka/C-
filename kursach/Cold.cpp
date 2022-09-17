#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <list>
#include <windows.h>
#include "main.h"

using namespace std;



    void Cold::SetWhenDrink(int t){
    tod=t;
    tod=2;
    }

    int Cold::GetWhenDrink(){
    return(tod);
    }

    void Cold::SetKakPodayut(string ps){
    posuda=ps;
    posuda="в стаканах";
    }

    string Cold::GetKakPodayut(){
    return(posuda);
    }

    void Cold::SetKakoyVkus(int vk){
    vkus=vk;
    cout << "Какой вкус у напитка? (1-нет ,2-сладко-кислый)" << endl;
    cin>>vkus;
    }

    int Cold::GetKakoyVkus(){
    return(vkus);
    }

    void Cold::SetGotovka(bool gt){
    got=gt;
    cout << "Требуется-ли готовка? (0-нет ,1-да)" << endl;
    cin>>got;
    }

    bool Cold::GetGotovka(){
    return(got);
    }
