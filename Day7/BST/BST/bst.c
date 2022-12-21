#include "bst.h"

#include <stdio.h>
#include <stdlib.h>

void inorder(treeNode* root) {
  if (root) {
      printf("정렬연산~");
  }
}

// Search x from BST, return node which has x
// Otherwise, return NULL
treeNode* find(treeNode* root, element x) {
    printf("탐색연산~");
    return 0;
}

// Insert x, check p->key
// If x already exists, do not insert
treeNode* insert(treeNode* p, element x) {
    printf("삽입연산~");
    return 0;
}

// Delete node which has key
// Will be a long~function
// if 1: key not found
// if 2: terminal node
// if 3: the node has one child
// if 4: the node has two children (solution chose successor from left tree)
void Erase(treeNode* root, element key) {
    printf("삭제연산~");
}
