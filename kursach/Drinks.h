#ifndef DRINKS_H_INCLUDED
#define DRINKS_H_INCLUDED

using namespace std;

class Drinks : public List{
private:
    int tod;
    string posuda;
public:

   void SetTimeOfDrink(int td);

  int GetTimeOfDrink();

    void SetVChemPodayut(string psd);

    string GetVChemPodayut();

};

#endif // DRINKS_H_INCLUDED
