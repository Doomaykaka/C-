
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <list>
#include <windows.h>
#include "main.h"

using namespace std;



   void Tea::SetVchemPreimushestva(string pr){
    preimushestva=pr;
    preimushestva="освежает";

    }

    string Tea::GetVchemPreimushestva(){
      return(preimushestva);
    }

    void Tea::SetKakGotovyat(bool kG){
    kakGotovit=kG;
    kakGotovit=false;
    }

    bool Tea::GetKakGotovyat(){
    return(kakGotovit);
    }


