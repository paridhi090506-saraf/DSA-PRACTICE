#include<iostream>
#include<vector>
#include<climits>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int value){
        data=value;
        left=NULL;
        right=NULL;
    }
};
Node* build(vector<int>& preorder,int &i,int bound){
    if(i==preorder.size() || preorder[i]>bound)
        return NULL;
    Node* root=new Node(preorder[i++]);
    root->left=build(preorder,i,root->data);
    root->right=build(preorder,i,bound);
    return root;
}
Node* bstFromPreorder(vector<int>& preorder){
    int i=0;
    return build(preorder,i,INT_MAX);
}
void inorder(Node* root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    vector<int> preorder={8,5,1,7,10,12};
    Node* root=bstFromPreorder(preorder);
    inorder(root);
}

/* sort preorder so,will get inorder and then unique tree from inorder and preorder code */

/*
Node* insert(Node* root, int val){
    if(root==NULL)
        return new Node(val);
    if(val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}
Node* bstFromPreorder(vector<int>& preorder){
    Node* root = NULL;
    for(int x : preorder)
        root = insert(root, x);
    return root;
}*/