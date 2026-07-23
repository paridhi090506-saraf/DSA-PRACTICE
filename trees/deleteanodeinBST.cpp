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
Node* findlastRight(Node* root){
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}
Node* helper(Node* root){
    if(root->left == NULL)
    return root->right;
    else if( root->right ==NULL)
    return root->left;
    Node* rightChild= root->right;
    Node* lastright=findlastRight(root->left);
    lastright->right=rightChild;
    return root->left;
}
Node* deleteNode(Node* root, int val){
    if(root==NULL)
    return NULL;
    if(root->data==val){
        return helper(root);
    }
    Node* dummy=root;
    while(root!=NULL){
        if(root->data>val){
            if(root->left!=NULL && root->left->data==val){
                root->left=helper(root->left);
                break;
            }
            else
            root=root->left;
        }
        else{
            if(root->right!=NULL && root->right->data==val){
                root->right=helper(root->right);
                break;
            }
            else
            root=root->right;
        }
    }
    return dummy;
}
void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    Node* root=new Node(9);
    root->left=new Node(5);
    root->left->left=new Node(2);
    root->left->left->left=new Node(1);
    root->left->left->right=new Node(3);
    root->left->left->right->right=new Node(4);
    root->left->right=new Node(7);
    root->left->right->left=new Node(6);
    root->left->right->right=new Node(8);
    root->right=new Node(12);
    root->right->left=new Node(11);
    root->right->right=new Node(13);
    Node* ans=deleteNode(root,5);
    inorder(ans);

}