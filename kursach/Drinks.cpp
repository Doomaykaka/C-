#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <list>
#include <windows.h>
#include "main.h"
#include <ctime>

using namespace std;



   void Drinks::SetTimeOfDrink(int td){
    tod=td;
    cout << "� ����� ������ ��� ����? (1-� �������� , 2-� ������)" << endl;
    cin>>tod;
    }

   int Drinks::GetTimeOfDrink(){
   return(tod);
   }

    void Drinks::SetVChemPodayut(string psd){
    posuda=psd;
    cin.get();
    cout << "� ��� ��� ����? (� ������� ,� ��������)" << endl;
    getline(cin,posuda);
    }

    string Drinks::GetVChemPodayut(){
    return (posuda);
    }


