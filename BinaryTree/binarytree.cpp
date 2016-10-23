// 10.03.2016
#ifndef BINARYTREE_CPP
#define BINARYTREE_CPP

#include <iostream>
#include <algorithm>    // For the max function
#include "binarytree.h"
using namespace std;

template <class T>
void BinaryTree<T>::deleteAll(BinaryNode<T>*& node)
{
// Deletes all nodes in the tree starting at node
    if (node == NULL)
        ;               // Don't do anything
    else
    {
        deleteAll(node->leftChild);
        deleteAll(node->rightChild);

        if (node->isLeaf())
        {
            delete node;
            node = NULL;    // Set it to NULL because the node that this pointer pointed to has been removed
        }
    }
}

template <class T>
int BinaryTree<T>:: height() const     // Returns the height of the tree
{
    return(height(root));
}

template <class T>
int BinaryTree<T>:: size() const  // Returns the number of nodes in the tree
{
    return(size(root));
}

template <class T>
void BinaryTree<T>:: inorder() const // Traverses the tree in inorder
{
    inorder(root);
}

template <class T>
void BinaryTree<T>:: preorder() const // Traverses the tree in preorder
{
    preorder(root);
}

template <class T>
void BinaryTree<T>:: postorder() const // Traverses the tree in postorder
{
    postorder(root);
}

template <class T>
int BinaryTree<T>:: height(BinaryNode<T>* node) const
{
    if (node == NULL || node->isLeaf())
        return 0;

    else
    {
        int left = 0;
        int right = 0;

        left = height(node->leftChild);
        right = height(node->rightChild);

        if (left > right)
            return (1 + left);

        else
            return (1 + right);
    }
}

template <class T>
int BinaryTree<T>:: size(BinaryNode<T>* node) const
{
    if (node == NULL)
        return 0;

    else
    {
        if (node->isLeaf())
            return 1;

        else
        {
            int right = 0;
            int left = 0;

            right = size(node->rightChild);
            left = size(node->leftChild);

            return (1 + left + right);
        }
    }
}


template <class T>
void BinaryTree<T>:: inorder(BinaryNode<T>* node) const // Traverses the tree in inorder starting at the given node
{
    if (node != NULL)
    {
        inorder(node->leftChild);
        cout << node->item << " ";
        inorder(node->rightChild);
    }
}


template <class T>
void BinaryTree<T>:: preorder(BinaryNode<T>* node) const // Traverses the tree in preorder starting at the given node
{
    if (node != NULL)
    {
        cout << node->item << " ";
        preorder(node->leftChild);
        preorder(node->rightChild);
    }
}

template <class T>
void BinaryTree<T>:: postorder(BinaryNode<T>* node) const // Traverses the tree in postorder starting at the given node
{
    if (node != NULL)
    {
        postorder(node->leftChild);
        postorder(node->rightChild);
        cout << node->item << " ";
    }
}



#endif // BINARYTREE_CPP
