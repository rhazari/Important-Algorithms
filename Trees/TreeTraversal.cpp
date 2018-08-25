/* The different types of traversals of a Binary Tree 
    1. Iterative Pre-order Traversal
    2. Iterative In-order Traversal
    3. Iterative Post-order Traversal
    3. Level Order Traversal
    4. Level Order bottom-up traversal
*/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): data(val), left(nullptr), right(nullptr){}
};

void insert(TreeNode **root, int value) {
    if (nullptr == (*root) ){
        TreeNode *temp = new TreeNode(value);
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

void iterativePreorder(TreeNode* root){
    stack<TreeNode*> treeStack;
    treeStack.push(root);

    while( !treeStack.empty() ){
        auto* temp = treeStack.top();
        treeStack.pop();
        cout<<temp->data<<" ";

        if( nullptr != temp->right ){
            treeStack.push(temp->right);
        }
        if( nullptr != temp->left ){
            treeStack.push(temp->left);
        }
    }
}

void iterativeInorder(TreeNode* root) {
    stack<TreeNode*> treeStack;
    if(nullptr == root){
        return;
    }
    treeStack.push(root);
    while( !treeStack.empty() ){
        auto* temp = treeStack.top();
        if(temp->left){
            treeStack.push(temp->left);
            temp->left = nullptr;
        }
        else {
            cout<<temp->data<<" ";
            treeStack.pop();
            if(temp->right)
                treeStack.push(temp->right);
        }
    }
}

void iterativePostOrder(TreeNode* root){
    stack<TreeNode*> treeStack;
    if(nullptr == root){
        return;
    }
    treeStack.push(root);
    while(!treeStack.empty()){
        auto* temp = treeStack.top();
        if(nullptr == temp->left && nullptr == temp->right){
            treeStack.pop();
            cout<<temp->data<<" ";
        }
        else{
            if(temp->right){
                treeStack.push(temp->right);
                temp->right = nullptr;
            }
            if(temp->left){
                treeStack.push(temp->left);
                temp->left = nullptr;
            }
        }
    }
}

vector<vector<int>> levelOrder(TreeNode* root) {
    queue<TreeNode*> current;
    queue<TreeNode*> next;
    vector<vector<int>> result;
    vector<int> vec;

    current.push(root);

    while(!current.empty()) {
        auto* temp = current.front();
        vec.push_back(temp->data);
        current.pop();
        if(temp->left){
            next.push(temp->left);
        }
        if(temp->right){
            next.push(temp->right);
        }
        if(current.empty()){
            result.push_back(vec);
            vec.clear();
            swap(current,next);
        }
    }
    return result;
}

void buildTree(TreeNode** root){
    insert(&(*root), 17);
    insert(&(*root), 9);
    insert(&(*root), 23);
    insert(&(*root), 11);
    insert(&(*root), 21);
    insert(&(*root), 7);
    insert(&(*root), 31);
    insert(&(*root), 13);
}

int main() {
    {
        TreeNode *root = nullptr;
        buildTree(&root);
        cout<<"Iterative Pre Order Traversal of BST"<<endl;
        iterativePreorder(root);
        cout<<"\n";
        cout<<"\n";
    }
    {
        TreeNode *root = nullptr;
        buildTree(&root);
        cout<<"Iterative In Order Traversal of BST"<<endl;
        iterativeInorder(root);
        cout<<"\n";
        cout<<"\n";
    }
    {
        TreeNode *root = nullptr;
        buildTree(&root);
        cout<<"Iterative Post Order Traversal of BST"<<endl;
        iterativePostOrder(root);
        cout<<"\n";
        cout<<"\n";
    }
    {
        TreeNode *root = nullptr;
        buildTree(&root);
        cout<<"Iterative Level Order Traversal of BST"<<endl;
        auto result = levelOrder(root);
        for(const auto& vec: result){
            for(const auto& v: vec){
                cout<<v<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    {
        TreeNode *root = nullptr;
        buildTree(&root);
        cout<<"Iterative Level Order Traversal bottom up"<<endl;
        auto result = levelOrder(root);
        reverse(result.begin(), result.end());
        for(const auto& vec: result){
            for(const auto& v: vec){
                cout<<v<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
}