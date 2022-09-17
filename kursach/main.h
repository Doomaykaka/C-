#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED


#include "List.h"
 void addNode(int d);
 void printList(string nm1);
 void SaveList(string nm1);
 void ReadList();
 void RedactList();
 void GetDate(int a);
 void GetDate();

#include "Drinks.h"
void SetTimeOfDrink(int td);
int GetTimeOfDrink();
void SetVChemPodayut(string psd);
string GetVChemPodayut();


#include "Hot.h"
void SetWhenDrink(int t);
int GetWhenDrink();
void SetKakPodayut(string ps);
string GetKakPodayut();

#include "Cold.h"
void SetWhenDrink(int t);
int GetWhenDrink();
void SetKakPodayut(string ps);
string GetKakPodayut();
void SetKakoyVkus(int vk);
int GetKakoyVkus();
void SetGotovka(bool gt);
bool GetGotovka();

#include "Other.h"
void SetPodacha(int Podacha);

#include "Tea.h"
void SetVchemPreimushestva(string pr);
string GetVchemPreimushestva();
void SetKakGotovyat(bool kG);
bool GetKakGotovyat();

#include "Coffee.h"
void SetVchemPreimushestva(string pr);
string GetVchemPreimushestva();
void SetKakGotovyat(bool kG);
bool GetKakGotovyat();

#include "Lemonade.h"
void SetKakoyVkus(int vk);
int GetKakoyVkus();
void SetGotovka(bool gt);
bool GetGotovka();

#include "Water.h"
void SetKakoyVkus(int vk);
int GetKakoyVkus();
void SetGotovka(bool gt);
bool GetGotovka();

#endif // MAIN_H_INCLUDED
