#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data=value;
        left=nullptr;
        right=nullptr;
    }
};

int main(){
    Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    root->left->right=new Node(50);
    

    cout << root->data << endl;                    
    cout << root->left->data << endl;              
    cout << root->right->data << endl;             
    cout << root->left->left->data << endl;        
    cout << root->left->right->data << endl;     
    return 0; 
}


//to construct a unique binary tree we need either inorder and postorder or inorder and preorder
//with only postorder and preorder given, we can construct binary tree but not unique binary tree