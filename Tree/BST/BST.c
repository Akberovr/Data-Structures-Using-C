//
// Created by Rovshan Akberov on 2019-07-15.
//

#include "BST.h"
#include <stdio.h>
#include <stdlib.h>



node * createNode(int data){
    node * newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node * findLargest(node * root){
    if(root == NULL || root->right == NULL){
        return root;
    } else{
        return findLargest(root->right);
    }
}

node * findSmallest(node * root){
    if(root == NULL || root->left == NULL){
        return root;
    } else{
        return findLargest(root->left);
    }
}


node * insertElement(node * root, int data){
    if(root == NULL){
        root = createNode(data);
    } else if(data <= root->data){
        root->left = insertElement(root->left,data);
    } else{
        root->right = insertElement(root->right,data);
    }

    return root;

}

node * deleteElement(node * root, int data){

    if(root == NULL){
        /* return empty tree */
        return root;
    } else if(data < root->data){
        root->left = deleteElement(root->left, data);
    } else if(data > root->data){
        root->right = deleteElement(root->right, data);
    } else{

        /* if there is NO child */
        if(root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
        }

            /* if there is one child */
        else if(root->right == NULL){
            node * temp = root;
            root = root->left;
            free(temp);
        }

        else if(root->left == NULL){
            node * temp = root;
            root = root->right;
            free(temp);
        }
            /* if there are TWO children */
        else{
            node * temp = findLargest(root->right);
            root->data = temp->data;
            root->right = deleteElement(root->right,data);
        }
    }
    return root;
}


void inOrderTraversal(node * root){

    if(root == NULL) return;

    /* Visit left subtree  */
    inOrderTraversal(root->left);
    /* Print data  */
    printf("%d ",root->data);
    /* Visit right subtree */
    inOrderTraversal(root->right);

}

void preOrderTraversal(node * root){

    if(root == NULL){
        return;
    }else{
        /* Print data  */
        printf("%d ", root->data);
        /* Visit left subtree  */
        preOrderTraversal(root->left);
        /* Visit right subtree */
        preOrderTraversal(root->right);
    }

}

int height(node * root){
    int leftHeight, rightHeight;

    if(root == NULL){
        return -1;
    }
    else{
        leftHeight = height(root->left);
        rightHeight = height(root->right);

        if(leftHeight > rightHeight ){
            return (leftHeight + 1);
        } else{
            return (rightHeight + 1);
        }
    }
}
