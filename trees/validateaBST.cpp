#include<iostream>
#include<climits>
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
bool isValidBST(Node* root, long minval, long maxval){
    if(root==NULL)
    return true;
    if(root->data>=maxval || root->data<=minval)
    return false;
    return isValidBST(root->left,minval,root->data) && isValidBST(root->right,root->data,maxval);
}
int main(){
    Node* root=new Node(5);
    root->left=new Node(2);
    root->right=new Node(6);
    root->right->left=new Node(4);
    root->right->right=new Node(9);
    long minval=INT_MIN;
    long maxval=INT_MAX;
    if(isValidBST(root,minval,maxval))
    cout<<"YES BST";
    else
    cout<<"NOT A BST";
}