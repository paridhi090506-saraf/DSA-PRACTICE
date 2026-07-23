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
Node* lcaNodeinBST(Node* root,Node* p, Node* q){
    if(root==NULL)
    return NULL;
    int curr=root->data;
    if(curr<p->data && curr<q->data)
    return lcaNodeinBST(root->right,p,q);
    if(curr>p->data && curr>q->data)
    return lcaNodeinBST(root->left,p,q);
    return root;
}
int main(){
    Node* root=new Node(10);
    root->left=new Node(4);
    root->left->left=new Node(3);
    root->left->left->left=new Node(1);
    root->left->left->left->right=new Node(2);
    root->left->right=new Node(8);
    root->left->right->left=new Node(6);
    root->left->right->left->left=new Node(5);
    root->left->right->left->right=new Node(7);
    root->left->right->right=new Node(9);
    root->right=new Node(13);
    root->right->left=new Node(11);
    root->right->right=new Node(15);

    Node* ans=lcaNodeinBST(root,root->left->right->left->right,root->left->right->right);
    cout<<ans->data<<endl;
}