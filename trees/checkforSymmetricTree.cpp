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
bool isSymmetricCheck(Node* left, Node* right){
    if(left==NULL || right==NULL){
        return (left==right);
    }
    if( left->data!=right->data)
    return false;
    return isSymmetricCheck(left->left,right->right) && isSymmetricCheck(left->right,right->left);
}
bool isSymmetric(Node* root)
{
    return root==NULL || isSymmetricCheck(root->left,root->right);
}
int main(){
    Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(20);
    root->left->left=new Node(40);
    root->left->right=new Node(50);
    root->right->right=new Node(40);
    root->right->left=new Node(50);
    bool check=isSymmetric(root);
    cout<<check<<endl;
}