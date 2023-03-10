#include <stdio.h>
#include <stdlib.h>

#include "binary_tree.h"
#include "utils.h"

int main() {
    BTNode *root = NULL;

    // Inserez in arbore
    root = insertNode(root, 10);
    insertNode(root, 5);
    insertNode(root, 15);
    insertNode(root, 12);
    insertNode(root, 18);
    insertNode(root, 3);
    insertNode(root, 7);
    insertNode(root, 4);
    insertNode(root, 6);
    insertNode(root, 8);
    insertNode(root, 17);
    insertNode(root, 20);

    prettyPrintTree(root);

    // Eliberez memoria ocupata de arbore
    destroyTree(&root);

    return 0;
}