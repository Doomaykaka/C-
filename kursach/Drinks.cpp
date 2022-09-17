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
    cout << "В какую погоду его пьют? (1-в холодную , 2-в жаркую)" << endl;
    cin>>tod;
    }

   int Drinks::GetTimeOfDrink(){
   return(tod);
   }

    void Drinks::SetVChemPodayut(string psd){
    posuda=psd;
    cin.get();
    cout << "В чём его пьют? (в кружках ,в стаканах)" << endl;
    getline(cin,posuda);
    }

    string Drinks::GetVChemPodayut(){
    return (posuda);
    }


