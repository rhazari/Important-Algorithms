#include <iostream>

using namespace std;

class tree{
public:
	int data;
	tree* left;
	tree* right;
	tree(int _data){
		data = _data;
		left = nullptr;
		right = nullptr;
	}
};

void createBST(tree **root, int val){
	if(!(*root)){
		tree* t = new tree(val);
		(*root) = t;
	}
	else if( (*root)->data < val ){
		createBST(&(*root)->right, val);
	}
	else{
		createBST(&(*root)->left, val);	
	}
}

void inorderT(tree *root){
	if(root){
		inorderT(root->left);
		cout<<root->data<<"\t";
		inorderT(root->right);
	}
}

tree* successor(tree *root, tree *p){
	tree *sc = nullptr;
	cout<<"Root: "<<root->data<<endl;
	cout<<"Node: "<<p->data<<endl;
	if(p->right){
		p = p->right;
		while(p->left){
			p = p->left;
		}
		sc = p;
	}
	else{
		while(root){
			if(root->data < p->data)
				root = root->right;
			else if(root->data > p->data){
				sc = root;
				root = root->left;
			}
			else
				break;
		}
	}
	return sc;
}

int main(){

	tree *root = nullptr;
	createBST(&root,17);
	createBST(&root,11);
	createBST(&root,13);
	createBST(&root,7);
	createBST(&root,9);
	createBST(&root,21);
	createBST(&root,31);
	createBST(&root,26);
	createBST(&root,15);

	cout<<"BST Inorder"<<endl;
	inorderT(root);
	cout<<endl;

	tree *suc = successor(root,root->left->left->right);
	if(suc){
		cout<<"Successor: "<<suc->data<<endl;
	}
	else{
		cout<<"No successor"<<endl;
	}
	return 0;
}