#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    Node *prev;
    T data;
    Node *next;
};

template <typename T>
class DoublyLinked
{
private:
    Node<T> *first;

public:
    DoublyLinked(){first = NULL;} 
    DoublyLinked(int A[], int n);
   // ~DoublyLinked();
    void Display();
};

template <typename T>
DoublyLinked<T>::DoublyLinked(int A[], int n)
{
    Node<T> *temp, *last;
    first = new Node<T>;
    first->data = A[0];
    first->prev = NULL;
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        temp = new Node<T>;
        temp->data = A[i];
        last->next = temp;
        temp->prev = last;
        temp->next = NULL;
        last = temp;
    }
}

template <typename T>
void DoublyLinked<T>::Display()
{
    Node<T> *temp;
    temp = first;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
    int main()
    {
        int A[] = {1 , 2 , 3, 4};
        DoublyLinked<int> D(A, 4);
        D.Display();
        return 0;
    }