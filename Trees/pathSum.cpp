#include <iostream>
#include <cstdlib>
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

bool hasPathSum(struct Tree* root, int total) {
	if( NULL == root ) {
		return false;
	}

	queue<Tree*> treeNodes;
	queue<int> pathSum;

	treeNodes.push(root);
	pathSum.push(root->data);
	Tree* temp;
	int sum = 0;
	while(! treeNodes.empty() ){
		temp = treeNodes.front();
		treeNodes.pop();
		sum = pathSum.front();
		pathSum.pop();

		if( NULL == temp->left && NULL == temp->right && sum == total ){
			return true;
		}

		if( NULL != temp->left ){
			treeNodes.push(temp->left);
			pathSum.push(sum + temp->left->data);
		}

		if( NULL != temp->right ){
			treeNodes.push(temp->right);
			pathSum.push(sum + temp->right->data);
		}

	}
	return false;  
}

bool recurHasPathSum(struct Tree* root, int sum){
	if( NULL == root ){
		return false;
	}

	if(sum == root->data && NULL == root->left && NULL == root->right ){
		return true;
	}

	return recurHasPathSum(root->left, sum-root->data) || 
			recurHasPathSum(root->right, sum - root->data);
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

	if( hasPathSum(root,50) ){
		cout<<"Root to leaf sum Exists !!!"<<endl;
	}
	else{
		cout<<"Root to leaf sum does not exist"<<endl;
	}

	if( recurHasPathSum(root,62) ){
		cout<<"Root to leaf sum Exists !!!"<<endl;
	}
	else{
		cout<<"Root to leaf sum does not exist"<<endl;
	}

	return 0;
}