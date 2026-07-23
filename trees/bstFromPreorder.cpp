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