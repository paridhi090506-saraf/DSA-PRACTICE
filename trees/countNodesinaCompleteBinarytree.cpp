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
int leftHeight(Node* root){
    int h=0;
    while(root){
        h++;
        root=root->left;
    }
    return h;
}
int rightHeight(Node* root){
    int h=0;
    while(root){
        h++;
        root=root->right;
    }
    return h;
}
int nodes(Node* root)
{
    if(root==NULL)
    return 0;
    int lh=leftHeight(root);
    int rh=rightHeight(root);

    if(lh==rh)
    return (1<<lh)-1;

    return 1+nodes(root->left)+nodes(root->right);
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
    int n=nodes(root);
    cout<<n;
}