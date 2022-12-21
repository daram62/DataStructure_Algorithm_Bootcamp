#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct Node{
	element data;
	struct Node* left;
	struct Node* right;
} treeNode;

treeNode* makeRootNode(element data, treeNode* leftNode, treeNode* rightNode) {
    treeNode* new= (treeNode*)malloc(sizeof(treeNode));
    new->data = data;
    new->left = leftNode;
    new->right = rightNode;
    return 0;
}

// Preorder traversal: -*AB/CD
void pre_order(treeNode* root) {
    if (root !=NULL){
        printf("%c",root->data);
        pre_order(root->left);
        pre_order(root->right);
        printf("end");
    }
    printf("root가 널이양");
}

// Inorder traversal: A*B-C/D
void in_order(treeNode* root) {
    if( root != NULL){
        in_order(root->left);
        printf("%c",root->data);
        in_order(root->right);
    }
}

// Postorder traversal: AB*CD/-
void post_order(treeNode* root) {
	if(root != NULL){
		post_order(root->left);
		post_order(root->right);
		printf("%c",root->data);
	}
}

// main.c
int main(void) {
	// (A*B-C/D)
	treeNode* n7 = makeRootNode('D', NULL, NULL);
	treeNode* n6 = makeRootNode('C', NULL, NULL);
	treeNode* n5 = makeRootNode('B', NULL, NULL);
	treeNode* n4 = makeRootNode('A', NULL, NULL);
	treeNode* n3 = makeRootNode('/', n6, n7);
	treeNode* n2 = makeRootNode('*', n4, n5);
	treeNode* n1 = makeRootNode('-', n2, n3);

	printf("\n preorder : ");
	pre_order(n1);

	printf("\n inorder : ");
	in_order(n1);

	printf("\n postorder : ");
	post_order(n1);

	getchar();  
	return 0;
}
