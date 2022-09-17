#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

using namespace std;

struct Node
{
    int data;
    Node *next;
};
class List
{
private:
    Node *head;
public:
    List();

    void addNode(int d);

    void printList(string nm1);

    void SaveList(string nm1);

    void ReadList();

    void RedactList();

    void GetDate(int a);

    void GetDate();

};


#endif // LIST_H_INCLUDED
