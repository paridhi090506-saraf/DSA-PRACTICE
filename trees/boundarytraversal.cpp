#include<iostream>
#include<vector>
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
bool isLeaf(Node* root){
    return (root->left==NULL) && (root->right==NULL);
}
vector<int> addLeft(Node* root, vector<int>& res){
    Node* curr=root->left;
    while(curr){
        if(!isLeaf(curr))
        res.push_back(curr->data);
        if(curr->left)
        curr=curr->left;
        else
        curr=curr->right;
    }
    return res;
}
vector<int> addRight(Node* root,vector<int> & res){
    Node* curr=root->right;
    vector<int> temp;
    while(curr){
        if(!isLeaf(curr))
        temp.push_back(curr->data);
        if(curr->right)
        curr=curr->right;
        else
        curr=curr->left;
    }
    for(int i=temp.size()-1;i>=0;i--)
    res.push_back(temp[i]);
    return res;
}
vector<int> addLeaves(Node* root, vector<int> & res){
    if(isLeaf(root)){
    res.push_back(root->data);
    return res;
    }
    if(root->left)
    addLeaves(root->left,res);
    if(root->right)
    addLeaves(root->right,res);
}
vector<int> boundaryTraversal(Node* root){
    vector<int> result;
    if(!root)
    return result;
    if(!isLeaf(root))
    result.push_back(root->data);
    addLeft(root,result);
    addLeaves(root,result);
    addRight(root,result);
    return result;
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

    vector<int> ans=boundaryTraversal(root);
    for(auto it:ans){
        cout<<it<<" ";
    }
}