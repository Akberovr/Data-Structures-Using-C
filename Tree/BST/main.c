//
// Created by Rovshan Akberov on 2019-07-15.
//
#include <stdio.h>
#include "BST.h"

int main(int argc, const char * argv[]) {

    int option, val;
    node *tree = NULL;

    do {
        printf("\n ***** MAIN MENU *****");
        printf("\n 1. Insert an element");
        printf("\n 2. Delete an element");
        printf("\n 3. In-order-traverse");
        printf("\n 4. Pre-order-traverse");
        printf("\n 5. Height of tree");
        printf("\n Enter your option : ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\n Enter the value of the new node : ");
                scanf("%d", &val);
                tree = insertElement(tree, val);
                break;
            case 2:
                printf("\n Enter the element to be deleted : ");
                scanf("%d", &val);
                tree = deleteElement(tree, val);
                break;
            case 3:
                printf("\n The elements of the tree are : \n");
                inOrderTraversal(tree);
                break;
            case 4:
                printf("\n The elements of the tree are : \n");
                preOrderTraversal(tree);
                break;
            case 5:
                printf("\n Height of tree is : \n");
                printf("%d", height(tree));
                break;
        }
    } while (option != 6);
    return 0;
}