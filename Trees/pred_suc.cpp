//Program to find the in-order successor and predecessor 
//of a node with a given value
#include <iostream>
#include <cstdlib>

using namespace std;

class Node{
public:
    int value;
    Node* left;
    Node* right;
    Node(int _val){
        value = _val;
        left = nullptr;
        right = nullptr;
    }
};

Node* root = nullptr;

int contains(int num){
    Node* index = root;
    if(!index)
        return 0;
    
    while(index){
        if(index->value ==  num){
            return 1;
        }
        else if(index->value > num){
            index = index->left;
        }
        else if(index->value < num){
            index = index->right;
        }
    }
    return 0;    
}

int insert(int num){
    Node* ptr = new Node(num);
    
    Node* index = root;
    Node* prev = nullptr;
    
    if(contains(num)){
        cout<< num<<" already exits in the tree\n";
        return 0;
    }
    else{
        while(index){
            if(index->value > num){
                prev = index;
                index = index->left;
            }
            else{
                prev = index;
                index = index->right;
            }
        }
    }    
    if(!index){
        if(prev->value > num){
            prev->left = ptr;
            return 1;
        }
        else{
            prev->right = ptr;
            return 1;
        }   
    }
    return 0;
}

void inorder(Node* ptr){
    if(ptr){
        inorder(ptr->left);
        cout<<ptr->value<<" ";
        inorder(ptr->right);
    }
}

void predecessor(Node* ptr, Node** pred, int val){
	(*pred) = ptr;
	if(ptr->value == val){
		if(ptr->left){
			ptr = ptr->left;
			while(ptr->right)
				ptr = ptr->right;
			(*pred) = ptr;
		}
	}
	else if(ptr->value > val){
		if(ptr->left)
			predecessor(ptr->left, pred, val);
	}
	else if(ptr->value < val){
		if(ptr->right && ptr->right->value < val)
			predecessor(ptr->right, pred, val);
	}
}

void successor(Node* ptr, Node** pred, int val){
	(*pred) = ptr;
	if(ptr->value == val){
		if(ptr->right){
			ptr = ptr->right;
			while(ptr->left)
				ptr = ptr->left;
			(*pred) = ptr;
		}
	}
	else if(ptr->value > val){
		if(ptr->left && ptr->left->value > val)
			successor(ptr->left, pred, val);
	}
	else if(ptr->value < val){
		if(ptr->right)
			successor(ptr->right, pred, val);
	}
}

int main(){ 
    root = new Node(13);
    
    int read = 6;
    int x;
    while(read){
        cout<<"Enter a value into the BST\n";
        cin >> x;
        
        if(insert(x))
            read--;
    }
    
    cout<<"Inorder BST traversal\n";
    inorder(root);
    cout<<"\n";

	 Node* pred = nullptr;
	 Node* succ = nullptr;	
	 int num;	
	 cout<<"Enter a value whose predecessor & successor needs to be found"<<endl;
	 cin >> num;		
	 predecessor(root, &pred, num);
	 successor(root, &succ, num);
	
	 cout<<"Predecessor of "<<num<<": "<<pred->value<<endl;
	 cout<<"Successor of "<<num<<": "<<succ->value<<endl;

    return 0;
}