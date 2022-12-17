#include <stdlib.h>
#include <stdio.h>

#include "stack.h"
#include "queue.h"
#include "binary_tree.h"

#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

#define abs(a) \
   ({ __typeof__ (a) _a = (a); \
     _a > 0 ? _a : -_a; })

BTNode *initNode(int value) {
    BTNode *node = (BTNode *) malloc(sizeof(BTNode));

    if (node == NULL) {
        return NULL;
    }
    node->data = value;
    node->left = node->right = node->parent = NULL;

    return node;
}

void destroyTree(BTNode **root) {
    if (*root == NULL) {
        return;
    }

    // Sterg subarborele stang
    destroyTree(&(*root)->left);

    // Sterg subarborele drept
    destroyTree(&(*root)->right);

    // Sterg nodul curent
    free(*root);

    *root = NULL;
}

int isLeaf(BTNode *node) {
    return (node->left == NULL
            && node->right == NULL);
}

int getNodeDegrees(BTNode *node) {
    return (node->left != NULL) + (node->right != NULL);
}

BTNode *insertNode(BTNode *root, int value) {
    
    return NULL;
}

BTNode *searchNode(BTNode *root, int value) {
    // TODO Ex2
    return NULL;
}

int removeNode(BTNode **root, BTNode *node) {
    // TODO Ex 3
    return 0;
}

void printInOrder(BTNode *root) {
    // TODO Ex4
}

void printPreOrder(BTNode *root) {
    // TODO Ex4
}

void printPostOrder(BTNode *root) {
    // TODO Ex4
}

size_t getHeight(BTNode *root) {
    // TODO Ex5
    return 0;
}

int isBSTreeBalanced(BTNode *root) {
    // TODO Ex6
    return 0;
}


