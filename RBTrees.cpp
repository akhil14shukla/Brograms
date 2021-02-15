#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

template <typename T>
class Node
{
public:
    Node<T> *left = NULL;
    Node<T> *right = NULL;
    T data;
    int color = 1; // 1 - red, 0 - black
};

template <typename T>
class Tree
{
public:
    Node<T> *root;

public:
    Tree()
    {
        root = NULL;
    }
    void create();
    int Search(T x);
    Node<T> *Insert(T x, Node<T> *p);
    Node<T> *LRotation(Node<T> *p);
    Node<T> *RRotation(Node<T> *p);
    int black_height(Node<T> *p);
};
template <typename T>
void Tree<T>::create()
{
    Node<T> *p;
    root = new Node<T>;
    p = root;
    T x;
}

template <typename T>
Node<T> *Tree<T>::Insert(T x, Node<T> *p)
{
    p = root;
    while (1)
    {
        if (x < p->data)
        {
            if (p->left != NULL)
            {
                p = p->left;
            }
            else
            {
                Node<T> *t = new Node<T>;
                t->left = NULL;
                t->right = NULL;
                t->data = x;
                p->left = t;
                //balancing will be added later
                break;
            }
        }
        else
        {
            if (p->right != NULL)
            {
                p = p->right;
            }
            else
            {
                Node<T> *t = new Node<T>;
                t->left = NULL;
                t->right = NULL;
                t->data = x;
                p->right = t;
                // balancing will be added later
                break;
            }
        }
    }
}

template <typename T>
Node<T> *Tree<T>::LRotation(Node<T> *p)
{
    Node<T> *temp = p;
    p = p->right;
    temp->right = p->left;
    p->left = temp;
    if(temp == root){
        root = p;
    } 
    return p;

}
template <typename T>
Node<T> *Tree<T>::RRotation(Node<T> *p)
{
    Node<T> *temp = p;
    p = p->left;
    temp->left = p->right;
    p->right = temp;
    if(temp == root){
        root = p;
    }
    return p;

}

int main()
{
    return 0;
}