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
    posuda="� ��������";
    }

    string Cold::GetKakPodayut(){
    return(posuda);
    }

    void Cold::SetKakoyVkus(int vk){
    vkus=vk;
    cout << "����� ���� � �������? (1-��� ,2-������-������)" << endl;
    cin>>vkus;
    }

    int Cold::GetKakoyVkus(){
    return(vkus);
    }

    void Cold::SetGotovka(bool gt){
    got=gt;
    cout << "���������-�� �������? (0-��� ,1-��)" << endl;
    cin>>got;
    }

    bool Cold::GetGotovka(){
    return(got);
    }
