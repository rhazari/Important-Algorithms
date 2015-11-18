#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct Tree {
	int data;
	struct Tree *left;
	struct Tree *right;
}
Tree;

void inOrder( Tree *root ) {
	if( NULL != root ){
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}
}

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

int main() {
	int N, tmp;
	Tree *root = NULL;
	cout<<"Number of Elements to enter in BST"<<endl;
	cin >> N;

	while(N) {
		cout<<"Enter a value"<<endl;
		cin >> tmp;
		insert(&root, tmp);
		--N;
	}
	cout<<"\nIn-Order traversal after BST insertion"<<endl;
	inOrder(root);
	cout<<endl;

	return 0;
}