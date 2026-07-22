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
Node* insertVal(Node* root, int ele){
    if(root==NULL){
        root=new Node(ele);
        return root;
    }
    Node* curr=root;
    while(true){
        if(ele>curr->data){
            if(curr->right!=NULL)
            curr=curr->right;
            else{
            curr->right=new Node(ele);
            break;
            }
        }
        else{
            if(curr->left!=NULL)
            curr=curr->left;
            else{
                curr->left=new Node(ele);
                break;
            }
        }
    }
    return root;
}
void inorder(Node* root){
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    Node* root=new Node(10);
    root->left=new Node(5);
    root->left->left=new Node(3);
    root->left->left->left=new Node(2);
    root->left->left->right=new Node(4);
    root->left->right=new Node(6);
    root->left->right->right=new Node(9);
    root->right=new Node(13);
    root->right->left=new Node(11);
    root->right->right=new Node(14);
    Node* ans=insertVal(root,15);
    inorder(ans);
}