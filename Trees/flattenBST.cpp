#include <iostream>
#include <cstdlib>
#include <stack>
#include <queue>

using namespace std;

typedef struct Tree {
	int data;
	struct Tree *left;
	struct Tree *right;
} Tree;

void insert(struct Tree **root, int value) {
	if ( NULL == (*root) ){
		Tree *temp = new Tree;
		temp->data = value;
		temp->left = NULL;
		temp->right = NULL;
		(*root) = temp;
	}
	else {
		if( (*root)->data > value ) {
			insert(&((*root)->left), value);
		}
		else if ( (*root)->data < value ) {
			insert(&((*root)->right), value);
		}
	}
}

struct Tree* makeFlatBst(struct Tree *root) {
	stack<Tree* > treeStack;
	Tree *ptr = root;
	while( !treeStack.empty() || NULL != ptr ){
		if(NULL != ptr->right){
			treeStack.push(ptr->right);
		}

		if(NULL != ptr->left ){
			ptr->right = ptr->left;
			ptr->left = NULL;
		}
		else if( !treeStack.empty() ){
			Tree *temp = treeStack.top();
			treeStack.pop();
			ptr->right = temp;
		}
		ptr = ptr->right;	
	}
	return root;
}

void inOrder(struct Tree* root){
	if(NULL != root){
		inOrder(root->left);
		cout<<root->data<<"\t";
		inOrder(root->right);
	}
}

int main() {
	Tree *root = NULL;
	insert(&root, 17);
	insert(&root, 9);
	insert(&root, 23);
	insert(&root, 11);
	insert(&root, 21);
	insert(&root, 7);
	insert(&root, 31);
	insert(&root, 13);

	cout<<"In Order traversal of the original BST"<<endl;
	inOrder(root);
	cout<<endl;

	cout<<"In order traversal of the flattened BST"<<endl;
	Tree* temp = makeFlatBst(root);
	inOrder(temp);
	cout<<endl;
	cout<<endl;
}