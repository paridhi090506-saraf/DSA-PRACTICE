#include<iostream>
#include<vector>
#include<queue>
#include<map>
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
bool rootToNodePath(Node* root, vector<int> & arr, int x){
    if(root==NULL)
    return false;
    arr.push_back(root->data);
    if(root->data==x)
    return true;
    if(rootToNodePath(root->left,arr,x) || rootToNodePath(root->right,arr,x))
    return true;
    arr.pop_back();
    return false;
}
vector<int> getPath(Node* root,int B){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    rootToNodePath(root,ans,B);
    return ans;
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
    vector<int> arr=getPath(root,7);
    for(auto it: arr){
        cout<<it<<" ";
    }
}