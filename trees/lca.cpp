#include<iostream>
#include<vector>
#include<queue>
#include<map>
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
Node* lcaNode(Node* root, Node* p, Node* q){
    if(root==NULL || root==p || root==q){
        return root;
    }
    Node* left=lcaNode(root->left,p,q);
    Node* right=lcaNode(root->right,p,q);
    if(left==NULL)
    return right;
    if(right==NULL)
    return left;
    else{
        return root;
    }
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(8);
    root->right->right = new Node(6);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);
    Node* p = root->left->left;
    Node* q = root->left->right->left;
    Node* ans=lcaNode(root,p,q);
    cout<<ans->data;
}