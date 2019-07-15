//
// Created by Rovshan Akberov on 2019-07-15.
//

#ifndef DATA_STRUCTURES_BST_H
#define DATA_STRUCTURES_BST_H

typedef struct node{
    int data;
    struct node * left;
    struct node * right;
}node;

node * createNode(int);

node * insertElement(node *, int);

node * deleteElement(node *, int);

node * findSmallest(node *);

node * findLargest(node *);

void inOrderTraversal(node*);

void preOrderTraversal(node*);

int height(node *);





#endif //DATA_STRUCTURES_BST_H
