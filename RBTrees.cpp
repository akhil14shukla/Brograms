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
    Node<T> *parent = NULL;
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
    void check(Node<T> *p);
};
template <typename T>
void Tree<T>::create()
{
    Node<T> *p;
    root = new Node<T>;
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
                // p - //balancing will be added later
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
void Tree<T>::check(Node<T> *p)
{
    if(p == root){
        root->color = 0;
        return ;
    }
    if(p->parent->color == 0){
        continue;
    }
    else{
        if(p->parent->parent->left == p->parent){ // p's parent is left child of p's grandparent
            if(p->parent->parent->right->color == 1){ // if p's uncle is red
                p->parent->color = 0;
                p->parent->parent->right->color = 0;
                p->parent->parent->color = 1;
                check(p->parent->parent);
            }
            else{ // if p's uncle is black
                if(p->parent->left == p){

                }
                else{
                    p = LRotation(p->parent)->left;
                    RRotation(p->parent->parent);
                }

            }
        }
        else{ // if p's parent is right child of p's grandparent

        }
    }
}
template <typename T>
Node<T> *Tree<T>::LRotation(Node<T> *p)
{
    Node<T> *temp = p;
    if (p->parent != NULL)
    {
        if (p->parent->left == p)
        {
            p->parent->left = p->right;
        }
        else
        {
            p->parent->right = p->right;
        }
    }
    p->right->parent = p->parent;
    // p = p->right;
    p->parent = p->right;
    Node<T> *t = p->right->left;
    p->right->left = p;
    p->right = t;
    if (t != NULL)
    {
        t->parent = p;
    }
    if (root == p)
    {
        root = p->parent;
    }
    return p = p->parent;
}
template <typename T>
Node<T> *Tree<T>::RRotation(Node<T> *p)
{
    Node<T> *temp = p;
    if (p->parent != NULL)
    {
        if (p->parent->left == p)
        {
            p->parent->left = p->left;
        }
        else
        {
            p->parent->right = p->left;
        }
    }
    p->left->parent = p->parent;
    // p = p->right;
    p->parent = p->left;
    Node<T> *t = p->left->right;
    p->left->right = p;
    p->left = t;
    if (t != NULL)
    {
        t->parent = p;
    }
    if (root == p)
    {
        root = p->parent;
    }
    return p = p->parent;
}

int main()
{
    Tree<int> T1;
    T1.root = new Node<int>;
    T1.root->color = 0;
    T1.root->data = 12;
    Node<int> *t1 = new Node<int>;
    t1->data = 11;
    t1->color = 0;
    Node<int> *t2 = new Node<int>;
    t2->data = 13;
    t2->color = 0;
    t1->parent = t2->parent = T1.root;
    T1.root->left = t1;
    T1.root->right = t2;
    T1.LRotation(T1.root);
    cout << 12 << endl;
    return 0;
}