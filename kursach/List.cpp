#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <windows.h>
#include "List.h"
#include <stdio.h>
#include <cmath>
#include <ctime>
#include "main.h"

using namespace std;



List::List(){
    head = NULL;
            }

void List::addNode(int d)
    {
        Node *nd = new Node();
        nd->data = d;
        nd->next = head;
        head = nd;
    }

void List::printList(string nm1)
    {
         cout<<"-----------"<<endl;
Node *current = head;
        while(current)
        {
            cout << current->data << endl;
            current = current->next;
        }
        cout<< nm1<<endl;
        cout<<"-----------"<<endl;
    }

void List::SaveList(string nm1){
Node *current = head;
        while(current)
        {

         ifstream file("list.txt");
         if(file.is_open()){
          ofstream out("list.txt",ios::app);
          out<<current->data<<"\n";
          current = current->next;
          out.close();
         }else{
         ofstream out;
         out.open("list.txt");
         out<<current->data<<"\n";
         current = current->next;
         out.close();
         }

}

ifstream fl("list.txt");
         if(fl.is_open()){
         ofstream ot("list.txt",ios::app);
         ot<<nm1<<"\n";
         ot<<"------------------\n";
         ot.close();
        }
        cout<< nm1<<endl;

}

void List::ReadList(){

       int m;
       int n;

       m=0;

       cout <<"*****************"<< endl;
       string line;
       ifstream llsstt ("list.txt");
       if (llsstt.is_open())
       {
       while (! llsstt.eof() )
       {
         if((m%4)==0){
        cout<<"������ ����� "<<m/4<<endl;
        cout <<"------------------"<< endl;
        }
       getline (llsstt,line);
       cout << line << endl;
       m++;

       }
       llsstt.close();
       }

       m=0;
       n=0;

       int number1;
       int number2;

       cout <<"������� ����� ������"<< endl;
       cin>>n;

       cout<<"*****************"<<endl;
       string line1;
       string line2;
       ifstream lost ("list.txt");
       if (lost.is_open())
       {
       while (! lost.eof() )
       {
         if((((m-1)%4)==0)&(((m-1)/4)==n)){
        getline (lost,line1);
        cout<<line1<<endl;
        number1=atoi(line1.c_str());
        cout<<"������ ��������� "<<number1<<endl;
        }
        if((((m-2)%4)==0)&(((m-2)/4)==n)){
        getline (lost,line2);
        cout<<line2<<endl;
        number2=atoi(line2.c_str());
        cout<<"������ ��������� "<<number2<<endl;
        break;
        }
       m++;

       }
       lost.close();
       }
       cout<<"*****************"<<endl;

       cout<<"������ ����� � ������"<<endl;

       cout<<"������ �������"<<endl;

       addNode(number1);

       cout<<"������ �������"<<endl;

       addNode(number2);

       string nm="����� �������";

       printList(nm);

}



void List::RedactList(){
   cout<<"������� ��������:"<<endl;
   cout<<"1-������� ������� , 2-�������� �������"<<endl;
   cout<<"11-���� , 12-��� , 21-������� ,22-����" <<endl;


  ReadList();

    Node *lt = head;
    head = lt->next;

    string good = "success";

    cout<<"������� ����� ��������� �������"<<endl;
    int nr;
    cin>>nr;
    addNode(nr);
    printList(good);


    cout<<"������� ����� �������� �������"<<endl;
    int ce;
    cin>>ce;

    Node *nt= head;
    nt->next=NULL;

    Node *ntf= new Node;
    ntf->data=ce;
    ntf->next=NULL;
    nt->next=ntf;


    printList(good);

    cin.clear();
    cin.ignore();

    getline(cin,good);

    SaveList(good);



}

 void List::GetDate(int a){

cout<<"������"<<endl;

}

void List::GetDate(){
    SYSTEMTIME st;
    GetSystemTime(&st);
    time_t rawtime;
    cout<<st.wDay<<"."<<st.wMonth<<"."<<st.wYear<<endl;
    };

