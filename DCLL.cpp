#include <iostream>
using namespace std;
template <typename T>
class Dnode
{
public:
    T data;
    Dnode<T> *next;
    Dnode<T> *previous;

    Dnode()
    {
        data = 0;
        next = NULL;
        previous = NULL;
    }

    Dnode(T val)
    {
        data = val;
        next = 0;
        previous = 0;
    }
};
template <typename T>

class CDLinkedList
{

private:
    Dnode<T> *head;

public:
    CDLinkedList()
    {
        head = NULL;
    }

    void insertAtHead(T val)
    {
        if (!head)
        {
            Dnode<T> *newnode = new Dnode<T>(val);
            newnode->next = newnode;
            newnode->previous = newnode;
            head = newnode;
            return;
        }

        Dnode<T> *newnode = new Dnode<T>(val);
        newnode->next = head;
        newnode->previous = head->previous;
        head->previous->next = newnode;
        head->previous = newnode;

        head = newnode;
    }

    void insertAtTail(T val)
    {
        if (!head)
        {
            Dnode<T> *newnode = new Dnode<T>(val);
            newnode->next = newnode;
            newnode->previous = newnode;
            head = newnode;
            return;
        }

        Dnode<T> *last = head->previous;

        Dnode<T> *newnode = new Dnode<T>(val);
        newnode->next = head;
        newnode->previous = last;

        last->next = newnode;
        head->previous = newnode;
    }

    void removeAtHead()
    {
        if (!head)
        {
            cout << "List is empty..";
            return;
        }
        if (head->next == head)
        {
            delete head;
            head = nullptr;
            return;
        }

        Dnode<T> *todelete = head;
        Dnode<T> *last = head->previous;
        head = head->next;
        last->next = head;
        head->previous = last;

        delete todelete;
    }

    void removAtTail()
    {
        if (!head)
        {
            cout << "List is empty..";
            return;
        }
        if (head->next == head)
        {
            delete head;
            head = nullptr;
            return;
        }

        Dnode<T> *last = head->previous;
        Dnode<T> *todelete = last;
        last = last->previous;
        last->next = head;
        head->previous = last;

        delete todelete;
    }

    void remove(T val)
    {
        if (!head)
        {
            cout << "List is empty..";
            return;
        }
        if (head->next == head && head->data == val)
        {
            Dnode<T> *todelete = head;
            Dnode<T> *last = head->previous;
            head = head->next;
            last->next = head;
            head->previous = last;

            delete todelete;
            return;
        }

        Dnode<T> *temp = head;
        while (temp->next != head)
        {
            if (temp->data == val)
            {
                Dnode<T> *todelete = temp;
                temp->next->previous = temp->previous;
                temp->previous->next = temp->next;
                delete todelete;
                return;
            }
            temp = temp->next;
        }
        cout << "Value not Found in the list";
    }

    bool search(int key)
    {
        if (!head)
        {

            return false;
        }

        Dnode<T> *temp = head;
        do
        {
            if (temp->data == key)
            {
                return true;
            }
            temp = temp->next;

        } while (temp != head);

        return false;
    }

    void update(int key, T val)
    {
        if (!head)
        {
            cout << "List is empty..";
            return;
        }
        Dnode<T> *temp = head;
        int count = 0;
        do
        {
            count++;

            temp = temp->next;

        } while (temp != head);

        if (key < 0 || key > count)
        {
            cout << "Invalid";
            return;
        }

        temp = head;
        if (count >= key)
        {

            for (int i = 0; i < key; i++)
            {
                temp = temp->next;
            }

            temp->data = val;
            return;
        }
    }

    int countnodes()
    {
        int count = 0;
        Dnode<T> *temp = head;
        if (head == nullptr)
        {
            return 0;
        }

        do
        {
            count++;

            temp = temp->next;

        } while (temp != head);
        return count;
    }

    ~CDLinkedList()
    {
        if (!head)
            return;

        Dnode<T> *curr = head->next;

        while (curr != head)
        {
            Dnode<T> *nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }

        delete head;
        head = nullptr;
    }

    // Provide limited accessors so external functions (like merge) can operate
    // without exposing the internal pointer as public state.
    Dnode<T> *getHead()
    {
        return head;
    }

    void setHead(Dnode<T> *h)
    {
        head = h;
    }

    /* bool hasDuplicates()
     {
         if (head == 0)
             return false;
         if (!head->next)
             return false;

         DNode<T> *temp1 = head;
         DNode<T> *temp2 = head->next;
         while (temp1->next != head)
         {

             while (temp2 != head)
             {
                 if (temp2->data == temp1->data)
                 {
                     return true;
                 }
                 temp2 = temp2->next;
             }

             temp1 = temp1->next;
             temp2 = temp1->next;
         }

         return false;
     }
 */

    void combine(CDLinkedList<int> &other)
    {
        if (other.head == nullptr)
        {
            return;
        }

        if (head == nullptr)
        {

            head = other.head;
            other.head = nullptr;
            return;
        }

        Dnode<int> *tail = head;
        while (tail->next != head)
        {
            tail = tail->next;
        }

        Dnode<int> *last = head->previous;
        last->next = other.head;
        Dnode<int> *otherlast = other.head->previous;
        other.head->previous = last;

        otherlast->next = head;
        head->previous = otherlast;

        tail->next = other.head;
        other.head = nullptr;

        while(head->next!=head)
        {
            if(head->data > head->next->data)
            {
                 Dnode<int>*temp3=head;
                temp3->data= head->data;
                head->data=head->next->data;
                head->next->data= temp3->data; 

            }
            head=head->next;
        }
        return ;
    }

   

    void display()
    {
        Dnode<int> *dis = head;

        do
        {
            cout << dis->data << " ";

            dis = dis->next;

        } while (dis != head);
    }

    void splitlist(CDLinkedList &list1, CDLinkedList &list2)
{
    if (!head || head->next == head)
        return; 

    int total = countnodes();
    int half = total / 2;
    if (total % 2 != 0)
        half++;

    Dnode<int>* curr = head;

    
    for (int i = 1; i < half; i++)
        curr = curr->next;

    Dnode<int>* head2 = curr->next;

    
    curr->next = head;
    head->previous = curr;

    Dnode<int>* tail2 = head2;
    while (tail2->next != head)
        tail2 = tail2->next;

    tail2->next = head2;
    head2->previous = tail2;

   
    list1.head = head;
    list2.head = head2;
}

};

int main()
{
    CDLinkedList<int> list1;
   

    CDLinkedList<int> list3;
    list3.insertAtTail(1);
    list3.insertAtTail(3);
    list3.insertAtTail(6);
    list3.insertAtTail(8);
    list3.insertAtTail(9);
    list3.insertAtTail(15);
    list3.insertAtTail(16);

    CDLinkedList<int>list2;
    list3.splitlist(list1,list2);
    list1.display();
    cout<<endl;
    list2.display();

   
  

    cout<<endl;
    
  
    
    

    return 0;
}
