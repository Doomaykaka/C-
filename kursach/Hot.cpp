#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <list>
#include <windows.h>
#include "main.h"

using namespace std;




    void Hot::SetWhenDrink(int t){
    t=tod;
    tod=1;
    }

    int Hot::GetWhenDrink(){
    return(tod);
    }


    void Hot::SetKakPodayut(string ps){
    posuda=ps;
    posuda="� �������";
    }

    string Hot::GetKakPodayut(){
    return(posuda);
    }

    void Hot::SetVchemPreimushestva(string pr){
    preimushestva=pr;
    cout << "� ��� ������������ �������? (�������� , ������������ ������)" << endl;
    getline(cin,preimushestva);
    }

    string Hot::GetVchemPreimushestva(){
    return(preimushestva);
    }

    void Hot::SetKakGotovyat(bool kG){
    kakGotovit=kG;
    cout << "� ����� ������ ������� �������? (0-���������� ������ ,1-�����)" << endl;
    cin>>kakGotovit;
    }

     bool Hot::GetKakGotovyat(){
     return(kakGotovit);
     }
