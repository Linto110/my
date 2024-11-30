#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

// Function declarations
struct node* insert(struct node*, int);
struct node* deleteNode(struct node*, int);
struct node* search(struct node*, int);
void display(struct node*);

void main() {
    struct node* root = NULL;
    int opt, data;

    do {
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\nEnter your choice: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                printf("Enter the element: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;

            case 2:
                printf("Enter the element to be deleted: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;

            case 3:
                printf("Enter element to be searched: ");
                scanf("%d", &data);
                if (search(root, data)) {
                    printf("Found the searched data\n");
                } else {
                    printf("Not found the searched element\n");
                }
                break;

            case 4:        
            	if (root == NULL) 
            		printf("empty");
            	else
            		display(root);
             	break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    } while (1);
}

// Function to insert a node
struct node* insert(struct node* bst, int data) {
    struct node* t, *t1 = bst;
    t = (struct node*)malloc(sizeof(struct node));
    t->data = data;
    t->left = t->right = NULL;

    if (bst == NULL) {
        return t;
    }

    while (1) {
        if (data < t1->data) {
            if (t1->left == NULL) {
                t1->left = t;
                break;
            }
            t1 = t1->left;
        } else if (data > t1->data) {
            if (t1->right == NULL) {
                t1->right = t;
                break;
            }
            t1 = t1->right;
        } else {
            printf("Duplicate element!\n");
            free(t);
            break;
        }
    }

    return bst;
}

// Function to search for a node
struct node* search(struct node* bst, int data) {
    while (bst != NULL && bst->data != data) {
        if (data < bst->data)
            bst = bst->left;
        else
            bst = bst->right;
    }
    return bst;
}

// Function to delete a node
struct node* deleteNode(struct node* bst, int item) {
    struct node *t1, *t2 = NULL, *successorParent, *t;

    t1 = search(bst, item);

    if (t1 == NULL) {
        printf("Element not found!\n");
        return bst;
    }

    t2 = bst;
    while (t2 != NULL && t2->left != t1 && t2->right != t1) {
        if (item < t2->data) {
            t2 = t2->left;
        } else {
            t2 = t2->right;
        }
    }

    if (t1->left == NULL || t1->right == NULL) {
        t = (t1->left) ? t1->left : t1->right;

        if (t2 == NULL) {
            free(t1);
            return t;
        }

        if (t2->left == t1) {
            t2->left = t;
        } else {
            t2->right = t;
        }

        free(t1);
    } else {
        successorParent = t1;
        t = t1->right;
        while (t->left != NULL) {
            successorParent = t;
            t = t->left;
        }
        t1->data = t->data;

        if (successorParent->left == t) {
            successorParent->left = t->right;
        } else {
            successorParent->right = t->right;
        }

        free(t);
    }

    return bst;
}
// Function to display the tree (in-order traversal)
void display(struct node* bst) {
  if(bst!=NULL)
  {
        display(bst->left);
        printf("%d ", bst->data);
        display(bst->right);
}}

