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
    Node<T> *Search(T x);
    Node<T> *Insert(T x);
    Node<T> *LRotation(Node<T> *p);
    Node<T> *RRotation(Node<T> *p);
    Node<T> *Delete_main(Node<T> *p, Node<T> *child, Node<T> *brother);
    Node<T> *Delete(T x);
    Node<T> *Exchange(Node<T> *p1, Node<T> *p2);
    int black_height(Node<T> *p);
    void check(Node<T> *p);
};
template <typename T>
int Tree<T>::black_height(Node<T> *p) // completed according to me
{
    int x = 0;
    while (p != NULL)
    {
        if (p->color == 0)
        {
            x++;
        }
        p = p->left;
    }
    return x;
}

template <typename T>
Node<T> *Tree<T>::Search(T x) // completed according to me
{
    Node<T> *p = root;
    while (p != NULL)
    {
        if (p->data == x)
        {
            return p;
        }
        if (p->data < x)
        {
            p = p->left;
        }
        else
        {
            p = p->right;
        }
    }
    return NULL;
}

template <typename T>
void Tree<T>::create()
{
    Node<T> *p;
    root = new Node<T>;
}

template <typename T>
Node<T> *Tree<T>::Insert(T x) // completed according to me
{
    Node<T> *p = root;
    if (p == NULL && root == NULL)
    {
        Node<T> *t = new Node<T>;
        t->data = x;
        t->color = 0;
        t->left = t->right = NULL;
        root = t;
        return root;
    }
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
                t->parent = p;
                check(t);
                return t;
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
                t->parent = p;
                check(t);
                return t;
                // balancing will be added later
                break;
            }
        }
    }
    return NULL;
}
template <typename T>
void Tree<T>::check(Node<T> *p) // completed according to me
{
    if (p == root)
    {
        root->color = 0;
        return;
    }
    if (p->color == 1 && p->parent->color == 1)
    {
        if (p->parent->color == 0)
        {
            return;
        }
        else
        {
            if (p->parent->parent != NULL)
            {
                if (p->parent->parent->left == p->parent)
                { // p's parent is left child of p's grandparent
                    if (p->parent->parent->right != NULL && p->parent->parent->right->color == 1)
                    { // if p's uncle is red
                        p->parent->color = 0;
                        p->parent->parent->right->color = 0;
                        p->parent->parent->color = 1;
                        check(p->parent->parent);
                    }
                    else
                    { // if p's uncle is black or NULL that is black
                        if (p->parent->left == p)
                        {
                            p = RRotation(p->parent->parent);
                            p->color = 0;
                            p->left->color = p->right->color = 1;
                        }
                        else
                        {
                            p = LRotation(p->parent)->left;
                            p = RRotation(p->parent->parent);
                            p->color = 0;
                            p->left->color = p->right->color = 1;
                        }
                    }
                }
                else
                { // if p's parent is right child of p's grandparent
                    if (p->parent->parent->left != NULL && p->parent->parent->left->color == 1)
                    { // if p's uncle is red
                        p->parent->color = 0;
                        p->parent->parent->left->color = 0;
                        p->parent->parent->color = 1;
                        check(p->parent->parent);
                    }
                    else
                    { // if p's uncle is black or NULL that is black
                        if (p->parent->right == p)
                        {
                            p = LRotation(p->parent->parent);
                            p->color = 0;
                            p->left->color = p->right->color = 1;
                        }
                        else
                        {
                            p = RRotation(p->parent)->right;
                            p = LRotation(p->parent->parent);
                            p->color = 0;
                            p->left->color = p->right->color = 1;
                        }
                    }
                }
            }
        }
    }
}
template <typename T>
Node<T> *Tree<T>::LRotation(Node<T> *p) // completed according to me
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
Node<T> *Tree<T>::RRotation(Node<T> *p) // completed according to me
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

// template<typename T>     // For exchanging the whole nodes
// Node<T>* Tree<T>::Exchange(Node<T>* p1, Node<T>* p2){
//     if(p1)
// }
template <typename T>
Node<T> *Tree<T>::Delete_main(Node<T> *p, Node<T> *child, Node<T> *brother)
{
    if (p!=NULL && p->color == 1)

    
    {
        free(p);   
    }
    else // if p is black
    {
        if (child->color == 1) // if p's child is red
        {
            child->color = 0;
            free(p);
        }
        else // if p's child is black AND brother can't be NULL in this case
        {
            if (brother != NULL && brother->color == 1) //brother can't be NULL in this case
            {
                if (brother->parent->left == brother)
                {
                    LRotation(brother->parent);
                }
                else
                {
                    RRotation(brother->parent);
                }
                brother->color = 0;
                brother->left->color = 1;
                free(p);
            }
            else                                                                                                                    // Difficult case
            {                                                                                                                       // brother is also black
                if ((brother->left == NULL || brother->left->color == 0) && (brother->right == NULL || brother->right->color == 0)) //brother can't be NULL in this case
                {
                    if (child->parent->color == 1)
                    {
                        brother->color = 1;
                        child->parent->color = 0;
                        free(p);
                    }
                    else
                    {
                        free(p);
                        brother->color = 1;
                        Delete_main(NULL, child->parent); // lets see what we can do aout this
                    }
                }
                else
            }
        }
    }
}
template <typename T>
Node<T> *Tree<T>::Delete(T x)
{
    Node<T> *p = Tree<T>::Search(T x);
    if (p == NULL)
    {
        cout << "Node not found in the Tree"
    }
    else
    {
        if (p->left != NULL && p->right != NULL)
        {
            Node<T> *t = p->left;
            while (t->right != NULL)
            {
                t = t->right;
            }
            p->data = t->data;          // exchanging the data, and not saving p's data, cause its gonna be deleted
            Delete_call_1(Node<T> * t); // might create a function for other case
        }
        else if (p->left == NULL && p->right != NULL)
        {
            Node<T> *child = p->right;
            Node<T> *brother;
            child->parent = p->parent;
            if (p->parent == NULL) // to be considered again, check once again
            {
                root = child;
                child->color = 0;
                return child; 
            }
            if (p->parent->left == p)
            {
                p->parent->left = child;
                brother = p->parent->right;
            }
            else
            {
                p->parent->right = child;
                brother = p->parent->left;
            }
            // starting th main part //
        }
        else if (p->left != NULL && p->right == NULL) // just need to mirror the above case
        {
        }
    }
}
int main()
{
    Tree<int> T1;
    T1.root = new Node<int>;
    T1.root->color = 0;
    T1.root->data = 12;
    // Node<int> *t1 = new Node<int>;
    // t1->data = 11;
    // t1->color = 0;
    // Node<int> *t2 = new Node<int>;
    // t2->data = 13;
    // t2->color = 0;
    // t1->parent = t2->parent = T1.root;
    // T1.root->left = t1;
    // T1.root->right = t2;
    // T1.LRotation(T1.root);
    T1.Insert(11);
    T1.Insert(13);
    T1.Insert(14);
    T1.Insert(15);
    T1.Insert(16);
    T1.Insert(17);
    cout << 12 << endl;
    return 0;
}