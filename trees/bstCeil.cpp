#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};
int ceilFind(Node* root,int key){
    int ceil=-1;
    while(root){
        if(key==root->data){
            ceil=root->data;
            return ceil;
        }
        else if(key>root->data){
            root=root->right;
        }
        else
        {
            ceil=root->data;
            root=root->left;
        }
    }
    return ceil;
}
int main(){
    Node* root=new Node(10);
    root->left=new Node(5);
    root->left->left=new Node(3);
    root->left->left->left=new Node(2);
    root->left->right=new Node(6);
    root->left->left->right=new Node(4);
    root->left->right->right=new Node(9);
    root->right=new Node(13);
    root->right->left=new Node(11);
    root->right->right=new Node(14);

    int ans=ceilFind(root,8);
    cout<<ans;
}