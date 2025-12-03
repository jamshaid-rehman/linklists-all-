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

class CSLL
{
private:
    node<T> *head;

public:
    CSLL()
    {
        head = NULL;
    }

    void insertAtHead(T val)
    {
        if (head == 0)
        {
            node<T> *newnode = new node<T>(val);
            head = newnode;
            newnode->next = newnode;
        }

        else
        {
            node<T> *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            node<T> *newnode = new node<T>(val);
            newnode->next = head;
            temp->next = newnode;
        }
    }

    void insertAtTail(int val)
    {
        if (head == 0)
        {
            node<T> *newnode = new node<T>(val);
            head = newnode;
            newnode->next = newnode;
        }

        else
        {
            node<T> *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            node<T> *newnode = new node<T>(val);
            temp->next = newnode;
            newnode->next = head;
        }
    }

    void removeAtHead()
    {
        if (!head)
        {
            cout << "Head is NUll";
            return;
        }
        if (head->next == head)
        {
            delete head;
            head = nullptr;
            return;
        }

        node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }

        node<T> *point = head;

        head = point->next;
        delete point;
        temp->next = head;
    }

    void removeAtTail()
    {
        if (!head)
        {
            cout << "Head is NUll";
            return;
        }
        if (head->next == head)
        {
            delete head;
            head = nullptr;
            return;
        }

        node<t> *temp = head;
        node<T> *previous = head;
        while (temp->next != head)
        {
            previous = temp;
            temp = temp->next;
        }
        previous->next = head;
        delete temp;
    }
};