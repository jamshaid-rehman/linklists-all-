#include <iostream>
#include <string>
#include <array>
using namespace std;
template <typename T>

class node
{
public:
    T info;
    node<T> *next;

    node()
    {
        info = 0;
        next = NULL;
    }
    node(T val)
    {
        info = val;
        next = 0;
    }
};

template <typename T>
class LSLL
{
private:
    node<T> *head;

public:
    LSLL()
    {
        head = NULL;
    }
    void insertAtHead(T val)
    {
        node<T> *temp = new node<T>(val);

        if (!head)
        {
            head = temp;
            return;
        }

        temp->next = head;
        head = temp;
    }

    void insertAtTail(T val)
    {
        node<T> *n = new node<T>(val);
        if (!head)
        {
            head = n;
            return;
        }
        else
        {

            node<T> *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = n;
        }
    }

    void insertafterkey(T key, T val)
    {
        if (!head)
        {
            cout << "List is empty. Cannot insert after key " << key;
            return;
        }

        node<T> *temp = head;
        while (temp != NULL)
        {
            if (temp->info == key)
            {
                node<T> *n = new node<T>(val);
                n->next = temp->next;
                temp->next = n;
                return;
            }
            else
                temp = temp->next;
        }

        cout << "Cannot found key." << endl;
    }

    void insertbeforekey(T key, T val)
    {
        if (!head)
        {
            cout << "List is empty. Cannot insert after key " << key;
            return;
        }
        if (head->info == key)
        {
            node<T> *n = new node<T>(val);
            n->next = head;
            head = n;
            return;
        }

        node<T> *temp = head;
        node<T> *previous = head;

        while (temp != NULL)
        {
            if (temp->info == key)
            {
                node<T> *n = new node<T>(val);
                n->next = previous->next;
                previous->next = n;
                return;
            }
            else
            {
                previous = temp;
                temp = temp->next;
            }
        }

        cout << "Cannot found key." << endl;
    }

    void removeAtHead()
    {
        if (!head)
        {
            cout << "Head is NUll";
        }
        else
        {
            node<T> *temp = head;
            head = temp->next;
            delete temp;

            cout << "Node is removed..";
        }
    }

    void removeAtTail()
    {
        if (!head)
        {
            cout << "LSLL is Empty ";
        }
        else
        {
            node<T> *temp = head;
            node<T> *previos = head;
            while (temp->next != NULL)
            {
                previos = temp;
                temp = temp->next;
            }
            delete temp;
            previos->next = NULL;
        }
    }

    void remove(T val)
    {
        if (!head)
        {
            cout << "LSLL is empty.";
            return;
        }
        if (head->info == val)
        {
            node<T> *temp = head;
            head = head->next;
            delete temp;
            cout << "Node with value " << val << " removed from head." << endl;
            return;
        }

        node<T> *temp = head->next;
        node<T> *previous = head;
        while (temp != NULL)
        {
            if (temp->info == val)
            {
                previous->next = temp->next;
                delete temp;
                return;
            }
            previous = temp;
            temp = temp->next;
        }

        cout << "Value not found , so node does not remove.";
    }

    void removeBefore(T val)
    {
        if (!head)
        {
            cout << "LSLL is empty.so cannot remove before ";
            return;
        }
        if (head->info == val)
        {

            cout << "Node with value " << val << " cannot remove from head.As no node before head." << endl;
            return;
        }

        node<T> *temp = head->next;
        node<T> *previous = head;
        node<T> *preprevious = nullptr;

        while (temp != NULL)
        {
            if (temp->info == val)
            {
                if (preprevious == nullptr)
                {
                    node<T> *todelete = head;
                    head = head->next;
                    delete todelete;
                }
                else
                {
                    node<T> *todelete = previous;
                    preprevious->next = temp;
                    delete todelete;
                }
                cout << "Node has been removed successfully.";
                return;
            }
            preprevious = previous;
            previous = temp;

            temp = temp->next;
        }
        cout << "Value cannot found , so node cannot remove before..";
    }

    void removeAfter(T val)
    {
        if (!head)
        {
            cout << "LSLL is empty. Cannot remove after " << val << endl;
            return;
        }

        node<T> *temp = head;

        while (temp != NULL)
        {
            if (temp->info == val)
            {

                if (temp->next == NULL)
                {
                    cout << "No node exists after " << val << endl;
                    return;
                }

                node<T> *toDelete = temp->next;
                temp->next = toDelete->next;
                delete toDelete;

                cout << "Node after value " << val << " removed successfully." << endl;
                return;
            }

            temp = temp->next;
        }

        cout << "Value " << val << " not found in the list." << endl;
    }

    void search(T key)
    {
        if (!head)
        {
            cout << "LSLL is empty" << key << endl;
            return;
        }

        node<T> *temp = head;
        int position = 0;
        while (temp != NULL)
        {
            if (temp->info == key)
            {
                cout << "Value found at" << position << endl;
                return;
            }
            temp = temp->next;
            position++;
        }
        cout << "Key not found in the list..";
    }

    void update(T key, T val)
    {
        if (!head)
        {
            cout << "List is empty. Cannot found key " << key;
            return;
        }

        node<T> *temp = head;
        while (temp != NULL)
        {
            if (temp->info == key)
            {
                temp->info = val;
                return;
            }
            else
                temp = temp->next;
        }

        cout << "Cannot found key." << endl;
    }
    int countNodes()
    {
        int count = 0;
        if (!head)
        {
            count = 0;
        }
        else
        {
            node<T> *temp = head;
            while (temp != NULL)
            {
                count++;
                temp = temp->next;
            }
        }
        return count;
    }

    void display()
    {
        node<T> *dis = head;
        while (dis != NULL)
        {
            cout << dis->info << " ";
            dis = dis->next;
        }
        cout << endl;
    }

    // task01

    bool removeKthNode(int key, int &val)
    {
        if (!head)
        {
            return false;
        }
        if (head == 0 && key == 1)
        {
            return false;
        }

        if (countNodes() >= key)
        {

            node<int> *pre = head;
            node<int> *temp = head;
            int count = 0;
            while (temp != NULL)
            {
                if (count == key)
                {
                    val = temp->info;
                    pre->next = temp->next;

                    delete temp;
                    return true;
                }
                pre = temp;
                temp = temp->next;
                count++;
            }
        }
        return false;
    }

    //  task05

    void removedulplicates()
    {
        if (head == NULL)
        {
            cout << "List is empty";
            return;
        }

        node<T> *p = head;
        while (p != NULL)
        {
            node<T> *prev = p;
            node<T> *q = p->next;
            while (q != NULL)
            {
                if (q->info == p->info)
                {

                    prev->next = q->next;
                    node<T> *toDelete = q;
                    q = prev->next;
                    delete toDelete;
                }
                else
                {
                    prev = q;
                    q = q->next;
                }
            }
            p = p->next;
        }

        cout << "duplicates has been removed successfully";
    }

    // task02

    void combine(LSLL<T> &other)
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

        node<int> *tail = head;
        while (tail->next != nullptr)
        {
            tail = tail->next;
        }

        tail->next = other.head;
        other.head = nullptr;
    }

    // task03
    void shuffleMerge(LSLL<T> &list1, LSLL<T> &list2)
    {

        if (list1.head == nullptr)
        {
            list1.head = list2.head;
            list2.head = nullptr;
            return;
        }

        node<T> *a = list1.head;
        node<T> *b = list2.head;
        node<T> *a_next;
        node<T> *b_next;

        while (a != nullptr && b != nullptr)
        {
            a_next = a->next;
            b_next = b->next;

            a->next = b;
            b->next = a_next;

            a = a_next;
            b = b_next;
        }

        if (b != nullptr)
        {
            node<T> *tail = list1.head;
            while (tail->next != nullptr)
            {
                tail = tail->next;
            }
            tail->next = b;
        }

        list2.head = nullptr;
    }

    void display(node<int> *head)
    {
        node<int> *dis = head;
        while (dis != NULL)
        {
            cout << dis->info << " ";
            dis = dis->next;
        }
    }

    ~LSLL()
    {
        node<T> *temp = head;
        while (temp != NULL)
        {
            node<T> *nextnode = temp->next;
            delete temp;
            temp = nextnode;
        }
        cout << "Link list has been deleted successfully.";
    }

    void reverse()
    {
        node<int> *pre = NULL;
        node<int> *curr = head;
        while (curr != NULL)
        {
            node<int> *forward = curr->next;
            curr->next = pre;
            pre = curr;
            curr = forward;
        }
        head = pre;
    }
};

int main()
{

    LSLL<int> list;
    LSLL<int> list2;
    list.insertAtTail(23);
    list.insertAtTail(5);
    list.insertAtTail(4);
    list.insertAtTail(23);
    list.insertAtTail(6);
    list.insertAtTail(78);
    list.display();
    cout << endl;

    list.reverse();
    list.display();
}
