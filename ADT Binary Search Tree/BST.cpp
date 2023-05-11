#include <iostream>
#include <iomanip>
#include "BST.h"
using namespace std;

template<class T>
BST<T>::BST()
{
    root = 0;
}

template<class T>
BST<T>::~BST()
{
    deleteTree(root);
}

template<class T>
BSTNode<T> *BST<T>::copyHelper(const BSTNode<T> *source)
{
    if(source == 0)
        return 0;

    BSTNode<T> *copy = new BSTNode<T>;
    copy->setVal(source->getVal());
    copy->setLeft(copyHelper(source->getLeft()));
    copy->setRight(copyHelper(source->getRight()));
    return copy;
}

template<class T>
void BST<T>::preOrder(BSTNode<T> *r)
{
    if(r != 0)
    {
        cout << r->getVal() << ' ';
        preOrder(r->getLeft());
        preOrder(r->getRight());
    }
}

template<class T>
void BST<T>::inOrder(BSTNode<T> *r)
{
    if(r != 0)
    {
        inOrder(r->getLeft());
        cout << r->getVal() << ' ';
        inOrder(r->getRight());
    }
}

template<class T>
void BST<T>::postOrder(BSTNode<T> *r)
{
    if(r != 0)
    {
        postOrder(r->getLeft());
        postOrder(r->getRight());
        cout << r->getVal() << ' ';
    }
}

template<class T>
bool BST<T>::search(BSTNode<T> *p, T v)
{
    bool found = false;
    if(root == 0)
        cout << "Cannot search.. The tree is empty.\n";
    else
    {
        while (p != 0) {
            if (p->getVal() == v)
                found = true;
            else if (v < p->getVal())
                p = p->getLeft();
            else
                p = p->getRight();
        }
    }
    return found;
}

template<class T>
void BST<T>::insert(T v)
{
    BSTNode<T> *p = root, *prev = 0;
    while(p != 0)
    {
        prev = p;
        if(v < p->getVal())
            p = p->getLeft();
        else
            p = p->getRight();
    }
    if(root == 0)                   // if the tree is empty
        root = new BSTNode<T>(v);
    else if(v < prev->getVal())
        prev->setLeft(new BSTNode<T>(v));
    else
        prev->setRight(new BSTNode<T>(v));
}

template<class T>
T BST<T>::getSuccessor(BSTNode<T>* curr)
{
    BSTNode<T>* temp = curr;
    while(temp->getLeft() != 0)
        temp = temp->getLeft();
    return temp->getVal();
}

template<class T>
std::pair<BSTNode<T> *, BSTNode<T> *> BST<T>::getNode(T val)
{
    BSTNode<T> *current;
    BSTNode<T> *trailCurrent;
    bool found = false;
    if (root == 0)
        cout << "Cannot search.. The tree is empty.\n";
    else
    {
        current = root;
        trailCurrent = root;
        while (current != 0 && !found)
        {
            if (current->getVal() == val)
                found = true;
            else
            {
                trailCurrent = current;
                if (current->getVal() > val)
                    current = current->getLeft();
                else
                    current = current->getRight();
            }
        }
        return std::make_pair(trailCurrent, current);
    }
}
template <class T>
void BST<T>::deleteNode(T del)
{
    pair<BSTNode<T> *, BSTNode<T> *> node = getNode(del);
    BSTNode<T> *trailCurrent = node.first;
    BSTNode<T> *current = node.second;

    if(node.second == 0)
        cout << "The deleted item isn't in the tree!.\n";
    else
    {
        // Case #1: Lead node -> Just delete it.
        if(current->getLeft() == 0 && current->getRight() == 0)
        {
            if(current == trailCurrent->getLeft())
                trailCurrent->setLeft(NULL);
            else
                trailCurrent->setRight(NULL);
            delete current;
            return;
        }
        // Case #2: Two children -> replace it with its successor and delete.
        if(current->getLeft() && current->getRight())
        {
            T successorValue = getSuccessor(current->getRight());
            pair<BSTNode<T> *, BSTNode<T> *> sNode = getNode(successorValue);
            BSTNode<T> *parent   = sNode.first;
            BSTNode<T> *succesor = sNode.second;
            if(parent->getLeft() == succesor)
                parent->setLeft(NULL);
            else if(parent->getRight() == succesor)
                parent->setRight(NULL);
            current->setVal(succesor->getVal());
            delete succesor;
            return;
        }
        // Case #3: Only one child -> replace it with its child and delete.
        BSTNode<T> *child;
        if(current->getLeft())
            child = current->getLeft();
        else if(current->getRight())
            child = current->getRight();
        if(trailCurrent->getLeft() && trailCurrent->getLeft() == current)
            trailCurrent->setLeft(child);
        else if(trailCurrent->getRight() && trailCurrent->getRight() == current)
            trailCurrent->setRight(child);
        delete current;
        return;
    }
}

template<class T>
bool BST<T>::isEmpty()
{
    return root == 0;
}

template<class T>
int BST<T>::getHeight(BSTNode <T> *current)
{
    /* if the tree is empty */
    if(current == 0)
        return 0;
    else  /// if the tree contains data.
    {
        int heightOfLeft = getHeight(current->getLeft());
        int heightOfRight = getHeight(current->getRight());

        return max(heightOfLeft, heightOfRight) + 1;
    }
}

template<class T>
void BST<T>::deleteTree(BSTNode<T> *p)
{
    if(p == 0)
        return;
    deleteTree(p->getLeft());
    deleteTree(p->getRight());
    delete p;
}

template<class T>
void BST<T>::plotTree(BSTNode<T> *root, int h, int H, int mid, int Y)
{
    if(root == 0)
    {
        return;
    }
    int x = mid;
    int y = Y + 1 + (H * (H + 1)) / 2 - (h * (h + 1)) / 2;
    gTool.goToXY(x,y);
    printf("%d",root->getVal());
    if(root->getRight() != 0)
    {
        for(int i = 1; i <= (h - 1); i++)
        {
            gTool.goToXY(mid + i, y + i);
            printf(" \\ ");
        }
        plotTree(root->getRight(),h - 1, H,mid+h, Y);
    }
    if(root->getLeft() != 0)
    {
        for(int i = 1; i <= (h - 1); i++)
        {
            gTool.goToXY(mid - i, y + i);
            printf(" / ");
        }
        plotTree(root->getLeft(),h - 1, H,mid - h, Y);
    }
}

template<class T>
void BST<T>::plot()
{
    int height;
    cout << "\nGraphical Plot of the Tree: " << endl;
    height = this->getHeight();
    plotTree(this->root, height, height, height * (height + 1) / 2, gTool.getY());
    cout << endl;
    cout << endl;
}

template<class T>
int BST<T>::getNumberOfNodes(BSTNode<T> *root)
{
    if(root == NULL)
        return 0;
    else
        return 1 + getNumberOfNodes(root->getLeft()) + getNumberOfNodes(root->getRight());
}

template class BST<int>;