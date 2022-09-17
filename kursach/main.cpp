#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <list>
#include <windows.h>
#include "main.h"
#include <fstream>
#include <time.h>
#include <stdio.h>

using namespace std;

template<class Type>
Type _min(Type hell) {
    hell="ѕри¤тного использовани¤";
    return hell;
}

class abst{
public:
    virtual void GetTime(){
    cout<<"error"<<endl;
    }
    virtual ~abst(){}
};

class example : public abst{
public:
    void GetTime(){
    SYSTEMTIME st;
    GetLocalTime(&st);
    time_t rawtime;
    cout<<st.wHour<<":"<<st.wMinute<<endl;
    }
    virtual ~example(){}
};

int main()
{
     srand(time(NULL));
    setlocale(LC_ALL,"");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int rez;
    cout << "«драствуйте" << endl;
    List lis ;
    lis.GetDate();
    abst *abst = new example;
    abst->GetTime();
    delete abst;
    string hle;
    cout<<_min<string>(hle)<<endl;
    cout << "¬ыберите режим (0- посититель , 1- работник)" << endl;
    cin>>rez;
    if(rez==0){
    cout << "лист:" << endl;
    cout << " " << endl;
    ifstream G("log.txt");
    string sb;
    while(getline(G,sb)){
        cout << sb << endl;
    }
    G.close();
    cout << " " << endl;
    int pdh;
    Other oth;
    oth.SetPodacha(pdh);
    }else{
    if(rez==1){
     cout << "введите пароль" << endl;
     cout << "451" << endl;
     int pss;
     cin>>pss;
     if(pss==451){
            int lever;
        cout << "вы вошли в систему" << endl;
        cout <<"команды :"<<endl;
        cout <<"1- статистика"<<endl;
        cout <<"2- редактирование позиций"<<endl;
        cout <<"3- добавление новых позиций"<<endl;
        cin>>lever;
        if(lever==1){
    cout << " " << endl;
    ifstream N("list.txt");
    string sn;
    while(getline(N,sn)){
        cout << sn << endl;
    }
    N.close();
    cout << " " << endl;
        }
        if(lever==2){
          int lever2;
          cout <<"редактирование :"<<endl;
          cout <<"1- считать список из файла"<<endl;
          cout <<"2- редактировать список"<<endl;
          cin>>lever2;
        if(lever2==1){
            List lst;
            lst.ReadList();
        }

        if(lever2==2){
            List lsto;
            lsto.RedactList();
        }

        }
        if(lever==3){




    int tod=0;
    string posuda ;

    Drinks dr;


    dr.SetTimeOfDrink(tod);
   tod = dr.GetTimeOfDrink();

    dr.SetVChemPodayut(posuda);
    posuda = dr.GetVChemPodayut();

    Hot ht;
    ht.SetWhenDrink(tod);
    int td = ht.GetWhenDrink();
    ht.SetKakPodayut(posuda);
    string ps = ht.GetKakPodayut();



    if((tod==td)&&(posuda==ps)){



       cout <<"¬ам подойдет гор¤чий напиток"<<endl;
       dr.addNode(1);

       Hot ht;

        string preimushestva;
        bool kakGotovit;

        ht.SetVchemPreimushestva(preimushestva);
        preimushestva = ht.GetVchemPreimushestva();
        ht.SetKakGotovyat(kakGotovit);
        kakGotovit = ht.GetKakGotovyat();


        Tea t;
        t.SetVchemPreimushestva(preimushestva);
        string pr = t.GetVchemPreimushestva();
        t.SetKakGotovyat(kakGotovit);
        bool kg = t.GetKakGotovyat();

        if((preimushestva==pr)&&(kakGotovit==kg)){
         cout <<"¬ам подойдет чай"<<endl;
         dr.addNode(12);



         cin.clear();
         cin.ignore();
         string nm1;
         cout<<"введите название"<<endl;
         getline(cin,nm1);
         ifstream file("log.txt");
         if(file.is_open()){
          ofstream out("log.txt",ios::app);
          out<<"чай "<<nm1<<"\n";
          out.close();
         }else{
         ofstream out;
         out.open("log.txt");
         out<<"чай "<<nm1<<"\n";
         out.close();
         }
          dr.printList(nm1);
          dr.SaveList(nm1);

        }


        Coffee c;
        c.SetVchemPreimushestva(preimushestva);
        string pre = c.GetVchemPreimushestva();
        c.SetKakGotovyat(kakGotovit);
        bool kag = c.GetKakGotovyat();

        if((preimushestva==pre)&&(kakGotovit==kag)){
         cout <<"¬ам подойдет кофе"<<endl;
         dr.addNode(11);


           cin.clear();
         cin.ignore();
         string nm1;
         cout<<"введите название"<<endl;
         getline(cin,nm1);
         ifstream file("log.txt");
         if(file.is_open()){
          ofstream out("log.txt",ios::app);
          out<<"кофе "<<nm1<<"\n";
          out.close();
         }else{
         ofstream out;
         out.open("log.txt");
         out<<"кофе "<<nm1<<"\n";
         out.close();
         }
          dr.SaveList(nm1);
          dr.printList(nm1);
      }
    }


    Cold cd;

    cd.SetWhenDrink(tod);
    int wd = cd.GetWhenDrink();
    cd.SetKakPodayut(posuda);
    string kp = cd.GetKakPodayut();

    if((tod==wd)&&(posuda==kp)){

    cout <<"¬ам подойдет холодный напиток"<<endl;
       dr.addNode(2);

        Cold cd;

        int vkus;
        bool got;

        cd.SetKakoyVkus(vkus);
        vkus=cd.GetKakoyVkus();
        cd.SetGotovka(got);
        got=cd.GetGotovka();

        Water wt;

        wt.SetKakoyVkus(vkus);
        int vk = wt.GetKakoyVkus();
        wt.SetGotovka(got);
        int gt = wt.GetGotovka();

        if((vkus==vk)&&(got==gt)){
          cout <<"¬ам подойдет вода"<<endl;
          dr.addNode(22);

          cin.clear();
         cin.ignore();
         string nm1;
         cout<<"введите название"<<endl;
         getline(cin,nm1);
         ifstream file("log.txt");
         if(file.is_open()){
          ofstream out("log.txt",ios::app);
          out<<"вода "<<nm1<<"\n";
          out.close();
         }else{
         ofstream out;
         out.open("log.txt");
         out<<"вода "<<nm1<<"\n";
         out.close();
         }
         dr.SaveList(nm1);
         dr.printList(nm1);
        }
        Lemonade ld;

        ld.SetKakoyVkus(vkus);
        int kv = ld.GetKakoyVkus();
        ld.SetGotovka(got);
        int go = ld.GetGotovka();

        if((vkus==kv)&&(got==go)){
          cout <<"¬ам подойдет лимонад"<<endl;
          dr.addNode(21);

          cin.clear();
         cin.ignore();
         string nm1;
         cout<<"введите название"<<endl;
         getline(cin,nm1);
         ifstream file("log.txt");
         if(file.is_open()){
          ofstream out("log.txt",ios::app);
          out<<"лимонад "<<nm1<<"\n";
          out.close();
         }else{
         ofstream out;
         out.open("log.txt");
         out<<"лимонад "<<nm1<<"\n";
         out.close();
         }
             dr.SaveList(nm1);
             dr.printList(nm1);
           }

    }
     }else{
         if((lever!=1)&(lever!=2)&(lever!=3)){
    cout << "вы неверно ввели параметр" << endl;
         }
     }
     }else{
        cout << "неверный пароль" << endl;
     }
    }else{
    cout << "вы неверно ввели параметр" << endl;
    }
    }


    return 0;
}
