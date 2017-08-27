#include <iostream>
#include <map>
#include <queue>

using namespace std;

class TreeNode
{
public:
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int _val){
		val = _val;
		left = nullptr;
		right = nullptr;
	}
};

void createBST(TreeNode **root, int num){
	if(!(*root)){
		TreeNode* newNode = new TreeNode(num);
		*root = newNode;
	}
	else if((*root)->val < num)
		createBST(&(*root)->right, num);
	else
		createBST(&(*root)->left, num);
}

void verticalOrder(TreeNode *root){
	if(!root)
		return;
	map<int, vector<int>> myMap;
	queue<pair<TreeNode*, int>> Q;
	Q.push(make_pair(root, 0));

	while(!Q.empty()){
		auto temp = Q.front();
		Q.pop();
		TreeNode *node = temp.first;
		int level = temp.second;

		myMap[level].push_back(node->val);
		if(node->left)
			Q.push(make_pair(node->left, level-1));
		if(node->right)
			Q.push(make_pair(node->right, level+1));
	}

	for(auto itr = myMap.begin(); itr != myMap.end(); ++itr){
		for(int k = 0; k < itr->second.size(); ++k)
			cout<<itr->second[k]<<" ";
		cout<<endl;
	}
}

void preOrder(TreeNode *root){
	if(!root)
		return;
	cout<<root->val<<" ";
	preOrder(root->left);
	preOrder(root->right);
}

int main(){

	TreeNode *tree;
	createBST(&tree, 6);
	createBST(&tree, 11);
	createBST(&tree, 7);
	createBST(&tree, 4);
	createBST(&tree, 5);
	createBST(&tree, 3);
	createBST(&tree, 8);
	createBST(&tree, 13);

	cout<<"Pre Order Traversal"<<endl;
	preOrder(tree);
	cout<<endl;

	cout<<"Vertical Order Traversal"<<endl;
	verticalOrder(tree);
	cout<<endl;

	return 0;
}


