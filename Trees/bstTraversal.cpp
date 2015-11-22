#include <iostream>
#include <cstdlib>
#include <stack>

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

void iterativePreorder(struct Tree* root){
	stack<Tree*> treeStack;
	treeStack.push(root);

	Tree *temp;
	while( !treeStack.empty() ){
		temp = treeStack.top();
		treeStack.pop();
		cout<<temp->data<<"\t";

		if( NULL != temp->right ){
			treeStack.push(temp->right);
		}
		if( NULL != temp->left ){
			treeStack.push(temp->left);
		}
	}
}

void iterativeInorder(struct Tree* root) {
	stack<Tree*> treeStack;
	if(NULL == root){
		return;
	}

	Tree* p = root;
	Tree* temp;

	while( !treeStack.empty() || NULL != p ){
		if(NULL != p){
			treeStack.push(p);
			p = p->left;
		}
		else {
			temp = treeStack.top();
			treeStack.pop();
			cout<<temp->data<<"\t";
			p = temp->right;
		}	

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

	cout<<"Iterative Pre Order Traversal of BST"<<endl;
	iterativePreorder(root);
	cout<<endl;

	cout<<"Iterative In Order Traversal of BST"<<endl;
	iterativeInorder(root);
	cout<<endl;

	return 0;
}