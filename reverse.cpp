//task03
#include <iostream>
#include "LSLL.cpp"
#include <stdexcept>

void reverselist(node<int>*&head)
{
    node<int> *pre= NULL;
    node<int> *curr= head;
    while(curr!=NULL)
    {
        node<int>*forward= curr->next;
        curr->next=pre;
        pre=curr;
        curr = forward;
    }
    head=pre;
}

 void display(node<int>* head)
    {
        node<int> *dis=head;
        while(dis!=NULL)
        {
            cout<<dis->info<<" ";
            dis=dis->next;
        }
    }

using namespace std;

int main()
{
   node<int>* head = new node<int>(10);
    head->next = new node<int>(1);
    head->next->next = new node<int>(20);
    head->next->next->next = new node<int>(10);
    head->next->next->next->next = new node<int>(11);
    cout<<"Original list is :";
      display(head);
     reverselist(head);
     cout<<endl;
     cout<<"Reverse list is : ";

      display(head);


    return 0;
}