#include "TreeNode.h"
#include <vector>
#include <algorithm>

using namespace std;

void createTree(TreeNode **root, vector<int> array, int left, int right){
    if(left > right){
        return;
    }
    int mid = (left+right)/2;
    TreeNode *p = new TreeNode(array[mid]);
    (*root) = p;
    createTree(&(*root)->left, array, left, mid-1);
    createTree(&(*root)->right, array, mid+1, right);
}

void dfsBtree(TreeNode* root, vector<vector<int>> &result, vector<int>& vec){
    if(nullptr == root->left && nullptr == root->right){
        result.push_back(vec);
        return;
    }
    if(root->left){
        vec.push_back(root->left->data);
        dfsBtree(root->left, result, vec);
        vec.pop_back();
    }
    if(root->right){
        vec.push_back(root->right->data);
        dfsBtree(root->right, result, vec);
        vec.pop_back();
    }
}

int main(){

    vector<int> array = {11,5,8,9,23,31,17,19,7};
    sort(array.begin(), array.end());
    TreeNode *root = nullptr;
    createTree(&root, array, 0, array.size()-1);

    displayTree(root);
    cout<<"\n";

    vector<vector<int> > allPaths;
    vector<int> vec;
    vec.push_back(root->data);
    dfsBtree(root, allPaths, vec);

    cout<<"All Paths from Root to Leaves..."<<endl;
    for(auto& vec: allPaths){
        for(auto v: vec){
            cout<<v<<" ";
        }
        cout<<"\n";
    }
}