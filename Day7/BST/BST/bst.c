#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

void inorder(treeNode* root) { // 중위 순회
  if (root) {
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
  }
}

// Search x from BST
treeNode* find(treeNode* root, element x) {
  treeNode* p;
  p = root;
  while (p != NULL) {
    if (x < p->key)
      p = p->left;
    else if (x == p->key)
      return p;
    else
      p = p->right;
  }
  //printf("Key %d does not exist.\n", x);
  return p;
}

treeNode* findparent(treeNode* root, treeNode* node) {
    treeNode* p;
    treeNode* parent;
    p = root;
    parent = root;
    while(p!=NULL){
        if(p->key == node->key){
            return parent;
        }
        else if(p->key < node->key){
            parent = p;
            p=p->right;
        }
        else if(p->key > node->key){
            parent = p;
            p=p->left;
        }
    }
    return parent;
}

// Insert x, check p->key
// If x already exists, do not insert
treeNode* insert(treeNode* p, element x) {
  treeNode* newNode;
  if (p == NULL) {
    newNode = (treeNode*)malloc(sizeof(treeNode));
    newNode->key = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
  } else if (x < p->key)
    p->left = insert(p->left, x);
  else if (x > p->key)
    p->right = insert(p->right, x);
  else
    printf("You already have %d!\n", x);

  return p;
}

treeNode* maxNode(treeNode* node){
    treeNode* p;
    p = node->left;
    while (p != NULL){ // 이거 다시 해보기!
        if(!p->left && !p->right) // 말단 노드일때
            return p;
        else if(!p->right && p->left) //오른쪽은 없고 왼쪽만 있을 때
            return p;
        else if(p->right) // 오른쪽 노드가 있을 때
            p= p->right;
    }
    return 0;
}

// Delete node which has key
void Erase(treeNode* root, element key) {
    treeNode* p;
    treeNode* parent;
    p = find(root,key);
    
    if(!p){
        return;
    }
    // 삭제할 노드의 차수가 0
    if(!p->left && !p->right)
    {
        parent = findparent(root, p);
        if(parent->left == p)
            parent->left = NULL;
        else
            parent->right = NULL;
    }
    // 삭제할 노드의 차수가 1
    else if(!p->left || !p->right)
    {
        parent = findparent(root, p);
        if(p->left)
        { //만약 왼쪽 자식이 있으면
            if(parent->left==p)
                parent->left = p->left;
            else parent->right = p->left;
        }
        else
        { // 만약 오른쪽 자식이 있으면
            if(parent->left==p)
                parent->left = p->right;
            else parent->right = p->right;
        }
    }
    // 삭제할 노드의 차수가 2
    else if(p->left && p->right)
    {
        treeNode* q;
        treeNode* qparent;
        q = maxNode(p);
        qparent = findparent(root,q);
        
        if(!q->left && !q->right){
            Erase(qparent,q->key);
        }
        else Erase(p->left,q->key);
        p->key = q->key;
    }
}
