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

int height(Node* root){
    if(root==NULL)
    return 0;
    int lh=height(root->left);
    if(lh==-1) return -1;
    int rh=height(root->right);
    if(rh==-1) return -1;
    if(abs(lh-rh)>1) return -1;
    return 1+max(lh,rh);
}
bool isBalanced(Node* root){
    return height (root) != -1;
}
int main(){
    Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    root->left->right=new Node(50);
    bool check=isBalanced(root);
    cout<<check<<endl;
}