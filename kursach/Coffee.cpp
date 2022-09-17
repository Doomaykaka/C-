
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <list>
#include <windows.h>
#include "main.h"

using namespace std;



 void Coffee::SetVchemPreimushestva(string pr){
    preimushestva=pr;
    preimushestva="неповторимый аромат";
    }

string Coffee::GetVchemPreimushestva(){
    return(preimushestva);
}

    void Coffee::SetKakGotovyat(bool kG){
    kakGotovit=kG;
    kakGotovit=true;
    }

    bool Coffee::GetKakGotovyat(){
    return(kakGotovit);
    }


