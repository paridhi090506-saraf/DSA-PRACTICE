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
void changeTree(Node* root){
    if(root==NULL)
    return;
    int count=0;
    if(root->left){
         count+=root->left->data;
    }
    if(root->right){
        count+=root->right->data;
    }

    if(count>=root->data)
    root->data=count;
    else{
        if(root->left){
            root->left->data=root->data;
        }
        if(root->right){
            root->right->data=root->data;
        }
    }
    changeTree(root->left);
    changeTree(root->right);

    int tot=0;
    if(root->left){
        tot+=root->left->data;
    }
    if(root->right){
        tot+=root->right->data;
    }
    if(root->left || root->right)
    root->data=tot;
}
void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
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
    cout << "Inorder traversal before conversion:\n";
    inorder(root);
    changeTree(root);
    cout << "\n\nInorder traversal after conversion:\n";
    inorder(root);
    return 0;
}