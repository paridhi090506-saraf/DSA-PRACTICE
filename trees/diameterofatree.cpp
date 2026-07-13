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
int height(Node* root, int& maxi){
    if(root==NULL)
    return 0;
    int lh=height(root->left,maxi);
    int rh=height(root->right,maxi);
    maxi=max(maxi,lh+rh);
    return 1+max(lh,rh);
}
int diameter(Node* root){
    int dia=0;
    height(root,dia);
    return dia;
}
int main(){
    Node* root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    root->left->right=new Node(50);
    int diam=diameter(root);
    cout<<diam<<endl;
}
