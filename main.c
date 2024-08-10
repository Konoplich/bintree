#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libbintree.h"

void main() {
    node_t *root = NULL;
    bintree_insert(&root, 10);
    bintree_insert(&root, 12);
    bintree_insert(&root, 8);
    bintree_insert(&root, 9);
    bintree_insert(&root, 7);
    bintree_insert(&root, 3);
    bintree_insert(&root, 4);
    printf("tree\n");
    bintree_print(root, "root", 0);
    printf("max = %d\n", bintree_get_max(root)->data);
    printf("min = %d\n", bintree_get_min(root)->data);
    printf("test get node: 7\n");
    printf("parent of 7 is %d\n", bintree_get_node(root, 7)->parent->data);
    printf("test del: 4, 8\n");
    bintree_delete_value(root, 4);
    bintree_delete_value(root, 8);
    printf("tree\n");
    bintree_print(root, "root", 0);
    printf("------------------\n");
    printf("del 10\n");
    bintree_delete_value(root, 10);
    printf("tree\n");
    bintree_print(root, "root", 0);
    printf("ok\n");
    getchar();
}
