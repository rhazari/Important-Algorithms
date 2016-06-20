#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct tree{
    int data;
    struct tree* left;
    struct tree* right;
}tree;

void createTree(tree **root, int *array, int left, int right){
    if(left > right){
        return;
    }
    int mid = (left+right)/2;
    tree *p = new tree;
    p->data = array[mid]; p->left = NULL; p->right = NULL;
    (*root) = p;
    createTree(&(*root)->left, array, left, mid-1);
    createTree(&(*root)->right, array, mid+1, right);
}

void displayTree(tree *root){
    if(root->left){
        displayTree(root->left);
    }
    cout<<root->data<<"\t";
    if(root->right){
        displayTree(root->right);
    }
}

void dfsBtree(tree* root, vector<vector<int> > &result, vector<int> vec){
    vec.push_back(root->data);
    if(NULL == root->left && NULL == root->right){
        result.push_back(vec);
        return;
    }
    if(NULL != root->left){
        vector<int> temp(vec);
        dfsBtree(root->left, result, temp);
    }
    if(NULL != root->right){
        vector<int> temp(vec);
        dfsBtree(root->right, result, temp);
    }
}

int main(){

    int arr[] = {11,5,8,9,23,31,17,19,7};
    int size = sizeof(arr)/sizeof(arr[0]);
    tree *root = NULL;
    createTree(&root, arr, 0, size-1);

    displayTree(root);
    cout<<endl;

    vector<vector<int> > allPaths;
    vector<int> vec;
    dfsBtree(root, allPaths, vec);

    cout<<"All Paths from Root to Leaves..."<<endl;
    for(auto ii = allPaths.begin(); ii != allPaths.end(); ++ii){
        for(auto jj = (*ii).begin(); jj != (*ii).end(); ++jj){
            cout<<*jj<<"\t";
        }
        cout<<endl;
    }

    return 0;
}