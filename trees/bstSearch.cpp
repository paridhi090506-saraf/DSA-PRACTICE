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
Node* searchBST(Node* root, int search){
    while(root!=NULL && root->data!=search){
        root=search<root->data? root->left:root->right;
    }
    return root;
}
int main(){
    Node* root=new Node(8);
    root->left=new Node(5);
    root->left->left=new Node(4);
    root->left->right=new Node(7);
    root->left->right->left=new Node(6);
    root->right=new Node(12);
    root->right->right=new Node(14);
    root->right->left=new Node(10);
    root->right->right->left=new Node(13);

    Node* ans=searchBST(root,13);
    if(ans!=NULL){
        cout<<"Found"<<endl;
    }
    else
    cout<<"Not found"<<endl;
}