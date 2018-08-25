#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): data(val), left(nullptr), right(nullptr){}
};

TreeNode* createBST(vector<int> array, int left, int right) {
    if(left < right) {
        int mid = (left+right)/2;
        TreeNode *root = new TreeNode(array[mid]);
        root->left = createBST(array, left, mid);
        root->right = createBST(array, mid+1, right);
        return root;
    }
    return nullptr;
}

void inOrder(TreeNode* root ){
    if(nullptr != root){
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}

int main() {
    vector<int> vec(10,0);
    for(int k = 0; k < 10; ++k ){
        vec[k] = k+2;
    }

    TreeNode* temp = createBST(vec, 0, vec.size());
    cout<<"In Order traversal of the BST"<<endl;
    inOrder(temp);
    cout<<endl;
    return 0;
}